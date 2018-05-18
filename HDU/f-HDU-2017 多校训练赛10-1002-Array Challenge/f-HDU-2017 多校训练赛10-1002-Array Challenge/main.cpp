//
//  main.cpp
//  f-HDU-2017 多校训练赛10-1002-Array Challenge
//
//  Created by ZYJ on 2017/8/29.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAGIC_1 = 31;
const int MAGIC_2 = 197;
const int MAGIC_3 = 1255;

struct matrix
{
    ll v[3][3];
    
    matrix()
    {
        memset(v, 0, sizeof(v));
    }
};

ll n;
matrix M, E, ans;

void init()
{
    for (int i = 0; i < 3; i++)
    {
        E.v[i][i] = 1;
    }
    M.v[0][0] = 4, M.v[0][1] = 17, M.v[0][2] = -12;
    M.v[1][0] = 1, M.v[1][1] = 0, M.v[1][2] = 0;
    M.v[2][0] = 0, M.v[2][1] = 1, M.v[2][2] = 0;
}

matrix mul(matrix a, matrix b)
{
    matrix c;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                c.v[i][j] = (c.v[i][j] % MOD + a.v[i][k] * b.v[k][j] % MOD + MOD) % MOD;
            }
        }
    }
    
    return c;
}

matrix pow(matrix p, ll k)
{
    matrix tmp = E;
    while (k)
    {
        if (k & 1)
        {
            tmp = mul(tmp, p);
            k--;
        }
        k >>= 1;
        p = mul(p, p);
    }
    
    return tmp;
}

int main()
{
    init();
    
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%lld", &n);
        
        if (n == 2)
        {
            printf("%d\n", MAGIC_1);
        }
        else if (n == 3)
        {
            printf("%d\n", MAGIC_2);
        }
        else if (n == 4)
        {
            printf("%d\n", MAGIC_3);
        }
        else
        {
            ans = pow(M, n - 4);
            ll res = (ans.v[0][0] * MAGIC_3 % MOD
                    + ans.v[0][1] * MAGIC_2 % MOD
                    + ans.v[0][2] * MAGIC_1 % MOD + MOD) % MOD;
            printf("%lld\n", res);
        }
    }
    
    return 0;
}
