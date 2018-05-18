//
//  main.cpp
//  f-51Nod-1244-莫比乌斯函数之和
//
//  Created by ZYJ on 2017/8/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 5e6 + 10;
const int MOD = 857777;

ll a, b;
int tot;
ll tmp[MOD];
ll val[MOD];
int mu[MAXN];
int prime[MAXN];
int sum[MAXN];
int nxt[MOD];
int had[MOD];
bool vis[MAXN];

void add(int x, ll y, int z)
{
    val[++tot] = y;
    nxt[tot] = had[x];
    had[x] = tot;
    tmp[tot] = z;
}

ll cal(ll x)
{
    int t = x % MOD, ret = 1;
    if (x <= MAXN)
    {
        return sum[x];
    }
    for (int i = had[t]; i; i = nxt[i])
    {
        if (val[i] == x)
        {
            return tmp[i];
        }
    }
    
    ll l = 2, r;
    while (l <= x)
    {
        r = x / (x / l);
        ret -= 1ll * (r - l + 1) * cal(x / l);
        l = r + 1;
    }
    add(t, x, ret);
    return ret;
}

void init()
{
    tot = 0;
    
    //  线性筛法求解部分莫比乌斯函数
    mu[1] = 1;
    for (int i = 2; i <= MAXN; i++)
    {
        if (!vis[i])
        {
            mu[i] = -1;
            prime[++prime[0]] = i;
        }
        for (int j = 1, t; j <= prime[0]; j++)
        {
            t = i * prime[j];
            if (t > MAXN)
            {
                break;
            }
            vis[t] = 1;
            if (!(i % prime[j]))
            {
                break;
            }
            mu[t] = -mu[i];
        }
    }
    
    for (int i = 1; i <= MAXN; i++)
    {
        sum[i] = sum[i - 1] + mu[i];
    }
}

int main()
{
    init();
    
    scanf("%lld%lld", &a, &b);
    printf("%lld", cal(b) - cal(a - 1));
    
    return 0;
}
