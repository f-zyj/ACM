//
//  main.cpp
//  f-ZZULIOJ-多校训练（985专场）-C-985的方格难题
//
//  Created by ZYJ on 16/8/3.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;

int dp[31][31];

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    int n, x, y;
    while (T--)
    {
        cin >> n >> x >> y;
        if ((x == n && y == n) || (x == 1 && y == 1))
        {
            cout << "-1\n";
            continue;
        }
        
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            dp[i][1] = 1;
            dp[1][i] = 1;
        }
        dp[x][y] = 0;
        if (x == 1)
        {
            for (int i = y + 1; i <= n; i++)
            {
                dp[1][i] = 0;
            }
        }
        if (y == 1)
        {
            for (int i = x + 1; i <= n; i++)
            {
                dp[i][1] = 0;
            }
        }
        
        for (int i = 2; i <= n; i++)
        {
            for (int j = 2; j <= n; j++)
            {
                if (!(i == x && j == y))
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
                }
            }
        }
        
        cout << dp[n][n] << '\n';
        
    }
    return 0;
}
