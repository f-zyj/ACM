//
//  main.cpp
//  f-51Nod-1811-联通分量计数
//
//  Created by ZYJ on 2017/8/4.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>

#define ll long long

using namespace std;

const int MAXN = 2e5 + 5;
const int MAXM = MAXN << 4;

int n;
int cnt = 0, pos = 0;
ll ans = 0, tmp;
int root[MAXN];
int l1[MAXM], r1[MAXM];
int ls[MAXM], rs[MAXM];
int lb[MAXM], rb[MAXM];
int nt[MAXN], head[MAXN], v[MAXN];
ll s[MAXM];

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

ll get_n(int n)
{
    return (ll)(n + 1) * n / 2;
}

void add(int x, int y)
{
    nt[++pos] = head[x];
    head[x] = pos;
    v[pos] = y;
}

void ins(int &x, int l, int r, int a)
{
    if (!x)
    {
        x = ++cnt;
    }
    if (l == r)
    {
        ls[x] = rs[x] = 1;
        lb[x] = rb[x] = 0;
        s[x] = 1;
        return ;
    }
    
    int m = (l + r) >> 1;
    if (a <= m)
    {
        ins(l1[x], l, m, a);
    }
    else
    {
        ins(r1[x], m + 1, r, a);
    }
    if (!l1[x])
    {
        l1[x] = ++cnt;
        lb[cnt] = rb[cnt] = m - l + 1;
        s[cnt] = get_n(m - l + 1);
    }
    if (!r1[x])
    {
        r1[x] = ++cnt;
        lb[cnt] = rb[cnt] = r - m;
        s[cnt] = get_n(r - m);
    }
    int k1 = l1[x], k2 = r1[x];
    s[x] = s[k1] + s[k2];
    if (ls[k2] && rs[k1])
    {
        s[x] -= get_n(rs[k1]) + get_n(ls[k2]);
        s[x] += get_n(rs[k1] + ls[k2]);
    }
    if (lb[k2] && rb[k1])
    {
        s[x] -= get_n(rb[k1]) + get_n(lb[k2]);
        s[x] += get_n(rb[k1] + lb[k2]);
    }
    ls[x] = ls[k1];
    rs[x] = rs[k2];
    lb[x] = lb[k1];
    rb[x] = rb[k2];
    if (ls[k1] == m - l + 1)
    {
        ls[x] += ls[k2];
    }
    if (lb[k1] == m - l + 1)
    {
        lb[x] += lb[k2];
    }
    if (rs[k2] == r - m)
    {
        rs[x] += rs[k1];
    }
    if (rb[k2] == r - m)
    {
        rb[x] += rb[k1];
    }
}

int merge(int x, int y, int l, int r)
{
    if (!x || !y)
    {
        return x + y;
    }
    if (lb[x] == r - l + 1)
    {
        return y;
    }
    if (lb[y] == r - l + 1)
    {
        return x;
    }
    
    int m = (l + r) >> 1;
    l1[x] = merge(l1[x], l1[y], l, m);
    r1[x] = merge(r1[x], r1[y], m + 1, r);
    if (!l1[x])
    {
        l1[x] = ++cnt;
        lb[cnt] = rb[cnt] = m - l + 1;
        s[cnt] = get_n(m - l + 1);
    }
    if (!r1[x])
    {
        r1[x] = ++cnt;
        lb[cnt] = rb[cnt] = r - m;
        s[cnt] = get_n(r - m);
    }
    int k1 = l1[x], k2 = r1[x];
    s[x] = s[k1] + s[k2];
    if (ls[k2] && rs[k1])
    {
        s[x] -= get_n(rs[k1]) + get_n(ls[k2]);
        s[x] += get_n(rs[k1] + ls[k2]);
    }
    if (lb[k2] && rb[k1])
    {
        s[x] -= get_n(rb[k1]) + get_n(lb[k2]);
        s[x] += get_n(rb[k1] + lb[k2]);
    }
    ls[x] = ls[k1];
    rs[x] = rs[k2];
    lb[x] = lb[k1];
    rb[x] = rb[k2];
    if (ls[k1] == m - l + 1)
    {
        ls[x] += ls[k2];
    }
    if (lb[k1] == m - l + 1)
    {
        lb[x] += lb[k2];
    }
    if (rs[k2] == r - m)
    {
        rs[x] += rs[k1];
    }
    if (rb[k2] == r - m)
    {
        rb[x] += rb[k1];
    }
    
    return x;
}

void dfs(int rt, int pre)
{
    for (int i = head[rt]; i; i = nt[i])
    {
        int v_ = v[i];
        if (v_ != pre)
        {
            dfs(v_, rt);
            root[rt] = merge(root[rt], root[v_], 1, n);
        }
    }
    
    ins(root[rt], 1, n, rt);
    ans += tmp - s[root[rt]];
}

int main()
{
    scan_d(n);
    tmp = get_n(n);
    
    int x, y;
    for (int i = 1; i < n; i++)
    {
        scan_d(x), scan_d(y);
        add(x, y), add(y, x);
    }
    
    dfs(1, 0);
    
    printf("%lld\n", ans);
    
    return 0;
}
