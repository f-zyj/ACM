//
//  main.cpp
//  f-HDU-1595-find the longest of the shortest
//
//  Created by ZYJ on 2016/11/25.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

/*
 *  单源最短路径，Dijkstra算法，邻接矩阵形式，复杂度为O(n^2)
 *  求出源beg到所有点的最短路径，传入图的顶点数和邻接矩阵cost[][]
 *  返回各点的最短路径lowcost[]，路径pre[]，pre[i]记录beg到i路径上的父节点，pre[beg] = -1
 *  可更改路径权类型，但是权值必须为非负，下标0~n-1
 */
const int MAXN = 1010;
const int INF = 0x3f3f3f3f; //  表示无穷
bool vis[MAXN];
int pre[MAXN];

void Dijkstra(int cost[][MAXN], int lowcost[], int n, int beg, int flag)
{
    if (flag)
    {
        memset(pre, -1, sizeof(pre));
    }
    for (int i = 0; i < n; i++)
    {
        lowcost[i] = INF;
        vis[i] = false;
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
                if (flag)
                {
                    pre[i] = k; //  只标记最短路上的父节点
                }
            }
        }
    }
}

int cost[MAXN][MAXN];
int lowcost[MAXN];

int main(int argc, const char * argv[])
{
    int n, m;
    while (cin >> n >> m)
    {
        memset(cost, 0x3f, sizeof(cost));
        
        int x, y, w;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &x, &y, &w);
            x--, y--;
            if (w < cost[x][y])
            {
                cost[x][y] = cost[y][x] = w;
            }
        }
        
        Dijkstra(cost, lowcost, n, 0, 1);
        
        int ans = lowcost[n - 1];
        for (int i = n - 1; i != 0; i = pre[i])
        {
            int temp = cost[i][pre[i]];
            cost[i][pre[i]] = cost[pre[i]][i] = INF;
            Dijkstra(cost, lowcost, n, 0, 0);
            ans = max(ans, lowcost[n - 1]);
            cost[i][pre[i]] = cost[pre[i]][i] = temp;
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
