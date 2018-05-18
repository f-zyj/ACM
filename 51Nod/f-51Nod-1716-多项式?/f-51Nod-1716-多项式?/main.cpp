//
//  main.cpp
//  f-51Nod-1716-多项式?
//
//  Created by ZYJ on 2017/7/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>

const int MOD = 1e9 + 7;

long long n;

int main()
{
    scanf("%lld", &n);
    
    if (n & 1)
    {
        puts("1");
    }
    else
    {
        printf("%lld\n", n / 2 % MOD * ((n / 2 + 1) % MOD) % MOD);
    }
    
    return 0;
}
