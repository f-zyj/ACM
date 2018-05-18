//
//  main.c
//  f-51Nod-1008-N的阶乘 mod P
//
//  Created by ZYJ on 16/4/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int N, P, i = 1;
    long long ans = 1;
    scanf("%d %d", &N, &P);
    
    for (; i <= N; i++)
    {
        ans *= i;
        ans %= P;
    }
    
    printf("%lld\n", ans);
    return 0;
}
