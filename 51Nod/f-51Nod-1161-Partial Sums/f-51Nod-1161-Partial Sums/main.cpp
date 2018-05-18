//
//  main.cpp
//  f-51Nod-1161-Partial Sums
//
//  Created by ZYJ on 2017/3/21.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 5e3 + 5;
const int MOD = 1e9 + 7;

ll A[MAXN], inv[MAXN];

void getInv()
{
    inv[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        inv[i] = ((MOD - MOD / i) * inv[MOD % i]) % MOD;
    }
}

ll res[MAXN];

void init(int n, int k)
{
    res[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        res[i] = ((res[i - 1] * (k - 1 + i) % MOD) * inv[i]) % MOD;
    }
}

int main()
{
    getInv();
    
    int n, k;
    while (~scanf("%d%d", &n, &k))
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &A[i]);
        }
        
        init(n, k);
        
        for (int i = 1; i <= n; i++)
        {
            ll sum = 0;
            for (int j = 1; j <= i; j++)
            {
                sum = (sum + res[i - j] * A[j] % MOD + MOD) % MOD;
            }
            if (i == n)
            {
                printf("%lld ", sum);
            }
            else
            {
                printf("%lld\n", sum);
            }
        }
    }
    
    return 0;
}
