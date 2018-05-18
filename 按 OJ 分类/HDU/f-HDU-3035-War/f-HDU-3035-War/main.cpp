//
//  main.cpp
//  f-HDU-3035-War
//
//  Created by ZYJ on 2016/12/11.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 1000100;
const int MAXM = 7000000;
const int INF = 0x3f3f3f3f;

struct node
{
    int v, d;
    node(int _v, int _d) : v(_v), d(_d) {}
    bool operator < (const node a) const
    {
        return a.d < d;
    }
};

int n, m, en, S, T;
int head[MAXN];

struct Edge
{
    int v, w, next;
    Edge() {}
    Edge(int _v, int _w, int _next) : v(_v), w(_w), next(_next) {}
} e[MAXM];

inline void add(int u, int v, int w)
{
    e[en].v = v;
    e[en].w = w;
    e[en].next = head[u];
    head[u] = en++;
    e[en].v = u;
    e[en].w = w;
    e[en].next = head[v];
    head[v] = en++;
}

void initGraph()
{
    en = S = 0;
    T = n * m * 4 + 1;
    for (int i = S; i <= T; i++)
    {
        head[i] = -1;
    }
    
    int x, y, z;
    for (int j = 0; j < m; j++)
    {
        x = j * 4 + 1;
        scanf("%d", &z);
        add(S, x, z);
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            y = (i * m + j) * 4 + 1;
            x = y - m * 4 + 3;
            scanf("%d", &z);
            add(x, y, z);
        }
    }
    for (int j = 0; j < m; j++)
    {
        x = ((n - 1) * m + j) * 4 + 4;
        scanf("%d", &z);
        add(x, T, z);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &z);
        add(i * m * 4 + 2, T, z);
        for (int j = 1; j < m; j++)
        {
            y = (i * m + j) * 4 + 2;
            x = y - 3;
            scanf("%d", &z);
            add(x, y, z);
        }
        scanf("%d", &z);
        add(S, (i + 1) * m * 4 - 1, z);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            x = (i * m + j) * 4 + 1;
            scanf("%d", &z);
            add(x, x + 1, z);
            scanf("%d", &z);
            add(x, x + 2, z);
        }
        for (int j = 0; j < m; j++)
        {
            x = (i * m + j) * 4 + 4;
            scanf("%d", &z);
            add(x, x - 2, z);
            scanf("%d", &z);
            add(x, x - 1, z);
        }
    }
}

int dis[MAXN];
bool vis[MAXN];

void dijstra()
{
    for (int i = S; i <= T; i++)
    {
        dis[i] = INF;
        vis[i] = 0;
    }
    dis[S] = 0;
    
    priority_queue<node> q;
    q.push(node(S,0));
    while (!q.empty())
    {
        int u = q.top().v;
        q.pop();
        if (u == T)
        {
            break;
        }
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (int i = head[u]; i != -1; i = e[i].next)
        {
            int v = e[i].v;
            if (!vis[v] && dis[v] > dis[u] + e[i].w)
            {
                dis[v] = dis[u] + e[i].w;
                q.push(node(v, dis[v]));
            }
        }
    }
    
    printf("%d\n", dis[T]);
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        initGraph();
        dijstra();
    }
    
    return 0;
}
