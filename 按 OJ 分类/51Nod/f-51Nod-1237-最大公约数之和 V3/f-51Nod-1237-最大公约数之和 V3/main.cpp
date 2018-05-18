//
//  main.cpp
//  f-51Nod-1237-最大公约数之和 V3
//
//  Created by ZYJ on 2017/8/16.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

#define ll long long

using namespace std;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
const int INV_2 = 5e8 + 4;

ll pri[MAXN];
ll vis[MAXN];
ll phi[MAXN];
ll h[MAXN * 10];
ll f[MAXN * 10];
ll n, ans;

int hash_(ll x)
{
    int t = x % MAXN;
    while (h[t] && h[t] != x)
    {
        t = (t + 1) % MAXN;
    }
    return t;
}

ll Gphi(ll n)
{
    if (n <= MAXN)
    {
        return phi[n];
    }
    
    ll x = hash_(n);
    if (h[x])
    {
        return f[x];
    }
    
    ll t = n % MOD;
    ll k = t * (t + 1) % MOD * INV_2 % MOD;
    for (ll i = 2; i <= n; i = t + 1)
    {
        t = n / (n / i);
        k -= Gphi(n / i) * (t - i + 1) % MOD;
    }
    k = (k % MOD + MOD) % MOD;
    h[x] = n;
    f[x] = k;
    return k;
}

void init()
{
    phi[1] = 1;
    for (int i = 2; i <= MAXN; i++)
    {
        if (!vis[i])
        {
            pri[++pri[0]] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= pri[0]; j++)
        {
            if (i * pri[j] > MAXN)
            {
                break;
            }
            
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0)
            {
                phi[i * pri[j]] = phi[i] * pri[j];
                break;
            }
            else
            {
                phi[i * pri[j]] = phi[i] * phi[pri[j]];
            }
        }
    }
    for (int i = 1; i <= MAXN; i++)
    {
        phi[i] += phi[i - 1];
    }
}

int main()
{
    init();
    
    scanf("%lld", &n);
    
    ll t, l, k;
    for (ll i = 1; i <= n; i = t + 1)
    {
        t = n / (n / i);
        k = (Gphi(t) - Gphi(i - 1) + MOD) % MOD;
        l = n / i % MOD;
        ans = (ans + l * l % MOD * k % MOD) % MOD;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
