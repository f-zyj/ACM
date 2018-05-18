//
//  main.cpp
//  f-HDU-2017"百度之星"程序设计大赛-复赛-1003-Pokémon GO
//
//  Created by ZYJ on 2017/8/18.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <stdio.h>

const int MAXN = 1e4 + 10;
const int MOD = 1e9 + 7;

int n;
long long a[MAXN];
long long b[MAXN];

void init()
{
    b[1] = 1;
    for (int i = 2; i <= MAXN; i++)
    {
        b[i] = (b[i - 1] * 2 % MOD);
    }
    a[1] = 1;
    a[2] = 6;
    for (int i = 3; i <= MAXN; i++)
    {
        a[i] = (2 * a[i - 1] + b[i] + 4 * a[i - 2]) % MOD;
    }
}

int main()
{
    init();
    
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d", &n);
        
        long long ans = 4 * a[n];
        for (int i = 2; i < n; i++)
        {
            ans += ((8 * b[n - i] * a[i - 1]) % MOD + (8 * a[n - i] * b[i - 1]) % MOD) % MOD;
            ans %= MOD;
        }
        if (n == 1)
        {
            ans = 2;
        }
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
