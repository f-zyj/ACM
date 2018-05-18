//
//  main.cpp
//  f-生成树计数
//
//  Created by ZYJ on 16/7/17.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

//  求生成树计数部分代码,计数对10007取模
//const int MOD = 10007;
//int INV[MOD];
////  求ax = 1(mod m)的x值,就是逆元(0<a<m)
//long long inv(long long a, long long m)
//{
//    if (a == 1)
//    {
//        return 1;
//    }
//    return inv(m % a, m) * (m - m / a) % m;
//}
//
//struct Matrix
//{
//    int mat[330][330];
//    
//    void init()
//    {
//        memset(mat, 0, sizeof(mat));
//    }
//    
//    int det(int n)  //  求行列式的值模上MOD,需要使用逆元
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                mat[i][j] = (mat[i][j] % MOD + MOD) % MOD;
//            }
//        }
//        int res = 1;
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = i; j < n; j++)
//            {
//                if (mat[j][i] != 0)
//                {
//                    for (int k = i; k < n; k++)
//                    {
//                        swap(mat[i][k], mat[j][k]);
//                    }
//                    if (i != j)
//                    {
//                        res = (-res + MOD) % MOD;
//                    }
//                    break;
//                }
//            }
//            if (mat[i][i] == 0)
//            {
//                res = -1;   //  不存在(也就是行列式值为0)
//                break;
//            }
//            for (int j = i + 1; j < n; j++)
//            {
//                //int mut = (mat[j][i]*INV[mat[i][i]])%MOD;//打表逆元
//                int mut = (mat[j][i] * inv(mat[i][i], MOD)) % MOD;
//                for (int k = i; k < n; k++)
//                {
//                    mat[j][k] = (mat[j][k] - (mat[i][k] * mut) % MOD + MOD) % MOD;
//                }
//            }
//            res = (res * mat[i][i]) % MOD;
//        }
//        return res;
//    }
//};
//
//
//    Matrix ret;
//    ret.init();
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (i != j && g[i][j])
//            {
//                ret.mat[i][j] = -1;
//                ret.mat[i][i]++;
//            }
//        }
//    }
//    printf("%d\n", ret.det(n - 1));


//  计算生成树个数,不取模,
//  SPOJ 104
const double eps = 1e-8;
const int MAXN = 110;

int sgn(double x)
{
    if (fabs(x) < eps)
    {
        return 0;
    }
    if (x < 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

double b[MAXN][MAXN];
double det(double a[][MAXN], int n)
{
    int i, j, k, sign = 0;
    double ret = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            b[i][j] = a[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (sgn(b[i][i]) == 0)
        {
            for (j = i + 1; j < n; j++)
            {
                if (sgn(b[j][i]) != 0)
                {
                    break;
                }
            }
            if (j == n)
            {
                return 0;
            }
            for (k = i; k < n; k++)
            {
                swap(b[i][k], b[j][k]);
            }
            sign++;
        }
        ret *= b[i][i];
        for (k = i + 1; k < n; k++)
        {
            b[i][k] /= b[i][i];
        }
        for (j = i+1; j < n; j++)
        {
            for (k = i+1; k < n; k++)
            {
                b[j][k] -= b[j][i] * b[i][k];
            }
        }
    }
    if (sign & 1)
    {
        ret = -ret;
    }
    return ret;
}

double a[MAXN][MAXN];
int g[MAXN][MAXN];

int main()
{
    int T;
    int n, m;
    int u, v;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        memset(g, 0, sizeof(g));
        while (m--)
        {
            scanf("%d%d", &u, &v);
            u--;
            v--;
            g[u][v] = g[v][u] = 1;
        }
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && g[i][j])
                {
                    a[i][i]++;
                    a[i][j] = -1;
                }
            }
        }
        double ans = det(a, n - 1);
        printf("%.0lf\n", ans);
    }
    return 0;
}
