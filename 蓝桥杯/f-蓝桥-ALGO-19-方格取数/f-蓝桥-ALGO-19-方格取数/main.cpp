//
//  main.cpp
//  f-蓝桥-ALGO-19-方格取数
//
//  Created by ZYJ on 2017/6/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 11;

int map[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN * 2];

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int n;
    cin >> n;
    
    int x, y, z;
    while (cin >> x >> y >> z, x != 0)
    {
        map[x][y] = z;
    }
    
    dp[1][1][0] = map[1][1];
    int max_steps = (n - 1) * 2 - 1;
    for (int k = 1; k <= max_steps; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                int coli = k - i + 2;
                int colj = k - j + 2;
                if (coli < 1 || colj < 1 || coli > n || colj > n)
                {
                    continue;
                }
                int cost = map[i][coli] + map[j][colj];
                dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + cost);
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1] + cost);
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + cost);
                dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + cost);
            }
        }
    }
    
    cout << dp[n - 1][n][max_steps] + map[n][n] << '\n';
    
    return 0;
}
