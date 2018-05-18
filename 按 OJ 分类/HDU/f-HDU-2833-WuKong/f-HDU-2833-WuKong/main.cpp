//
//  main.cpp
//  f-HDU-2833-WuKong
//
//  Created by ZYJ on 2016/12/9.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

/*
 *  dp大法好
 *  题意：
 *  给定一个无向图，和两对起点终点，求两条最短路上的最多公共交点数。
 *  反证法容易验证相交公共点比连续！！
 *  那么我们假设存在2组数据 s1,e1,s2,e2;
 *  我们用dp[i][j] 代表 从点i到点j最短路上最多有多少个点！
 *  那么 map[s1][i] + map[i][j] + map[j][e1] = map[s1][e1] 不就表示i到j的最短路为 s1到e1最短路的子路嘛；
 *  我们只需更新dp[i][j]中的最大值即可。
 */
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int MAXN= 305;
//const int INF = 0x3f3f3f3f;
//
//int dp[MAXN][MAXN];
//int map[MAXN][MAXN];
//int ans,n,m;
//
//void floyd()
//{
//    for (int k = 1; k <= n; k++)
//    {
//        for (int i = 1; i <= n; i++)
//        {
//            if (map[i][k] != INF && i != k)
//            {
//                for (int j = 1; j <= n; j++)
//                {
//                    if (i == j || j == k)
//                    {
//                        continue;
//                    }
//                    if (map[i][j] > map[i][k] + map[k][j])
//                    {
//                        map[i][j] = map[i][k] + map[k][j];
//                        dp[i][j] = dp[i][k] + dp[k][j] - 1;
//                    }
//                    else if (map[i][j] == map[i][k] + map[k][j] && dp[i][j] < dp[i][k] + dp[k][j])
//                    {
//                        dp[i][j] = dp[i][k] + dp[k][j] - 1;
//                    }
//                }
//            }
//        }
//    }
//}
//
//int solve(int s1, int e1, int s2, int e2)
//{
//    int res = 0;
//    if (map[s1][e1] >= INF || map[s2][e2] >= INF)
//    {
//        return 0;
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//            if (map[s1][i] + map[i][j] + map[j][e1] == map[s1][e1] &&
//                map[s2][i] + map[i][j] + map[j][e2] == map[s2][e2])
//            {
//                res = max(res, dp[i][j]);
//            }
//        }
//    }
//    return res;
//}
//
//int main()
//{
//    while (scanf("%d%d", &n, &m) != EOF && (n | m))
//    {
//        int u, v, w;
//        int s1, e1, s2, e2;
//        for (int i = 1; i <= n; i++)
//        {
//            for (int j = 1; j <= n; j++)
//            {
//                map[i][j] = INF;
//                dp[i][j] = 2;
//            }
//            dp[i][i] = 1;
//            map[i][i] = 0;
//        }
//        for (int i = 1; i <= m; i++)
//        {
//            scanf("%d%d%d", &u, &v, &w);
//            map[v][u] = map[u][v] = min(map[u][v], w);
//        }
//        
//        floyd();
//        
//        scanf("%d%d%d%d", &s1, &e1, &s2, &e2);
//        printf("%d\n", solve(s1, e1, s2, e2));
//    }
//    
//    return 0;
//}

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 305;

int n;
int cost[MAXN][MAXN];
int lowcost[MAXN];
int lowcost_[MAXN];
int cnt[MAXN][MAXN];
bool vis[MAXN];

void init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cost[i][j] = INF;
        }
    }
    memset(cnt, -1, sizeof(cnt));
}

void dijkstra(int u, int lowc[])
{
    memset(vis, false, sizeof(vis));
    
    int mins, v = 0;
    for (int i = 1; i <= n; i++)
    {
        lowc[i] = cost[u][i];
    }
    lowc[u] = 0;
    vis[u] = true;
    while (1)
    {
        mins = INF;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && lowc[j] < mins)
            {
                mins = lowc[j];
                v = j;
            }
        }
        if (mins == INF)
        {
            break;
        }
        vis[v] = true;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && lowc[v] + cost[v][j] < lowc[j])
            {
                lowc[j] = lowc[v] + cost[v][j];
            }
        }
    }
}

int dfs(int a, int b)
{
    if (cnt[a][b] > -1)
    {
        return cnt[a][b];
    }
    int v = 0;
    if (a == b)
    {
        v++;
        for (int i = 1; i <= n; i++)    //  枚举第一条最短路的可以到达a的前一个点
        {
            if (lowcost[i] + cost[i][a] != lowcost[a])  //  i-a不是最短路上的边
            {
                continue;
            }
            for (int j = 1; j <= n; j++)//  枚举第二条最短路的可以到达b的前一个点
            {
                if (lowcost_[j] + cost[j][b] == lowcost_[b])
                {
                    v = max(v, dfs(i, j) + 1);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)        //  a往前走一步
    {
        if (lowcost[i] + cost[i][a] == lowcost[a])
        {
            v = max(v, dfs(i, b));
        }
    }
    for (int i = 1; i <= n; i++)        //  b往前走一步
    {
        if (lowcost_[i] + cost[i][b] == lowcost_[b])
        {
            v = max(v, dfs(a, i));
        }
    }
    cnt[a][b] = v;
    return v;
}

int main()
{
    int m;
    int u, v, w;
    int s1, e1, s2, e2;
    
    while (scanf("%d%d", &n, &m), (n | m))
    {
        init();
        
        while (m--)
        {
            scanf("%d%d%d", &u, &v, &w);
            if (w < cost[u][v])
            {
                cost[u][v] = cost[v][u] = w;
            }
        }
        
        scanf("%d%d%d%d", &s1, &e1, &s2, &e2);
        
        cnt[s1][s2] = 0;
        if (s1 == s2)
        {
            cnt[s1][s2] = 1;
        }
        dijkstra(s1, lowcost);
        dijkstra(s2, lowcost_);
        printf("%d\n", dfs(e1, e2));
    }
    
    return 0;
}
