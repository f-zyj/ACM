//
//  main.cpp
//  f-51Nod-1101-换零钱
//
//  Created by ZYJ on 16/8/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 13;
const int value[13] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

int dp[MAXN] = {1};  //  dp[i]:i的换法

int main(int argc, const char * argv[])
{
    int N;
    
    while (cin >> N)
    {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        
        for (int i = 0; i < SIZE; i++)
        {
            if (value[i] > N)
            {
                break;
            }
            for (int j = value[i]; j <= N; j++)
            {
                dp[j] = (dp[j] + dp[j - value[i]]) % MOD;
            }
        }
        std::cout << dp[N] << '\n';
    }
    
    return 0;
}
