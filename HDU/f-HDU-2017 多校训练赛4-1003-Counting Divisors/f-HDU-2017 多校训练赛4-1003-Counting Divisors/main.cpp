//
//  main.cpp
//  f-HDU-2017 多校训练赛4-1003-Counting Divisors
//
//  Created by ZYJ on 2017/8/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long ll;

const int MOD = 998244353;
const int MAXN = 1e6 + 10;

ll l, r, k, ans;
ll A[MAXN];
ll B[MAXN];

int prime[MAXN];

void init()
{
    memset(prime, 0, sizeof(prime));
    
    for (int i = 2; i <= MAXN; i++)
    {
        if (!prime[i])
        {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++)
        {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
}

void solve()
{
    for (int i = 0; i <= r - l; i++)
    {
        A[i] = i + l;
        B[i] = 1;
    }
    
    for (int i = 1; i <= prime[0] && prime[i] * prime[i] <= r; i++)
    {
        ll tmp = prime[i];
        ll t = l / tmp * tmp;
        if (t != l)
        {
            t += tmp;
        }
        
        while (t <= r)
        {
            ll cnt = 0;
            ll x = A[t - l];
            while (x % tmp == 0)
            {
                x /= tmp;
                cnt++;
            }
            
            A[t - l] = x;
            cnt = (cnt * k) % MOD;
            B[t - l] = (((cnt + 1) % MOD) * B[t - l]) % MOD;
            t += tmp;
        }
    }
    
    ans = 0;
    for (ll i = 0; i <= (r - l); i++)
    {
        if (A[i] != 1)
        {
            B[i] *= (k + 1) % MOD;
            B[i] %= MOD;
        }
        ans = (ans + B[i]) % MOD;
    }
}

int main()
{
    init();
    
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld%lld", &l, &r, &k);
        
        solve();
        
        printf("%lld\n", ans);
    }
    
    return 0;
}

