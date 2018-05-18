//
//  main.cpp
//  f-莫队算法
//
//  Created by ZYJ on 16/7/24.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

//  分块

//const int MAXN = 50010;
//const int MAXM = 50010;
//
//struct Query
//{
//    int L, R, id;
//} node[MAXM];
//
//long long gcd(long long a, long long b)
//{
//    if (b == 0)
//    {
//        return a;
//    }
//    return gcd(b, a % b);
//}
//
//struct Ans
//{
//    long long a, b; //  分数a/b
//    void reduce()   //  分数化简
//    {
//        long long d = gcd(a, b);
//        a /= d;
//        b /= d;
//        return ;
//    }
//} ans[MAXM];
//
//int a[MAXN];
//int num[MAXN];
//int n, m, unit;
//
//bool cmp(Query a, Query b)
//{
//    if (a.L / unit != b.L / unit)
//    {
//        return a.L / unit < b.L / unit;
//    }
//    else
//    {
//        return a.R < b.R;
//    }
//}
//
//void work()
//{
//    long long temp = 0;
//    memset(num, 0, sizeof(num));
//    int L = 1;
//    int R = 0;
//    for (int i = 0; i < m; i++)
//    {
//        while (R < node[i].R)
//        {
//            R++;
//            temp -= (long long)num[a[R]] * num[a[R]];
//            num[a[R]]++;
//            temp += (long long)num[a[R]] * num[a[R]];
//        }
//        while (R > node[i].R)
//        {
//            temp -= (long long)num[a[R]] * num[a[R]];
//            num[a[R]]--;
//            temp += (long long)num[a[R]] * num[a[R]];
//            R--;
//        }
//        while (L < node[i].L)
//        {
//            temp -= (long long)num[a[L]] * num[a[L]];
//            num[a[L]]--;
//            temp += (long long)num[a[L]] * num[a[L]];
//            L++;
//        }
//        while (L > node[i].L)
//        {
//            L--;
//            temp -= (long long)num[a[L]] * num[a[L]];
//            num[a[L]]++;
//            temp += (long long)num[a[L]] * num[a[L]];
//        }
//        ans[node[i].id].a = temp - (R - L + 1);
//        ans[node[i].id].b = (long long)(R - L + 1) * (R - L);
//        ans[node[i].id].reduce();
//    }
//    return ;
//}
//
//int main()
//{
//    while (scanf("%d%d", &n, &m) == 2)
//    {
//        for (int i = 1; i <= n; i++)
//        {
//            scanf("%d", &a[i]);
//        }
//        for (int i = 0; i < m; i++)
//        {
//            node[i].id = i;
//            scanf("%d%d", &node[i].L, &node[i].R);
//        }
//        unit = (int)sqrt(n);
//        sort(node,node+m,cmp);
//        work();
//        for (int i = 0; i < m; i++)
//        {
//            printf("%lld/%lld\n", ans[i].a, ans[i].b);
//        }
//    }
//    return 0;
//}

//  MST的dfs顺序求解

const int MAXN = 50010;
const int MAXM = 50010;
const int INF = 0x3f3f3f3f;

struct Point
{
    int x, y, id;
} p[MAXN], pp[MAXN];

bool cmp(Point a, Point b)
{
    if (a.x != b.x)
    {
        return a.x < b.x;
    }
    else
    {
        return a.y < b.y;
    }
}

//  树状数组,找y-x大于当前的,但是y+x最小的
struct BIT
{
    int min_val,pos;
    void init()
    {
        min_val = INF;
        pos = -1;
        return ;
    }
} bit[MAXN];

struct Edge
{
    int u, v, d;
} edge[MAXN << 2];

bool cmpedge(Edge a, Edge b)
{
    return a.d < b.d;
}

int tot;
int n;
int F[MAXN];

int find(int x)
{
    if (F[x] == -1)
    {
        return x;
    }
    else
    {
        return F[x] = find(F[x]);
    }
}

void addedge(int u, int v, int d)
{
    edge[tot].u = u;
    edge[tot].v = v;
    edge[tot++].d = d;
    return ;
}

struct Graph
{
    int to,next;
} e[MAXN << 1];

int total, head[MAXN];

void _addedge(int u, int v)
{
    e[total].to = v;
    e[total].next = head[u];
    head[u] = total++;
    return ;
}

int lowbit(int x)
{
    return x & (-x);
}

