
//
//  main.cpp
//  f-NYOJ-1249-物资调度
//
//  Created by ZYJ on 2017/5/5.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 110;
const int MAXM = 1010;

int A[MAXN];
int dp[MAXM];

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    int N, M;
    while (T--)
    {
        cin >> N >> M;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", A + i);
        }
        
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= N; i++)
        {
            for (int j = M; j >= A[i]; j--)
            {
                if (dp[j - A[i]])
                {
                    dp[j] += dp[j - A[i]];
                }
            }
        }
        
        cout << dp[M] << '\n';
    }
    
    return 0;
}
