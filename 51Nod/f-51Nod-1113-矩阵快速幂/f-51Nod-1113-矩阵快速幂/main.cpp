//
//  main.cpp
//  f-51Nod-1113-矩阵快速幂
//
//  Created by ZYJ on 16/8/13.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

#define MAXN 111
#define mod(x) ((x) % MOD)
#define MOD 1000000007
#define LL long long

int n;

struct mat
{
    int m[MAXN][MAXN];
} unit; //  单元矩阵

//  矩阵乘法
mat operator * (mat a, mat b)
{
    mat ret;
    LL x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            x = 0;
            for (int k = 0; k < n; k++)
            {
                x += mod((LL)a.m[i][k] * b.m[k][j]);
            }
            ret.m[i][j] = mod(x);
        }
    }
    return ret;
}

void init_unit()
{
    for (int i = 0; i < MAXN; i++)
    {
        unit.m[i][i] = 1;
    }
    return ;
}

mat pow_mat(mat a, LL n)
{
    mat ret = unit;
    while (n)
    {
        if (n & 1)
        {
//            n--;
            ret = ret * a;
        }
        n >>= 1;
        a = a * a;
    }
    return ret;
}

int main()
{
    LL x;
    init_unit();
    
    while (cin >> n >> x)
    {
        mat a;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a.m[i][j];
            }
        }
        a = pow_mat(a, x);  //  a矩阵的x次幂
        //  输出矩阵
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j + 1 == n)
                {
                    cout << a.m[i][j] << endl;
                }
                else
                {
                    cout << a.m[i][j] << " ";
                }
            }
        }
    }
    return 0;
}