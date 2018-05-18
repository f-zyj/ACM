//
//  main.cpp
//  f-51Nod-1199-Money out of Thin Air
//
//  Created by ZYJ on 2017/3/24.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

#define lson l, mid, x << 1
#define rson mid + 1, r, x << 1 | 1
#define ll long long

using namespace std;

const int MAXN = 5e4 + 10;

struct edge
{
    int to;
    int nt;
    
    edge()
    {
        nt = -1;
    }
};

int tot = 0;
int head[MAXN];
edge eg[MAXN << 1];

int read()
{
    int x = 0;
    char c = getchar();
    while (!isdigit(c))
    {
        c = getchar();
    }
    while (isdigit(c))
    {
        x = x * 10 + c - '0', c = getchar();
    }
    return x;
}

void add(int p, int pos)
{
    eg[tot].to = pos;
    eg[tot].nt = head[p];
    head[p] = tot++;
    eg[tot].to = p;
    eg[tot].nt = head[pos];
    head[pos] = tot++;
}

int N, M;
int size[MAXN];
int son[MAXN];
int idx[MAXN];  //  idx[v] 表示 v 和其父节点的连边在线段树中的对应关系
int id[MAXN];   //  id[v] 表示 v 在原树中的对应关系
int w[MAXN];

struct node
{
    ll sum;
    ll add;
};

node tree[MAXN << 2];

//  查找重边
void dfsI(int x = 1, int pre = 0)
{
    size[x] = 1;
    for (int nt = head[x]; nt != -1; nt = eg[nt].nt)
    {
        if (eg[nt].to != pre)
        {
            dfsI(eg[nt].to, x);
            size[x] += size[eg[nt].to];
            if (!son[x] || size[eg[nt].to] > size[son[x]])
            {
                son[x] = eg[nt].to;
            }
        }
    }
}

//  构造重链
void dfsII(int x = 1)
{
    id[++id[0]] = x;
    idx[x] = id[0];
    if (son[x])
    {
        dfsII(son[x]);
    }
    for (int nt = head[x]; nt != -1; nt = eg[nt].nt)
    {
        if (!idx[eg[nt].to])
        {
            dfsII(eg[nt].to);
        }
    }
}

void build(int l = 1, int r = N, int x = 1)
{
    tree[x].add = -1;
    if (l == r)
    {
        tree[x].sum = w[id[l]];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    tree[x].sum = tree[x << 1].sum + tree[x << 1 | 1].sum;
}

void pushdown(int x, int cnt)
{
    if (tree[x].add != -1)
    {
        if (tree[x << 1].add != -1)
        {
            tree[x << 1].add += tree[x].add;
        }
        else
        {
            tree[x << 1].add = tree[x].add;
        }
        if (tree[x << 1 | 1].add != -1)
        {
            tree[x << 1 | 1].add += tree[x].add;
        }
        else
        {
            tree[x << 1 | 1].add = tree[x].add;
        }
        tree[x << 1].sum += tree[x].add * (cnt - (cnt >> 1));
        tree[x << 1 | 1].sum += tree[x].add * (cnt >> 1);
        tree[x].add = -1;
    }
}

//  更新单结点
void update1(int p, int add, int l, int r, int x)
{
    if (l == r)
    {
        tree[x].sum += add;
        return ;
    }
    pushdown(x, r - l + 1);
    int mid = (l + r) >> 1;
    p <= mid ? update1(p, add, lson) : update1(p, add, rson);
    tree[x].sum = tree[x << 1].sum + tree[x << 1 | 1].sum;
}

void update2(int tl, int tr, int add, int l, int r, int x)
{
    if (tl <= l && tr >= r)
    {
        if (tree[x].add != -1)
        {
            tree[x].add += add;
        }
        else
        {
            tree[x].add = add;
        }
        tree[x].sum += (ll)add * (r - l + 1);
        return ;
    }
    pushdown(x, r - l + 1);
    int mid = (l + r) >> 1;
    if (tl <= mid)
    {
        update2(tl, tr, add, lson);
    }
    if (tr > mid)
    {
        update2(tl, tr, add, rson);
    }
    tree[x].sum = tree[x << 1].sum + tree[x << 1 | 1].sum;
}

ll query1(int p, int l, int r, int x)
{
    if (l == r)
    {
        return tree[x].sum;
    }
    pushdown(x, r - l + 1);
    int mid = (l + r) >> 1;
    return p <= mid ? query1(p, lson) : query1(p, rson);
}

ll query2(int tl, int tr, int l, int r, int x)
{
    if (tl <= l && tr >= r)
    {
        return tree[x].sum;
    }
    pushdown(x, r - l + 1);
    int mid = (l + r) >> 1;
    ll ans = 0;
    if (tl <= mid)
    {
        ans += query2(tl, tr, lson);
    }
    if (tr > mid)
    {
        ans += query2(tl, tr, rson);
    }
    return ans;
}

int main()
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    memset(head, -1, sizeof(head));
    
    N = read();
    M = read();
    
    int p;
    for (int i = 2; i <= N; i++)
    {
        p = read() + 1;
        w[i] = read();
        add(p, i);
    }
    
    dfsI();
    dfsII();
    build();
    
    int x, y, z;
    char s[3];
    for (int i = 1; i <= M; i++)
    {
        scanf("%s", s);
        x = read() + 1;
        y = read();
        z = read();
        if (s[0] == 'S')
        {
            if (query1(idx[x], 1, N, 1) < y)
            {
                update1(idx[x], z, 1, N, 1);
            }
        }
        else
        {
            ll sum = query2(idx[x], idx[x] + size[x] - 1, 1, N, 1);
            if (sum >= (ll)y * size[x])
            {
                continue;
            }
            update2(idx[x], idx[x] + size[x] - 1, z, 1, N, 1);
        }
    }
    
    for (int i = 1; i <= N; i++)
    {
        printf("%lld\n", query1(idx[i], 1, N, 1));
    }
    
    return 0;
}
