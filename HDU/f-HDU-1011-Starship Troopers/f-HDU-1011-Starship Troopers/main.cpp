//
//  main.cpp
//  f-HDU-1011-Starship Troopers
//
//  Created by ZYJ on 2016/10/23.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 110;
const int TROOPER_FIGHT = 20;

int n, m;
int cos[MAXN];
int val[MAXN];
int dp[MAXN][MAXN]; //  dp[p][i]：以i个士兵占领p为根节点的子树所能获得的最大价值
bool vis[MAXN];

vector<int> dv[MAXN];

inline int max(int a, int b)
{
    return a > b ? a : b;
}

void dfs(int p)
{
    int temp = (cos[p] + TROOPER_FIGHT - 1) / TROOPER_FIGHT;
    for (int i = temp; i <= m; i++)
    {
        dp[p][i] = val[p];
    }
    vis[p] = 1;
    for (int i = 0; i < dv[p].size(); i++)
    {
        int t = dv[p][i];
        if (vis[t])
        {
            continue;
        }
        dfs(t);
        for (int j = m; j >= temp; j--)
        {
            for (int k = 1; k <= j - temp; k++)     //  留下temp攻打p
            {
                dp[p][j] = max(dp[p][j], dp[p][j - k] + dp[t][k]);
            }
        }
    }
}

int main()
{
    while (scanf("%d%d", &n, &m), n != -1 || m != -1)
    {
        for (int i = 0; i <= n; i++)
        {
            dv[i].clear();
        }
        memset(dp, 0, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", cos + i, val + i);
        }
        int u, v;
        for (int i = 1; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            dv[u].push_back(v);
            dv[v].push_back(u);
        }
        if (m == 0)
        {
            printf("0\n");
            continue;
        }
        
        dfs(1);
        printf("%d\n", dp[1][m]);
    }
    
    return 0;
}
