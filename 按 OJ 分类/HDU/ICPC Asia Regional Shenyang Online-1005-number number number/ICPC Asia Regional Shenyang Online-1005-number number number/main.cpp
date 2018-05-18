//
//  main.cpp
//  ICPC Asia Regional Shenyang Online-1005-number number number
//
//  Created by ZYJ on 2017/9/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int MOD =  998244353;

ll k;
ll A[2][2];
ll res[2][2];
ll c[2][2];

void mull(ll a[2][2], ll b[2][2])
{
    memset(c, 0, sizeof(c));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
            }
        }
    }
    memcpy(a, c, sizeof(c));
}

void mul_pow(ll n)
{
    res[0][0] = res[1][1] = 1;
    res[1][0] = res[0][1] = 0;
    while (n)
    {
        if (n & 1)
        {
            mull(res, A);
        }
        mull(A, A);
        n >>= 1;
    }
}

int main()
{
    while (~scanf("%lld", &k))
    {
        k = (k - 1) * 2 + 4;
        A[0][0] = 1, A[0][1] = 1;
        A[1][0] = 1, A[1][1] = 0;
        
        mul_pow(k);
        
        printf("%lld\n", (res[0][0] - 1 + MOD) % MOD);
    }
    
    return 0;
}
