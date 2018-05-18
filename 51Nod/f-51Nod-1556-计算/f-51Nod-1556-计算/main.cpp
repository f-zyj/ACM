//
//  main.cpp
//  f-51Nod-1556-计算
//
//  Created by ZYJ on 2017/7/5.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;

ll n;
ll f[MAXN];
ll m[MAXN];

ll inv(ll a, ll m)
{
    ll ret = 1;
    for (; m; m >>= 1, a = a * a % MOD)
    {
        if (m & 1)
        {
            ret = ret * a % MOD;
        }
    }
    
    return ret;
}

int main()
{
    scanf("%lld", &n);
    
    m[1] = f[1] = 1;
    m[2] = f[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        m[i] = (m[i - 1] * (2 * i + 1) % MOD + m[i - 2] * 3 * (i - 1) % MOD) % MOD
             * inv(i + 2, MOD - 2) % MOD;
        f[i] = ((f[i - 1] * 3 - m[i - 2]) % MOD + MOD) % MOD;
    }
    
    printf("%lld\n", f[n]);
    
    return 0;
}
