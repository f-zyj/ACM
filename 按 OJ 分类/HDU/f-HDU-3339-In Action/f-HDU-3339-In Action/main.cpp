//
//  main.cpp
//  f-HDU-3339-In Action
//
//  Created by ZYJ on 2016/11/23.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

/*
 *  单源最短路径，Dijkstra算法，邻接矩阵形式，复杂度为O(n^2)
 *  求出源beg到所有点的最短路径，传入图的顶点数和邻接矩阵cost[][]
 *  返回各点的最短路径lowcost[]，路径pre[]，pre[i]记录beg到i路径上的父节点，pre[beg] = -1
 *  可更改路径权类型，但是权值必须为非负，下标0~n-1
 */
const int MAXN = 110;
const int INF = 0x3f3f3f3f; //  表示无穷
bool vis[MAXN];
int pre[MAXN];

void Dijkstra(int cost[][MAXN], int lowcost[], int n, int beg)
{
    for (int i = 0; i < n; i++)
    {
        lowcost[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    lowcost[beg] = 0;
    for (int j = 0; j < n; j++)
    {
        int k = -1;
        int min = INF;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && lowcost[i] < min)
            {
                min = lowcost[i];
                k = i;
            }
        }
        if (k == -1)
        {
            break;
        }
        vis[k] = true;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && lowcost[k] + cost[k][i] < lowcost[i])
            {
                lowcost[i] = lowcost[k] + cost[k][i];
                pre[i] = k;
            }
        }
    }
}

int cost[MAXN][MAXN];
int lowcost[MAXN];
int power[MAXN];
int dp[MAXN * MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    
    int n, m;
    while (T--)
    {
        memset(cost, 0x3f, sizeof(cost));
        
        scanf("%d%d", &n, &m);
        
        int st, ed, val;
        while (m--)
        {
            scanf("%d%d%d", &st, &ed, &val);
            if (val < cost[st][ed])
            {
                cost[st][ed] = cost[ed][st] = val;
            }
        }
        
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &power[i]);
            sum += power[i];
        }
        
        Dijkstra(cost, lowcost, n + 1, 0);
        
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = sum; j >= power[i]; j--)
            {
                dp[j] = min(dp[j], dp[j - power[i]] + lowcost[i]);
            }
        }
        
        int mid = sum / 2 + 1;  //  大于一半
        int res = INF;
        for (int i = mid; i <= sum; i++)
        {
            if (dp[i] < res)
            {
                res = dp[i];
            }
        }
        
        if (res == INF)
        {
            printf("impossible\n");
        }
        else
        {
            printf("%d\n", res);
        }
    }
    
    return 0;
}

