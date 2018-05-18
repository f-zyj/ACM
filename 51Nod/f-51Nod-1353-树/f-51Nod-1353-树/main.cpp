//
//  main.cpp
//  f-51Nod-1353-树
//
//  Created by ZYJ on 2017/6/8.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 2222;
const int MOD = 1e9 + 7;

int n, k;
int tot = 0;
int pre[MAXN];
int dp[MAXN][MAXN];
int s[MAXN];

struct edge
{
    int next;
    int to;
} e[MAXN << 1];

void AND_MOD(int &x, int y)
{
    x += y;
    if (x >= MOD)
    {
        x -= MOD;
    }
}

void dfs(int u, int fa)
{
    dp[u][s[u] = 1] = 1;
    for (int it = pre[u]; it; it = e[it].next)
    {
        if (e[it].to == fa)
        {
            continue;
        }
        dfs(e[it].to, u);
        for (int i = s[u]; i > 0; i--)
        {
            for (int j = s[e[it].to]; j > 0; j--)
            {
                AND_MOD(dp[u][i + j], (long long)dp[u][i] * dp[e[it].to][j] % MOD);
            }
            dp[u][i] = (long long)dp[u][i] * dp[e[it].to][0] % MOD;
        }
        s[u] += s[e[it].to];
    }
    
    for (int i = k; i <= s[u]; i++)
    {
        AND_MOD(dp[u][0], dp[u][i]);
    }
}

int main()
{
    cin >> n >> k;
    
    int u, v;
    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        e[++tot] = (edge){pre[u], v};
        pre[u] = tot;
        e[++tot] = (edge){pre[v], u};
        pre[v] = tot;
    }
    
    dfs(1, -1);
    
    printf("%d\n", dp[1][0]);
    
    return 0;
}
