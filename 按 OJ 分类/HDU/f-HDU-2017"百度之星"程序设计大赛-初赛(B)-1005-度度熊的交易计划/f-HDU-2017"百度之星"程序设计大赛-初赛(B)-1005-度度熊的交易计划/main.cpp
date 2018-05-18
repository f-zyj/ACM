//
//  main.cpp
//  f-HDU-2017"百度之星"程序设计大赛-初赛(B)-1005-度度熊的交易计划
//
//  Created by ZYJ on 2017/8/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 505;
const int MAXM = 400005;
const int INF = 0x3f3f3f3f;

struct Edge
{
    int v, c, w, next;
    Edge() {}
    Edge(int v, int c, int w, int next) : v(v), c(c), w(w), next(next) {}
} E[MAXM];

int flow, cost, s, t, T, cnt;
int hed[MAXN];
int cap[MAXN];
int vis[MAXN];
int dis[MAXN];
int cur[MAXN];
queue<int> q;

void addedges(int u, int v, int c, int w)
{
    E[cnt] = Edge(v, c, w, hed[u]);
    hed[u] = cnt++;
    E[cnt] = Edge(u, 0, -w, hed[v]);
    hed[v] = cnt++;
}

bool spfa()
{
    memset(dis, INF, sizeof dis);
    cur[s] = -1;
    vis[s] = ++T;
    cap[s] = INF;
    dis[s] = 0;
    q.push(s);
    
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = T - 1;
        for (int e = hed[u]; ~e; e = E[e].next)
        {
            int v = E[e].v, c = E[e].c, w = E[e].w;
            if (c && dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                cap[v] = min(cap[u], c);
                cur[v] = e;
                if (vis[v] != T)
                {
                    vis[v] = T;
                    q.push(v);
                }
            }
        }
    }
    if (dis[t] > 0)
    {
        return false;
    }
    
    cost += cap[t] * dis[t];
    flow += cap[t];
    for (int e = cur[t]; ~e; e = cur[E[e ^ 1].v])
    {
        E[e].c -= cap[t];
        E[e ^ 1].c += cap[t];
    }
    
    return true;
}

int mfmc()
{
    flow = cost = 0;
    while (spfa()) ;
    return cost;
}

void init()
{
    cnt = T = 0;
    memset(hed, -1, sizeof hed);
    memset(vis, 0, sizeof vis);
}

int n, m;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int g[MAXN][MAXN];

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

void work()
{
    init();
    
    for (int i = 1; i <= n; i++)
    {
        scan_d(a[i]), scan_d(b[i]), scan_d(c[i]), scan_d(d[i]);
    }
    
    s = 0, t = n + 1;
    for (int i = 0; i <= t; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            if (i == j)
            {
                g[i][j] = 0;
            }
            else
            {
                g[i][j] = INF;
            }
        }
    }
    int u, v, k;
    for (int i = 1; i <= m; i++)
    {
        scan_d(u), scan_d(v), scan_d(k);
        if (g[u][v] > k)
        {
            g[u][v] = g[v][u] = k;
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        addedges(i, t, b[i], a[i]);
        addedges(s, i, d[i], -c[i]);
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j && g[i][j] != INF)
            {
                addedges(i, j, INF, g[i][j]);
            }
        }
    }
    int ans = -mfmc();
    
    printf("%d\n", ans);
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        work();
    }
    
    return 0;
}
