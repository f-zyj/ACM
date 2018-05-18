//
//  main.c
//  f-蓝桥杯省A-四平方和
//
//  Created by ZYJ on 16/4/6.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define _MAX 5000005
short power[_MAX] = {0};

void solve(int n)
{
    int i, j, k, temp;
    double x;
    for (i = 0; i * i <= n; i++)
    {
        for (j = 0; j * j <= n; j++)
        {
            if (power[n - i * i - j * j] == 0)
            {
                continue;
            }
            for (k = 0; k * k <= n; k++)
            {
                temp = n - i * i - j * j - k * k;
                x = sqrt((double)temp);
                if (x == (int)x)
                {
                    printf("%d %d %d %g\n", i, j, k, x);
                    return ;
                }
            }
        }
    }
    return ;
}

int main(int argc, const char * argv[])
{
    int n, i, j;
    //预处理power
    for (i = 0; i * i <= _MAX; i++)
    {
        for (j = 0; j * j <= _MAX; j++)
        {
            if (i * i + j * j <= _MAX)
            {
                power[i * i + j * j] = 1;
            }
        }
    }
    scanf("%d", &n);
    solve(n);
    return 0;
}
