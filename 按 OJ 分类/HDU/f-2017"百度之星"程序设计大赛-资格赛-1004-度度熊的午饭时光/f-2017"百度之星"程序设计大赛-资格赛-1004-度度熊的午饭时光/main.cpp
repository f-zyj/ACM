//
//  main.cpp
//  f-2017"百度之星"程序设计大赛-资格赛-1004-度度熊的午饭时光
//
//  Created by ZYJ on 2017/8/6.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>

#define clr(a, b) memset(a, b, sizeof(a))

using namespace std;

typedef long long ll;

const int MAXN = 111;
const int MAXB = 1111;

struct meal
{
    int score, cost;
} m[MAXN];

int B, N;
int dp[MAXB];
bool tmp[MAXN];
bool vis[MAXN][MAXB];

int main()
{
    int T, ce = 1;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &B, &N);
        for (int i = 1; i <= N; i++)
        {
            scanf("%d%d", &m[i].score, &m[i].cost);
        }
        
        clr(dp, 0);
        clr(tmp, 0);
        clr(vis, false);
        
        for (int i = 1; i <= N; i++)
        {
            for (int j = B; j >= 0; j--)
            {
                if (j >= m[i].cost)
                {
                    if (dp[j] < dp[j - m[i].cost] + m[i].score)
                    {
                        vis[i][j] = true;
                        dp[j] = dp[j - m[i].cost] + m[i].score;
                    }
                    else
                    {
                        vis[i][j] = false;
                    }
                }
            }
        }
        
        int t = B, cnt = 0;
        for (int i = N; i >= 1; i--)
        {
            if (vis[i][t])
            {
                tmp[i] = true;
                t -= m[i].cost;
                cnt++;
            }
        }
        
        printf("Case #%d:\n%d %d\n", ce++, dp[B], B - t);
        for (int i = 1; i <= N; i++)
        {
            if (tmp[i])
            {
                printf("%d%c", i, (--cnt == 0) ? '\n' : ' ');
            }
        }
    }
    
    return 0;
}
