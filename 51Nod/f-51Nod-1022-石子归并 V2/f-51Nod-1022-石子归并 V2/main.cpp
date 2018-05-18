//
//  main.cpp
//  f-51Nod-1022-石子归并 V2
//
//  Created by ZYJ on 2016/10/20.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 2020;
const int INF = 0x3f3f3f3f;

int A[MAXN];
int S[MAXN][MAXN];
int W[MAXN][MAXN];
int dp[MAXN][MAXN] = {0};

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        A[i + N] = A[i];
    }
    
    int N_ = 2 * N;
    for (int i = 1; i < N_; i++)
    {
        for (int j = i; j <= i + N; j++)
        {
            W[i][j] = W[i][j - 1] + A[j];
        }
        S[i][i] = i;
    }
    
    for (int len = 2; len <= N; len++)
    {
        for (int i = 1; i + len - 1 <= N_; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INF;
            for (int k = S[i][j - 1]; k <= S[i + 1][j]; k++)
            {
                int temp = dp[i][k] + dp[k + 1][j] + W[i][j];
                if (temp < dp[i][j])
                {
                    dp[i][j] = temp;
                    S[i][j] = k;
                }
            }
        }
    }
    
    int res = INF;
    for (int i = 1; i <= N; i++)
    {
        res = res < dp[i][i + N - 1] ? res : dp[i][i + N - 1];
    }
    cout << res << endl;
    
    return 0;
}
