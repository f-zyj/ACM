//
//  main.cpp
//  f-HDU-1176-免费馅饼
//
//  Created by ZYJ on 2016/10/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std ;

const int MAX_PLACE = 11;
const int MAX_TIME = 1e5 + 10;

int a[MAX_TIME][MAX_PLACE + 1];
int dp[MAX_TIME][MAX_PLACE + 1];    //  dp[i][j]第i秒在第j个位置的收获

int main ( )
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        
        int x, T, i, j, maxT = 0, ans = 0;
        while (n--)
        {
            scanf("%d%d", &x, &T);
            ++a[T][x];
            maxT = max(maxT, T);
        }
        //  初始化第一秒
        dp[1][4] = a[1][4];
        dp[1][5] = a[1][5];
        dp[1][6] = a[1][6];
        for (i = 2; i <= maxT; ++i)
        {
            for ( j = 0; j < MAX_PLACE; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (j > 0)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
                }
                if (j < MAX_PLACE - 1)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
                }
                dp[i][j] += a [i][j];
            }
        }
        
        for (i = 0; i < MAX_PLACE; ++i)
        {
            ans = max(ans, dp[maxT][i]) ;
        }
        printf("%d\n", ans);
    }
    
    return 0 ;
}
