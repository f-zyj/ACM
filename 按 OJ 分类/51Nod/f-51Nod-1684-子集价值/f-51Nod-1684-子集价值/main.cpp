//
//  main.cpp
//  f-51Nod-1684-子集价值
//
//  Created by ZYJ on 2017/7/21.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 5e4 + 10;
const int MOD = 1e9 + 7;

int n, p;
int b[MAXN];
int a[2][2];
int dp[MAXN][2][2];

void get_mod(int &x)
{
    if (x >= MOD)
    {
        x -= MOD;
    }
}

int get(int x, int y)
{
    memset(dp, 0, sizeof(dp));
    
    for (int k = 1; k <= n; k++)
    {
        int n1 = (b[k] >> x) & 1, n2 = (b[k] >> y) & 1;
        get_mod(++dp[k][n1][n2]);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                get_mod(dp[k][a[i][n1]][a[j][n2]] += dp[k - 1][i][j]);
                get_mod(dp[k][i][j] += dp[k - 1][i][j]);
            }
        }
    }
    
    return dp[n][1][1];
}

int main()
{
    scanf("%d%d", &n, &p);
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }
    
    int ans = 0;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < p; j++)
        {
            ans = (ans + (1ll << (i + j)) % MOD * get(i, j)) % MOD;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
