//
//  main.cpp
//  f-POJ-1681-Painter's Problem
//
//  Created by ZYJ on 16/7/6.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

//  高斯消元法求方程组的解

/*
 *  一类开关问题，对2取模的01方程组
 *  需要枚举自动变元，找解中1个数最少的
 */

//  对2取模的01方程组
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

int n;

void init()
{
    memset(a, 0, sizeof(a));
    memset(x, 0, sizeof(x));
    equ = n * n;
    var = n * n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int t = i * n + j;
            a[t][t] = 1;
            if (i > 0)
            {
                a[(i - 1) * n + j][t] = 1;
            }
            if (i < n - 1)
            {
                a[(i + 1) *  n + j][t] = 1;
            }
            if (j > 0)
            {
                a[i * n + j - 1][t] = 1;
            }
            if (j < n - 1)
            {
                a[i * n + j + 1][t] = 1;
            }
        }
    }
    return ;
}

void solve()
{
    int t = Gauss();
    if (t == -1)
    {
        cout << "inf\n";
        return ;
    }
    else if (t == 0)
    {
        int ans = 0;
        for (int i = 0; i < n * n; i++)
        {
            ans += x[i];
        }
        cout << ans << '\n';
        return ;
    }
    else
    {
        //  枚举自由变元
        int ans = 0x3f3f3f3f;
        int tot = (1 << t);
        for (int i = 0; i < tot; i++)
        {
            int cnt = 0;
            for (int j = 0; j < t; j++)
            {
                if (i & (i << j))
                {
                    x[free_x[j]] = 1;
                    cnt++;
                }
                else
                {
                    x[free_x[j]] = 0;
                }
            }
            for (int j = var - t - 1; j >= 0; j--)
            {
                int idx;
                for (idx = j; idx < var; idx++)
                {
                    if (a[j][idx])
                    {
                        break;
                    }
                }
                x[idx] = a[j][var];
                for (int l = idx + 1; i < var; i++)
                {
                    if (a[j][l])
                    {
                        x[idx] ^= x[l];
                    }
                }
                cnt += x[idx];
            }
            ans = min(ans, cnt);
        }
        cout << ans << '\n';
    }
    return ;
}

char str[30][30];

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        init();
        for (int i = 0; i < n; i++)
        {
            cin >> str[i];
            for (int j = 0; j < n; j++)
            {
                if (str[i][j] == 'y')
                {
                    a[i * n + j][n * n] = 0;
                }
                else
                {
                    a[i * n + j][n * n] = 1;
                }
            }
        }
        solve();
    }
    
    return 0;
}
