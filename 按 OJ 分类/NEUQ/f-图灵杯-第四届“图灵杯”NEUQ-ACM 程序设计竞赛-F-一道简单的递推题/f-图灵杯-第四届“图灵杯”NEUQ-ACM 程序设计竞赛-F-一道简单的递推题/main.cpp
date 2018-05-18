//
//  main.cpp
//  f-图灵杯-第四届“图灵杯”NEUQ-ACM 程序设计竞赛-F-一道简单的递推题
//
//  Created by ZYJ on 2017/6/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

////AC 代码
//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//#include <cstring>
//
//#define mod(x) ((x) % MOD)
//
//using namespace std;
//
//typedef long long ll;
//
///*
// *  矩阵快速幂 n*n矩阵的x次幂
// */
//
//const int MAXN = 111;
//const int MOD = 1e9 + 7;
//
//int n;
//
//struct mat
//{
//    int m[MAXN][MAXN];
//    
//    //  矩阵乘法
//    mat operator * (mat &b) const
//    {
//        mat ret;
//        memset(ret.m, 0, sizeof(ret.m));
//        
//        for (int k = 1; k <= n; k++)
//        {
//            for (int i = 1; i <= n; i++)
//            {
//                if (m[i][k])
//                {
//                    for (int j = 1; j <= n; j++)
//                    {
//                        ret.m[i][j] = mod(ret.m[i][j] + (ll)m[i][k] * b.m[k][j]);
//                    }
//                }
//            }
//        }
//        return ret;
//    }
//    
//    void init_unit()
//    {
//        for (int i = 1; i <= n; i++)
//        {
//            m[i][i] = 1;
//        }
//    }
//    
//    mat operator ^ (ll p) const
//    {
//        mat ret;
//        ret.init_unit();
//        mat a;
//        memcpy(a.m, m, sizeof(m));
//        
//        while (p)
//        {
//            if (p & 1)
//            {
//                ret = ret * a;
//            }
//            p >>= 1;
//            a = a * a;
//        }
//        return ret;
//    }
//} tmp; //  单元矩阵
//
//ll k, F[MAXN];
//
//int main()
//{
//    scanf("%d%lld", &n, &k);
//    
//    for (int i = 1; i <= n; i++)
//    {
//        scanf("%lld", F + i);
//    }
//    
//    for (int i = 1; i < n; i++)
//    {
//        tmp.m[i][i + 1] = 1;
//    }
//    for (int j = 1; j <= n; j++)
//    {
//        scanf("%d", &tmp.m[n][n - j + 1]);
//    }
//    
//    tmp = tmp ^ (k - n);
//    
//    long long ans = 0;
//    for (int j = 1; j <= n; j++)
//    {
//        ans = mod(ans + tmp.m[n][j] * F[j]);
//    }
//    
//    printf("%lld\n", ans);
//    
//    return 0;
//}

//
//  main.cpp
//  f-图灵杯-第四届“图灵杯”NEUQ-ACM 程序设计竞赛-F-一道简单的递推题
//
//  Created by ZYJ on 2017/6/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

//  AC 代码
#include <iostream>
#include <cstdio>
#include <cstring>

#define mod(x) ((x) % MOD)

using namespace std;

typedef long long ll;

/*
 *  矩阵快速幂 n * n矩阵的x次幂
 */

const int MAXN = 111;
const int MOD = 1e9 + 7;

int n;

struct mat
{
    int m[MAXN][MAXN];
} unit, a; //  单元矩阵

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
                    ret.m[i][j] = mod(ret.m[i][j] + (ll)a.m[i][k] * b.m[k][j]);
                }
            }
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

mat pow_mat(mat &a, ll n)
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

ll k, F[MAXN];

int main()
{
    init_unit();
    
    scanf("%d%lld", &n, &k);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", F + i);
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        a.m[i][i + 1] = 1;
    }
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &a.m[n - 1][n - j - 1]);
    }
    
    if (k <= n)
    {
        printf("%lld\n", mod(F[k - 1]));
        return 0;
    }
    
    a = pow_mat(a, k - n);  //  a矩阵的x次幂
    
    long long ans = 0;
    for (int j = 0; j < n; j++)
    {
        ans = mod(ans + a.m[n - 1][j] * F[j]);
    }
    
    printf("%lld\n", ans);
    
    return 0;
}

