//
//  main.cpp
//  f-51Nod-1781-Pinball
//
//  Created by ZYJ on 2017/7/21.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

#define lson rt << 1
#define rson rt << 1 | 1

using namespace std;

typedef long long ll;

const int MAXN = 100100;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll m, n, ans = INF;

struct node
{
    int l, r;
    ll sum;     //  球到 l~r 的最小代价
} Seg[MAXN << 4];

void build(int rt, int l, int r)
{
    Seg[rt].l = l;
    Seg[rt].r = r;
    if (l == r)
    {
        Seg[rt].sum = INF;
        return ;
    }
    int m = (l + r) >> 1;
    build(lson, l, m);
    build(rson, m + 1, r);
    Seg[rt].sum = min(Seg[lson].sum, Seg[rson].sum);
}

void update(int rt, int a, ll c)
{
    if (Seg[rt].l == a && Seg[rt].r == a)
    {
        Seg[rt].sum = min(Seg[rt].sum, c);
        return;
    }
    int m = (Seg[rt].l + Seg[rt].r) >> 1;
    if (a <= m)
    {
        update(lson, a, c);
    }
    else
    {
        update(rson, a, c);
    }
    Seg[rt].sum = min(Seg[lson].sum, Seg[rson].sum);
}

ll query(int rt, int a, int b)
{
    if (Seg[rt].l == a && Seg[rt].r == b)
    {
        return Seg[rt].sum;
    }
    int m = (Seg[rt].l + Seg[rt].r) >> 1;
    if (b <= m)
    {
        return query(lson, a, b);
    }
    else if (a > m)
    {
        return query(rson, a, b);
    }
    else
    {
        return min(query(lson, a, m), query(rson, m + 1, b));
    }
}

ll dct[MAXN << 2];
ll A[MAXN], B[MAXN], C[MAXN], D[MAXN];
ll l[MAXN], r[MAXN];

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
    scan_d(m), scan_d(n);
    
    int cnt = 1;
    for (int i = 1; i <= m; i++)
    {
        scan_d(A[i]), scan_d(B[i]), scan_d(C[i]), scan_d(D[i]);
        dct[cnt++] = A[i];
        dct[cnt++] = B[i];
        dct[cnt++] = C[i];
    }
    dct[cnt++] = 1;
    dct[cnt++] = n;
    sort(dct + 1, dct + cnt);
    cnt = (int)(unique(dct + 1, dct + cnt) - dct);
    
    for (int i = 1; i <= m; i++)
    {
        A[i] = lower_bound(dct + 1, dct + cnt, A[i]) - dct;
        B[i] = lower_bound(dct + 1, dct + cnt, B[i]) - dct;
        C[i] = lower_bound(dct + 1, dct + cnt, C[i]) - dct;
    }
    
    int tmp = cnt - 1;
    
    //  从 1 位置落下最小费用
    build(1, 1, tmp);
    update(1, 1, 0);
    for (int i = 1; i <= m; i++)
    {
        l[i] = query(1, (int)A[i], (int)B[i]) + D[i];
        update(1, (int)C[i], l[i]);
    }
    
    //  从 tmp 位置落下最小费用
    build(1, 1, tmp);
    update(1, tmp, 0);
    for (int i = 1; i <= m; i++)
    {
        r[i] = query(1, (int)A[i], (int)B[i]) + D[i];
        update(1, (int)C[i], r[i]);
    }
    
    //  落在 i 个漏斗的代价之和，多计算一次 d[i]，减去，取小
    for (int i = 1; i <= m; i++)
    {
        ans = min(ans, l[i] + r[i] - D[i]);
    }
    
    if (ans == INF)
    {
        puts("-1");
    }
    else
    {
        printf("%lld\n", ans);
    }
    
    return 0;
}
