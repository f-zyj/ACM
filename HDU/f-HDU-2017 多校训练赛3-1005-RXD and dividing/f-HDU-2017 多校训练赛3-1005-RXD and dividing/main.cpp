//
//  main.cpp
//  f-HDU-2017 多校训练赛3-1005-RXD and dividing
//
//  Created by ZYJ on 2017/8/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1e6 + 10;

typedef long long ll;

int n, k;
int tot;
ll ans;
bool vis[MAXN];
int fount[MAXN], sz[MAXN], dis[MAXN];
int que[MAXN], pre[MAXN];

struct Edge
{
    int to, dis, net;

    Edge(int a = 0, int b = 0, int c = 0) : to(a), dis(b), net(c) {}
} edge[MAXN << 1];

void add(int u, int v, int w)
{
    edge[tot] = Edge(v, w, fount[u]);
    fount[u] = tot++;
}

void bfs(int src)
{
    memset(vis, 0, sizeof(vis));
    
    int head = 0, tail = 0;
    que[tail++] = src;
    vis[src] = true;
    
    while (tail > head)
    {
        int u = que[head++];
        sz[u] = 1;
        for (int i = fount[u]; i != -1; i = edge[i].net)
        {
            Edge e = edge[i];
            int v = e.to;
            if (vis[v])
            {
                continue;
            }
            vis[v] = true;
            que[tail++] = v;
            pre[v] = u;
            dis[v] = e.dis;
        }
    }
    for (int i = tail - 1; i >= 0; --i)
    {
        sz[pre[que[i]]] += sz[que[i]];
    }
}

void solve()
{
    bfs(1);
    ans = 0;
    for (int i = 2; i <= n; ++i)
    {
        ans += (ll)dis[i] * min(sz[i], k);
    }
}

int main()
{
    while (~scanf("%d%d", &n, &k))
    {
        memset(fount, -1, sizeof(fount));
        
        tot = 0;
        int u, v, w;
        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        
        solve();
        
        printf("%lld\n", ans);
    }
    
    return 0;
}

