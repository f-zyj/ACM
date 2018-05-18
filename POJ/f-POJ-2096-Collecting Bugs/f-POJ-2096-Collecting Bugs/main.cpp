//
//  main.cpp
//  f-POJ-2096-Collecting Bugs
//
//  Created by ZYJ on 2017/10/30.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e3 + 10;

int n, s;
double dp[MAXN][MAXN];

int main(int argc, const char * argv[])
{
    cin >> n >> s;
    
    int t = n * s;
    dp[n][s] = 0.0;
    for (int i = n; i >= 0; i--)
    {
        for (int j = s; j >= 0; j--)
        {
            if (i == n && j == s)
            {
                continue;
            }
            dp[i][j] = (t
                     + (n - i) * j * dp[i + 1][j]
                     + i * (s - j) * dp[i][j + 1]
                     + (n - i) * (s - j) * dp[i + 1][j + 1])
                     / (t - i * j);
        }
    }
    printf("%.4lf\n", dp[0][0]);
    
    return 0;
}
