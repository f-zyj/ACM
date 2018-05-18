//
//  main.cpp
//  f-蓝桥-ALGO-35-传球游戏
//
//  Created by ZYJ on 2017/6/6.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 33;

int n, m;
int dp[MAXN][MAXN];

int main(int argc, const char * argv[])
{
    cin >> n >> m;
    
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = dp[i - 1][(j - 1 + n) % n] + dp[i - 1][(j + 1) % n];
        }
    }
    
    cout << dp[m][0] << '\n';
    
    return 0;
}
