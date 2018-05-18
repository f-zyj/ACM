//
//  main.c
//  f-51Nod-1130-N的阶乘的长度 V2（斯特林近似）
//
//  Created by ZYJ on 16/4/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <math.h>
//斯特林公式n!=sqrt(2*PI*n)*(n/e)^n
#define PI 3.1415926

int main()
{
    int T, n;
    long long a;
    scanf("%d",  &T);
    while(T--)
    {
        scanf("%d",&n);
        a = (long long)((0.5 * log(2 * PI * n) + n * log(n) - n) / log(10));
        printf("%lld\n", a + 1);
    }
    return 0;
}