//
//  main.cpp
//  f-51Nod-1296-有限制的排列
//
//  Created by ZYJ on 2017/4/21.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 5e3 + 10;
const int MOD = 1e9 + 7;

int N, K, L;
int state[MAXN], sum[MAXN];
int dp[MAXN];

int main()
{
    scanf("%d%d%d", &N, &K, &L);
    
    int a;
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &a);
        state[++a] = 1;
        state[a + 1] = 2;
    }
    for (int i = 0; i < L; i++)
    {
        scanf("%d", &a);
        state[++a] = 2;
        state[a + 1] = 1;
    }

    sum[0] = 0;
    dp[1] = sum[1] = 1;
    
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (state[i] == 0)
            {
                dp[j] = sum[i - 1];
            }
            else if (state[i] == 1)
            {
                dp[j] = ((sum[i - 1] - sum[j - 1]) % MOD + MOD) % MOD;
            }
            else
            {
                dp[j] = sum[j - 1];
            }
        }
        for (int j = 1; j <= i; j++)
        {
            sum[j] = (sum[j - 1] + dp[j]) % MOD;
        }
    }
    
    printf("%d\n", sum[N]);
    
    return 0;
}
