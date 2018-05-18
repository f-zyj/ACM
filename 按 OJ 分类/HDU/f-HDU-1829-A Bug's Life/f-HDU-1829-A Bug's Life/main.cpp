//
//  main.cpp
//  f-HDU-1829-A Bug's Life
//
//  Created by ZYJ on 2016/11/3.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>

const int MAXN = 2010;

int pre[MAXN];
int rank[MAXN];  //  1:同 0:异
bool flag;      //  false:无冲突，true：有冲突

void init(int n)
{
    flag = false;
    for (int i = 0; i <= n; i++)
    {
        pre[i] = i;
        rank[i] = 0;
    }
}

int find(int x)
{
    if (x == pre[x])
    {
        return pre[x];
    }
    int temp = find(pre[x]);
    rank[x] = (rank[pre[x]] + rank[x]) & 1;
    pre[x] = temp;
    return pre[x];
}

void join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    
    if (fx != fy)
    {
        pre[fx] = fy;
        rank[fx] = (rank[x] + rank[y] + 1) & 1;
    }
    else
    {
        if (rank[x] == rank[y])
        {
            flag = true;
        }
    }
    
    return ;
}

int main()
{
    int T;
    scanf("%d", &T);
    
    int n, m;
    int bug, bug_;
    
    for (int i = 1; T--; i++)
    {
        scanf("%d%d", &n, &m);
        
        init(n);
        
        for (int j = 0; j < m; j++)
        {
            scanf("%d%d", &bug, &bug_);
            if (flag)
            {
                continue;
            }
            join(bug, bug_);
        }
        
        if (flag)
        {
            printf("Scenario #%d:\nSuspicious bugs found!\n\n", i);
        }
        else
        {
            printf("Scenario #%d:\nNo suspicious bugs found!\n\n", i);
        }
    }
    
    return 0;
}
