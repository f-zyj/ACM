//
//  main.cpp
//  f-51Nod-1175-区间中第K大的数
//
//  Created by ZYJ on 2017/8/6.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e5;
const int MAXM = MAXN * 30;

int n, q, m, tot;
int a[MAXN], t[MAXN];
int T[MAXN], lson[MAXM], rson[MAXM], c[MAXM];

void Init_hash()
{
    for (int i = 1; i <= n; i++)
    {
        t[i] = a[i];
    }
    sort(t + 1, t + 1 + n);
    m = (int)(unique(t + 1, t + 1 + n) - t - 1);
}

int build(int l, int r)
{
    int root = tot++; c[root] = 0;
    if (l != r)
    {
        int mid = (l + r) >> 1;
        lson[root] = build(l, mid);
        rson[root] = build(mid + 1, r);
    }
    return root;
}

int hash_(int x)
{
    return (int)(lower_bound(t + 1, t + 1 + m, x) - t);
}

int update(int root, int pos, int val)
{
    int newroot = tot++, tmp = newroot;
    c[newroot] = c[root] + val;
    int l = 1, r = m;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (pos <= mid)
        {
            lson[newroot] = tot++;
            rson[newroot] = rson[root];
            newroot = lson[newroot];
            root = lson[root];
            r = mid;
        }
        else
        {
            rson[newroot] = tot++;
            lson[newroot] = lson[root];
            newroot = rson[newroot];
            root = rson[root];
            l = mid + 1;
        }
        c[newroot] = c[root] + val;
    }
    return tmp;
}

int query(int left_root, int right_root, int k)
{
    int l = 1, r = m;
    while ( l < r)
    {
        int mid = (l + r) >> 1;
        if (c[lson[left_root]] - c[lson[right_root]] >= k )
        {
            r = mid;
            left_root = lson[left_root];
            right_root = lson[right_root];
        }
        else
        {
            l = mid + 1;
            k -= c[lson[left_root]] - c[lson[right_root]];
            left_root = rson[left_root];
            right_root = rson[right_root];
        }
    }
    return l;
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        tot = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        
        Init_hash();
        
        T[n + 1] = build(1, m);
        for (int i = n; i; i--)
        {
            int pos = hash_(a[i]);
            T[i] = update(T[i + 1], pos, 1);
        }
        
        scanf("%d", &q);
        
        int l, r, k;
        while (q--)
        {
            scanf("%d%d%d", &l, &r, &k);
            printf("%d\n", t[query(T[l + 1], T[r + 2], r - l + 2 - k)]);
        }
    }
    
    return 0;
}
