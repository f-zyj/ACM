//
//  main.cpp
//  f-CF-Tinkoff Challenge-Elimination Round-D-Presents in Bankopolis
//
//  Created by ZYJ on 2017/4/27.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>

#define POSTIVE 1
#define REBERSE 0

using namespace std;

const int MAXN = 88;
const int INF = 0x3f3f3f3f;

int dp[MAXN][MAXN][MAXN];
int mp[MAXN][MAXN];

int n, k, m;
int u, v, c;

void init()
{
    memset(dp, -1, sizeof(dp));
    memset(mp, 0x3f, sizeof(mp));
}

int getDP(int st, int ed, int k, int dir)
{
    if (dp[st][ed][k] != -1)
    {
        return dp[st][ed][k];
    }
    if (k == 0)
    {
        dp[st][ed][k] = 0;
        return dp[st][ed][k];
    }
    int res = INF;
    if (dir)
    {
        for (int i = st + 1; i < ed; i++)
        {
            if (mp[st][i] != INF)
            {
                res = min(res, mp[st][i] + getDP(i, st, k - 1, REBERSE));
                res = min(res, mp[st][i] + getDP(i, ed, k - 1, POSTIVE));
            }
        }
    }
    else
    {
        for (int i = ed + 1; i < st; i++)
        {
            if (mp[st][i] != INF)
            {
                res = min(res, mp[st][i] + getDP(i, st, k - 1, POSTIVE));
                res = min(res, mp[st][i] + getDP(i, ed, k - 1, REBERSE));
            }
        }
    }
    
    dp[st][ed][k] = res;
    return dp[st][ed][k];
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    init();
    
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        mp[u][v] = min(mp[u][v], c);  //  可能会有重边，重边只保留最短边
    }
    
    int res = INF;
    for (int i = 1; i <= n; i++)        //  以任何一个点为起点
    {
        res = min(res, getDP(i, 0, k - 1, REBERSE));
        res = min(res, getDP(i, n + 1, k - 1, POSTIVE));
    }
    
    if (res == INF)
    {
        cout << "-1\n";
    }
    else
    {
        cout << res << '\n';
    }
    
    return 0;
}
