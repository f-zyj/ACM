//
//  main.cpp
//  f-51Nod-1355-斐波那契的最小公倍数
//
//  Created by ZYJ on 2017/9/7.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

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

inline ll get_inv(ll a)
{
    return QPow(a, MOD - 2);
}

int n;
int vis[MAXN];
ll f[MAXN];
ll g[MAXN];

void init()
{
    f[0] = 0;
    f[1] = 1;
    
    for (int i = 2; i <= n; i++)
    {
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    }
    for (int i = 1; i <= n; i++)
    {
        g[i] = f[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ll inv = get_inv(g[i]);
        for (int j = i + i; j <= n; j += i)
        {
            g[j] *= inv;
            g[j] %= MOD;
        }
    }
}

int main()
{
    scan_d(n);
    int x, mx = 0;
    for (int i = 1; i <= n; i++)
    {
        scan_d(x);
        vis[x] = 1;
        mx = max(mx, x);
    }
    n = mx;
    
    init();
    
    ll ans = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            if (vis[j])
            {
                ans = ans * g[i] % MOD;
                break;
            }
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
