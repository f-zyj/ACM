//
//  main.cpp
//  f-HDU-2224-The shortest path
//
//  Created by ZYJ on 2016/11/23.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

/*
 *  将各点按照x坐标从小到大排列(如果需要的话)
 */
const int MAXN = 1005;
const int INF = 0x3f3f3f3f;

struct node
{
    double x, y;
} P[MAXN];

double dist(node a, node b)
{
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

int n;
double dp[MAXN][MAXN];

void solve()
{
    dp[1][0] = dp[0][1] = dist(P[0], P[1]);
    
    for (int i = 2; i < n; i++)
    {
        dp[i][i - 1] = INF;
        for (int j = 0; j < i - 1; j++)
        {
            dp[i][i - 1] = min(dp[i][i - 1], dist(P[i], P[j]) + dp[i - 1][j]);
            dp[i][j] = dist(P[i], P[i - 1]) + dp[i - 1][j];
        }
    }
    double ans = INF;
    for (int i = 0; i < n - 1; i++)
    {
        ans = min(ans, dp[n - 1][i] + dist(P[i], P[n - 1]));
    }
    printf("%.2lf\n", ans);
}

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> P[i].x >> P[i].y;
        }
        solve();
    }
    
    return 0;
}
