//
//  main.c
//  f-HDU-5698-瞬间移动
//
//  Created by ZYJ on 16/6/1.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MOD 1000000007
typedef long long LL;

//快速幂
LL quickPower(LL a, LL b)
{
    LL ans = 1;
    a %= MOD;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a %MOD;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return ans;
}

LL c(LL n, LL m)
{
    if (m > n)
    {
        return 0;
    }
    LL ans = 1;
    for (int i = 1; i <= m; i++)
    {
        LL a = (n + i - m) % MOD;
        LL b = i % MOD;
        ans = ans * (a * quickPower(b, MOD - 2) % MOD) % MOD;
    }
    return ans;
}

//卢卡斯定理（应用解决杨辉三角问题）
LL lucas(LL n, LL m)
{
    if (m == 0)
    {
        return 1;
    }
    return c(n % MOD, m % MOD) * lucas(n / MOD, m / MOD) % MOD;
}

int main(int argc, const char * argv[])
{
    LL n, m;
    while (~scanf("%lld %lld", &n, &m))
    {
        LL max, min;
        max = n + m - 3;
        min = m - 1;
        printf("%lld\n", lucas(max - 1, min - 1));
    }
    return 0;
}
