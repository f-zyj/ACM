//
//  main.cpp
//  f-HDU-2017 多校训练赛1-1011-KazaQ's Socks
//
//  Created by ZYJ on 2017/7/25.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int n;
long long k;

int main()
{
    int ce = 0;
    
    while (~scanf("%d%lld", &n, &k))
    {
        printf("Case #%d: ", ++ce);
        if (k <= n)
        {
            printf("%lld\n", k);
        }
        else
        {
            k -= n;
            long long tol = k / (n - 1);
            long long m = k % (n - 1);
            if (m == 0)
            {
                if (tol & 1)
                {
                    printf("%d\n", n - 1);
                }
                else
                {
                    printf("%d\n", n);
                }
            }
            else
            {
                printf("%lld\n", m);
            }
        }
    }
    
    return 0;
}
