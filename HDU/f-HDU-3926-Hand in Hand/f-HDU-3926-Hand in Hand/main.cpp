//
//  main.cpp
//  f-HDU-3926-Hand in Hand
//
//  Created by ZYJ on 2016/11/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int pre[MAXN];
int p[MAXN];
int sum[MAXN];

int find(int x)
{
    int i = x, root;
    while (x != pre[x])
    {
        x = pre[x];
    }
    
    root = x;
    x = i;
    while (x != pre[x])
    {
        i = pre[x];
        pre[x] = root;
        sum[root] += sum[x];
        p[root] += p[x];
        sum[x] = 0;
        p[x] = 0;
        x = i;
    }
    return root;
}

void join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    
    if (fx != fy)
    {
        pre[fx] = fy;
        sum[fy] += sum[fx];
        p[fy] += p[fx];
        sum[fx] = 0;
        p[fx] = 0;
    }
    else
    {
        //  形成环
        p[fx]++;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    int key = 1;
    
    while (T--)
    {
        set<int> cirNode, other;
    
        int n, m;
        
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; i++)
        {
            pre[i] = i;
            p[i] = 1;
            sum[i] = 1;
        }
        for (int i = 1; i <= m; i++)
        {
            int tmp, tmp_;
            scanf("%d%d", &tmp, &tmp_);
            if (tmp == tmp_)
            {
                continue;
            }
            join(tmp, tmp_);
        }
        
        for (int i = 1; i <= n; i++)
        {
            if (p[i] == sum[i])
            {
                other.insert(p[i]);
            }
            else
            {
                cirNode.insert(p[i]);
            }
        }
        int ans = (int)other.size();
        int ans_ = (int)cirNode.size();
        
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; i++)
        {
            pre[i] = i;
            p[i] = 1;
            sum[i] = 1;
        }
        for (int i = 1; i <= m; i++)
        {
            int tmp, tmp_;
            scanf("%d%d", &tmp, &tmp_);
            if (tmp == tmp_)
            {
                continue;
            }
            join(tmp, tmp_);
        }
        for (int i = 1; i <= n; i++)
        {
            if (p[i] == sum[i])
            {
                other.insert(p[i]);
            }
            else
            {
                cirNode.insert(p[i]);
            }
        }
        
        
        if (cirNode.size() == ans_ && other.size() == ans)
        {
            printf("Case #%d: YES\n", key++);
        }
        else
        {
            printf("Case #%d: NO\n", key++);
        }
    }
    
    return 0;
}

