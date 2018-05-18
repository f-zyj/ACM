//
//  main.cpp
//  f-51Nod-1681-公共祖先
//
//  Created by ZYJ on 2017/7/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 10;
const int MAXM = 2e6 + 10;

int n, tot, sz;
int LS[MAXN], RS[MAXN]; //  LS[i]: L 树的 i 结点的 dfs 序的起点 RS[i]: 同理
int LE[MAXN], RE[MAXN]; //  LE[i]: L 树的 i 结点的 dfs 序的终点 RE[i]: 同理
int tmp[MAXN];          //  tmp[i]: R 树中 dfs 序为 i 的结点 u 在 L 树 dfs 序中对应的位置
int pos[MAXN];          //  pos[i]: L 树中 i 结点的 dfs 序的位置
int vis[MAXN];
int head[MAXN];
int root[MAXN];

struct node
{
    int l, r, c;
} tree[MAXM];

struct Edge
{
    int to, nt;
} e[MAXN];

void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
}

void addedge(int u, int v)
{
    e[tot].to = v;
    e[tot].nt = head[u];
    head[u] = tot++;
}

void dfs(int u, int pre, int flag)
{
    if (flag)
    {
        RS[u] = ++sz;
        tmp[sz] = pos[u];
    }
    else
    {
        LS[u] = ++sz;
        pos[u] = sz;
    }

    int v;
    for (int i = head[u]; i != -1; i = e[i].nt)
    {
        v = e[i].to;
        if (v != pre)
        {
            dfs(v, u, flag);
        }
    }
    if (flag)
    {
        RE[u] = sz;
    }
    else
    {
        LE[u] = sz;
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

void update(int &rt, int l, int r, int num)
{
    tree[++sz] = tree[rt];
    rt = sz;
    tree[rt].c++;
    
    if (l == r)
    {
        return ;
    }
    int mid = (l + r) >> 1;
    if (num <= mid)
    {
        update(tree[rt].l, l, mid, num);
    }
    else
    {
        update(tree[rt].r, mid + 1, r, num);
    }
}

int query(int x, int y, int L, int R, int l, int r)
{
    if (L <= l && R >= r)
    {
        return tree[y].c - tree[x].c;
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m)
    {
        ret += query(tree[x].l, tree[y].l, L, R, l, m);
    }
    if (R > m)
    {
        ret += query(tree[x].r, tree[y].r, L, R, m + 1, r);
    }
    return ret;
}

int main()
{
    scan_d(n);
    
    int u, v, r = 0;
    
    init();
    for (int i = 1; i < n; i++)
    {
        scan_d(u), scan_d(v);
        addedge(u, v);
        vis[v] = 1;
    }

    sz = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            r = i;
            break;
        }
    }
    dfs(r, 0, 0);
    
    init();
    for (int i = 1; i < n; i++)
    {
        scan_d(u), scan_d(v);
        addedge(u, v);
        vis[v] = 1;
    }
    
    sz = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            r = i;
            break;
        }
    }
    dfs(r, 0, 1);
    
    root[0] = 0, sz = 0;
    for (int i = 1; i <= n; i++)
    {
        root[i] = root[i - 1];
        update(root[i], 1, n, tmp[i]);
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = query(root[RS[i] - 1], root[RE[i]], LS[i], LE[i], 1, n);
        ans += 1LL * (x - 1) * (x - 2) / 2;
    }
    
    printf("%lld\n",ans);
    
    return 0;
}

