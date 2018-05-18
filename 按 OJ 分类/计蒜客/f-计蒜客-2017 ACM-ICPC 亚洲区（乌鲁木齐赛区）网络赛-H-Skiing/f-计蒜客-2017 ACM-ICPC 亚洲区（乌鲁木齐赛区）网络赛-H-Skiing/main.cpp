//
//  main.cpp
//  f-计蒜客-2017 ACM-ICPC 亚洲区（乌鲁木齐赛区）网络赛-H-Skiing
//
//  Created by ZYJ on 2017/9/9.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 1e4 + 7;
const int MAXM = 2e5 + 7;

int n, m, tol;
int dis[MAXN];
int vis[MAXN];
int head[MAXN];

struct Node
{
    int v, w, next;
} st[MAXM];

void add_edge(int u, int v, int w)
{
    st[tol].v = v;
    st[tol].w = w;
    st[tol].next = head[u];
    head[u] = tol++;
}

void spfa(int s)
{
    queue<int> q;
    memset(dis, -1, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s] = 0;
    vis[s] = 1;
    q.push(s);
    
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i != -1; i = st[i].next)
        {
            int v = st[i].v;
            if (dis[v] < dis[u] + st[i].w)
            {
                dis[v] = dis[u] + st[i].w;
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}

void init()
{
    tol = 0;
    memset(head, -1, sizeof(head));
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        init();
        scanf("%d%d", &n, &m);
        
        int u, v, w;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
        }
        for (int i = 1; i <= n; i++)
        {
            add_edge(0, i, 0);
            add_edge(i, n + 1, 0);
        }
        spfa(0);
        printf("%d\n", dis[n + 1]);
    }
    
    return 0;
}
