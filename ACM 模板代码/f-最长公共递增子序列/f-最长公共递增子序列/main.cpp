//
//  main.cpp
//  f-最长公共递增子序列
//
//  Created by ZYJ on 16/7/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

/*
 *  最长公共递增子序列 O(n^2)
 *  f记录路径,DP记录长度, 用a对b扫描,逐步最优化。
 */
const int N = 1010;

int f[N][N], dp[N];

int gcis(int a[], int la, int b[], int lb, int ans[])
{   //  a[1...la], b[1...lb]
    int i, j, k, mx;
    memset(f, 0, sizeof(f));
    memset(dp, 0, sizeof(dp));
    for (i = 1; i <= la; i++)
    {
        memcpy(f[i], f[i-1], sizeof(f[0]));
        for (k = 0, j = 1; j <= lb; j++)
        {
            if (b[j - 1] < a[i - 1] && dp[j] > dp[k])
            {
                k = j;
            }
            if (b[j - 1] == a[i - 1] && dp[k] + 1 > dp[j])
            {
                dp[j] = dp[k] + 1,
                f[i][j] = i * (lb + 1) + k;
            }
        }
    }
    for (mx = 0, i = 1; i <= lb; i++)
    {
        if (dp[i] > dp[mx])
        {
            mx = i;
        }
    }
    for (i = la * lb + la + mx, j = dp[mx]; j; i = f[i / (lb + 1)][i % (lb + 1)], j--)
    {
        ans[j - 1] = b[i % (lb + 1) - 1];
    }
    return dp[mx];
}