//
//  main.cpp
//  f-UVALive-4394-String painter
//
//  Created by ZYJ on 2017/10/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 111;

char A[MAXN];
char B[MAXN];
int ans[MAXN];
int dp[MAXN][MAXN];

int main(int argc, const char * argv[])
{
    while (cin >> A >> B)
    {
        memset(dp, 0, sizeof(dp));
        memset(ans, 0, sizeof(ans));
        
        int len = (int)strlen(A);
        for (int i = 0; i < len; i++)
        {
            dp[i][i] = 1;
        }
        for (int i = 1; i < len; i++)           //  区间长度
        {
            for (int j = 0; j + i < len; j++)   //  区间起始位置
            {
                int r = i + j;                  //  区间终点位置
                dp[j][r] = dp[j + 1][r] + 1;
                for (int k = j + 1; k <= r; k++)//  遍历区间
                {
                    if (B[j] == B[k])
                    {
                        dp[j][r] = min(dp[j][r], dp[j + 1][k] + dp[k + 1][r]);
                    }
                }
            }
        }
        
        if (A[0] != B[0])
        {
            ans[0] = 1;
        }
        for (int i = 1; i < len; i++)
        {
            if (A[i] == B[i])
            {
                ans[i] = ans[i - 1];
            }
            else
            {
                ans[i] = dp[0][i];
                for (int j = 0; j < i; j++)
                {
                    ans[i] = min(ans[i], ans[j] + dp[j + 1][i]);
                }
            }
        }
        
        printf("%d\n", ans[len - 1]);
    }
    
    return 0;
}
