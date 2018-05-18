//
//  main.cpp
//  f-蓝桥-ALGO-36-传纸条
//
//  Created by ZYJ on 2017/6/6.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 55;

int map[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN * 2];

int main(int argc, const char * argv[])
{
//        freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    }
    
    int max_steps = n - 1 + m - 1 - 1;
//    cout << max_steps << '\n';
    for (int k = 1; k <= max_steps; k++)
    {
//        cout << k << '\n';
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                int coli = k - i + 2;
                int colj = k - j + 2;
                if (coli < 1 || colj < 1 || coli > m || colj > m)
                {
                    continue;
                }
                int cost = map[i][coli] + map[j][colj];
                dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + cost);
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1] + cost);
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + cost);
                dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + cost);
//                cout << i << ' ' << j << ' ' << k << " : ";
//                cout << dp[i][j][k] << '\n';
            }
        }
    }
    
    cout << dp[n - 1][n][max_steps] << '\n';
    
    return 0;
}
