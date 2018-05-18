//
//  main.cpp
//  f-HDU-2066-一个人的旅行
//
//  Created by ZYJ on 2016/11/9.
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
const int MAXN = 1010;
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

int T, S, D, num;
int lowcost[MAXN];
int cost[MAXN][MAXN];
int want[MAXN];

int main()
{
    int x, y, z;
    while (~scanf("%d%d%d",&T, &S, &D))
    {
        num = 0;
        memset(cost, 0x3f, sizeof(cost));
        
        while (T--)
        {
            scanf("%d%d%d", &x, &y, &z);
            num = max(max(num, x), y);
            if (z < cost[x][y])
            {
                cost[x][y] = cost[y][x] = z;
            }
        }
        int minn = INF;
        for (int i = 0; i < S; i++)
        {
            scanf("%d", &x);
            cost[0][x] = cost[x][0] = 0;
        }
        for (int i = 0; i < D; i++)
        {
            scanf("%d", &want[i]);
        }
        
        Dijkstra(cost, lowcost, num, 0);
        
        for (int i = 0; i < D; i++)
        {
            minn = min(minn, lowcost[want[i]]);
        }
        printf("%d\n", minn);
    }
    
    return 0;
}
