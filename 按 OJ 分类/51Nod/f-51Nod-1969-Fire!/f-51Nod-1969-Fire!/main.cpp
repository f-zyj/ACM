//
//  main.cpp
//  f-51Nod-1969-Fire!
//
//  Created by ZYJ on 2017/8/1.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;
const int MAGIC = 998244352;
const int MAXN = 1e5 + 10;

int T, base;
long long pow_base[MAXN];

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

void init()
{
    pow_base[0] = 1;
    pow_base[1] = base;
    for (int i = 2; i < T; i++)
    {
        pow_base[i] = base * pow_base[i - 1];
        pow_base[i] %= MOD;
    }
}

int main(int argc, const char * argv[])
{
    cin >> T >> base;
    
    init();
    
    long long N, ans = 0;
    while (T--)
    {
        scan_d(N);
        double tmp = sqrt(1 + 24 * N);
        int k1 = (tmp + 1) / 6;
        int k2 = (tmp - 1) / 6;
        if (k1 * (3 * k1 - 1) == 2 * N)
        {
            if (k1 & 1)
            {
                ans += (MAGIC * pow_base[T]) % MOD;
            }
            else
            {
                ans += pow_base[T];
            }
            ans %= MOD;
        }
        else if (k2 * (3 * k2 + 1) == 2 * N)
        {
            if (k2 & 1)
            {
                ans += (MAGIC * pow_base[T]) % MOD;
            }
            else
            {
                ans += pow_base[T];
            }
            ans %= MOD;
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
