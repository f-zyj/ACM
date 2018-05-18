//
//  main.cpp
//  f-SHU-“盛大游戏杯”第15届上海大学程序设计联赛夏季赛暨上海高校金马五校赛-I-丢史蒂芬妮
//
//  Created by ZYJ on 2017/7/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 555;

int n, m;
int prime[MAXN];
bool dp[MAXN][MAXN];
int vis[MAXN][MAXN];

bool dfs(int x, int y)
{
    if (vis[x][y])
    {
        return dp[x][y];
    }
    vis[x][y] = true;
    for (int i = 1; i <= prime[0]; i++)
    {
        if (x - prime[i] > 0)
        {
            dp[x][y] |= (!dfs(x - prime[i], y));
        }
        if (y - prime[i] > 0)
        {
            dp[x][y] |= (!dfs(x, y - prime[i]));
        }
        if (x - prime[i] > 0 && y - prime[i] > 0)
        {
            dp[x][y] |= (!dfs(x - prime[i], y - prime[i]));
        }
    }
    
    return dp[x][y];
}

void init()
{
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i <= MAXN; i++)
    {
        if (!prime[i])
        {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++)
        {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
    
    for (int i = 1; i < MAXN; i++)
    {
        for (int j = 1; j < MAXN; j++)
        {
            dfs(i, j);
        }
    }
}

int main()
{
    init();
    
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        puts(dp[n][m] ? "Sora" : "Shiro");
    }
    
    return 0;
}
