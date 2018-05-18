//
//  main.cpp
//  f-周期性方程
//
//  Created by ZYJ on 16/7/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

//  追赶法解周期性方程

/*
 *  周期性方程定义(n = 5)
 *  |a_1 b_1 c_1 d_1 e_1| = x_1  ---  1
 *  |e_2 a_2 b_2 c_2 d_2| = x_2  ---  2
 *  |d_2 e_2 a_2 b_2 c_2| = x_3  ---  3
 *  |c_4 d_2 e_2 a_4 b_4| = x_4  ---  4
 *  |b_5 c_5 d_5 e_5 a_5| = x_5  ---  5
 *  输入： a[], b[], c[], x[]
 *  输出： 求解结果x在x[]中
 */
const int MAXN = 1000;

int a[MAXN];
int b[MAXN];
int c[MAXN];
int x[MAXN];

void run()
{
    c[0] /= b[0];
    a[0] /= b[0];
    x[0] /= b[0];
    
    for (int i = 1; i < MAXN - 1; i ++)
    {
        double temp = b[i] - a[i] * c[i - 1];
        c[i] /= temp;
        x[i] = (x[i] - a[i] * x[i - 1]) / temp;
        a[i] = -a[i] * a[i - 1] / temp;
    }
    
    a[MAXN - 2] = -a[MAXN - 2] - c[MAXN - 2];
    for (int i = MAXN - 3; i >= 0; i--)
    {
        a[i] = -a[i] - c[i] * a[i + 1];
        x[i] -= c[i] * x[i + 1];
    }
    
    x[MAXN - 1] -= (c[MAXN - 1] * x[0] + a[MAXN - 1] * x[MAXN - 2]);
    x[MAXN - 1] /= (c[MAXN - 1] * a[0] + a[MAXN - 1] * a[MAXN - 2] + b[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; i --)
    {
        x[i] += a[i] * x[MAXN - 1];
    }
    return ;
}

int main(int argc, const char * argv[])
{
    return 0;
}
