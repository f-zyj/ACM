//
//  main.cpp
//  f-51Nod-1461-稳定桌
//
//  Created by ZYJ on 2017/6/29.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>

#define lson k << 1
#define rson k << 1 | 1

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;

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

struct leg
{
    int l, d;
    bool operator < (const leg &b) const
    {
        return l > b.l;
    }
} L[MAXN];

struct node
{
    int c;
    ll v;
} tree[MAXN << 2];

int n;
int cnt[MAXN];      //  每种代价的数量

inline void pushup(int k)
{
    tree[k].v = tree[lson].v + tree[rson].v;
    tree[k].c = tree[lson].c + tree[rson].c;
}

void build(int l, int r, int k)
{
    if (l == r)
    {
        if (cnt[l])
        {
            tree[k].v = 1ll * (tree[k].c = cnt[l]) * l;
        }
        return ;
    }
    int m = (l + r) >> 1;
    build(l, m, lson);
    build(m + 1, r, rson);
    pushup(k);
}

int ld, flag;
void update(int l, int r, int k)
{
    if (flag == -1)
    {
        tree[k].c--, tree[k].v -= ld;
    }
    else
    {
        tree[k].c++, tree[k].v += ld;
    }
    
    if (l == r)
    {
        return ;
    }
    int m = (l + r) >> 1;
    if (ld <= m)
    {
        update(l, m, lson);
    }
    else
    {
        update(m + 1, r, rson);
    }
}

ll query(int l, int r, int k)
{
    if (l == r)
    {
        return 1ll * ld * l;
    }
    
    int m = (l + r) >> 1;
    if (tree[lson].c >= ld)
    {
        return query(l, m, lson);
    }
    else
    {
        ld -= tree[lson].c;
        return tree[lson].v + query(m + 1, r, rson);
    }
}

int main()
{
    scan_d(n);
    ll ans = INF, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        scan_d(L[i].l);
    }
    for (int i = 1; i <= n; i++)
    {
        scan_d(L[i].d);
        cnt[L[i].d]++;
    }
    
    build(1, MAXN, 1);
    sort(L + 1, L + n + 1);
    
    ll tmp = 0;
    for (int i = 1, j; i <= n; i = j + 1)
    {
        if (sum >= ans)
        {
            break;
        }
        
        sum += tmp;
        j = i;
        tmp = ld = L[i].d;
        flag = -1;
        update(1, MAXN, 1);
        
        while (j < n && L[j + 1].l == L[i].l)
        {
            tmp += (ld = L[++j].d);
            flag = -1;
            update(1, MAXN, 1);
        }
        
        int num = j - i;    //  当前高度桌腿的数目
        if (n - j <= num)
        {
            ans = min(ans, sum);
            break;
        }
        else
        {
            ld = n - j - num;
            ans = min(ans, sum + query(1, MAXN, 1));
        }
    }
    
    cout << ans << endl;
    
    return 0;
}

