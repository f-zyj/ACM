//
//  main.cpp
//  f-51Nod-1836-战忽局的手段
//
//  Created by ZYJ on 2017/7/9.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>

using namespace std;

__float128 QPow(__float128 x, long long p)
{
    __float128 ret = 1.0;
    while (p)
    {
        if (p & 1)
        {
            ret = ret * x;
        }
        x = x * x;
        p >>= 1;
    }
    
    return ret;
}

int T;
__float128 ans;
long long n, m;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld", &n, &m);
        ans = n - n * QPow((__float128)(n - 1) / n, m);
        printf("%.7f\n", (double)ans);
    }
    
    return 0;
}
