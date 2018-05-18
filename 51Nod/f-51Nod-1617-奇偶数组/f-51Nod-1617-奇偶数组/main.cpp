//
//  main.cpp
//  f-51Nod-1617-奇偶数组
//
//  Created by ZYJ on 2017/9/27.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>

using namespace std;

long long n, m, mod;
long long l, r, u, v;

long long cal(long long a, long long b, long long c)
{
    a -= b;
    if (a < 0)
    {
        a = -1;
    }
    else
    {
        a = a >> c;
    }
    
    long long B = b + a * (1ll << c);
    long long s;
    if ((++a) & 1)
    {
        s = (((B + b) >> 1) % mod) * (a % mod);
    }
    else
    {
        s = ((B + b) % mod) * ((a >> 1) % mod);
    }
    
    return s % mod;
}

long long _cal(long long ll, long long rr, long long c, int d)
{
    if (u > n)
    {
        return 0;
    }
    
    long long ans = 0;
    if (l > ll || r < rr)
    {
        long long m = (ll + rr) >> 1;
        if (l <= m)
        {
            ans += _cal(ll, m, c, d + 1);
        }
        if (r > m)
        {
            ans += _cal(m + 1, rr, c + (1ll << d), d + 1);
        }
        if (ans >= mod)
        {
            ans -= mod;
        }
    }
    else
    {
        ans = cal(v, c, d) - cal(u - 1, c, d);
        if (ans < 0)
        {
            ans += mod;
        }
    }
    
    return ans;
}

int main()
{
    scanf("%lld%lld%lld", &n, &m, &mod);
    
    while (m--)
    {
        scanf("%lld%lld%lld%lld", &l, &r, &u, &v);
        
        v = min(v, n);
        long long ans = _cal(1, n, 1, 0);
        
        printf("%lld\n", ans % mod);
    }
    
    return 0;
}
