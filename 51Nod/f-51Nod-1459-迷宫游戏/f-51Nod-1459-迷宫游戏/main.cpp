//
//  main.cpp
//  f-51Nod-1459-迷宫游戏
//
//  Created by ZYJ on 16/7/29.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#define M 505

using namespace std;

const int inf = 0x3f3f3f3f;

int num[M];       //  结点权值
int map[M][M];  //  图的临近矩阵
int vis[M];       //  结点是否处理过
int ans[M];       //  最短路径结点权值和
int dis[M];       //  各点最短路径花费
int n, m, Start, End;// n结点数，m边数，Start起点，End终点

void Dij(int v)
{
    ans[v] = num[v];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i)
    {
        if (map[v][i] < inf)
        {
            ans[i] = ans[v] + num[i];
        }
        dis[i] = map[v][i];
    }
    dis[v] = 0;
    vis[v] = 1;
    for (int i = 1; i < n; ++i)
    {
        int u = 0, min = inf;
        for (int j = 0; j < n; ++j)
        {
            if (!vis[j] && dis[j] < min)
            {
                min = dis[j];
                u = j;
            }
        }
        vis[u] = 1;
        for (int k = 0; k < n; ++k)
        {
            if (!vis[k] && dis[k] > map[u][k] + dis[u])
            {
                dis[k] = map[u][k] + dis[u];
                ans[k] = ans[u] + num[k];
            }
        }
        for (int k = 0; k < n; ++k)
        {
            if (dis[k] == map[u][k] + dis[u])
            {
                ans[k] = max(ans[k], ans[u] + num[k]);
            }
        }
    }
    printf("%d %d\n", dis[End], ans[End]);  //  输出终点最短路径花费、最短路径结点权值和
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &Start, &End);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &num[i]);
    }
    memset(vis, 0, sizeof(vis));
    memset(map, 0x3f, sizeof(map));
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (map[x][y] > z)
        {
            map[x][y] = z;
            map[y][x] = z;
        }
    }
    Dij(Start);
    
    return 0;
}
