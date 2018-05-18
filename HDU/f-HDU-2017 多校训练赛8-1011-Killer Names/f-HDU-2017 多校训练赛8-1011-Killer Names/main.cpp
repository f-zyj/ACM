//
//  main.cpp
//  f-HDU-2017 多校训练赛8-1011-Killer Names
//
//  Created by ZYJ on 2017/8/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 2222;
const int MOD = 1e9 + 7;

int n, m;
int C[MAXN][MAXN];
ll p[MAXN];

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
    C[0][0] = 1;
    for (int i = 1; i < MAXN; i++)
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
    
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            p[i] = QPow(i, n);
        }
        for (int i = 2; i <= m; i++)
        {
            for (int j = 1; j < i; j++)
            {
                p[i] = (p[i] - p[j] * C[i][j] % MOD + MOD) % MOD;
            }
        }
        
        ll ans = 0;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1, k = m - i; j <= k; j++)
            {
                ans = (ans + p[i] * p[j] % MOD * C[m][i] % MOD * C[k][j] % MOD) % MOD;
            }
        }
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
