//
//  main.cpp
//  f-HDU-2588-GCD
//
//  Created by ZYJ on 2017/9/25.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int Euler(int n)
{
    if (n == 1)
    {
        return 1;
    }
    
    int x = 2, m = n, tmp = (int)sqrt(n);
    while (x <= tmp)
    {
        if (m % x == 0)
        {
            n -= n / x;
            while (m % x == 0)
            {
                m /= x;
            }
            tmp = (int)sqrt(m);
        }
        x++;
    }
    if (m != 1)
    {
        n -= n / m;
    }
    return n;
}

int solve(int n, int m)
{
    int tmp = sqrt(n), ans = 0;
    for (int i = 1; i <= tmp; i++)
    {
        if (n % i)
        {
            continue;
        }
        
        if (i >= m && i != tmp)
        {
            ans += Euler(n / i);
        }
        if (n / i >= m)
        {
            ans += Euler(i);
        }
    }
    
    return ans;
}

int N, M;

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d%d", &N, &M);
        printf("%d\n", solve(N, M));
    }
    
    return 0;
}
