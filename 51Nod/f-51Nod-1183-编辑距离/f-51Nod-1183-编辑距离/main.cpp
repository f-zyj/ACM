//
//  main.cpp
//  f-51Nod-1183-编辑距离
//
//  Created by ZYJ on 16/7/26.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e3 + 5;

int T, cas = 0;
int n, m;
int dp[N][N];
char s[N], t[N];

int main()
{
    while (scanf("%s%s", s, t) != EOF)
    {
        int n = (int)strlen(s), m = (int)strlen(t);
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i <= m; i++)
        {
            dp[0][i] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
            }
        }
        printf("%d\n", dp[n][m]);
    }
    
    return 0;
}