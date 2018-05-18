//
//  main.cpp
//  f-HDU-5791-Two
//
//  Created by ZYJ on 16/8/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

typedef long long ll;

using namespace std;

const int mod = 1000000007;

int a[1005], b[1005];
long long dp[1005][1005];

int main()
{
    int n, m, i, j;
    while (~scanf("%d%d", &n, &m))
    {
        memset(dp, 0, sizeof(dp));
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (i = 1; i <= m; i++)
        {
            scanf("%d", &b[i]);
        }
        
        //  考虑到四部分dp[i - 1][j - 1] x 2（重叠部分）
        //  dp[i - 1][j] - dp[i - 1][j - 1]
        //  dp[i][j - 1] - dp[i - 1][j - 1]
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                if (a[i] == b[j])   //  这里重叠部分，一部分与a[i]、b[j]搭配，剩下一部分保持原组合
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + 1) % mod;
                }
                else                //  因为不存在与a[i]、b[j]搭配的组合，所以需要减去此重叠部分，去重
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mod) % mod;
                }
            }
        }
        printf("%lld\n", dp[n][m] % mod);
    }
    
    return 0;
}