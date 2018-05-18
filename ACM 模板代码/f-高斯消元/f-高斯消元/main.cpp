//
//  main.cpp
//  f-高斯消元
//
//  Created by ZYJ on 16/7/4.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

//  高斯消元

/*
 *  高斯消元（浮点数）
 */
#define eps 1e-9
const int MAXN = 220;

double a[MAXN][MAXN];   //  方程的左边的矩阵
double x[MAXN];         //  等式右边的值，求解后x存的就是结果
int equ, var;           //  方程数和未知数个数

//  返回0无解，返回1有解
int Gauss()
{
    int i, j, k, col, MAX;
    for (k = 0, col = 0; k < equ && col < var; k++, col++)
    {
        MAX = k;
        for (i = k + 1; i < equ; i++)
        {
            if (fabs(a[i][col]) > fabs(a[MAX][col]))
            {
                MAX = i;
            }
        }
        if (fabs(a[MAX][col]) < eps)
        {
            return 0;
        }
        if (k != MAX)
        {
            for (j = col; j < var; j++)
            {
                swap(a[k][j], a[MAX][j]);
            }
            swap(x[k], x[MAX]);
        }
        x[k] /= a[k][col];
        for (j = col + 1; j < var; j++)
        {
            a[k][j] /= a[k][col];
        }
        a[k][col] = 1;
        for (i = 0; i < equ; i++)
        {
            if (i != k)
            {
                x[i] -= x[k] * a[i][k];
                for (j = col + 1; j < var; j++)
                {
                    a[i][j] -= a[k][j] * a[i][col];
                }
                a[i][col] = 0;
            }
        }
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
