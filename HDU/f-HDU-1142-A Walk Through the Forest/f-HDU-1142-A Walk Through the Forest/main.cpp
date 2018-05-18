//
//  main.cpp
//  f-HDU-1142-A Walk Through the Forest
//
//  Created by ZYJ on 2016/12/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
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
int paths[MAXN];

int dfs(int s, int n)
{
    if (paths[s])   //  记忆化搜索
    {
        return paths[s];
    }
    if (s == 1)
    {
        return 1;   //  到达终点
    }
    
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (cost[s][i] != INF && lowcost[i] < lowcost[s])
        {
            count += dfs(i, n);
        }
    }
    paths[s] = count;
    
    return paths[s];
}

int main(int argc, const char * argv[])
{
    int N, M;
    while (cin >> N, N != 0)
    {
        cin >> M;
        memset(cost, 0x3f, sizeof(cost));
        memset(paths, 0, sizeof(paths));
        int u, v, w;
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            u--;
            v--;
            if (w < cost[u][v])
            {
                cost[u][v] = cost[v][u] = w;
            }
        }
        
        Dijkstra(cost, lowcost, N, 1);
        
        int count = dfs(0, N);
        cout << count << '\n';
    }
    
    return 0;
}
