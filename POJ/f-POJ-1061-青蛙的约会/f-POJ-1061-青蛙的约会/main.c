//
//  main.c
//  f-POJ-1061-青蛙的约会
//
//  Created by ZYJ on 16/4/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
typedef long long LL;
LL x, y;
LL e_gcd(LL a, LL b)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL ans = e_gcd(b, a % b);
    LL temp = x;
    x = y;
    y = temp - a / b * y;
    return ans;
}

LL cal(LL a, LL b, LL c)
{
    LL gcd = e_gcd(a, b);
    if (c % gcd != 0)
    {
        return -1;
    }
    x *= c / gcd;
    b /= gcd;
    if (b < 0)
    {
        b = -b;
    }
    LL ans = x % b;
    if (ans <= 0)
    {
        ans += b;
    }
    return ans;
}

int main(int argc, const char * argv[])
{
    LL x, y, m, n, L;
    while (~scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L))
    {
        
        LL ans = cal(m - n, L, y - x);
        if (ans == -1)
        {
            printf("Impossible\n");
        }
        else
        {
            printf("%lld\n", ans);
        }
    }
    return 0;
}
