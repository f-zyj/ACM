//
//  main.cpp
//  f-51Nod-1239-欧拉函数之和
//
//  Created by ZYJ on 2017/8/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD1 = 1e9 + 7;
const int MOD2 = 2333333;
const int INV_2 = 5e8 + 4;
const int MAXN = 5e6 + 10;

ll n;
int tot;
ll tep[MOD2];
ll val[MOD2];
int phi[MAXN + 5];
int prime[MAXN + 5];
int hed[MOD2];
int net[MOD2];
bool vis[MAXN + 5];

void add(int x, ll y, ll z)
{
    tep[++tot] = y;
    val[tot] = z;
    net[tot] = hed[x];
    hed[x] = tot;
}

ll cal(ll x)
{
    if (x <= MAXN)
    {
        return phi[x];
    }
    
    int k = x % MOD2;
    ll ret = 0, z = x % MOD1;
    for (int i = hed[k]; i; i = net[i])
    {
        if (tep[i] == x)
        {
            return val[i];
        }
    }
    for (ll l = 2, r; l <= x; l = r + 1)
    {
        r = x / (x / l);
        ret += (r - l + 1) % MOD1 * cal(x / l) % MOD1;
        ret %= MOD1;
    }
    ret = (z * (z + 1) % MOD1 * INV_2 % MOD1 - ret + MOD1) % MOD1;
    add(k, x, ret);
    return ret;
}

void init()
{
    for (int i = 2; i <= MAXN; i++)
    {
        if (!vis[i])
        {
            prime[++prime[0]] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= prime[0]; j++)
        {
            int k = i * prime[j];
            if (k > MAXN)
            {
                break;
            }
            vis[k] = 1;
            if (!(i % prime[j]))
            {
                phi[k] = phi[i] * prime[j];
                break;
            }
            phi[k] = phi[i] * (prime[j] - 1);
        }
    }
    
    phi[1] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        phi[i] += phi[i - 1];
        phi[i] %= MOD1;
    }
}

int main()
{
    init();
    
    scanf("%lld", &n);
    printf("%lld", cal(n));
    
    return 0;
}
