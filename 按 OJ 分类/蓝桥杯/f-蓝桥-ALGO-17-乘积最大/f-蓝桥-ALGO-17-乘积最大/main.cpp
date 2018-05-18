//
//  main.cpp
//  f-蓝桥-ALGO-17-乘积最大
//
//  Created by ZYJ on 2017/6/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 44;
const int MAXK = 10;

int N, K;
int A[MAXN];
int dp[MAXN][MAXK];

int getNum(int st, int ed)
{
    int num = 0;
    for (int i = st; i <= ed; i++)
    {
        num *= 10;
        num += A[i];
    }
    return num;
}

int main(int argc, const char * argv[])
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        scanf("%1d", A + i);
    }
    for (int i = 1; i <= N; i++)
    {
        dp[i][0] = dp[i - 1][0] * 10 + A[i];
    }
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            for (int k = j - 1; k < i; k++)
            {
                dp[i][j] = max(dp[i][j], dp[k][j - 1] * getNum(k + 1, i));
            }
        }
    }
    
    cout << dp[N][K] << '\n';
    
    return 0;
}
