//
//  main.cpp
//  f-51Nod-1443-路径和树
//
//  Created by ZYJ on 2017/9/24.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 10;

int n, m;
int vis[MAXN];
int pre[MAXN];
int bz[MAXN];
ll dist[MAXN];

vector<pair<int, ll> > vpil[MAXN];
queue<int> qi;

struct Edge
{
    int u, v;
    ll cost;
    Edge(int U = -1, int V = -1, ll C = -1)
    {
        u = U;
        v = V;
        cost = C;
    }

    bool operator < (const Edge &x) const
    {
        return cost < x.cost;
    }
};

vector <Edge> edge;

int find(int x)
{
    if (x == pre[x])
    {
        return x;
    }
    else
    {
        return pre[x] = find(pre[x]);
    }
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
    {
        return ;
    }
    pre[x] = pre[y];
}

void spfa(int star)
{
    memset(dist, -1, sizeof(dist));
    memset(vis, 0, sizeof(vis));

    while (!qi.empty())
    {
        qi.pop();
    }
    dist[star] = 0;
    vis[star] = 1;
    qi.push(star);
    while (!qi.empty())
    {
        int now = qi.front();
        qi.pop();
        vis[now] = 0;
        int sz = (int)vpil[now].size();
        for (int i = 0; i < sz; i++)
        {
            int v = vpil[now][i].first;
            ll cost = vpil[now][i].second;
            if (dist[v] == -1 || dist[v] > dist[now] + cost)
            {
                dist[v] = dist[now] + cost;
                if (!vis[v])
                {
                    vis[v] = 1;
                    qi.push(v);
                }
            }
        }
    }
}

ll Kruskal()
{
    ll ret = 0;
    memset(bz, 0, sizeof(bz));
    sort(edge.begin(), edge.end());
    
    int sz = (int)edge.size();
    for (int i = 0; i < sz; i++)
    {
        int u = edge[i].u, v = edge[i].v;
        ll cost = edge[i].cost;
        if (bz[v] || find(u) == find(v))
        {
            continue;
        }
        bz[v] = 1;
        merge(u, v);
        ret += cost;
    }
    
    return ret;
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 0; i <= n; i++)
        {
            vpil[i].clear();
            pre[i] = i;
        }
        
        int u, v, cost;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &cost);
            vpil[u].push_back(make_pair(v, (ll)cost));
            vpil[v].push_back(make_pair(u, (ll)cost));
        }
        
        int star;
        scanf("%d", &star);
        
        spfa(star);
        edge.clear();
        
        for (int i = 1; i <= n; i++)
        {
            int sz = (int)vpil[i].size();
            for (int j = 0; j < sz; j++)
            {
                
                int v = vpil[i][j].first;
                ll cost = vpil[i][j].second;
                if (dist[v] == dist[i] + cost)
                {
                    edge.push_back(Edge(i, v, cost));
                }
            }
        }
        
        printf("%lld\n", Kruskal());
    }
    
    return 0;
}
