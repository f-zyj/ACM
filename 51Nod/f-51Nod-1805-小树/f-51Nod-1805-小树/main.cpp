//
//  main.cpp
//  f-51Nod-1805-小树
//
//  Created by ZYJ on 2018/1/5.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>

typedef long long ll;

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;

int n, m;
ll fac[MAXN];       //  阶乘
ll inv[MAXN];       //  阶乘的逆元

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
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv[MAXN - 1] = QPow(fac[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

ll C(ll a, ll b)
{
    if (b > a)
    {
        return 0;
    }
    if (b == 0)
    {
        return 1;
    }
    return fac[a] * inv[b] % MOD * inv[a - b] % MOD;
}

int main()
{
    init();
    
    scanf("%d%d", &n, &m);

    if (n == 1 || n == 2)
    {
        puts("1");
        return 0;
    }
    
    ll ans = 0;
    int tmp = n - m;
    for (int i = tmp; i >= 1; i--)
    {
        if ((i & 1) == (tmp & 1))
        {
            ans += QPow(i, n - 2) * C(n - m, i) % MOD;
        }
        else
        {
            ans -= QPow(i, n - 2) * C(n - m, i) % MOD;
        }
        ans = (ans + MOD) % MOD;
    }
    ans = ans * C(n, m) % MOD;
    
    printf("%lld\n", ans);
    
    return 0;
}
