//
//  main.cpp
//  f-51Nod-1500-苹果曼和树
//
//  Created by ZYJ on 2017/7/14.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

int n;
int x[MAXN];
long long dp[MAXN][2];
vector<int> G[MAXN];

void dfs(int r, int pre)
{
    if (x[r])
    {
        dp[r][1] = 1;
    }
    else
    {
        dp[r][0] = 1;
    }
    
    int sz = (int)G[r].size(), nt;
    for (int i = 0; i < sz; i++)
    {
        nt = G[r][i];
        if (pre != nt)
        {
            dfs(nt, r);
            dp[r][1] = (dp[r][1] * (dp[nt][0] + dp[nt][1]) + dp[r][0] * dp[nt][1]) % MOD;
            dp[r][0] = (dp[r][0] * (dp[nt][0] + dp[nt][1])) % MOD;
        }
    }
}

int main()
{
    scanf("%d", &n);
    
    int p;
    for (int i = 1;i < n; i++)
    {
        scanf("%d", &p);
        G[p].push_back(i);
        G[i].push_back(p);
    }
    
    for (int i = 0;i < n; i++)
    {
        scanf("%d", x + i);
    }
    
    dfs(0, -1);
    
    printf("%lld\n", dp[0][1]);
    
    return 0;
}
