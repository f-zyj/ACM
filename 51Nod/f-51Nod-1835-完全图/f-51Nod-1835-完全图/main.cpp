//
//  main.cpp
//  f-51Nod-1835-完全图
//
//  Created by ZYJ on 2017/12/7.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 998244353;
const int MAXN = 555;

int n, m;
int dp[MAXN][MAXN];
int C[MAXN][MAXN];

ll QPow(ll x, ll n)
{
    ll ret = 1;
    ll tmp = x % MOD;
    
    while (n)
    {
        if (n & 1)
        {
            ret = (ret * tmp) % MOD;
        }
        tmp = tmp * tmp % MOD;
        n >>= 1;
    }
    
    return ret;
}

void init()
{
    for (int i = 0; i < MAXN; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
}

int main(int argc, const char * argv[])
{
    init();
    
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j <= i; j++)
        {
            for (int k = 1, t = i - j + 1; k <= t; k++)
            {
                dp[i][j] = (dp[i][j] + (ll)dp[i - k][j - 1] * dp[k][1] % MOD
                         * C[i - 1][k - 1] % MOD) % MOD;
            }
        }
        dp[i][1] = (int)QPow(2, i * (i - 1) >> 1);
        for (int j = 2; j <= i; j++)
        {
            dp[i][1] = (dp[i][1] - dp[i][j] + MOD) % MOD;
        }
    }
    
    printf("%d\n", m != 1 ? dp[n][m] : dp[n][m] - 1);
    
    return 0;
}
