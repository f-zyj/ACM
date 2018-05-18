//
//  main.cpp
//  f-CCF模拟-4-有趣的数
//
//  Created by ZYJ on 2016/12/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 1010;
const ll MOD = 1e9 + 7;
const int MAXM = 6;

ll dp[MAXN][MAXM];

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < MAXM; i++)
    {
        dp[0][i]=0;
    }
    /*6种状态
     * 0－－剩013
     * 1－－剩13
     * 2－－剩01
     * 3－－剩3
     * 4－－剩1
     * 5－－无
     */
    for (int i = 1; i <= n; i++)
    {
        int temp = i - 1;
        dp[i][0] = 1;
        dp[i][1] = (dp[temp][0] + dp[temp][1] * 2) % MOD;
        dp[i][2] = (dp[temp][0] + dp[temp][2]) % MOD;
        dp[i][3] = (dp[temp][1] + dp[temp][3] * 2) % MOD;
        dp[i][4] = (dp[temp][1] + dp[temp][2] + dp[temp][4] * 2) % MOD;
        dp[i][5] = (dp[temp][3] + dp[temp][4] + dp[temp][5] * 2) % MOD;
    }
    
    cout << dp[n][5] << endl;
    
    return 0;
}
