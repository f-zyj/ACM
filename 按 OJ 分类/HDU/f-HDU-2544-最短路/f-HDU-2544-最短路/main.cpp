//
//  main.cpp
//  f-HDU-2544-最短路
//
//  Created by ZYJ on 2016/11/9.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

/*
 *  单源最短路径，Dijkstra算法，邻接矩阵形式，复杂度为O(n^2)
 *  求出源beg到所有点的最短路径，传入图的顶点数和邻接矩阵cost[][]
 *  返回各点的最短路径lowcost[]，路径pre[]，pre[i]记录beg到i路径上的父节点，pre[beg] = -1
 *  可更改路径权类型，但是权值必须为非负
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

int main(int argc, const char * argv[])
{
    int N, M;
    while (cin >> N >> M, N + M)
    {
        memset(cost, 0x3f, sizeof(cost));
        
        int A, B, C;
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d%d", &A, &B, &C);
            cost[A - 1][B - 1] = C;
            cost[B - 1][A - 1] = C;
        }
        
        Dijkstra(cost, lowcost, N, 0);
        printf("%d\n", lowcost[N - 1]);
    }
    
    return 0;
}
