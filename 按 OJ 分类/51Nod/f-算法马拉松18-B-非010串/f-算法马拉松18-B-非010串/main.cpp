//
//  main.cpp
//  f-算法马拉松18-B-非010串
//
//  Created by ZYJ on 2016/9/25.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>

const int MOD = 1e9 + 7;
const int MAXN = 62;

typedef long long ll;

typedef struct
{
    ll A[4][4];
} E;

E D[MAXN];

void mat_ab(E *a, E *b) //  a*b-->a
{
    E c = *a;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            (*a).A[i][j] = 0;
            for (int k = 0; k < 4; k++)
            {
                (*a).A[i][j] += c.A[i][k] * (*b).A[k][j] % MOD;
                (*a).A[i][j] %= MOD;
            }
        }
    }
}

void mat_aa(E *a, E *b) //  a^2-->b
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                (*b).A[i][j] += (*a).A[i][k] * (*a).A[k][j] % MOD;
                (*b).A[i][j] %= MOD;
            }
        }
    }
}

void init()
{
    D[0].A[0][0] = 0, D[0].A[0][1] = 1,	D[0].A[0][2] = 1, D[0].A[0][3] = 0;
    D[0].A[1][0] = 0, D[0].A[1][1] = 0,	D[0].A[1][2] = 0, D[0].A[1][3] = 1;
    D[0].A[2][0] = 0, D[0].A[2][1] = 1,	D[0].A[2][2] = 1, D[0].A[2][3] = 0;
    D[0].A[3][0] = 1, D[0].A[3][1] = 0,	D[0].A[3][2] = 0, D[0].A[3][3] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        mat_aa(D + i - 1, D + i);
    }
}

ll solve(ll n)
{
    E p;
    memset(p.A, 0, sizeof(p.A));
    ll sum = 0;
    for (int i = 0; i < 4; i++)
    {
        p.A[i][i] = 1;  //  p设置为单位矩阵
    }
    for (ll i = 0; i < MAXN; i++)
    {
        if ((1ll << i) & n)
        {
            mat_ab(&p, D + i);
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sum += p.A[i][j];
            sum %= MOD;
        }
    }
    return sum;
}

int main ()
{
    ll n;
    scanf("%lld", &n);
    if (n < 3)
    {
        printf("%d\n", 1 << n);
        return 0;
    }
    n -= 2;
    init();
    printf("%lld\n", solve(n));
    
    return 0;
}
