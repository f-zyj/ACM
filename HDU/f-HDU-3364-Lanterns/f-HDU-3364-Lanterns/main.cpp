//
//  main.cpp
//  f-HDU-3364-Lanterns
//
//  Created by ZYJ on 2017/9/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

//  高斯消元法求方程组的解

const int MAXN = 300;
//  有equ个方程，var个变元。增广矩阵行数为equ，列数为var＋1，分别为0到var
int equ, var;
int a[MAXN][MAXN];  //  增广矩阵
int x[MAXN];        //  解集
int free_x[MAXN];   //  用来存储自由变元（多解枚举自由变元可以使用）
int free_num;       //  自由变元的个数

//  返回值为－1表示无解，为0是唯一解，否则返回自由变元个数
int Gauss()
{
    int max_r, col, k;
    free_num = 0;
    for (k = 0, col = 0; k < equ && col < var; k++, col++)
    {
        max_r = k;
        for (int i = k + 1; i < equ; i++)
        {
            if (abs(a[i][col]) > abs(a[max_r][col]))
            {
                max_r = i;
            }
        }
        if (a[max_r][col] == 0)
        {
            k--;
            free_x[free_num++] = col;   //  这是自由变元
            continue;
        }
        
        if (max_r != k)
        {
            for (int j = col; j < var + 1; j++)
            {
                swap(a[k][j], a[max_r][j]);
            }
        }
        for (int i = k + 1; i < equ; i++)
        {
            if (a[i][col] != 0)
            {
                for (int j = col; j < var + 1; j++)
                {
                    a[i][j] ^= a[k][j];
                }
            }
        }
    }
    for (int i = k; i < equ; i++)
    {
        if (a[i][col] != 0)
        {
            return -1;  //  无解
        }
    }
    
    if (k < var)
    {
        return var - k; //  自由变元个数
    }
    
    //  唯一解，回代
    for (int i = var - 1; i >= 0; i--)
    {
        x[i] = a[i][var];
        for (int j = i + 1; j < var; j++)
        {
            x[i] ^= (a[i][j] && x[j]);
        }
    }
    
    return 0;
}

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

int n, m, q;
int b[MAXN];
int t[MAXN][MAXN];

int main()
{
    int T;
    scan_d(T);
    
    for (int cs = 1; cs <= T; cs++)
    {
        printf("Case %d:\n", cs);
        
        memset(a, 0, sizeof(a));
        
        scan_d(n), scan_d(m);
        equ = n, var = m;
        
        int k, x;
        for (int i = 0; i < m; i++)
        {
            scan_d(k);
            while (k--)
            {
                scan_d(x);
                a[x - 1][i] = 1;
            }
        }
        memcpy(t, a, sizeof(a));
        
        scan_d(q);
        while (q--)
        {
            memcpy(a, t, sizeof(a));
            
            for (int i = 0; i < n; i++)
            {
                scan_d(a[i][var]);
            }
            
            int res = Gauss();
            
            if (res == -1)
            {
                puts("0");
            }
            else
            {
                printf("%lld\n", 1ll << res);
            }
        }
    }
    
    return 0;
}
