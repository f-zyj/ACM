//
//  main.cpp
//  f-51Nod-1032-骨牌覆盖 V2
//
//  Created by ZYJ on 2017/11/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 1 << 5;

ll dp[MAXN][MAXN];
ll ret[MAXN][MAXN];
ll tmp[MAXN][MAXN];

int m, n = 3;

void dfs(int col, int pre, int now)
{
    if (col > n)
    {
        return ;
    }
    if (col == n)
    {
        dp[pre][now]++;
        return ;
    }
    
    dfs(col + 1, pre << 1, (now << 1) | 1);
    dfs(col + 1, (pre << 1) | 1, now << 1);
    dfs(col + 2, pre << 2 , now << 2);
}

void mul(ll ret[][MAXN], ll a[][MAXN], ll b[][MAXN])
{
    int t = 1 << n;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            ll tmp = 0;
            for (int k = 0; k < t; k++)
            {
                tmp += a[i][k] * b[k][j];
                tmp %= MOD;
            }
            ret[i][j] = tmp;
        }
    }
}

int main()
{
    scanf("%d", &m);
    
    dfs(0, 0, 0);
    
    int t = 1 << n;
    for (int i = 0; i < t; i++)
    {
        ret[i][i] = 1;
    }
    
    m++;
    while (m)
    {
        for (int i = 0; i < t; i++)
        {
            for (int j = 0; j < t; j++)
            {
                tmp[i][j] = ret[i][j];
            }
        }
        
        if (m & 1)
        {
            mul(ret, tmp, dp);
        }
        m = m >> 1;
        mul(tmp, dp, dp);
        for (int i = 0; i < t; i++)
        {
            for (int j = 0; j < t; j++)
            {
                dp[i][j] = tmp[i][j];
            }
        }
    }
    
    cout << ret[0][t - 1] << endl;
    
    return 0;
}
