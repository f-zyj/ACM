//
//  main.cpp
//  f-NYOJ-1251-山区修路
//
//  Created by ZYJ on 2017/5/5.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 520;
const int INF = 0x3f3f3f3f;

int a[MAXN], b[MAXN], dp[MAXN][MAXN];

int main()
{
    int T;
    cin >> T;
    
    int n;
    while (T--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(dp, 0, sizeof(dp));
        
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
            b[i] = a[i];
        }
        
        sort(b, b + n);
        for (int i = 0; i < n; i++)
        {
            int tmp = INF;
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k <= j; k++)
                {
                    tmp = min(tmp, dp[i][k]);
                }
                dp[i + 1][j] = tmp + abs(b[j] - a[i]);
            }
        }
        
        int res = INF;
        for (int i = 0; i < n; i++)
        {
            res = min(res, dp[n][i]);
        }
        
        reverse(a, a + n);
        for (int i = 0; i < n; i++)
        {
            int tmp = INF;
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k <= j; k++)
                {
                    tmp = min(tmp, dp[i][k]);
                }
                dp[i + 1][j] = tmp + abs(b[j] - a[i]);
            }
        }
        
        int res_ = INF;
        for (int i = 0; i < n; i++)
        {
            res_ = min(res_, dp[n][i]);
        }
        
        printf("%d\n", min(res, res_));
    }
    
    return 0;
}
