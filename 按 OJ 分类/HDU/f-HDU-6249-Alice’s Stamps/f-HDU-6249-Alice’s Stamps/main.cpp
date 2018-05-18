//
//  main.cpp
//  f-HDU-6249-Alice’s Stamps
//
//  Created by ZYJ on 2017/12/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 2005;

int dp[MAXN][MAXN];
int t[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    
    for (int ce = 1; ce <= T; ce++)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        
        int x, y;
        memset(t, 0, sizeof(t));
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &x, &y);
            for (int i = x; i <= y; i++)
            {
                t[i] = max(t[i], y);
            }
        }
        
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (t[i + 1])
                {
                    dp[t[i + 1]][j + 1] = max(dp[i][j] + t[i + 1] - i, dp[t[i + 1]][j + 1]);
                }
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                ans = max(ans, dp[i][j]);
            }
        }
        printf("Case #%d: %d\n", ce, ans);
    }
    
    return 0;
}
