//
//  main.cpp
//  f-51Nod-1228-序列求和
//
//  Created by ZYJ on 2017/8/9.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2222;
const int MOD = 1e9 + 7;

int k;
ll n;
int B[MAXN];
int inv[MAXN];
int C[MAXN][MAXN];

void init()
{
    C[0][0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
    
    inv[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        inv[i] = (ll)inv[MOD % i] * (MOD - MOD / i) % MOD;
    }
    
    B[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        B[i] = 0;
        for (int k = 0; k < i; k++)
        {
            B[i] = (B[i] + (ll)C[i + 1][k] * B[k] % MOD) % MOD;
        }
        B[i] = ((ll)B[i] * (-inv[i + 1]) % MOD + MOD) % MOD;
    }
}

int main()
{
    init();
    
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%d", &n, &k);
        
        n++;
        n %= MOD;
        ll tmp = n, ans = 0;
        for (int i = 1; i <= k + 1; i++)
        {
            ans = (ans + (ll)C[k + 1][i] * B[k + 1 - i] % MOD * n % MOD) % MOD;
            n = (ll)n * tmp % MOD;
        }
        ans = (ll)ans * inv[k + 1] % MOD;
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
