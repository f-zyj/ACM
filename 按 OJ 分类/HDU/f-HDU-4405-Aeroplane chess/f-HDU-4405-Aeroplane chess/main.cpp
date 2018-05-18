//
//  main.cpp
//  f-HDU-4405-Aeroplane chess
//
//  Created by ZYJ on 2017/11/1.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <cstring>

#define ll long long

const int MAXN = 1e5 + 10;

int n, m;
int vis[MAXN];
double dp[MAXN];

int main()
{
    while (~scanf("%d%d", &n, &m) && n + m)
    {
        memset(dp, 0, sizeof(dp));
        memset(vis, -1, sizeof(vis));
        
        int a, b;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &a, &b);
            vis[a] = b;
        }
        
        for (int i = n - 1; i >= 0; i--)
        {
            if (vis[i] == -1)
            {
                for (int j = 1; j <= 6; j++)
                {
                    dp[i] += dp[i + j] / 6.0;
                }
                dp[i] += 1;
            }
            else
            {
                dp[i] = dp[vis[i]];
            }
        }
        
        printf("%.4lf\n", dp[0]);
    }
    
    return 0;
}
