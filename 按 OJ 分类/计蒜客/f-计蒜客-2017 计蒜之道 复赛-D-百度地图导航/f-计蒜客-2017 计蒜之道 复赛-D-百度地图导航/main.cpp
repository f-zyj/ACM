//
//  main.cpp
//  f-计蒜客-2017 计蒜之道 复赛-D-百度地图导航
//
//  Created by ZYJ on 2017/6/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef long long ll;

const int MAXN = 20005;
const int MAXM = 1e6 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct node
{
    int v, next;
    ll w;
} edge[MAXM];

queue<int> q;
int n, m, k, x, m1, m2, cnt;
int head[MAXN * 3];
int vis[MAXN * 3];
ll dis[MAXN * 3];

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(dis, 0x3f, sizeof(dis));
}

inline void add(int u, int v, ll w)
{
    edge[cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void SPFA(int s, int t)
{
    while (!q.empty())
    {
        q.pop();
    }
    memset(vis, 0, sizeof(vis));
    
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        
        int k = head[u];
        while (k != -1)
        {
            if (dis[edge[k].v] > dis[u] + edge[k].w)
            {
                dis[edge[k].v] = dis[u] + edge[k].w;
                if (vis[edge[k].v] == 0)
                {
                    vis[edge[k].v] = 1;
                    q.push(edge[k].v);
                }
            }
            k = edge[k].next;
        }
    }
}

int main()
{
    init();
    
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &k);
        for (int j = 1; j <= k; j++)
        {
            scanf("%d", &x);
            add(x, n + 2 * i - 1, 0);   //  超级汇点
            add(n + 2 * i, x, 0);       //  超级源点
        }
    }
    
    int a, b;
    ll c;
    scanf("%d", &m1);
    for (int i = 1; i <= m1; i++)
    {
        scanf("%d%d%lld", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    
    scanf("%d", &m2);
    for (int i = 1; i <= m2; i++)
    {
        scanf("%d%d%lld", &a, &b, &c);
        add(n + a * 2 - 1, n + b * 2, c);
        add(n + b * 2 - 1, n + a * 2, c);
    }
    
    int s, t;
    scanf("%d%d", &s, &t);
    
    SPFA(s, t);
    
    if (dis[t] != INF)
    {
        cout << dis[t] << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
    
    return 0;
}
