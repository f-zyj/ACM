//
//  main.cpp
//  f-51Nod-1815-调查任务
//
//  Created by ZYJ on 2017/7/15.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <bitset>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 4e5 + 10;
const int MAXM = 2e6 + 10;

int N, M, Q, S;

struct node
{
    int nt, to;
} E[MAXM], E2[MAXM], E3[MAXM];

int cnt = 0, cnt3 = 0;
int head[MAXN];
int head2[MAXN];
int head3[MAXN];
int cur[MAXN];
int drg[MAXN];  //  度

void add_edge(int u, int v)
{
    E[++cnt] = (node){head[u], v};
    head[u] = cnt;
}

void add_edge_23(int u, int v)
{
    E2[++cnt] = (node){head2[u], v};
    head2[u] = cnt;
    E3[++cnt3] = (node){head3[v], u};
    head3[v] = cnt3;
}

int tot = 0, stop, top;
int dfn[MAXN];
int low[MAXN];
int a[MAXN];
int sta[MAXN];
int st[MAXN];
int id[MAXN];
int pre[MAXN];
bitset<MAXN> vis;

void tarjan(int x)
{
    st[top = 1] = x;
    stop = 0;
    while (top)
    {
        int u = st[top];
        if (!dfn[u])
        {
            dfn[u] = low[u] = ++cnt;
            sta[++stop] = u;
            vis[u] = 1;
        }
        
        if (cur[u])
        {
            int v = E[cur[u]].to;
            if (!dfn[v])
            {
                pre[st[++top] = v] = u;
            }
            else if (vis[v])
            {
                low[u] = min(low[u], dfn[v]);
            }
            cur[u] = E[cur[u]].nt;
        }
        else
        {
            low[pre[u]] = min(low[pre[u]], low[u]);
            if (dfn[u] == low[u])
            {
                ++tot;
                while (sta[stop] != u)
                {
                    vis[sta[stop]] = 0;
                    id[sta[stop]] = tot;
                    --stop;
                }
                vis[u] = 0;
                id[u] = tot;
                --stop;
            }
            --top;
        }
    }
}

int mx[MAXN];
int mx2[MAXN];
int mx3[MAXN];
int que[MAXN];
bitset<MAXN> vis2;

void BFS()
{
    int p = 0, q = 1;
    vis2[que[1] = id[S]] = 1;
    while (p != q)
    {
        int u = que[++p];
        for (int i = head2[u]; i; i = E2[i].nt)
        {
            int v = E2[i].to;
            ++drg[v];
            if (!vis2[v])
            {
                vis2[v] = 1;
                que[++q] = v;
            }
        }
    }
    
    p = 0;
    q = 1;
    que[1] = id[S];
    while (p != q)
    {
        int u = que[++p];
        for (int i = head3[u]; i; i = E3[i].nt)
        {
            int v = E3[i].to;
            if (vis2[v])
            {
                if (mx[v] > mx[u])
                {
                    mx3[u] = mx[u];
                    mx[u] = mx[v];
                }
                else if (mx[v] < mx[u] && mx[v] > mx3[u])
                {
                    mx3[u] = mx[v];
                }
                if (mx3[v] > mx[u])
                {
                    mx3[u] = mx[u];
                    mx[u] = mx3[v];
                }
                else if (mx3[v] < mx[u] && mx3[v] > mx3[u])
                {
                    mx3[u] = mx3[v];
                }
            }
        }
        for (int i = head2[u]; i; i = E2[i].nt)
        {
            int v = E2[i].to;
            mx2[v] = max(mx2[v], mx2[u]);
            if (mx[u] != mx[v])
            {
                mx2[v] = max(mx2[v], min(mx[u], mx[v]));
            }
            else
            {
                mx2[v] = max(mx2[v], max(mx3[u], mx3[v]));
            }
            if (--drg[v] == 0)
            {
                que[++q] = v;
            }
        }
    }
}

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

int main()
{
    scanf("%d%d%d%d", &N, &M, &Q, &S);
    
    for (int i = 1; i <= N; ++i)
    {
        scan_d(a[i]);
    }
    
    int u, v;
    for (int i = 1; i <= M; ++i)
    {
        scan_d(u), scan_d(v);
        add_edge(u, v);
    }
    
    cnt = 0;
    memcpy(cur, head, sizeof(cur));
    memset(mx, -1, sizeof(mx));
    memset(mx2, -1, sizeof(mx2));
    
    for (int i = 1; i <= N; ++i)
    {
        if (!dfn[i])
        {
            tarjan(i);
        }
    }
    
    //  强连通块儿缩点
    cnt = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = head[i]; j; j = E[j].nt)
        {
            if (id[i] != id[E[j].to])
            {
                add_edge_23(id[i], id[E[j].to]);
            }
        }
    }
    
    //  维护所有强连通块儿的最大值和严格次大值
    for (int i = 1; i <= N; ++i)
    {
        int t = id[i];
        if (a[i] > mx[t])
        {
            mx2[t] = mx[t];
            mx[t] = a[i];
        }
        else if (a[i] < mx[t] && a[i] > mx2[t])
        {
            mx2[t] = a[i];
        }
    }
    for (int i = 1; i <= tot; ++i)
    {
        mx3[i] = mx2[i];
    }
    
    BFS();
    
    for (int i = 1; i <= Q; ++i)
    {
        scan_d(u);
        if (!vis2[id[u]])
        {
            printf("-1 ");
        }
        else if (mx2[id[u]] == -1)
        {
            printf("0 ");
        }
        else
        {
            printf("%d ", mx2[id[u]]);
        }
    }
    putchar(10);
    
    return 0;
}
