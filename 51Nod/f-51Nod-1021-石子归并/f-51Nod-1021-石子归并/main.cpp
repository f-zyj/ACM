//
//  main.cpp
//  f-51Nod-1021-石子归并
//
//  Created by ZYJ on 16/8/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 110;
const int INF = 0x3f3f3f3f;

int A[MAXN];
int S[MAXN] = {0};
int dp[MAXN][MAXN] = {0};

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    memset(dp, 0, sizeof(dp));
    
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        S[i] = S[i - 1] + A[i];
    }

    for (int i = 1; i < N; i++)                 //  从1到N-j(控制归并区间长度)
    {
        for (int j = 1; j + i <= N; j++)        //  从1到N(控制归并区间起点)
        {
            dp[j][i + j] = INF;
            int temp = S[i + j] - S[j - 1];     //  从j到i+j的和
            for (int k = j; k <= i + j; k++)    //  归并j~k与k+1~i+j
            {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + temp);
            }
        }
    }
    
    cout << dp[1][N] << endl;   //  归并区间到1~N
    
    return 0;
}
