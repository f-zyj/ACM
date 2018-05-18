//
//  main.cpp
//  f-HDU-2017 多校训练赛9-1006-Senior Pan
//
//  Created by ZYJ on 2017/8/28.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e5 + 10;
const int MAGIC = 20;

struct Edge
{
    int v, val, net;
} edg[MAXN];

struct node
{
    int x;
    ll step;
};

int n, m, k, tot;
int hed[MAXN];
int a[MAXN];
int vis[MAXN];
ll dis[MAXN];
priority_queue<node> pqn;

bool operator < (node a, node b)
{
    return a.step > b.step;
}

void addedge(int u, int v, int val)
{
    edg[tot].v = v;
    edg[tot].val = val;
    edg[tot].net = hed[u];
    hed[u] = tot++;
}

ll dijkstra()
{
    while (!pqn.empty())
    {
        node now = pqn.top();
        pqn.pop();
        
        if (vis[now.x])
        {
            return now.step;
        }
        for (int i = hed[now.x]; ~i; i = edg[i].net)
        {
            int next = edg[i].v;
            if (dis[next] > now.step + edg[i].val)
            {
                dis[next] = now.step + edg[i].val;
                pqn.push(node{next, dis[next]});
            }
        }
    }
    
    return INF;
}

void init()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    
    while (!pqn.empty())
    {
        pqn.pop();
    }
}

ll solve(int k)
{
    ll ans = INF;
    for (int i = 0; i < MAGIC; i++)
    {
        init();
        for (int j = 0; j < k; j++)
        {
            if (a[j] & (1 << i))
            {
                pqn.push(node{a[j], 0});
                dis[a[j]] = 0;
            }
            else
            {
                vis[a[j]] = 1;
            }
        }
        ans = min(ans, dijkstra());
        
        init();
        for (int j = 0; j < k; j++)
        {
            if (a[j] & (1 << i))
            {
                vis[a[j]] = 1;
            }
            else
            {
                pqn.push(node{a[j], 0});
                dis[a[j]] = 0;
            }
        }
        ans = min(ans, dijkstra());
    }
    
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    
    for (int ce = 1; ce <= T; ce++)
    {
        tot = 0;
        memset(hed, -1, sizeof(hed));
        
        scanf("%d%d", &n, &m);
        
        int u, v, w;
        while (m--)
        {
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
        }
        
        scanf("%d", &k);
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &a[i]);
        }
        
        printf("Case #%d: %lld\n", ce, solve(k));
    }
    
    return 0;
}
