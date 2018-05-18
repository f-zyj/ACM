//
//  main.cpp
//  f-HDU-3768-Shopping
//
//  Created by ZYJ on 2016/12/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;
const int MAXM = 15;

int k;
int head[MAXN];
int head_[MAXM];
int lowcost[MAXM][MAXN];
bool vis[MAXN];
bool vis_[MAXM];


struct
{
    int v;
    int w;
    int next;
} edge[MAXN * 2], dege_[MAXM * MAXM];

void add(int u, int v, int w)
{
    edge[k].v = v;
    edge[k].w = w;
    edge[k].next = head[u];
    head[u] = k++;
}

void add_(int u, int v, int w)
{
    dege_[k].v = v;
    dege_[k].w = w;
    dege_[k].next = head_[u];
    head_[u] = k++;
}

void spfa(int s, int n, int *dis)
{
    int st,ed;
    queue<int> x;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        dis[i] = INF;
    }
    dis[s] = 0;
    x.push(s);
    while (!x.empty())
    {
        st = x.front();
        x.pop();
        vis[st] = false;
        for (int i = head[st]; i != -1; i = edge[i].next)
        {
            ed = edge[i].v;
            if (dis[ed] > dis[st] + edge[i].w)
            {
                dis[ed] = dis[st] + edge[i].w;
                if (!vis[ed])
                {
                    vis[ed] = true;
                    x.push(ed);
                }
            }
        }
    }
}

int dfs(int s, int res, int n, int c)
{
    int ans = INF;
    vis_[s] = true;
    if (s == 0)
    {
        if (c == n)
        {
            return res;
        }
        else
        {
            return INF;
        }
    }
    for (int i = head_[s]; i != -1; i = dege_[i].next)
    {
        int v = dege_[i].v;
        if (!vis_[v] || v == 0)
        {
            ans = min(ans, dfs(v, res + dege_[i].w, n, c + 1));
        }
    }
    vis_[s] = false;
    return ans;
}

int main()
{
    int t;
    cin >> t;
    
    int n, m;
    int p[MAXM], q, cnt, ans;
    while (t--)
    {
        k = cnt = 0;
        ans = INF;
        memset(head, -1, sizeof(head));
        memset(head_, -1, sizeof(head_));
        
        cin >> n >> m;
        
        int u, v, w;
        while (m--)
        {
            scanf("%d%d%d", &u, &v, &w);
            add(u,v,w);
            add(v,u,w);
        }
        
        cin >> q;
        p[cnt] = 0;
        spfa(0, n, lowcost[cnt]);
        cnt++;
        while (q--)
        {
            scanf("%d", p + cnt);
            spfa(p[cnt], n, lowcost[cnt]);
            cnt++;
        }
        k = 0;
        for (int i = 0; i < cnt; i++)
        {
            for (int j = 0; j < cnt; j++)
            {
                if (i != j)
                {
                    add_(i, j, lowcost[i][p[j]]);
                }
            }
        }
        for (int i = 1; i < cnt; i++)
        {
            memset(vis_, false, sizeof(vis_));
            vis_[0] = true;
            ans = min(ans, dfs(i, lowcost[0][p[i]], cnt, 1));
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
