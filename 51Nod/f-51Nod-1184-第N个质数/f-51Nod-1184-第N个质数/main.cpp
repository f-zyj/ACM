//
//  main.cpp
//  f-51Nod-1184-第N个质数
//
//  Created by ZYJ on 2017/9/14.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <math.h>

typedef long long ll;

const int MAXN = 7500000 + 7;
const ll MAGIC = 22801763489;

ll n;
int f[MAXN];
int p[MAXN];
bool bz[MAXN];

ll g(ll n, int m)
{
    if (!m)
    {
        return n;
    }
    
    if (m == 1)
    {
        return n - n / 2;
    }
    
    if (n < MAXN)
    {
        if (f[n] <= m)
        {
            return 1;
        }
        
        if (f[(int)sqrt(n)] <= m)
        {
            return f[n] - m + 1;
        }
    }
    
    return g(n, m - 1) - g(n / p[m], m - 1);
}

bool check(ll x)
{
    ll y = sqrt(x);
    return f[y] + g(x, f[y]) - 1 >= n;
}

void init()
{
    ll t;
    for (int i = 2; i < MAXN; i++)
    {
        if (!bz[i])
        {
            p[++p[0]] = i;
        }
        for (int j = 1; j <= p[0]; j++)
        {
            t = p[j] * i;
            if (t > MAXN)
            {
                break;
            }
            
            bz[t] = 1;
            if (i % p[j] == 0)
            {
                break;
            }
        }
    }
    
    for (int i = 2; i < MAXN; i++)
    {
        f[i] = f[i - 1] + (bz[i] == 0);
    }
}

int main()
{
    init();
    
    scanf("%lld", &n);
    
    ll l = 1, r = MAGIC, m;
    
    if (n >= 900000000) l = 20422213579;
    if (n >= 950000000) l = 21610588367; else r = 21610588367;
    if (n >= 970000000) l = 22086742277; else r = 22086742277;
    if (n >= 985000000) l = 22444149523; else r = 22444149523;
    
    while (l < r)
    {
        m = (l + r) >> 1;
        if (check(m))
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    
    printf("%lld\n", l);
}
