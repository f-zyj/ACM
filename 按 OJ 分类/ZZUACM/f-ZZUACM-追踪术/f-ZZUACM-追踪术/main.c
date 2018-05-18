//
//  main.c
//  f-ZZUACM-追踪术
//
//  Created by ZYJ on 16/4/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define _MAX 65535

int main(int argc, const char * argv[])
{
    int s, a, b, c, t;
    double timeOne, timeTwo, time;
    while (scanf("%d %d %d %d %d", &s, &a, &b, &c, &t) != EOF)
    {
        timeOne = _MAX;
        timeTwo = _MAX;
        if (a > c)
        {
            timeOne = s * 1.0 / (a - c);
        }
        if (b > c)
        {
            timeTwo = (s + c * t) * 1.0 / (b - c) + t;
        }
        time = timeOne > timeTwo ? timeTwo : timeOne;
        if (time == _MAX)
        {
            printf("-1\n");
        }
        else
        {
            printf("%.6f\n", time);
        }
    }
    return 0;
}
