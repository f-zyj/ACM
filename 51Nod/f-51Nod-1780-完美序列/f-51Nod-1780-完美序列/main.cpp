//
//  main.cpp
//  f-51Nod-1780-完美序列
//
//  Created by ZYJ on 2017/7/21.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 3e4 + 5;
const int MAXM = 111;
const int MOD = 1e9 + 7;

int n;
int A[MAXN];
int cnt[MAXN];
ll C[MAXM][MAXM];
ll dp[MAXN][MAXM][3];

template <class T>
inline bool scan_d(T &ret)
{
    char c;
    int sgn;
    if (c = getchar(), c == EOF)
    {
        return 0; //EOF
    }
    while (c != '-' && (c < '0' || c > '9'))
    {
        c = getchar();
    }
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0');
    }
    ret *= sgn;
    return 1;
}

void init()
{
    for (int i = 0; i < MAXM; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

int main()
{
    init();
    
    scan_d(n);
    
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        scan_d(A[i]);
        if (i == 1)
        {
            cnt[++tot] = 1;
            continue;
        }
        if (A[i] - A[i - 1] > 1)
        {
            puts("0");
            return 0;
        }
        if (A[i] - A[i - 1] == 1)
        {
            cnt[++tot] = 1;
        }
        else
        {
            cnt[tot]++;
        }
    }
    
    dp[1][cnt[1] + 1][2] = 1;
    for (int i = 1; i < tot; i++)
    {
        for (int j = 0; j <= cnt[i] + 1; j++)
        {
            int x = cnt[i + 1];
            for (int k = 1; k <= j; k++)
            {
                ll tmp = C[x - 1][k - 1];   //  将 x 个数划分为 k 份（插空法）
                if (x - k >= 0)
                {
                    dp[i + 1][x - k][0] += (dp[i][j][0] * C[j][k] % MOD
                                         + dp[i][j][1] * C[j - 1][k] % MOD
                                         + dp[i][j][2] * C[j - 2][k] % MOD) % MOD
                                         * tmp % MOD;
                    dp[i + 1][x - k][0] %= MOD;
                }
                if (x - k + 1 >= 0)
                {
                    dp[i + 1][x - k + 1][1] += (dp[i][j][1] * C[j - 1][k - 1] % MOD
                                             + dp[i][j][2] * C[j - 2][k - 1] * 2 % MOD) % MOD
                                             * tmp % MOD;
                    dp[i + 1][x - k + 1][1] %= MOD;
                }
                if (k - 2 >= 0 && x - k + 2 >= 0)
                {
                    dp[i + 1][x - k + 2][2] += dp[i][j][2] * C[j - 2][k - 2] % MOD * tmp % MOD;
                    dp[i + 1][x - k + 2][2] %= MOD;
                }
            }
        }
    }
    
    ll ans = 0;
    for (int i = 0; i <= cnt[tot] + 1; i++)
    {
        ans = (ans + (dp[tot][i][0] + dp[tot][i][1] + dp[tot][i][2]) % MOD) % MOD;
    }
    cout << ans << endl;
    
    return 0;
}
