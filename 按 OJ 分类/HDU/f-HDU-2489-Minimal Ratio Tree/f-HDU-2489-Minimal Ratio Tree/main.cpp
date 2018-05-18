//
//  main.cpp
//  f-HDU-2489-Minimal Ratio Tree
//
//  Created by ZYJ on 2016/11/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>

const int INF = 0x3f3f3f3f;
const int MAXN = 20;

int n, m;
int vis[MAXN];
int ans[MAXN];
int pre[MAXN];
int hash[MAXN];
double minRatio;
double weight[MAXN];
double minCost[MAXN];
double G[MAXN][MAXN];


double prim()
{
    memset(hash, 0, sizeof(hash));
    
    int u;
    //  找一个起点当根
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
        {
            u = i;
            break;
        }
    }
    hash[u] = 1;
    double weightSum = 0, edgeSum = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
        {
            minCost[i] = G[u][i];
            pre[i] = u;
            weightSum += weight[i];
        }
    }
    
    for (int i = 1; i < m; ++i)
    {
        u = -1;
        for (int j = 1; j <= n; ++j)
        {
            if (vis[j] && !hash[j])
            {
                if (u == -1 || minCost[u] > minCost[j])
                {
                    u = j;
                }
            }
        }
        edgeSum += G[pre[u]][u];
        hash[u] = 1;
        for (int j = 1; j <= n; ++j)
        {
            if (vis[j] && !hash[j])
            {
                if (minCost[j] > G[u][j])
                {
                    minCost[j] = G[u][j];
                    pre[j] = u;
                }
            }
        }
    }
    return edgeSum / weightSum;
}


void dfs(int u, int num)
{
    if (num > m)
    {
        return ;
    }
    if (u == n + 1)
    {
        if (num != m)
        {
            return ;
        }
        double t = prim();
        if (t < minRatio)
        {
            minRatio = t;
            memcpy(ans, vis, sizeof(vis));
        }
        return ;
    }
    vis[u] = 1;
    dfs(u + 1, num + 1);
    vis[u] = 0;
    dfs(u + 1, num);
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        if (!n && !m)
        {
            break;
        }
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lf", &weight[i]);
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                scanf("%lf", &G[i][j]);
            }
        }
        
        memset(vis, 0, sizeof(vis));
        minRatio = INF;
        
        dfs(1, 0);
        
        bool flag = false;
        for (int i = 1; i <= n; ++i)
        {
            if (ans[i])
            {
                if (flag)
                {
                    printf(" %d", i);
                }
                else
                {
                    printf("%d", i);
                    flag = true;
                }
            }
        }
        puts("");
    }
    
    return 0;
}
