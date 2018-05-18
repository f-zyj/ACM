//
//  main.cpp
//  f-51Nod-1189-阶乘分数
//
//  Created by ZYJ on 2017/3/23.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;

int vis[MAXN];

/*
 *  素数筛选，查找出小于等于MAXN的素数
 *  prime[0]存素数的个数
 */
int prime[MAXN + 1];

void getPrime()
{
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i <= MAXN; i++)
    {
        if (!prime[i])
        {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++)
        {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
}

ll qPow(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1)
        {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        n >>= 1;
    }
    return ans;
}

int main()
{
    getPrime();
    
    int n;
    cin >> n;
    memset(vis, 0, sizeof(vis));
    
    for (int i = 1; i <= n; i++)
    {
        int k = i;
        for (int j = 1; j <= prime[0] && prime[j] * prime[j] <= k; j++)
        {
            if (k % prime[j] == 0)
            {
                while (k % prime[j] == 0)
                {
                    k /= prime[j];
                    vis[prime[j]] += 2;
                }
            }
        }
        if (k != 1)
        {
            vis[k] += 2;
        }
    }
    
    ll ans = 1;
    for (int i = 0; i <= MAXN; i++)
    {
        ans = ans * (vis[i] + 1) % MOD;
    }
    
    cout << (ans + 1) * qPow(2LL, MOD - 2) % MOD << endl;
    
    return 0;
}
