//
//  main.cpp
//  f-HDU-2017 多校训练赛6-1010-Gameia
//
//  Created by ZYJ on 2017/8/21.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 505;

vector<int> vt[MAXN];

int n, k, flag;
int sz[MAXN];

void dfs(int u)
{
    int num = 0;            //  奇数节点的个数
    sz[u] = 1;
    for (int i = 0; i < vt[u].size(); i++)  //  递归所有的子节点
    {
        int to = vt[u][i];
        dfs(to);
        sz[u] += sz[to];
        if (sz[to] % 2 == 1)
        {
            num++;          //  为奇数的节点（包括单独的叶子节点），Alice回赢
        }
    }
    if (num >= 2)
    {
        flag = 1;           //  这样的话也就相当于只有有两个节点的话，Bob才会赢
    }
}

void init()
{
    flag = 0;
    for (int i = 0; i < MAXN; i++)
    {
        vt[i].clear();
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        init();
        
        scanf("%d%d", &n, &k);
        
        int x;
        for (int i = 2; i <= n; i++)
        {
            scanf("%d", &x);
            vt[x].push_back(i);
        }
        
        flag = 0;
        if (n % 2 == 1 || n / 2 - 1 > k)    //  奇数个或者特权数不够用，必定Alice赢
        {
            printf("Alice\n");
        }
        else                                //  节点个数为偶数个并且特权个数足够用
        {
            dfs(1);
            
            if (flag == 1)
            {
                printf("Alice\n");
            }
            else
            {
                printf("Bob\n");
            }
        }
    }
    
    return 0;
}
