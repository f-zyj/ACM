//
//  main.cpp
//  f-51Nod-1747-近似多项式
//
//  Created by ZYJ on 2017/8/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 201;
const int MOD = 998244353;

int n;
int inv[MAXN << 1 | 1];
int b[MAXN];
int c[MAXN];
int mat[MAXN][MAXN + 2];

inline int mod_inv(int x)
{
    return x < MAXN << 1 ? inv[x] : MOD - MOD / x * (ll)mod_inv(MOD % x) % MOD;
}

void init()
{
    inv[1] = 1;
    for (int i = 2; i < MAXN << 1; ++i)
    {
        inv[i] = MOD - MOD / i * (ll)inv[MOD % i] % MOD;
    }
    
    b[0] = 1, c[0] = MOD - 1;
    for(int i = 1; i < MAXN; ++i)
    {
        b[i] = (1 + (ll)(MOD - i) * b[i - 1]) % MOD;
        c[i] = (ll)(MOD - i) * c[i - 1] % MOD;
    }
}

int main()
{
    init();
    
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                mat[i][j] = inv[i + j + 1];
            }
            mat[i][n + 1] = b[i];
            mat[i][n + 2] = c[i];
        }
        
        for (int i = 0; i <= n; ++i)
        {
            if (!mat[i][i])
            {
                for (int j = i + 1; j <= n; ++j)
                {
                    if (mat[j][i])
                    {
                        for (int k = i; k <= n + 2; ++k)
                        {
                            swap(mat[i][k], mat[j][k]);
                        }
                        break;
                    }
                }
            }
            
            int invi = mod_inv(mat[i][i]);
            for (int j = i; j <= n + 2; ++j)
            {
                mat[i][j] = (ll)mat[i][j] * invi % MOD;
            }
            for (int j = 0; j <= n; ++j)
            {
                if (i != j && mat[j][i])
                {
                    int d = mat[j][i];
                    for (int k = i; k <= n + 2; ++k)
                    {
                        mat[j][k] -= (ll)mat[i][k] * d % MOD;
                        if (mat[j][k] < 0)
                        {
                            mat[j][k] += MOD;
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i <= n; ++i)
        {
            printf("%d %d\n", mat[i][n + 1], mat[i][n + 2]);
        }
    }
    
    return 0;
}
