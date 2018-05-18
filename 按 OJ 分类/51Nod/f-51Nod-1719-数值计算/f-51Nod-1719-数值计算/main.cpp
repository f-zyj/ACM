//
//  main.cpp
//  f-51Nod-1719-数值计算
//
//  Created by ZYJ on 2017/7/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.1415926;
const double EPS = 1e-8;
const int MAXW = 1e4;

double A, B, n;

int main()
{
    scanf("%lf%lf%lf", &A, &B, &n);
    
    double tmp = 0;
    for (int i = 1; i <= MAXW; i++)
    {
        tmp += A / (i + sin(i)) * sin(i) + B / (i + cos(i)) * cos(i);
    }
    
    double l = 0, r = PI, m, temp;
    if (abs(tmp) < EPS)
    {
        l = PI;
    }
    else
    {
        while (r - l > EPS)
        {
            m = (l + r) / 2;
            temp = 0;
            for (int i = 1; i <= MAXW; i++)
            {
                temp += A / (i + sin(i)) * sin(m + i) + B / (i + cos(i)) * cos(m + i);
            }
            
            if (tmp < 0)
            {
                if (temp < 0)
                {
                    l = m;
                }
                else
                {
                    r = m;
                }
            }
            else
            {
                if (temp < 0)
                {
                    r = m;
                }
                else
                {
                    l = m;
                }
            }
        }
    }
    
    printf("%.3f\n", n * l + n * (n - 1) * PI / 2);
    
    return 0;
}
