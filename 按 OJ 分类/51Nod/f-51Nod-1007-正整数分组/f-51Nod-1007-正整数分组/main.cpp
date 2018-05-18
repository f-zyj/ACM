//
//  main.cpp
//  f-51Nod-1007-正整数分组
//
//  Created by ZYJ on 16/7/31.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int MAXN = 110;
const int MAXM = 5e3 + 10;

int A[MAXN];
int dp[MAXM][MAXM];

int main(int argc, const char * argv[])
{
//    freopen("input.txt", "r", stdin);
    
    int N;
    cin >> N;
    
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        sum += A[i];
    }
    int C = sum / 2;
    memset(dp, 0, sizeof(dp));
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (j < A[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i]] + A[i]);
            }
        }
    }
//    cout << dp[N][C] << '\n';
    cout << fabs(sum - dp[N][C] - dp[N][C]) << '\n';
    
    return 0;
}
