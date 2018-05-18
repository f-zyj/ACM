//
//  main.cpp
//  f-51Nod-1806-wangyurzee的树
//
//  Created by ZYJ on 2017/7/9.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;
const int MAXM = 20;

int n, m;
ll fac[MAXN];       //  阶乘
ll inv[MAXN];       //  阶乘的逆元
int u[MAXM];
int d[MAXM];
int vis[MAXM];

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

int main()
{
    init();
    
    scanf("%d%d", &n, &m);
    if (n == 1)
    {
        if (m == 1)
        {
            puts("0");
        }
        else
        {
            puts("1");
        }
        return 0;
    }
    
    for (int i = 0; i < m; i++)
    {
        scan_d(u[i]), scan_d(d[i]);
    }
    
    ll ans = QPow(n, n - 2);
    
    int state = (1 << m);
    for (int i = 1; i < state; i++)
    {
        int cnt = 0, sum = 0;
        memset(vis, 0, sizeof(vis));
        
        ll t = 1;
        for (int j = 0; j < m; j++)
        {
            if (i & (1 << j))
            {
                if (vis[u[j]])
                {
                    goto A;
                }
                cnt++;
                sum += (d[j] - 1);
                vis[u[j]] = 1;
                t = t * inv[d[j] - 1] % MOD;
            }
        }
        if (sum > n - 2)
        {
        A:
            continue;
        }
        ll tmp = fac[n - 2] * inv[n - 2 - sum] % MOD;
        tmp = tmp * QPow(n - cnt, n - 2 - sum) % MOD;
        tmp = tmp * t % MOD;
        if (cnt & 1)
        {
            ans = (ans - tmp) % MOD;
        }
        else
        {
            ans = (ans + tmp) % MOD;
        }
    }
    ans = (ans + MOD) % MOD;
    
    printf("%lld\n", ans);
    
    return 0;
}
