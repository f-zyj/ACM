//
//  main.cpp
//  f-51Nod-1120-机器人走方格 V3
//
//  Created by ZYJ on 2017/3/14.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MOD = 10007;

int fac[MOD + 5];
int inv[MOD + 5];

int QPow(int x, int n)
{
    int ret = 1;
    int tmp = x % MOD;
    
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
    for (int i = 1; i < MOD; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv[MOD - 1] = QPow(fac[MOD - 1], MOD - 2);
    for (int i = MOD - 2; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

inline int C(int n, int m)
{
    if (n < m)
    {
        return 0;
    }
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

inline int lucas(int n, int m)
{
    return m == 0 ? 1 : C(n % MOD, m % MOD) * lucas(n / MOD, m / MOD) % MOD;
}

int main()
{
    init();
    
    int n;
    scanf("%d", &n);
    n--;
    printf("%d\n", (lucas(n << 1, n) + MOD - lucas(n << 1, n - 1)) % MOD * 2 % MOD);
    
    return 0;  
}
