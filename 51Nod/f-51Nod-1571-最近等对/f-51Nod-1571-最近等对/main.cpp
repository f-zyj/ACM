//
//  main.cpp
//  f-51Nod-1571-最近等对
//
//  Created by ZYJ on 2017/7/30.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

#define lson rt << 1
#define rson rt << 1 | 1

using namespace std;

const int MAXN = 5e5 + 10;
const int INF = 0x3f3f3f3f;

struct node
{
    int l, r, id;
} q[MAXN];  //  查询

int n, m;
int a[MAXN];
int b[MAXN];
int pre[MAXN];
int ans[MAXN];
int minv[MAXN << 2];
int lazy[MAXN << 2];

int cmp(node a, node b)
{
    return a.r < b.r;
}

void build(int rt, int l, int r)
{
    minv[rt] = n, lazy[rt] = INF;
    if (l == r)
    {
        return ;
    }
    int m = (l + r) >> 1;
    build(lson, l, m);
    build(rson, m + 1, r);
}

void pushup(int rt)
{
    minv[rt] = min(minv[lson], minv[rson]);
}

void pushdown(int rt)
{
    if (lazy[rt] != INF)
    {
        minv[lson] = min(minv[lson], lazy[rt]);
        minv[rson] = min(minv[rson], lazy[rt]);
        lazy[lson] = min(lazy[lson], lazy[rt]);
        lazy[rson] = min(lazy[rson], lazy[rt]);
        lazy[rt] = INF;
    }
}

void update(int rt, int l, int r, int l_, int r_, int v)
{
    if (l_ <= l && r_ >= r)
    {
        minv[rt] = min(minv[rt], v);
        lazy[rt] = min(lazy[rt], v);
        return ;
    }
    
    pushdown(rt);
    int m = (l + r) >> 1;
    if (l_ <= m)
    {
        update(lson, l, m, l_, r_, v);
    }
    if (r_ > m)
    {
        update(rson, m + 1, r, l_, r_, v);
    }
    pushup(rt);
}

int query(int rt, int l, int r, int l_, int r_)
{
    if (l_ <= l && r_ >= r)
    {
        return minv[rt];
    }
    
    pushdown(rt);
    int ans = INF, m = (l + r) >> 1;
    if (l_ <= m)
    {
        ans = min(ans, query(lson, l, m, l_, r_));
    }
    if (r_ > m)
    {
        ans = min(ans, query(rson, m + 1, r, l_, r_));
    }
    pushup(rt);
    
    return ans;
}

void slove()
{
    build(1, 1, n);
    
    for (int i = 1; i <= n; i++)
    {
        pre[i] = n;
    }
    
    for (int i = 1, j = 1; i <= n && j <= m; i++)
    {
        if (pre[a[i]] == n) //  记录离散化后的 a[i] 的前一个位置
        {
            pre[a[i]] = i;
        }
        else
        {
            update(1, 1, n, 1, pre[a[i]], i - pre[a[i]]);
            pre[a[i]] = i;
        }
        while (j <= m && q[j].r == i)
        {
            ans[q[j].id] = query(1, 1, n, q[j].l, n);
            j++;
        }
    }
}

template <class T>
inline bool scan_d(T &ret)
{
    char c;
    int sgn;
    if (c = getchar(), c == EOF)
    {
        return 0; //EOF
    }
    while (c != '-' && (c < '0' || c > '9'))
    {
        c = getchar();
    }
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0');
    }
    ret *= sgn;
    return 1;
}

template <class T>
inline void print_d(T x)
{
    if (x > 9)
    {
        print_d(x / 10);
    }
    putchar(x % 10 + '0');
}

int main()
{
    scan_d(n), scan_d(m);
    for (int i = 1; i <= n; i++)
    {
        scan_d(a[i]);
        b[i] = a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        scan_d(q[i].l), scan_d(q[i].r);
        q[i].id = i;
    }
    
    //  离散化
    sort(b + 1, b + n + 1);
    sort(q + 1, q + m + 1, cmp);
    int tmp = (int)(unique(b + 1, b + n + 1) - b);
    for (int i = 1; i <= n; i++)
    {
        a[i] = (int)(lower_bound(b + 1, b + tmp, a[i]) - b);
    }
    
    slove();
    
    for (int i = 1; i <= m; i++)
    {
        if (ans[i] == n)
        {
            puts("-1");
        }
        else
        {
            print_d(ans[i]);
            putchar(10);
        }
    }
    
    return 0;
}
