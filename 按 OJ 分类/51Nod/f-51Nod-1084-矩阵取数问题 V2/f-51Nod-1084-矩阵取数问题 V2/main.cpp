//
//  main.cpp
//  f-51Nod-1084-矩阵取数问题 V2
//
//  Created by ZYJ on 2016/10/17.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 205;
const int MAX_STEPS = 405;

int res;
int m, n;
int A[MAXN][MAXN];
int dp[MAX_STEPS][MAXN][MAXN];

void input()
{
    scanf("%d%d", &m, &n);
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
}

void solve()
{
    for (int i = 2; i <= n + m; i++)
    {
        for (int j = 1; j <= n && i - j >= 0; j++)
        {
            for (int k = 1; k <= n && i - k >= 0; k++)
            {
                if (j == k)
                {   //  走到同一列，必定在同一行，所以确定到A[j][i - j]一点
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1] + A[j][i - j]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + A[j][i - j]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + A[j][i - j]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + A[j][i - j]);
                }
                else
                {   //  走到不同列，所以确定到A[j][i - j]、A[k][i - k]两点
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1] + A[j][i - j] + A[k][i - k]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + A[j][i - j] + A[k][i - k]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + A[j][i - j] + A[k][i - k]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + A[j][i - j] + A[k][i - k]);
                }
            }
        }
    }
    cout << dp[n + m][n][n] << endl;
}

int main()
{
    input();
    solve();
    
    return 0;
}
