//
//  main.cpp
//  f-51Nod-1371-填数字
//
//  Created by ZYJ on 2017/9/6.
//  Copyright ? 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 222;
const int MOD = 1e8 + 7;

int n;
ll C[MAXN][MAXN];
ll dp[MAXN][MAXN][MAXN];    //  dp[i][j][k]:填完第 i 行后，j 列和是 1，k 列和是 2 的方案数

int main()
{
    scanf("%d", &n);
    
    C[0][0] = 1;
    C[1][0] = C[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        C[i][i] = C[i][0] = 1;
        for (int j = 1; j < i; j++)
        {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            C[i][j] %= MOD;
        }
    }
    
    dp[1][0][0] = dp[1][1][0] = dp[1][0][1] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int col = j + 1, t = i - j;
            for (int k = 0; k <= t; k++)
            {
                int tmpi = min(col, 2);
                for (int ii = 0; ii <= tmpi; ii++)          //  放 1 在前 i 行和为 0 的列
                {
                    int tmpj = min(col - ii, 1);
                    for (int jj = 0; jj <= tmpj; jj++)      //  放 2 在前 i 行和为 0 的列
                    {
                        for (int kk = 0; kk <= k; kk++)     //  放 1 在前 i 行和为 1 的列
                        {
                            if (ii + kk > 2)
                            {
                                break;
                            }
                            if (col - jj + k - kk > i + 1)
                            {
                                break;
                            }
                            if (ii + kk + 2 * jj > 2)
                            {
                                continue;
                            }
                            
                            dp[i + 1][col - jj - ii][k - kk + ii] +=
                                    dp[i][col - 1][k] * C[col][ii] % MOD
                                    * C[col][jj] % MOD * C[k][kk] % MOD;
                            dp[i + 1][col - jj - ii][k - kk + ii] %= MOD;
                        }
                    }
                }
            }
        }
    }
    
    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= (n - i); j++)
        {
            ans += dp[n][i][j];
            ans %= MOD;
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
