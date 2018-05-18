//
//  main.cpp
//  f-HDU-1317-XYZZY
//
//  Created by ZYJ on 2016/11/20.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 105;
const int MAXM = MAXN * MAXN / 2;
const int INF = 0x3f3f3f3f;

int dist[MAXN];
int g[MAXN];
int map[MAXN][MAXN];

struct edge
{
    int x, y;
} Edge[MAXM];

int n, m;

void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                map[i][j] = map[i][j] || (map[k][j] && map[i][k]);
            }
        }
    }
}

bool bellman_ford(int s)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i]= -INF;
    }
    dist[s] = 100;
    for (int i = 1; i < n; i++)     //  n-1次
    {
        for (int j = 0; j < m; j++)
        {
            int x = Edge[j].x;
            int y = Edge[j].y;
            if (dist[y] < dist[x] + g[y] && dist[x] + g[y] > 0)
            {
                dist[y] = dist[x] + g[y];
            }
        }
    }
    for (int j = 0; j < m; j++)
    {
        int x = Edge[j].x;
        int y = Edge[j].y;
        if (dist[y] < dist[x] + g[y] && dist[x] + g[y] > 0 && map[y][n])
        {
            return 1;
        }
    }
    return dist[n] > 0;
}

int main()
{
    int num, ed;
    while (scanf("%d", &n) != EOF)
    {
        if (n == -1)
        {
            break;
        }
        m = 0;
        memset(map, 0, sizeof(map));
        
        for (int st = 1; st <= n; st++)
        {
            scanf("%d%d", &g[st], &num);
            while (num--)
            {
                scanf("%d", &ed);
                map[st][ed] = 1;
                Edge[m].x = st;
                Edge[m].y = ed;
                m++;
            }
        }
        
        //  判断是否连通
        floyd();
        
        if (!map[1][n])
        {
            printf("hopeless\n");
            continue;
        }
        if (bellman_ford(1))
        {
            printf("winnable\n");
        }
        else
        {
            printf("hopeless\n");
        }
    }
    
    return 0;
}
