//
//  main.cpp
//  f-51Nod-1083-矩阵取数问题
//
//  Created by ZYJ on 16/7/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 505;

int map[MAXN][MAXN] = {0};
int dp[MAXN][MAXN] = {0};

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", map[i] + j);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] + map[i][j] : dp[i][j - 1] + map[i][j];
        }
    }
    
    cout << dp[N][N] << '\n';
    
    return 0;
}
