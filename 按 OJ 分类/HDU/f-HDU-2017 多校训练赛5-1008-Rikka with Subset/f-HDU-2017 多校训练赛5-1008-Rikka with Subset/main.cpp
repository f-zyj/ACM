//
//  main.cpp
//  f-HDU-2017 多校训练赛5-1008-Rikka with Subset
//
//  Created by ZYJ on 2017/8/8.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 55;
const int MAXM = 1e4 + 10;

int n, m;
int A[MAXN];
int B[MAXM];
int tp[MAXM];
int dp[MAXM];

void solve()
{
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    
    int cnt = 1;
    for (int i = 1; i <= m; i++)
    {
        tp[i] = B[i] - dp[i];
        for (int j = 0; j < tp[i]; j++)
        {
            A[cnt++] = i;
            for (int k = m; k >= i; k--)
            {
                dp[k] += dp[k - i];
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= m; i++)
        {
            scanf("%d", B + i);
        }
        
        solve();
        
        for (int i = 1; i <= n; i++)
        {
            printf("%d%c", A[i], i == n ? '\n' : ' ');
        }
    }
    
    return 0;
}
