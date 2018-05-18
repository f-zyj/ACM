//
//  main.cpp
//  f-51Nod-1020-逆序排序
//
//  Created by ZYJ on 2016/10/9.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 1e3 + 10;
const int MAXK = 2e4 + 10;
const int MOD = 1e9 + 7;

int dp[MAXN][MAXK]; //  dp[n][k]表示n个数的排列中逆序数个数为k的排列数

void init()
{
    //  逆序数为0的排列为正序
    for (int i = 1; i < MAXN; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 2; i < MAXN; i++)
    {
        int up = i * (i - 1) / 2;
        for (int j = 1; j <= up && j < MAXK; j++)
        {
            dp[i][j] = ((dp[i][j - 1] + dp[i - 1][j] - (j - i >= 0 ? dp[i - 1][j - i] : 0)) % MOD + MOD) % MOD;
        }
    }
}

int main(int argc, const char * argv[])
{
    init();
    
    int T;
    cin >> T;
    
    int n, k;
    while (T--)
    {
        cin >> n >> k;
        cout << dp[n][k] << '\n';
    }
    
    return 0;
}
