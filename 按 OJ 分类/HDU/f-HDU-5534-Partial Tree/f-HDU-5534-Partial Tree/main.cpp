//
//  main.cpp
//  f-HDU-5534-Partial Tree
//
//  Created by ZYJ on 2017/10/16.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2e4 + 5;
const int INF = 0x3f3f3f3f;

int n;
int a[MAXN];
int dp[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i < n; i++)
        {
            scanf("%d", a + i);
        }
        
        for (int i = 0; i <= n; i++)
        {
            dp[i] = -INF;
        }
        
        for (int i = 2; i < n; i++)
        {
            a[i] -= a[1];
        }
        
        dp[0] = 0;
        for (int i = 2; i < n; i++)
        {
            for (int j = 0, t = n - 1; i + j - 1 < t; j++)
            {
                dp[i + j - 1] = max(dp[i + j - 1], dp[j] + a[i]);
            }
        }
        
        printf("%d\n", a[1] * n + dp[n - 2]);
    }
    
    return 0;
}
