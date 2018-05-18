//
//  main.cpp
//  f-51Nod-1201-整数划分
//
//  Created by ZYJ on 2016/10/12.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 5e4 + 10;
const int MOD = 1e9 + 7;

int dp[2][MAXN];

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    
    long long res = 1;
    for (int i = 1; i <= N; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; (i + 1) * i / 2 <= N; i++)
    {
        for (int j = 0; j < (i + 1) * i / 2; j++)
        {
            dp[i & 1][j] = 0;
        }
        for (int j = i; j <= N; j++)
        {
            dp[i & 1][j] = (dp[(i - 1) & 1][j - i] + dp[i & 1][j - i]) % MOD;
        }
        res = (res + dp[i & 1][N]) % MOD;
    }
    std::cout << res << '\n';
    
    return 0;
}