void update(int i, int val, int pos)
{
    while (i > 0)
    {
        if (val < bit[i].min_val)
        {
            bit[i].min_val = val;
            bit[i].pos = pos;
        }
        i -= lowbit(i);
    }
    return ;
}

int ask(int i, int m)
{
    int min_val = INF, pos = -1;
    while (i <= m)
    {
        if (bit[i].min_val < min_val)
        {
            min_val = bit[i].min_val;
            pos = bit[i].pos;
        }
        i += lowbit(i);
    }
    return pos;
}

int dist(Point a, Point b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void Manhattan_minimum_spanning_tree(int n, Point p[])
{
    int a[MAXN], b[MAXN];
    tot = 0;
    for (int dir = 0; dir < 4; dir++)
    {
        if (dir == 1 || dir == 3)
        {
            for (int i = 0; i < n; i++)
            {
                swap(p[i].x, p[i].y);
            }
        }
        else if (dir == 2)
        {
            for (int i = 0; i < n; i++)
            {
                p[i].x = -p[i].x;
            }
        }
        sort(p, p + n, cmp);
        for (int i = 0; i < n; i++)
        {
            a[i] = b[i] = p[i].y - p[i].x;
        }
        sort(b, b + n);
        int m = (int)(unique(b, b + n) - b);
        for (int i = 1; i <= m; i++)
        {
            bit[i].init();
        }
        for (int i = n - 1; i >= 0; i--)
        {
            int pos = (int)(lower_bound(b, b + m, a[i]) - b + 1);
            int ans = ask(pos, m);
            if (ans != -1)
            {
                addedge(p[i].id, p[ans].id, dist(p[i],p[ans]));
            }
            update(pos, p[i].x + p[i].y, i);
        }
    }
    memset(F, -1, sizeof(F));
    sort(edge, edge + tot, cmpedge);
    total = 0;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < tot; i++)
    {
        int u = edge[i].u, v = edge[i].v;
        int t1 = find(u), t2 = find(v);
        if (t1 != t2)
        {
            F[t1] = t2;
            _addedge(u, v);
            _addedge(v, u);
        }
    }
    return ;
}

int m;
int a[MAXN];

struct Ans
{
    long long a, b;
} ans[MAXM];

long long temp ;
int num[MAXN];
void add(int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        temp -= (long long)num[a[i]] * num[a[i]];
        num[a[i]]++;
        temp += (long long)num[a[i]] * num[a[i]];
    }
    return ;
}

void del(int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        temp -= (long long)num[a[i]] * num[a[i]];
        num[a[i]]--;
        temp += (long long)num[a[i]] * num[a[i]];
    }
    return ;
}

void dfs(int l1, int r1, int l2, int r2, int idx, int pre)
{
    if (l2 < l1)
    {
        add(l2, l1 - 1);
    }
    if (r2 > r1)
    {
        add(r1 + 1, r2);
    }
    if (l2 > l1)
    {
        del(l1, l2 - 1);
    }
    if (r2 < r1)
    {
        del(r2 + 1, r1);
    }
    ans[pp[idx].id].a = temp - (r2 - l2 + 1);
    ans[pp[idx].id].b = (long long)(r2 - l2 + 1) * (r2 - l2);
    for (int i = head[idx]; i != -1; i = e[i].next)
    {
        int v = e[i].to;
        if (v == pre)
        {
            continue;
        }
        dfs(l2, r2, pp[v].x, pp[v].y, v, idx);
    }
    if (l2 < l1)
    {
        del(l2, l1 - 1);
    }
    if (r2 > r1)
    {
        del(r1 + 1, r2);
    }
    if (l2 > l1)
    {
        add(l1, l2 - 1);
    }
    if (r2 < r1)
    {
        add(r2 + 1, r1);
    }
    return ;
}

long long gcd(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &p[i].x, &p[i].y);
            p[i].id = i;
            pp[i] = p[i];
        }
        Manhattan_minimum_spanning_tree(m, p);
        memset(num, 0, sizeof(num));
        temp = 0;
        dfs(1, 0, pp[0].x, pp[0].y, 0, -1);
        for (int i = 0; i < m; i++)
        {
            long long d = gcd(ans[i].a, ans[i].b);
            printf("%lld/%lld\n", ans[i].a / d, ans[i].b / d);
        }
    }
    return 0;
}
