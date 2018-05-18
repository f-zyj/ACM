//
//  main.cpp
//  f-HDU-5889-Barricade
//
//  Created by ZYJ on 2017/6/28.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 2005;
const int INF = 0x3f3f3f3f;

struct node
{
    int v, w;
    node(int v_, int w_) : v(v_), w(w_) {};
};

int n, m, vs, vt;
int s, t;
int dis[MAXN];
int vis[MAXN];
vector<node> e[MAXN];

void spfa()
{
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i].v;
            if (dis[v] > dis[u] + 1)
            {
                dis[v] = dis[u] + 1;
                if (!vis[v])
                {
                    q.push(v);
                }
                vis[v] = 1;
            }
        }
    }
}

struct edge
{
    int from, to, cap, flow;
    edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

struct Dinic
{
    int s, t;
    vector<edge> edges;     //  边数的两倍
    vector<int> G[MAXN];    //  邻接表，G[i][j]表示结点i的第j条边在e数组中的序号
    bool vis[MAXN];         //  BFS使用
    int dis[MAXN];          //  从起点到i的距离
    int cur[MAXN];          //  当前弧下标
    
    void init()
    {
        for (int i = 0; i <= n + 1; i++)
        {
            G[i].clear();
        }
        edges.clear();
    }
    
    void addEdge(int from, int to, int cap)
    {
        edges.push_back(edge(from, to, cap, 0));
        edges.push_back(edge(to, from, 0, 0));
        int sz = (int)edges.size();
        G[from].push_back(sz - 2);
        G[to].push_back(sz - 1);
    }
    
    bool bfs()
    {
        memset(vis, 0, sizeof(vis));
        
        queue<int> q;
        q.push(s);
        dis[s] = 0;
        vis[s] = 1;
        
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < G[x].size(); i++)
            {
                edge &e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow)
                {
                    vis[e.to] = 1;
                    dis[e.to] = dis[x] + 1;
                    q.push(e.to);
                }
            }
        }
        
        return vis[t];
    }
    
    int dfs(int x, int a)
    {
        if (x == t || a == 0)
        {
            return a;
        }
        int flow = 0, f = 0;
        for (int &i = cur[x]; i < G[x].size(); i++)
        {
            edge &e = edges[G[x][i]];
            if (dis[x] + 1 == dis[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0)
            {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0)
                {
                    break;
                }
            }
        }
        
        return flow;
    }
    
    int Maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;
        int flow = 0;
        
        while (bfs())
        {
            memset(cur, 0, sizeof(cur));
            flow += dfs(s, INF);
        }
        
        return flow;
    }
} dc;

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; i++)
        {
            e[i].clear();
        }
        int u, v, w;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            e[u].push_back(node(v, w));
            e[v].push_back(node(u, w));
        }
        
        s = 1, t = n;
        spfa();
        
        dc.init();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < e[i].size(); j++)
            {
                if (dis[e[i][j].v] == dis[i] + 1)
                {
                    dc.addEdge(i, e[i][j].v, e[i][j].w);
                }
            }
        }
        
        printf("%d\n", dc.Maxflow(s, t));
    }
    
    return 0;
}
