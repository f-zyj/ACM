//
//  main.cpp
//  f-HDU-2017 多校训练赛10-1011-Two Paths
//
//  Created by ZYJ on 2017/8/28.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int MAXN = 1e5 + 5;

int n, m;
int tot, st, ed, k;
ll dis[MAXN];
int hed1[MAXN];
int hed2[MAXN];
bool vis[MAXN];

struct Edge
{
    int u, v, nxt1, nxt2;
    ll c;
    Edge() {}
    Edge(int _u, int _v, ll _c) : u(_u), v(_v), c(_c) {}
} e[MAXN << 1];

struct qnode
{
    int v;
    ll c;
    
    qnode() {}
    
    qnode(int _v, ll _c) : v(_v), c(_c) {}
    
    bool operator < (const qnode &rhs) const
    {
        return c + dis[v] > rhs.c + dis[rhs.v];
    }
};

void addedge(int u, int v, ll c)
{
    e[tot] = Edge(u, v, c);
    e[tot].nxt1 = hed1[u];
    hed1[u] = tot;
    e[tot].nxt2 = hed2[v];
    hed2[v] = tot++;
}

void dij(int src)
{
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    
    dis[src] = 0;
    priority_queue<qnode> que;
    que.push(qnode(src, 0));
    
    while (!que.empty())
    {
        qnode pre = que.top();
        que.pop();
        
        if (vis[pre.v])
        {
            continue;
        }
        
        vis[pre.v] = true;
        for (int i = hed2[pre.v]; i != -1; i = e[i].nxt2)
        {
            if (dis[e[i].u] > dis[pre.v] + e[i].c)
            {
                dis[e[i].u] = dis[pre.v] + e[i].c;
                que.push(qnode(e[i].u, 0));
            }
        }
    }
}

ll a_star(int src)
{
    priority_queue<qnode> que;
    
    que.push(qnode(src, 0));
    k--;
    
    while (!que.empty())
    {
        qnode pre = que.top();
        que.pop();
        
        if (pre.v == ed)
        {
            if (k)
            {
                k--;
            }
            else
            {
                return pre.c;
            }
        }
        
        for (int i = hed1[pre.v]; i != -1; i = e[i].nxt1)
        {
            que.push(qnode(e[i].v, pre.c + e[i].c));
        }
    }
    
    return -1;
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        tot = 0;
        memset(hed1, -1, sizeof(hed1));
        memset(hed2, -1, sizeof(hed2));
        
        scanf("%d%d", &n, &m);
        
        int u, v;
        ll c;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%lld", &u, &v, &c);
            addedge(u, v, c);
            addedge(v, u, c);
        }
        
        st = 1, ed = n, k = 2;
        
        dij(ed);
        
        if (st == ed)
        {
            k++;
        }
        
        printf("%lld\n", a_star(st));
    }
    
    return 0;
}
