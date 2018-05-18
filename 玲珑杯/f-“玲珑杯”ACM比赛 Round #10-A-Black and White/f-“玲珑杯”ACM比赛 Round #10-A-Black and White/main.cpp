//
//  main.cpp
//  f-“玲珑杯”ACM比赛 Round #10-A-Black and White
//
//  Created by ZYJ on 2017/2/18.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

int dp[MAXN][2];    //  0:Black 1:Write
int sum[MAXN][2];

void init()
{
    dp[1][0] = dp[1][1] = 1;
    sum[1][0] = sum[1][1] = 1;
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        init();
        
        int a, b, n;
        scanf("%d%d%d", &a, &b, &n);
        //  a白、b黑 等价于 a黑、b白
        if (a > b)
        {
            swap(a, b);
        }
        
        if (a == 1)
        {
            if (b < n)
            {
                printf("0\n");
            }
            else
            {
                printf("1\n");
            }
            continue;
        }
        
        //  前 a-1 个不会出现违规排列
        for (int i = 2; i < a; i++)
        {
            dp[i][1] = dp[i][0] = dp[i - 1][0] * 2 % MOD;
            sum[i][0] = (sum[i - 1][0] + dp[i][0]) % MOD;
            sum[i][1] = (sum[i - 1][1] + dp[i][1]) % MOD;
        }
        
        //  a 到 b-1 只有一种会违规
        for (int i = a; i < b; i++)
        {
            dp[i][0] = (sum[i - 1][1] - sum[i - a][1] + MOD) % MOD;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            sum[i][0] = (sum[i - 1][0] + dp[i][0]) % MOD;
            sum[i][1] = (sum[i - 1][1] + dp[i][1]) % MOD;
        }
        //  b 到 n 两种违规可能
        for (int i = b; i <= n; i++)
        {
            dp[i][0] = (sum[i - 1][1] - sum[i - a][1] + MOD) % MOD;
            dp[i][1] = (sum[i - 1][0] - sum[i - b][0] + MOD) % MOD;
            sum[i][0] = (sum[i - 1][0] + dp[i][0]) % MOD;
            sum[i][1] = (sum[i - 1][1] + dp[i][1]) % MOD;
        }
        printf("%d\n", (dp[n][0] + dp[n][1]) % MOD);
    }
    
    return 0;
}
