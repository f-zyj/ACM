//
//  main.c
//  f-2016"百度之星"-资格赛-1001-A
//
//  Created by ZYJ on 16/5/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//逆元  ax ≡ 1(mod m)  此同余方程中x的最小正整数解叫做a mod m的逆元
//a与m互素的情况下，通常通过扩展欧几里得求逆元，但是这里的m：9973为素数，也可以使用费马小定理
//求得逆元为a^(m - 2)mod m
//a与m不互素时，转换一下公式求逆元：ans = a / b mod m = a mod (mb) / b

#include <stdio.h>
#include <string.h>
#define MOD 9973

char s[100010];
int num[100010];
int p[100010];
int res[10000];

//快速幂
int inv(int a, int b)   //b = MOD - 2
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % MOD;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return ans;
}

int main()
{
    int T;
    for (int i = 1; i < MOD; i++)
    {
        res[i] = inv(i, MOD - 2);
    }
    
    while (~scanf("%d", &T))
    {
        scanf("%s", s + 1);
        int len = (int)strlen(s + 1);
        num[0] = p[0] = 1;
        for (int i = 1; i <= len; i++)
        {
            num[i] = num[i - 1] * (s[i] - 28) % MOD;
            p[i] = res[num[i]];
        }
        while (T--)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", num[y] * p[x - 1] % MOD);
        }
    }
    
    return 0;
}