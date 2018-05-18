//
//  main.cpp
//  f-HDU-3237-Help Bubu
//
//  Created by ZYJ on 2017/10/13.
//  Copyright &#169; 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXB = 8;
const int MAXN = 110;
const int MAXM = 1 << MAXB;
const int LIMIT = 25;
const int INF = 0x3f3f3f3f;

int n, m, ans;
int book[MAXN];
int cnt[MAXM];
int state;
int dp[2][MAXN][MAXM][MAXB + 1];

void init()
{
    for (int i = 0; i < MAXM; i++)
    {
        for (int j = 0; j < MAXB; j++)
        {
            if (i & (1 << j))
            {
                cnt[i]++;
            }
        }
    }
}

int main()
{
    init();
    
    int ce = 0;
    
    while (~scanf("%d%d", &n, &m) && n + m)
    {
        int mx = state = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", book + i);
            
            book[i] -= LIMIT;
            if (book[i] > mx)
            {
                mx = book[i];
            }
            state |= (1 << book[i]);
        }
        
        ++mx;
        int tot = (1 << mx);
        memset(dp[1], 0x3f, sizeof(dp[1]));
        dp[1][0][1 << book[1]][book[1]] = 1;
        dp[1][1][0][mx] = 0;
        for (int i = 2; i <= n; i++)
        {
            int cur = i & 1;
            int pre = 1 - cur;
            memset(dp[cur], 0x3f, sizeof(dp[cur]));
            
            for (int j = 0; j <= m && j < i; j++)
            {
                for (int k = 0; k < tot; k++)
                {
                    for (int s = 0; s <= mx; s++)
                    {
                        if (dp[pre][j][k][s] == INF)
                        {
                            continue;
                        }
                        
                        int tmp = k | (1 << book[i]);
                        if (j < m)
                        {
                            dp[cur][j + 1][k][s] = min(dp[cur][j + 1][k][s], dp[pre][j][k][s]);    //  取最后一本
                        }
                        
                        if (s == book[i])
                        {
                            dp[cur][j][k][s] = min(dp[cur][j][k][s], dp[pre][j][k][s]);
                        }
                        else
                        {
                            dp[cur][j][tmp][book[i]] = min(dp[cur][j][tmp][book[i]],
                                                           dp[pre][j][k][s] + 1);
                        }
                    }
                }
            }
        }
        
        int cur = n & 1;
        int ans = n, st;
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k < tot; k++)
            {
                for (int s = 0; s < mx; s++)
                {
                    if (dp[cur][j][k][s] != INF)
                    {
                        st = state ^ k;        //  抽走的就是额外的类
                        ans = min(ans, cnt[st] + dp[cur][j][k][s]);
                    }
                }
            }
        }
        
        printf("Case %d: %d\n\n", ++ce, ans);
    }
    
    return 0;
}
