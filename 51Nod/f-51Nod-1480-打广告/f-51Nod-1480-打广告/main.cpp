//
//  main.cpp
//  f-51Nod-1480-打广告
//
//  Created by ZYJ on 2017/7/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;

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

struct node
{
    int l, r, pos;
} ad[MAXN], tp[MAXN];

int n, m;
int tot = 0;
ll ans;
int tmp[MAXN];

bool cmp(node a, node b)
{
    return a.l < b.l || (a.l == b.l && a.r > b.r);
}

int main()
{
    scan_d(n), scan_d(m);
    for (int i = 1; i <= n; i++)
    {
        scan_d(ad[i].l);
        scan_d(ad[i].r);
        ad[i].pos = i;
    }
    sort(ad + 1, ad + n + 1, cmp);
    
    tp[++tot] = ad[1];
    tmp[tot] = ad[1].l;
    for (int i = 2; i <= n; i++)
    {
        if (ad[i].r > tp[tot].r)
        {
            tp[++tot] = ad[i];
            tmp[tot] = ad[i].l;
        }
    }
    
    int a, b, c;
    for (int i = 1; i <= m; i++)
    {
        scan_d(a), scan_d(b), scan_d(c);
        
        int p = (int)(lower_bound(tmp + 1, tmp + tot + 1, a) - tmp - 1);
        for (; p <= tot && tp[p].l <= b; p++)
        {
            ll val = (ll)(min(tp[p].r, b) - max(tp[p].l, a)) * c;
            if (val > ans)
            {
                ans = val;
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
