//
//  main.cpp
//  f-UVA-11600-Masud Rana
//
//  Created by ZYJ on 2017/10/15.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

#define INF 0x3f3f3f3f
#define MAXN 32
#define MAXM 500

using namespace std;

int T, N, M, tot;
int vis[MAXN];
int cnt[MAXN];
int mp_[MAXN][MAXN];
map<int, double> dp[MAXM];

void dfs(int x)
{
    vis[x] = 1;
    cnt[tot]++;
    for (int i = 1; i <= N; i++)
    {
        if (mp_[x][i] && !vis[i])
        {
            dfs(i);
        }
    }
}

int num(int x)
{
    int ret = 0;
    for (int i = 0; i < tot; i++)
    {
        if (x & (1 << i))
        {
            ret += cnt[i];
        }
    }
    
    return ret;
}

double get_dp(int u, int st)
{
    if (dp[u].count(st))
    {
        return dp[u][st];
    }
    
    double &ans = dp[u][st];
    int n = num(st);
    if (n == N)
    {
        return ans = 0;
    }
    
    ans = 1.0 * (N - 1) / (N - n);
    for (int i = 0; i < tot; i++)
    {
        if (!(st & (1 << i)))
        {
            ans += get_dp(i, st | (1 << i)) * cnt[i] / (N - n);
        }
    }
    return ans;
}

int main()
{
    scanf("%d", &T);
    
    for (int ce = 1; ce <= T; ce++)
    {
        scanf("%d%d", &N, &M);
        
        memset(mp_, 0, sizeof(mp_));
        memset(vis, 0, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));
        
        int u, v;
        while (M--)
        {
            scanf("%d%d", &u, &v);
            mp_[u][v] = mp_[v][u] = 1;
        }
        
        //  缩点
        tot = 0;
        for (int i = 1; i <= N; i++)
        {
            if (!vis[i])
            {
                dfs(i);
                tot++;
            }
        }
        
        for (int i = 0; i < N; i++)
        {
            dp[i].clear();
        }
        printf("Case %d: %.6lf\n", ce, get_dp(0, 1));
    }
    
    return 0;
}

