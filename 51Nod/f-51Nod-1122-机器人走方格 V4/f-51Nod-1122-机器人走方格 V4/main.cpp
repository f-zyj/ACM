//
//  main.cpp
//  f-51Nod-1122-机器人走方格 V4
//
//  Created by ZYJ on 2017/9/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

/*
 *  矩阵快速幂 n*n矩阵的x次幂
 */
#define MAXN 5
#define MOD 1000000007
#define LL long long

using namespace std;

int n, N;

struct mat
{
    LL m[MAXN][MAXN];
} unit; //  单元矩阵

//  矩阵乘法
mat operator * (mat a, mat &b)
{
    mat ret;
    memset(ret.m, 0, sizeof(ret.m));
    
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (a.m[i][k])
            {
                for (int j = 0; j < n; j++)
                {
                    ret.m[i][j] = (ret.m[i][j] + a.m[i][k] * b.m[k][j] % MOD) % MOD;
                }
            }
        }
    }
    return ret;
}

void init_unit()
{
    n = 4;
    for (int i = 0; i < MAXN; i++)
    {
        unit.m[i][i] = 1;
    }
}

mat pow_mat(mat a, LL n)
{
    mat ret = unit;
    while (n)
    {
        if (n & 1)
        {
            ret = ret * a;
        }
        n >>= 1;
        a = a * a;
    }
    return ret;
}

int main()
{
    init_unit();
    
    cin >> N;
    
    if (N == 0)
    {
        puts("1");
        return 0;
    }
    
    mat a;
    a.m[0][0] = 1, a.m[0][1] = 1, a.m[0][2] = 1, a.m[0][3] = 0;
    a.m[1][0] = 1, a.m[1][1] = 1, a.m[1][2] = 0, a.m[1][3] = 1;
    a.m[2][0] = 1, a.m[2][1] = 0, a.m[2][2] = 1, a.m[2][3] = 1;
    a.m[3][0] = 0, a.m[3][1] = 1, a.m[3][2] = 1, a.m[3][3] = 1;
    
    a = pow_mat(a, N);
    
    LL ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            
            for (int k = 0; k < n; k++)
            {
                if (k == i || k == j)
                {
                    continue;
                }
                
                for (int l = 0; l < n; l++)
                {
                    if (l == i || l == j || l == k)
                    {
                        continue;
                    }
                    
                    ans += ((a.m[0][i] * a.m[1][j] % MOD) * (a.m[2][k] * a.m[3][l] % MOD)) % MOD;
                    ans %= MOD;
                }
            }
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
