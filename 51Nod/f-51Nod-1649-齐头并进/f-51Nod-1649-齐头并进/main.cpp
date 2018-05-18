//
//  main.cpp
//  f-51Nod-1649-齐头并进
//
//  Created by ZYJ on 2017/11/22.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 405;

int n, m;
bool vis[MAXN];
int dis[MAXN];
int train[MAXN][MAXN];
int bus[MAXN][MAXN];

void init()
{
    memset(train, 0x3f, sizeof(train));
    memset(bus, 0x3f, sizeof(bus));
}

void dijkstra(int map[][MAXN])
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    
    dis[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = INF, k = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && tmp > dis[j])
            {
                tmp = dis[j];
                k = j;
            }
        }
        if (tmp == INF)
        {
            break;
        }
        vis[k] = true;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dis[j] > dis[k] + map[k][j])
            {
                dis[j] = dis[k] + map[k][j];
            }
        }
    }
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        init();
        
        int a, b;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            train[a][b] = train[b][a] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (train[i][j] == INF)
                {
                    bus[i][j] = bus[j][i] = 1;
                }
            }
        }
        
        dijkstra(train);
        int ans1 = dis[n];
        
        dijkstra(bus);
        int ans2 = dis[n];
        
        int ans = max(ans1, ans2);
        
        printf("%d\n", ans == INF ? -1 : ans);
    }
    
    return 0;
}
