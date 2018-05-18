//
//  main.cpp
//  f-51Nod-1582-n叉树
//
//  Created by ZYJ on 2017/8/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 101;

ll a[MAXN], dp[MAXN], sum[MAXN];

struct Matrix
{
    ll m[MAXN][MAXN];
} init, res;

Matrix mul(Matrix x, Matrix y)
{
    Matrix tmp;
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            tmp.m[i][j] = 0;
            for (int k = 0; k < MAXN; k++)
            {
                tmp.m[i][j] += x.m[i][k] * y.m[k][j];
                if (tmp.m[i][j] >= MOD)
                {
                    tmp.m[i][j] %= MOD;
                }
            }
        }
    }
    
    return tmp;
}

Matrix qpow(Matrix x, int k)
{
    Matrix tmp;
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            tmp.m[i][j] = (i == j);
        }
    }
    
    while (k)
    {
        if (k & 1)
        {
            tmp = mul(tmp, x);
        }
        x = mul(x, x);
        k >>= 1;
    }
    
    return tmp;
}

int n, x;

int main()
{
    while (scanf("%d%d", &n, &x) != EOF)
    {
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        
        int y;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &y);
            a[y]++;
        }
        
        dp[0] = 1;
        sum[0] = 0;
        for (int i = 1; i < MAXN; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[i - j] * a[j];
                if (dp[i] >= MOD)
                {
                    dp[i] %= MOD;
                }
            }
            sum[i] = sum[i - 1] + dp[i];
            if (sum[i] >= MOD)
            {
                sum[i] %= MOD;
            }
        }
        
        if (x < MAXN)
        {
            printf("%lld\n", (sum[x] + 1) % MOD);
            continue;
        }
        
        memset(init.m, 0, sizeof(init.m));
        for (int  i = 0; i < MAXN - 1; i++)
        {
            init.m[0][i] = init.m[MAXN - 1][i] = a[i + 1];
        }
        for (int i = 1; i < MAXN - 1; i++)
        {
            init.m[i][i - 1] = 1;
        }
        init.m[MAXN - 1][MAXN - 1] = 1;
        
        res = qpow(init, x - MAXN + 1);
        ll ans = (sum[MAXN - 1] * res.m[MAXN - 1][MAXN - 1]) % MOD;
        for (int i = 1; i < MAXN; i++)
        {
            ans += dp[i] * res.m[MAXN - 1][MAXN - i - 1];
            if (ans >= MOD)
            {
                ans %= MOD;
            }
        }
        
        printf("%lld\n", (ans + 1) % MOD);
    }
    
    return 0;
}
