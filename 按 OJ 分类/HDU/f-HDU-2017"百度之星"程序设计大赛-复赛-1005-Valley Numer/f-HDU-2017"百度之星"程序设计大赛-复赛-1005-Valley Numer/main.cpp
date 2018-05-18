//
//  main.cpp
//  f-HDU-2017"百度之星"程序设计大赛-复赛-1005-Valley Numer
//
//  Created by ZYJ on 2017/8/18.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 111;
const int MAXM = 10;
const int MOD = 1e9 + 7;

char str[MAXN];
int num[MAXN];
int dp[MAXN][MAXN][MAXM][2][2];

int dfs(int pos, int pre, int up, int down, int flag, int tag, int len)
{
    if (pos < 0)
    {
        return 1;
    }
    
    if (dp[pos][len][pre][up][down] > -1 && !flag && !tag)
    {
        return dp[pos][len][pre][up][down];
    }
    
    int res = 0;
    int o = num[pos];
    for (int j = 0; j < MAXM; j++)
    {
        if (j > o && flag)
        {
            break;
        }
        if (tag)
        {
            res = res + dfs(pos - 1, j, 0, 0, j < o ? 0 : flag, tag && j == 0, len - (tag && j == 0));
        }
        else if (j == pre)
        {
            res = res + dfs(pos - 1, j, up, down, j < o ? 0 : flag, tag && j == 0, len);
        }
        else if (j > pre)
        {
            res = res + dfs(pos - 1, j, 1, down, j < o ? 0 : flag, tag && j == 0, len);
        }
        else if (j < pre)
        {
            if (up)
            {
                continue;
            }
            res = res + dfs(pos - 1, j, up, 1, j < o ? 0 : flag, tag && j == 0, len);
        }
        res %= MOD;
    }
    if (!flag && !tag)
    {
        dp[pos][len][pre][up][down] = res;
    }
    
    return res;
}

int cal()
{
    int len = (int)strlen(str);
    for (int i = 0; i < len; i++)
    {
        num[i] = str[len - 1 - i] - '0';
    }
    return dfs(len - 1, 0, 0, 0, 1, 1, len);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%s", str);
        
        long long ans = cal() - 1;
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
