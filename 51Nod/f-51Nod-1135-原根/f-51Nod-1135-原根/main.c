//
//  main.c
//  f-51Nod-1135-原根
//
//  Created by ZYJ on 16/4/29.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define _MAX 10000005

int P, tot;
int A[_MAX];

//已知质数P，无论g为何值，在指数为P－1时结果均为成立，
//如果指数不为P－1时也想满足g^i = 1(mod P)，则该指数一定是P－1的因子
//并且指数要小于sqrt(P－1)
void store()
{
    int tmp, now;
    tmp = (int)((double)sqrt(P - 1) + 1);
    tot = 0;
    now = P - 1;
    for (int i = 2; i <= tmp; i++)
    {
        if (now % i == 0)
        {
            A[tot++] = i;
        }
        while (now % i == 0)
        {
            now /= i;
        }
    }
    if (now != 1)
    {
        A[tot++] = now;
    }
    return ;
}

//快速幂取模P
long long QPow(long long x, long long n)
{
    long long ret = 1;
    while (n)
    {
        if (n & 1)
        {
            ret = ret * x % P;
        }
        n >>= 1;
        x = x * x % P;
    }
    
    return ret;
}

//检测是否满足g^i = 1(mod P)当且仅当指数为P－1时成立,0<i<P，1<g<P
//因为P为质数，所以可以肯定，无论g为什么，当指数为P－1时一定成立，省去判断
//只需要判断其他情况不等于1
int check(int g)
{
    for (int i = 0; i < tot; i++)
    {
        if (QPow((long long)g, (long long)(P - 1) / A[i]) == 1)
        {
            return 0;
        }
    }
    return 1;
}

//封装函数，1<g<P
int solve()
{
    for (int g = 2; g < P; g++)
    {
        if (check(g))
        {
            return g;
        }
    }
    return 0;
}

int main(int argc, const char * argv[])
{
    while (~scanf("%d", &P))
    {
        store();
        printf("%d\n", solve());
    }
    
    return 0;
}


