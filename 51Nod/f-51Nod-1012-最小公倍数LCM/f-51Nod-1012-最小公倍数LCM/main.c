//
//  main.c
//  f-51Nod-1012-最小公倍数LCM
//
//  Created by ZYJ on 16/4/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>

//long long gcd(long long A, long long B)
//{
//    if (!B)
//    {
//        return A;
//    }
//    else
//    {
//        return gcd(B, A % B);
//    }
//    return 0;
//}
//
//long long lcm(long long A, long long B)
//{
//    return (A * B / gcd(A, B));
//}

long long lcm(long long A, long long B)
{
    long long C, D, E;
    C = A;
    D = B;
    E = C % D;
    while (E)
    {
        C = D;
        D = E;
        E = C % D;
    }
    return (A * B / D);
}

int main(int argc, const char * argv[])
{
    long long A, B;
    scanf("%lld %lld", &A, &B);
    printf("%lld\n", lcm(A, B));
    return 0;
}
