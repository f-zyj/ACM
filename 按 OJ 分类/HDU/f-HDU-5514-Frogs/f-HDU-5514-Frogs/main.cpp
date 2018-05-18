//
//  main.cpp
//  f-HDU-5514-Frogs
//
//  Created by ZYJ on 2017/10/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MAXN = 1e4 + 5;

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int n;
ll m;
ll a[MAXN];
ll g[MAXN];
ll fac[MAXN];

ll Phi(ll x)
{
    ll ans = x;
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            ans -= ans / i;
            while (x % i == 0)
            {
                x /= i;
            }
        }
    }
    
    if (x > 1)
    {
        ans -= ans/x;
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    
    for (int ce = 1; ce <= T; ce++)
    {
        scanf("%d%lld", &n, &m);
        
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", a + i);
            
            g[i] = gcd(a[i], m);
            if (g[i] == 1)
            {
                flag = 1;
            }
        }
        
        printf("Case #%d: ", ce);
        if (flag == 1)
        {
            printf("%lld\n", m * (m - 1) >> 1);
            continue;
        }
        
        sort(g, g + n);
        n = (int)(unique(g, g + n) - g);
        
        int cnt = 0;
        for (ll i = 2; i * i <= m; i++)
        {
            if (i * i == m)
            {
                fac[cnt++] = m / i;
            }
            else if (m % i == 0)
            {
                fac[cnt++] = i;
                fac[cnt++] = m / i;
            }
        }
        sort(fac, fac + cnt);
        
        ll sum = 0;
        for (int i = 0; i < cnt; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (fac[i] % g[j] == 0)
                {
                    sum += Phi(m / fac[i]) * m >> 1;
                    break;
                }
            }
        }
        
        printf("%lld\n", sum);
    }
    
    return 0;
}
