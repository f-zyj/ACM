//
//  main.cpp
//  f-HDU-2017 多校训练赛3-1008-RXD and math
//
//  Created by ZYJ on 2017/8/1.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

ll n, k;

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

int main(int argc, const char * argv[])
{
    int ce = 1;
    while (~scanf("%lld%lld", &n, &k))
    {
        printf("Case #%d: %lld\n", ce++, QPow(n, k));
    }
    
    return 0;
}
