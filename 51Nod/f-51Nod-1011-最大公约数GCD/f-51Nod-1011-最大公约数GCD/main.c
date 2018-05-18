//
//  main.c
//  f-51Nod-1011-最大公约数GCD
//
//  Created by ZYJ on 16/4/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>

long gcd(long a, long b)
{
    if (!b)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
    return 0;
}

int main(int argc, const char * argv[])
{
    long A, B;
    scanf("%ld %ld", &A, &B);
    printf("%ld\n", gcd(A, B));
    return 0;
}
