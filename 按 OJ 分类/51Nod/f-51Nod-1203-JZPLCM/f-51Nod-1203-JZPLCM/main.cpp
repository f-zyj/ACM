//
//  main.cpp
//  f-51Nod-1203-JZPLCM
//
//  Created by ZYJ on 2017/9/26.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 5e4 + 5;
const int MOD = 1e9 + 7;

struct note
{
    int l, r, id;
    friend bool operator < (note x, note y)
    {
        return x.l < y.l;
    }
} ask[MAXN];

int n, m;
int x, y, tot;
int l[MAXN], r[MAXN];
int h[MAXN], ans[MAXN];
int tr[MAXN << 4];
int nxt[MAXN << 4];
int a[MAXN << 4];
int b[MAXN << 4];

int QPow(int x, int y)
{
    int z = 1;
    for (; y; y >>= 1, x = (ll)x * x % MOD)
    {
        if (y & 1)
        {
            z = (ll)z * x % MOD;
        }
    }
    
    return z;
}

void add(int x, int y)
{
    for (; x <= tot; x += x & -x)
    {
        tr[x] = (ll)tr[x] * y % MOD;
    }
}

int find(int x)
{
    int ret = 1;
    for (; x; x -= x & -x)
    {
        ret = (ll)ret * tr[x] % MOD;
    }
    
    return ret;
}

int main()
{
    scanf("%d%d", &n, &m);
    
    for (int j = 1; j <= n; j++)
    {
        scanf("%d", &x);
        
        int t = sqrt(x);
        if (x == 1)
        {
            continue;
        }
        
        l[j] = tot + 1;
        for (int i = 2; i <= t; i++)
        {
            if (!(x % i))
            {
                int k = i;
                while (!(x % i))
                {
                    x /= i;
                    a[++tot] = k;
                    b[tot] = i;
                    k *= i;
                }
            }
        }
        if (x > 1)
        {
            ++tot;
            a[tot] = b[tot] = x;
        }
        r[j] = tot;
    }
    
    for (int i = 1; i <= tot; i++)
    {
        tr[i] = 1;
    }
    for (int i = 1; i <= tot; i++)
    {
        if (h[a[i]])
        {
            nxt[h[a[i]]] = i;
        }
        else
        {
            add(i, b[i]);
        }
        h[a[i]] = i;
    }
    
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &ask[i].l, &ask[i].r);
        ask[i].l = l[ask[i].l];
        ask[i].r = r[ask[i].r];
        ask[i].id = i;
    }
    
    sort(ask + 1, ask + m + 1);
    
    for (int i = 1, j = 0; i <= tot; i++)
    {
        while (ask[j + 1].l == i)
        {
            ++j;
            ans[ask[j].id] = find(ask[j].r);
        }
        add(i, QPow(b[i], MOD - 2));
        if (nxt[i])
        {
            add(nxt[i], b[nxt[i]]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d\n",ans[i]);
    }
    
    return 0;
}
