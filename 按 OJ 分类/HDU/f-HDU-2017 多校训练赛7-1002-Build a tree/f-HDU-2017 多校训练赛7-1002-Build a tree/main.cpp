//
//  main.cpp
//  f-HDU-2017 多校训练赛7-1002-Build a tree
//
//  Created by ZYJ on 2017/8/21.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 111;
const int MAGIC = 62;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll n, k, X;
ll F[MAXN];
ll C[MAXN];

ll HR(ll a, ll n, ll k)
{
    if (a + 1 <= n / k && (a + 1) * k < n)
    {
        return HR((a + 1) * k, n, k) + 1;
    }
    
    return 0;
}

ll HL(ll a, ll n, ll k)
{
    if (a <= (n - 1) / k && a * k + 1 < n)
    {
        return HL(a * k + 1, n, k) + 1;
    }
    
    X = a;
    return 0;
}

ll slove(ll L, ll R, ll n, ll k)
{
    ll hr = HR(R, n, k);
    ll hl = HL(L, n, k);
    
    if (L == R)
    {
        if (hr == hl)
        {
            return F[hr];
        }
        
        if (L + 1 <= n / k && (L + 1) * k < n)
        {
            return (C[hr] + n - X) ^ slove(L * k + 1, (L + 1) * k, n, k);
        }
        
        return (C[hr] + n - X) ^ slove(L * k + 1, n - 1, n, k);
    }
    
    if (hr == hl)
    {
        if ((R - L + 1) & 1)
        {
            return F[hr];
        }
        
        return 0;
    }
    
    ll mid = (L + R) >> 1;
    return slove(L, mid, n, k) ^ slove(mid + 1, R, n, k);
}

ll cal(ll n, ll m)
{
    if (m == 1)
    {
        return 0;
    }
    
    if (n >= m)
    {
        if ((n - m + 1) & 1)
        {
            return m + cal(n - m, m >> 1);
        }
        
        return cal(n - m, m >> 1);
    }
    
    return cal(n, m >> 1);
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%lld%lld", &n, &k);
        if (k == 1)
        {
            printf("%lld\n", cal(n, 1ll << MAGIC) + (((n + 1) / 2) & 1));
            continue;
        }
        
        F[0] = 1;
        C[0] = 1;
        for (ll i = 1, s = INF - 1, j = 1; ; j++)
        {
            if (s / k < i)
            {
                break;
            }
        
            i *= k;
            s -= i;
            if (k & 1)
            {
                F[j] = F[j - 1];
            }
            F[j] ^= INF - s;
            C[j] = C[j - 1] + i;
        }
    
        printf("%lld\n", slove(0, 0, n, k));
    }
    
    return 0;
}
