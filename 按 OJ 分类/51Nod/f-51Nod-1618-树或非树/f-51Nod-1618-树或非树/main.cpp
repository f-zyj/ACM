//
//  main.cpp
//  f-51Nod-1618-树或非树
//
//  Created by ZYJ on 2017/9/29.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int n, m;
int cnt1, cnt2, tmp, mb, mdb, ans;
int d[MAXN], z[MAXN], g[MAXN], o[MAXN];
int pre[MAXN], pre_[MAXN], p[MAXN << 1], nxt[MAXN << 1];

struct node
{
    int g, cnt;
    int l[MAXN], r[MAXN];
    int z[MAXN], a[MAXN];
    int x[MAXN], y[MAXN];
    int pre[MAXN], root[MAXN];
    
    void put(int i, int j)
    {
        if (i && j)
        {
            z[i] = !z[i];
            a[i] = !a[i];
            swap(x[i], y[i]);
        }
    }
    
    void lazy(int i)
    {
        put(l[i], z[i]);
        put(r[i], z[i]);
        z[i] = 0;
    }
    
    void rt(int i, int j)
    {
        if (l[i] == j)
        {
            l[i] = r[j];
            pre[r[j]] = i;
            r[j] = i;
        }
        else
        {
            r[i] = l[j];
            pre[l[j]] = i;
            l[j] = i;
        }
        root[j] = root[i];
        root[i] = 0;
        if (l[pre[i]] == i)
        {
            l[pre[i]] = j;
        }
        else if (r[pre[i]] == i)
        {
            r[pre[i]] = j;
        }
        
        pre[j] = pre[i];
        pre[i] = j;
        update(i);
        update(j);
    }
    
    void splay(int i, int j)
    {
        if (root[i])
        {
            lazy(i);
        }
        while (!root[i])
        {
            lazy(pre[i]);
            lazy(i);
            rt(pre[i], i);
        }
        if (j)
        {
            root[g = r[i]] = 1;
            r[i] = 0;
            update(i);
        }
    }
    
    void update(int i)
    {
        x[i] = x[l[i]] + x[r[i]] + a[i];
        y[i] = y[l[i]] + y[r[i]] + 1 - a[i];
    }
    
    void access(int i)
    {
        splay(cnt = i, 1);
        while (pre[i])
        {
            splay(cnt = pre[i], 1);
            r[cnt] = 1;
            rt(cnt, i);
        }
    }
    
    void cover(int i)
    {
        access(i);
        splay(tmp, 0);
        ans += y[r[tmp]] - x[r[tmp]];
        put(r[tmp], 1);
    }
} tree;

void link(int a, int b)
{
    nxt[++cnt1] = d[a];
    d[a] = cnt1;
    p[cnt1] = b;
}

int find(int i)
{
    return (pre_[i] == i) ? i : pre_[i] = find(pre_[i]);
}

void dfs1(int i, int h)
{
    z[++cnt1] = i;
    o[i] = cnt1;
    for (int k = d[i], j = p[k]; k; k = nxt[k], j = p[k])
    {
        if ((h ^ k) != 1)
        {
            if (o[j])
            {
                mb = k;
                for (int l = o[j]; l <= cnt1; l++)
                {
                    g[++cnt2] = z[l];
                }
            }
            else
            {
                dfs1(j, k);
            }
        }
    }
    cnt1--;
}

void dfs2(int i, int h)
{
    for (int k = d[i], j = p[k]; k; k = nxt[k], j = p[k])
    {
        if ((h ^ k) != 1 && ((k ^ mb) > 1))
        {
            pre[j] = i;
            dfs2(j, k);
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
    scan_d(n);
    scan_d(m);
    
    cnt1 = 1;
    int a, b, mdb = 0;
    for (int i = 1; i <= n; i++)
    {
        scan_d(a);
        scan_d(b);
        link(a, b);
        link(b, a);
    }
    
    cnt1 = 0;
    dfs1(1, 0);
    dfs2(g[1], 0);
    for (int i = 0; i < MAXN; i++)
    {
        o[i] = 0;
    }
    for (int i = 1; i <= cnt2; i++)
    {
        o[g[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        pre_[i] = (o[i]) ? i : pre[i];
    }
    for (int i = 1; i <= n; i++)
    {
        find(i);
    }
    for (int i = 1; i <= n; i++)
    {
        tree.pre[i] = pre[i];
        tree.y[i] = tree.root[i] = 1;
    }
    
    g[0] = g[cnt2];
    tmp = g[cnt2 + 1] = g[1];
    while (m--)
    {
        scan_d(a);
        scan_d(b);
        int Fa = pre_[a], Fb = pre_[b];
        int d1 = abs(o[Fa] - o[Fb]);
        int g1, g2;
        if (o[Fa] < o[Fb])
        {
            g1 = g[o[Fa] + 1];
            g2 = g[o[Fa] - 1];
        }
        else
        {
            g1 = g[o[Fa] - 1];
            g2 = g[o[Fa] + 1];
        }
        
        tree.cover(a);
        tree.cover(b);
        if (d1 > cnt2 - d1 || ((d1 == cnt2 - d1) && g1 > g2))
        {
            mdb = !mdb;
            if (mdb)
            {
                ans++;
            }
            else
            {
                ans--;
            }
            tree.cover(g[cnt2]);
        }
        
        tree.access(g[cnt2]);
        int al = tree.x[g[cnt2]] + mdb == cnt2;
        
        printf("%d\n", n - ans + al);
    }
    
    return 0;
}
