//
//  main.cpp
//  f-CF-Codeforces Round #420 (Div. 2)-E-Okabe and El Psy Kongroo
//
//  Created by ZYJ on 2017/6/27.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>

#define mod(x) ((x) % MOD)

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAX_MAT_SIZE = 16;

typedef struct Matrix
{
    ll m[MAX_MAT_SIZE][MAX_MAT_SIZE];
} mat;

mat A, B, pre, unit;

mat matrix_mul(mat a, mat b, int len)
{
    mat ret;
    memset(ret.m, 0, sizeof(ret.m));
    
    for (int k = 0; k <= len; k++)
    {
        for (int i = 0; i <= len; i++)
        {
            if (a.m[i][k])
            {
                for (int j = 0; j <= len; j++)
                {
                    ret.m[i][j] = mod(ret.m[i][j] + (ll)a.m[i][k] * b.m[k][j]);
                }
            }
        }
    }
    return ret;
}

void init()
{
    memset(A.m, 0, sizeof(A.m));
    for (int i = 0; i < MAX_MAT_SIZE; i++)
    {
        for (int j = i - 1; j < i + 2 && j < MAX_MAT_SIZE; j++)
        {
            if (j >= 0)
            {
                A.m[i][j] = 1;
            }
        }
    }
    
    memset(unit.m, 0, sizeof(unit.m));
    for (ll i = 0; i < MAX_MAT_SIZE; i++)
    {
        unit.m[i][i] = 1;
    }
    
    memset(pre.m, 0, sizeof(pre.m));
    pre.m[0][0] = 1;
}

Matrix matrix_quick_power(mat a, ll k, int len)
{
    mat ret = unit;
    
    while (k)
    {
        if (k & 1)
        {
            ret = matrix_mul(a, ret, len);
        }
        a = matrix_mul(a, a, len);
        k >>= 1;
    }
    
    return ret;
}

int n;
ll k;

int main()
{
    init();
    
    scanf("%d%lld", &n, &k);
    
    ll a, b;
    int c, flag = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld%d", &a, &b, &c);
        if (b > k)
        {
            b = k;
            flag = 1;
        }
        B = matrix_quick_power(A, b - a, c);
        for (int j = c + 1; j < MAX_MAT_SIZE; j++)
        {
            pre.m[j][0] = 0;
        }
        B = matrix_mul(B, pre, c);
        
        for (int j = 0; j <= c; j++)
        {
            pre.m[j][0] = B.m[j][0];
        }
        if (flag == 1)
        {
            break;
        }
    }
    
    printf("%lld\n", B.m[0][0]);
    
    return 0;
}
