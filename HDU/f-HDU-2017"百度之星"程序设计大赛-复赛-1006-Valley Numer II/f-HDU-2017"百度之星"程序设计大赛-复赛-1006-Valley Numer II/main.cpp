//
//  main.cpp
//  f-HDU-2017"百度之星"程序设计大赛-复赛-1006-Valley Numer II
//
//  Created by ZYJ on 2017/8/23.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e4 + 10;
const int MAXM = 100;
const int MAXD = (1 << 15) + 10;

int N, M, K;
int vis[MAXN];
int V[MAXN];
int map[MAXM][MAXM];
int dp[2][MAXD];

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        memset(vis, 0, sizeof(vis));
        memset(map, 0, sizeof(map));
        
        scanf("%d%d%d", &N, &M, &K);
        
        int X, Y;
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d", &X, &Y);
            map[X][Y] = map[Y][X] = 1;
        }
        
        for (int i = 0; i < K; i++)
        {
            scanf("%d", &V[i]);
            vis[V[i]] = 1;
        }
        
        memset(dp, 0, sizeof(dp));
        
        int now = 0, tmp = 1 << K, sta;
        for (int i = 1; i <= N; i++)
        {
            if (vis[i])
            {
                continue;
            }
            
            now ^= 1;
            for (int j = 0; j < tmp; j++)
            {
                dp[now][j] = dp[now ^ 1][j];
            }
            for (int j = 0; j < tmp; j++)
            {
                for (int k = 0; k < K; k++)
                {
                    if (!(j & (1 << k)) && map[i][V[k]])
                    {
                        for (int l = k + 1; l < K; l++)
                        {
                            if (!(j & (1 << l)) && map[i][V[l]])
                            {
                                sta = (j) | (1 << k) | (1 << l);
                                dp[now][sta] = max(dp[now][sta], dp[now ^ 1][j] + 1);
                            }
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < tmp; i++)
        {
            ans = max(ans, dp[now][i]);
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
