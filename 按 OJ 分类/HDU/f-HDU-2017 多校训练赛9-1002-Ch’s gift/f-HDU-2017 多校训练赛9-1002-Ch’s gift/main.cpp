//
//  main.cpp
//  f-HDU-2017 多校训练赛9-1002-Ch’s gift
//
//  Created by ZYJ on 2017/8/22.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 7;

int A[MAXN];
int B[MAXN];
int pre[MAXN];
int id[MAXN];
int d[MAXN];
int ls[MAXN * 20];
int rs[MAXN * 20];
int T[MAXN * 20];
int anc[MAXN][25];
ll cnt[MAXN * 20];
vector<int> vi[MAXN];

int ql, qr, tol, tot;

void init(int n)
{
    tot = 1;
    tol = 0;
    for (int i = 1; i <= n; i++)
    {
        vi[i].clear();
    }
}

int low(int *a, int pos, int R)
{
    int l = 1, r = R;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (a[mid] == pos)
        {
            return mid;
        }
        else if (a[mid] > pos)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    
    return 0;
}

void builde(int l, int r, int &o)
{
    o = tol++;
    if (l == r)
    {
        cnt[o] = 0;
        return ;
    }
    
    int m = (l + r) >> 1;
    builde(l, m, ls[o]);
    builde(m + 1, r, rs[o]);
    cnt[o] = 0;
}

void update(int last, int l, int r, int pos, int &o)
{
    o = tol++;
    cnt[o] = cnt[last] + A[pos];
    ls[o] = ls[last];
    rs[o] = rs[last];
    if (l == r)
    {
        return ;
    }
    
    int m = (l + r) >> 1;
    if (m >= pos)
    {
        update(ls[last], l, m, pos, ls[o]);
    }
    else
    {
        update(rs[last], m + 1, r, pos, rs[o]);
    }
}

ll query(int ll, int rr, int l, int r)
{
    if (ql <= l && qr >= r)
    {
        return cnt[rr] - cnt[ll];
    }
    
    int m = (l + r) >> 1;
    long long ans = 0;
    if (ql <= m)
    {
        ans += query(ls[ll], ls[rr], l, m);
    }
    if (qr > m)
    {
        ans += query(rs[ll], rs[rr], m + 1, r);
    }
    
    return ans;
}

int LCA(int p, int q)
{
    if (d[p] < d[q])
    {
        swap(p, q);
    }
    int log;
    for (log = 1; (1 << log) <= d[p]; log++) ;
    log--;
    for (int i = log; i >= 0; i--)
    {
        if (d[p] - (1 << i) >= d[q])
        {
            p = anc[p][i];
        }
    }
    if (p == q)
    {
        return p;
    }
    
    for (int i = log; i >= 0; i--)
    {
        if (anc[p][i] != -1 && anc[p][i] != anc[q][i])
        {
            p = anc[p][i];
            q = anc[q][i];
        }
    }
    
    return anc[p][0];
}

void preprocess(int n)
{
    for (int i = 1; i <= n; i++)
    {
        anc[i][0] = pre[i];
        for (int j = 1; (1 << j) < n; j++)
        {
            anc[i][j] = -1;
        }
    }
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (anc[i][j - 1] != -1)
            {
                int a = anc[i][j - 1];
                anc[i][j] = anc[a][j - 1];
            }
        }
    }
}

void dfs(int u, int p, int m)
{
    d[u] = d[p] + 1;
    pre[u] = p;
    id[u] = tot++;
    int pos = low(A, B[u], m);
    update(T[id[p]], 1, m, pos, T[id[u]]);
    for (int i = 0; i < vi[u].size(); i++)
    {
        int v = vi[u][i];
        if (v == p)
        {
            continue;
        }
        
        dfs(v, u, m);
    }
}

int low1(int *a, int pos, int R)
{
    int l = 1, r = R;
    while (l < r)
    {
        int m = (l + r) >> 1;
        if (a[m] >= pos)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}

int n, q;

int main()
{
    while (~scanf("%d%d", &n, &q))
    {
        init(n);
        
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &A[i]);
            B[i] = A[i];
        }
        sort(A + 1, A + 1 + n);
        
        int m = 1;
        for (int i = 2; i <= n; i++)
        {
            if (A[i] != A[i - 1])
            {
                A[++m] = A[i];
            }
        }
        
        int u, v;
        for (int i = 1; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            vi[u].push_back(v);
            vi[v].push_back(u);
        }
        
        builde(1, m, T[0]);
        d[0] = 0;
        dfs(1, 0, m);
        preprocess(n);
        
        ll ans;
        int s, t, a, b;
        for (int i = 1; i <= q; i++)
        {
            scanf("%d%d%d%d", &s, &t, &a, &b);
            
            ql = low1(A, a, m);
            qr = low1(A, b, m);
            if (A[qr] > b)
            {
                qr--;
            }
            int o = LCA(s, t);
            ans = 0;
            ans += query(T[id[pre[o]]], T[id[s]], 1, m);
            ans += query(T[id[o]], T[id[t]], 1, m);
            
            if (i == 1)
            {
                printf("%lld", ans);
            }
            else
            {
                printf(" %lld", ans);
            }
        }
        putchar(10);
    }
    
    return 0;
}
