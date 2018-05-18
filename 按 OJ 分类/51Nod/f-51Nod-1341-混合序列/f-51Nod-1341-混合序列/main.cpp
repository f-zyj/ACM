//
//  main.cpp
//  f-51Nod-1341-混合序列
//
//  Created by ZYJ on 2017/5/4.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 3;

struct matrix
{
    ll m[MAXN][MAXN];
    matrix()
    {
        memset(m,0,sizeof(m));
    }
    void output()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%lld ",m[i][j]);
            }
            printf("\n");
        }
    }
};

matrix mat(matrix &a, matrix &b)
{
    matrix c;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                c.m[i][j] += (a.m[i][k] * b.m[k][j]);
                c.m[i][j] %= MOD;
            }
        }
    }
    return c;
}

void extgcd(ll a, ll b, ll &d, ll &x, ll &y)
{
    if (!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        extgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

//  逆元
ll inverse(ll a,ll n)
{
    ll d, x, y;
    extgcd(a, n, d, x, y);
    return d == 1 ? (x + n) % n : -1;
}

ll pow_mod(ll x, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    
    return res;
}

ll p, q, r;
ll solve(ll n)
{
    ll k = inverse(q, MOD);
    ll t = 3 * pow_mod(q, n) % MOD; //  t: q^n*3
    matrix A;
    A.m[0][0] = 1; A.m[0][1] = k * p % MOD; A.m[0][2] = k;
    A.m[1][0] = 0; A.m[1][1] = k * p % MOD; A.m[1][2] = k;
    A.m[2][0] = 0; A.m[2][1] = 0;           A.m[2][2] = k;
    matrix C;
    for (int i = 0; i < 3; i++)
    {
        C.m[i][i]=1;
    }
    while (n)
    {
        if (n & 1)
        {
            C = mat(C, A);
        }
        A = mat(A, A);
        n >>= 1;
    }
    
    return C.m[0][2] * t % MOD * r % MOD;
}

int main()
{
    ll n;
    scanf("%lld%lld%lld%lld", &p, &q, &r, &n);
    printf("%lld\n", solve(n));
    
    return 0;
}
