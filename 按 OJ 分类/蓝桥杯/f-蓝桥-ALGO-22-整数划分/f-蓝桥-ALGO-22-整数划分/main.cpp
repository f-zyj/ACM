//
//  main.cpp
//  f-蓝桥-ALGO-22-数的划分
//
//  Created by ZYJ on 2017/6/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 222;
const int MAXK = 9;

int dp[MAXN][MAXK];

int main(int argc, const char * argv[])
{
    int n, k;
    cin >> n >> k;
    
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i >= j)
            {
                dp[i][j] = dp[i - j][j] + dp[i - 1][j - 1];
            }
        }
    }
    
    cout << dp[n][k] << '\n';
    
    return 0;
}
