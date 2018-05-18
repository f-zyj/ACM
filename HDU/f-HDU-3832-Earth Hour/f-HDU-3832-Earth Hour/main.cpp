//
//  main.cpp
//  f-HDU-3832-Earth Hour
//
//  Created by ZYJ on 2016/11/27.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 205;
const int INF = 0x1f1f1f1f;

struct node
{
    int x, y, r;
} light[MAXN];

int g[MAXN][MAXN];
int dist[3][MAXN];
int vis[MAXN];

//  判断两个灯是否相交
int judge(int i, int j)
{
    int x = light[i].x - light[j].x;
    int y = light[i].y - light[j].y;
    int d = x * x + y * y;
    int r = light[i].r + light[j].r;
    if (r * r >= d)
    {
        return 1;
    }
    return 0;
}

void spfa(int s, int n, int *dis)
{
    memset(vis, 0, sizeof(vis));
    
    for (int i = 0; i < n; i++)
    {
        dis[i] = INF;
    }
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty())
    {
        s = q.front();
        q.pop();
        vis[s] = 0;
        for (int i = 0; i < n; i++)
        {
            if (dis[i] > dis[s] + g[s][i])
            {
                dis[i] = dis[s] + g[s][i];
                if (!vis[i])
                {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    
    int n;
    while (T--)
    {
        scanf("%d", &n);
        
        int x, y, r;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &x, &y, &r);
            light[i].x = x;
            light[i].y = y;
            light[i].r = r;
        }
        //  建无向图
        for (int i = 0; i < n; i++)
        {
            g[i][i] = 0;
            for (int j = 0; j < i; j++)
            {
                if (judge(i, j))
                {
                    g[i][j] = g[j][i] = 1;
                }
                else
                {
                    g[i][j] = g[j][i] = INF;
                }
            }
        }
        spfa(0, n, dist[0]);
        spfa(1, n, dist[1]);
        spfa(2, n, dist[2]);
        
        int ans = INF;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, dist[0][i] + dist[1][i] + dist[2][i]);
        }
        
        if (ans < INF)
        {
            printf("%d\n", n - ans - 1);
        }
        else
        {
            printf("-1\n");
        }
    }
    
    return 0;
}
