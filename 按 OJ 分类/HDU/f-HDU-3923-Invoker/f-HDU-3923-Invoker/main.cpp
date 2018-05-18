//
//  main.cpp
//  f-HDU-3923-Invoker
//
//  Created by ZYJ on 2017/9/5.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 1e4 + 10;
const int MOD = 1e9 + 7;

int m, n;
long long p[MAXN];

/*
 *  c种颜色的珠子，组成长为s的项链，项链没有方向和起始位置
 */
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

long long qpow(long long a, long long n)
{
    long long ans = 1;
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

int main(int argc, const char * argv[])
{
    int T, cs = 1;
    cin >> T;
    
    while (T--)
    {
        cin >> m >> n;
        
        p[0] = 1;                   // power of c
        for (int i = 0; i < n; i++)
        {
            p[i + 1] = p[i] * m % MOD;
        }
        
        long long cnt_1 = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            cnt_1 += p[gcd(i, n)];
            if (cnt_1 >= MOD)
            {
                cnt_1 -= MOD;
            }
        }
        
        long long cnt_2 = 0;
        if (n & 1)
        {
            cnt_2 = n * p[(n + 1) >> 1] % MOD;
        }
        else
        {
            cnt_2 = (n >> 1) * (p[n >> 1] + p[(n >> 1) + 1]) % MOD;
        }
        
        printf("Case #%d: %lld\n", cs++, (cnt_1 + cnt_2) * qpow(2 * n, MOD - 2) % MOD);
    }
    
    return 0;
}
