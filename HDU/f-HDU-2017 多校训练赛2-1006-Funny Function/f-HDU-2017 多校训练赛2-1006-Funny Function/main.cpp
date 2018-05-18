//
//  main.cpp
//  f-HDU-2017 多校训练赛2-1006-Funny Function
//
//  Created by ZYJ on 2017/7/30.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll QPow(ll x, ll n)
{
    ll ret = 1;
    for (; n; n >>= 1)
    {
        if (n & 1)
        {
            ret = ret * x % MOD;
        }
        x = x * x % MOD;
    }
    
    return ret;
}

ll inv(ll x)
{
    return QPow(x, MOD - 2);
}


ll n,m;
ll ans;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld", &n, &m);
        if (n & 1)
        {
            ans = (QPow(QPow(2, n) - 1, m - 1) * 2 % MOD + 1) * inv(3) % MOD;
        }
        else
        {
            ans = QPow(QPow(2, n) - 1, m - 1) * 2 % MOD * inv(3) % MOD;
        }
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
