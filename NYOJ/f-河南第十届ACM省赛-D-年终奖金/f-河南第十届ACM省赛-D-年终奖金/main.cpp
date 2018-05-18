//
//  main.cpp
//  f-河南第十届ACM省赛-D-年终奖金
//
//  Created by ZYJ on 2017/5/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 105;

int A[MAXN];
int dp[MAXN][MAXN];

int main()
{
    int n, c, k;
    while (cin >> n >> k >> c)
    {
        memset(dp, 0x3f, sizeof(dp));
        
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        sort(A, A + n);
        
        for (int i = n - k; i >= 0; i--)
        {
            for (int j = i + k - 1; j < n; j++)
            {
                dp[i][j] = c + (A[j] - A[i]) * (A[j] - A[i]);
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        
        cout << dp[0][n - 1] << endl;
    }

    return 0;
}
