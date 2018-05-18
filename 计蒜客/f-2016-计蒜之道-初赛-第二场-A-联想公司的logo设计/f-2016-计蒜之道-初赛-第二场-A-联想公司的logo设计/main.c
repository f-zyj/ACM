//
//  main.c
//  f-2016-计蒜之道-初赛-第二场-A-联想公司的logo设计
//
//  Created by ZYJ on 16/6/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define PI 3.1415926535898

int main(int argc, const char * argv[])
{
    double lOne, lTwo, angle;
    
    while (~scanf("%lf %lf %lf", &lOne, &lTwo, &angle))
    {
        double lThree = sqrt(lOne * lOne + lTwo * lTwo - 2 * lOne * lTwo * cos(angle / 180 * PI));
        double D = lThree / 2 + lOne / 2 + lTwo / 2;
        double area = PI * D / 2 * D / 2;
        printf("%.10lf\n", area);
    }

    return 0;
}
