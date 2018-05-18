//
//  main.cpp
//  f-51Nod-1363-最小公倍数之和
//
//  Created by ZYJ on 2017/8/8.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

#define ll long long

using namespace std;

const ll MAXN = 1e5 + 10;
const ll MOD = 1e9 + 7;
const ll INV_2 = 5e8 + 4;

ll n, m, ans;
ll prime[MAXN];
bool flag[MAXN];

ll qpow(ll x, ll y)
{
    if (y == 1)
    {
        return x;
    }
    ll t = qpow(x, y / 2);
    if (y % 2 == 0)
    {
        return t * t % MOD;
    }
    return t * t % MOD * x % MOD;
}

void init()
{
    for (int i = 2; i < MAXN; i++)
    {
        if (!flag[i])
        {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0]; j++)
        {
            if (i * prime[j] > MAXN)
            {
                break;
            }
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
}

int main()
{
    init();
    
    scanf("%lld", &n);
    
    ll x, y;
    while (n--)
    {
        scanf("%lld", &x);
        
        ans = 1;
        y = x;
        for (int i = 1; prime[i] * prime[i] <= x; i++)
        {
            if (x % prime[i])
            {
                continue;
            }
            ll t = 0, k = 1;
            while (x % prime[i] == 0)
            {
                x /= prime[i];
                t++;
            }
            k += prime[i] * (qpow(prime[i], 2 * t) - 1) % MOD * qpow(prime[i] + 1, MOD - 2) % MOD;
            ans = ans * k % MOD;
        }
        
        ll k = (1 + (x - 1) * x) % MOD;
        ans = ans * k % MOD;
        ans--;
        ans = (ans * y % MOD * INV_2 % MOD + y) % MOD;
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
