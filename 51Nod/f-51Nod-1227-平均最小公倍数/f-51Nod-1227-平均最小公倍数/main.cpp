//
//  main.cpp
//  f-51Nod-1227-平均最小公倍数
//
//  Created by ZYJ on 2017/8/31.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long ll;

const int MAXN = 4e6;
const int MOD = 1e9 + 7;
const int MAXM = 3e5;
const int INV_2 = 5e8 + 4;
const int INV_6 = 166666668;

int n, m;
bool prz[MAXN + 10];
int pri[MAXN >> 1];
int phi[MAXN + 10];
int hx[MAXM][2];

int HX(int q)
{
    int tmp = q % MAXM;
    while (hx[tmp][0] && hx[tmp][0] != q)
    {
        tmp = (tmp + 1) % MAXM;
    }
    
    return tmp;
}

ll SM(ll s, ll t)
{
    return (s + t) * (t - s + 1) % MOD * INV_2 % MOD;
}

ll Gphi(int q)
{
    if (q <= MAXN)
    {
        return phi[q];
    }
    
    int t = HX(q);
    if (hx[t][0])
    {
        return hx[t][1];
    }
    
    hx[t][0] = q;
    ll ans = 0;
    for (int i = 2, nx; i <= q; i = nx + 1)
    {
        nx = q / (q / i);
        ans = (ans + SM(i, nx) * Gphi(q / i) % MOD) % MOD;
    }
    q %= MOD;
    
    return hx[t][1] = (int)((ll)q * (q + 1) % MOD * (2 * q + 1) % MOD * INV_6 % MOD - ans);
}

ll Gans(int n)
{
    int ans = n % MOD;
    for (int i = 2, nx; i <= n; i = nx + 1)
    {
        nx = n / (n / i);
        ans = (ans + (ll)(n / i) * (Gphi(nx) - Gphi(i - 1)) % MOD * INV_2 % MOD) % MOD;
    }
    
    return ans;
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
        phi[i] = ((ll)phi[i] * ((ll)i) % MOD + phi[i - 1]) % MOD;
    }
}

int main()
{
    init();
    
    scanf("%d%d", &m, &n);
    printf("%lld\n", (Gans(n) - Gans(m - 1) + MOD) % MOD);
    
    return 0;
}
