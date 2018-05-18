//
//  main.cpp
//  f-51Nod-1358-浮波那契
//
//  Created by ZYJ on 16/9/12.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

#define INF 0x3fffffff

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

ll n;

struct matrix
{
    ll a[35][35];
};

matrix mu(matrix A, matrix B)
{
    matrix t;
    memset(t.a, 0, sizeof(t.a));
    
    int i, j, k;
    
    for (i = 1; i <= 34; i++)
    {
        for (j = 1; j <= 34; j++)
        {
            for (k = 1; k <= 34; k++)
            {
                t.a[i][j] += A.a[i][k] * B.a[k][j];
                t.a[i][j] %= mod;
            }
        }
    }
    return t;
}

matrix multi(matrix mat, long long x)
{
    int i;
    
    matrix b;
    memset(b.a, 0, sizeof(b.a));
    
    for (i = 1; i <= 34; i++)
    {
        b.a[i][i] = 1;
    }
    
    while (x)
    {
        if (x & 1)
        {
            b = mu(b, mat);
        }
        x = x >> 1;
        mat = mu(mat, mat);
    }
    return b;
}

void input()
{
    scanf("%lld", &n);
}

void solve()
{
    matrix mat;
    memset(mat.a, 0, sizeof(mat.a));
    
    int i;
    //  构造单元矩阵
    mat.a[1][10] = mat.a[1][34] = 1;
    for (i = 2; i <= 34; i++)
    {
        mat.a[i][i - 1] = 1;
    }
   
    //  特判n≤4
    if (n <= 4)
    {
        puts("1");
        return ;
    }
    //  n>4
    ll x = (n - 4) * 10;
    matrix res = multi(mat, x);
    
    ll  ans = 0;
    for (i = 1; i <= 34; i++)
    {
        ans = (ans + res.a[1][i]) % mod;
    }
    printf("%lld", ans);
}

int main()
{
    input();
    solve();
    
    return 0;
}
