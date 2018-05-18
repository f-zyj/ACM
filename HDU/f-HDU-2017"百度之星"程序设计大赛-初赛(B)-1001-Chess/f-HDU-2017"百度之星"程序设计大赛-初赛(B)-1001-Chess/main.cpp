//
//  main.cpp
//  f-HDU-2017"百度之星"程序设计大赛-初赛(B)-1001-Chess
//
//  Created by ZYJ on 2017/8/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;     //  必须为质数才管用
const ll MAXN = 1e5 + 3;

int N, M;
ll fac[MAXN];       //  阶乘
ll inv[MAXN];       //  阶乘的逆元

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

ll C(ll a, ll b)
{
    if (b > a)
    {
        return 0;
    }
    if (b == 0)
    {
        return 1;
    }
    return fac[a] * inv[b] % MOD * inv[a - b] % MOD;
}

int main(int argc, const char * argv[])
{
    init();
    
    int T;
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        if (N == M)
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << C(max(N, M), max(N, M) - min(N, M)) << '\n';
        }
    }
    
    return 0;
}
