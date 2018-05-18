//
//  main.cpp
//  f-HDU-1874-畅通工程续
//
//  Created by ZYJ on 2016/11/12.
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
 *  可更改路径权类型，但是权值必须为非负，下标0~n
 */
const int MAXN = 210;
const int INF = 0x3f3f3f3f; //  表示无穷
bool vis[MAXN];
int pre[MAXN];

void Dijkstra(int cost[][MAXN], int lowcost[], int n, int beg)
{
    for (int i = 0; i <= n; i++)
    {
        lowcost[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    lowcost[beg] = 0;
    for (int j = 0; j <= n; j++)
    {
        int k = -1;
        int min = INF;
        for (int i = 0; i <= n; i++)
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
        for (int i = 0; i <= n; i++)
        {
            if (!vis[i] && lowcost[k] + cost[k][i] < lowcost[i])
            {
                lowcost[i] = lowcost[k] + cost[k][i];
                pre[i] = k;
            }
        }
    }
}

int lowcost[MAXN];
int cost[MAXN][MAXN];
int want[MAXN];

int main()
{
    int N, M;
    int x, y, z;
    int S, T;
    while (~scanf("%d%d", &N, &M))
    {
        memset(cost, 0x3f, sizeof(cost));
        
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d%d", &x, &y, &z);
            if (z < cost[x][y])
            {
                cost[x][y] = cost[y][x] = z;
            }
        }

        scanf("%d%d", &S, &T);
        
        Dijkstra(cost, lowcost, N, S);
        
        if (lowcost[T] == INF)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", lowcost[T]);
        }
    }
    
    return 0;
}
