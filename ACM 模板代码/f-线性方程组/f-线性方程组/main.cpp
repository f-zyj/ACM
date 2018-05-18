//
//  main.cpp
//  f-线性方程组
//
//  Created by ZYJ on 16/6/29.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;


//  线性方程组 a[][] * x[] = b[]

#define fabs(x) ((x) > 0 ? (x) : (-x))
#define eps 1e-10

const int MAXN = 100;

/*
 *  列主元gauss消去求解a[][] * x[] = b[]
 *  返回是否有唯一解，若有解在b[]中
 */
int gaussCpivot(int n, double a[][MAXN], double b[])
{
    int i, j, k, row = 0;
    double MAXP, temp;
    for (k = 0; k < n; k++)
    {
        for (MAXP = 0, i = k; i < n; i++)
        {
            if (fabs(a[i][k]) > fabs(MAXP))
            {
                MAXP = a[row = i][k];
            }
        }
        if (fabs(MAXP) < eps)
        {
            return 0;
        }
        if (row != k)
        {
            for (j = k; j < n; j++)
            {
                temp = a[k][j];
                a[k][j] = a[row][j];
                a[row][j] = temp;
                temp = b[k];
                b[k] = b[row];
                b[row] = temp;
            }
        }
        for (j = k + 1; j < n; j++)
        {
            a[k][j] /= MAXP;
            for (i = k + 1; i < n; i++)
            {
                a[i][j] -= a[i][k] * a[k][j];
            }
        }
        b[k] /= MAXP;
        for (i = n - 1; i >= 0; i--)
        {
            for (j = i + 1; j < n; j++)
            {
                b[i] -= a[i][j] * b[j];
            }
        }
    }
    return 1;
}

/*
 *  全主元gauss消去解a[][] * x[] = b[]
 *  返回是否有唯一解，若有解在b[]中
 */
int gaussTpivot(int n, double a[][MAXN], double b[])
{
    int i, j, k, row = 0, col = 0, index[MAXN];
    double MAXP, temp;
    for (i = 0; i < n; i++)
    {
        index[i] = i;
    }
    for (k = 0; k < n; k++)
    {
        for (MAXP = 0, i = k; i < n; i++)
        {
            for (j = k; j < n; j++)
            {
                if (fabs(a[i][j] > fabs(MAXP)))
                {
                    MAXP = a[row = i][col = j];
                }
            }
        }
        if (fabs(MAXP) < eps)
        {
            return 0;
        }
        if (col != k)
        {
            for (i = 0; i < n; i++)
            {
                temp = a[i][col];
                a[i][col] = a[i][k];
                a[i][k] = temp;
            }
            j = index[col];
            index[col] = index[k];
            index[k] = j;
        }
        if (row != k)
        {
            for (j = k; j < n; j++)
            {
                temp = a[k][j];
                a[k][j] = a[row][j];
                a[row][j] = temp;
            }
            temp = b[k];
            b[k] = b[row];
            b[row] = temp;
        }
        for (j = k + 1; j < n; j++)
        {
            a[k][j] /= MAXP;
            for (i = k + 1; i < n; i++)
            {
                a[i][j] -= a[i][k] * a[k][j];
            }
        }
        b[k] /= MAXP;
        for (i = k + 1; i < n; i++)
        {
            b[i] -= b[k] * a[i][k];
        }
    }
    for (i = n - 1; i >= 0; i--)
    {
        for (j = i + 1; j < n; j++)
        {
            b[i] -= a[i][j] * b[j];
        }
    }
    for (k = 0; k < n; k++)
    {
        a[0][index[k]] = b[k];
    }
    for (k = 0; k < n; k++)
    {
        b[k] = a[0][k];
    }
    return 1;
}

int main(int argc, const char * argv[])
{
    
    std::cout << "Hello, World!\n";
    return 0;
}
