//
//  main.cpp
//  f-51Nod-1670-打怪兽
//
//  Created by ZYJ on 2016/10/1.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

int n;
ll dp[MAXN];
int a[MAXN];

void init()
{
    ll res = 1;
    for (int i = 1; i <= n; i++)
    {
        res = (res * i) % MOD;
    }
    dp[0] = res;
}

ll exp_mod(ll a, ll b)
{
    ll res = 1;
    while (b != 0)
    {
        if (b & 1)
        {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void input()
{
    int i, temp;
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        a[temp]++;
    }
}

void solve()
{
    int i;
    ll res = 0;
    for (i = 1; i <= n; i++)
    {
        a[i] = a[i] + a[i - 1];
    }
    for (i = 0; i <= n; i++)
    {
        //  已经击败i个
        ll t = exp_mod(n - i, MOD - 2) % MOD;   //  求逆元
        dp[i + 1] = ((dp[i] * (a[i] - i)) % MOD) * t % MOD;
    }
    for (i = 1; i <= n; i++)
    {
        ll s = (dp[i - 1] - dp[i] + MOD) % MOD; //  在第i轮被击败的情况
        res = (res + s * (i - 1) % MOD) % MOD;
    }
    res = (res + (dp[n] * n) % MOD) % MOD;
    cout << res;
}

int main()
{
    input();
    init();
    
    solve();
    
    return 0;
}
