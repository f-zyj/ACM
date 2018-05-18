//
//  main.cpp
//  f-51Nod-1238-最小公倍数之和 V3
//
//  Created by ZYJ on 2017/8/14.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 2e7;
const int MOD = 1e9 + 7;
const int MAXM = 224737;
const int INV_2 = 5e8 + 4;
const int INV_6 = 166666668;

ll n, ans;
bool prz[MAXN + 10];
int pri[MAXN >> 1];
int phi[MAXN + 10];
int Hx[MAXM + 10][2];

int HX(ll q)
{
    int i = q % MAXM;
    while (Hx[i][0] && Hx[i][0] != q)
    {
        i = (i + 1) % MAXM;
    }
    return i;
}

ll SM(ll s, ll t)
{
    if ((s + t) & 1)
    {
        return (s + t) % MOD * (((t-  s + 1) >> 1) % MOD) % MOD;
    }
    
    return ((s + t) >> 1) % MOD * ((t - s + 1) % MOD) % MOD;
}

ll PF(ll q)
{
    q %= MOD;
    return q * (q + 1) % MOD * (2 * q + 1) % MOD * INV_6 % MOD;
}

ll Gphi(ll q)
{
    if (q <= MAXN)
    {
        return phi[q];
    }
    
    int t = HX(q);
    if (Hx[t][0])
    {
        return Hx[t][1];
    }
    
    Hx[t][0] = (int)q;
    ll ans = 0;
    for (ll i = 2, nx; i <= q; i = nx + 1)
    {
        nx = q / (q / i);
        ans = (ans + (PF(nx) - PF(i - 1)) * Gphi(q / i)) % MOD;
    }
    q %= MOD;
    ll x = SM(1, q);
    return Hx[t][1] = (x * x - ans) % MOD;
}

void init()
{
    phi[1] = 1;
    for (int i = 2; i <= MAXN; i++)
    {
        if (!prz[i])
        {
            pri[++pri[0]] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= pri[0]; j++)
        {
            int t = pri[j] * i;
            if (t > MAXN)
            {
                break;
            }
            
            prz[t] = 1;
            phi[t] = phi[i] * pri[j];
            if (i % pri[j] == 0)
            {
                break;
            }
            phi[t] = phi[i] * (pri[j] - 1);
        }
    }
    
    for (int i = 2; i <= MAXN; i++)
    {
        phi[i] = ((ll)phi[i] * (1ll * i * i % MOD) % MOD + phi[i - 1]) % MOD;
    }
}

int main()
{
    init();
    
    scanf("%lld", &n);
    
    for (ll i = 2, nx; i <= n; i = nx + 1)
    {
        nx = n / (n / i);
        ans = (ans + SM(1, n / i) * (Gphi(nx) - Gphi(i - 1)) % MOD * INV_2 % MOD) % MOD;
    }
    
    printf("%lld\n", ((ans * 2 + SM(1, n)) % MOD + MOD) % MOD);
    
    return 0;
}
