//
//  main.cpp
//  ICPC Asia Regional Shenyang Online-1008-transaction transaction transaction
//
//  Created by ZYJ on 2017/9/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 7;
const int MAXM = 2e5 + 7;

int n, tol;
int dis[MAXN];
int vis[MAXN];
int hed[MAXN];
int pre[MAXN];

struct Node
{
    int v, w, next;
} st[MAXM << 1];

void AddEdge(int u, int v, int w)
{
    st[tol].v = v;
    st[tol].w = w;
    st[tol].next = hed[u];
    hed[u] = tol++;
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
        for (int i = hed[u]; i != -1; i = st[i].next)
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
    memset(hed, -1, sizeof(hed));
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        init();
        
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", pre + i);
            AddEdge(0, i, 0);
        }
        
        int u, v, w;
        for (int i = 1; i < n; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            AddEdge(u, v, pre[v] - pre[u] - w);
            AddEdge(v, u, pre[u] - pre[v] - w);
        }
        
        spfa(0);
        
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, dis[i]);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
