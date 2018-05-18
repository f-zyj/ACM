//
//  main.cpp
//  f-多项式求根（牛顿法）
//
//  Created by ZYJ on 16/7/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

/* 
 *  牛顿法解多项式的根
 *  输入:多项式系数 c[],多项式度数 n,求在[a,b]间的根
 *  输出:根 要求保证[a,b]间有根
 */

double fabs(double x)
{
    return (x < 0) ? -x : x;
}

double f(int m, double c[], double x)
{
    int i;
    double p = c[m];
    for (i = m; i > 0; i--)
    {
        p = p * x + c[i - 1];
    }
    return p;
}

int newton(double x0, double *r, double c[], double cp[], int n, double a, double b, double eps)
{
    int MAX_ITERATION = 1000;
    int i = 1;
    double x1, x2, fp, eps2 = eps / 10.0;
    x1 = x0;
    while (i < MAX_ITERATION)
    {
        x2 = f(n, c, x1);
        fp = f(n - 1, cp, x1);
        if ((fabs(fp) < 0.000000001) && (fabs(x2) > 1.0))
        {
            return 0;
        }
        x2 = x1 - x2 / fp;
        if (fabs(x1 - x2) < eps2)
        {
            if (x2 < a || x2 > b)
            {
                return 0;
            }
            *r = x2;
            return 1;
        }
        x1 = x2;
        i++;
    }
    return 0;
}

double Polynomial_Root(double c[], int n, double a, double b, double eps)
{
    double *cp;
    int i;
    double root;
    cp = (double *)calloc(n, sizeof(double));
    for (i = n - 1; i >= 0; i--)
    {
        cp[i] = (i + 1) * c[i + 1];
    }
    if (a > b)
    {
        root = a;
        a = b;
        b = root;
    }
    if ((!newton(a, &root, c, cp, n, a, b, eps)) && (!newton(b, &root, c, cp, n, a, b, eps)))
    {
        newton((a + b) * 0.5, &root, c, cp, n, a, b, eps);
    }
    free(cp);
    if (fabs(root) < eps)
    {
        return fabs(root);
    }
    else
        return root;
}