//
//  main.cpp
//  f-51Nod-1463-找朋友
//
//  Created by ZYJ on 2017/7/1.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

#define lson root << 1
#define rson root << 1 | 1

using namespace std;

const int MAXN = 1e5 + 10;

struct node
{
    int l, r;
    int mx;
};

node tree[MAXN << 2];

struct interval //  区间
{
    int l;
    int r;
    int pos;
    
    bool operator < (const interval &b)
    {
        return r < b.r;
    }
} itv[MAXN];

int n, Q, m;
int res;
int A[MAXN];
int B[MAXN];
int K[MAXN];
int B_pos[MAXN];
int tp[MAXN];
int ans[MAXN];

//  建空树
void build(int root, int l, int r)
{
    tree[root].l = l;
    tree[root].r = r;
    tree[root].mx = 0;
    
    if (l == r)
    {
        return ;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}

void query(int root, int l, int r)
{
    if (tree[root].l == l && tree[root].r == r)
    {
        res = max(res, tree[root].mx);
        return ;
    }
    int mid = (tree[root].l + tree[root].r) >> 1;
    if (r <= mid)
    {
        query(lson, l, r);
    }
    else if (l > mid)
    {
        query(rson, l, r);
    }
    else
    {
        query(lson, l, mid);
        query(rson, mid + 1, r);
    }
}

void insert(int root, int pos, int val)
{
    tree[root].mx = max(tree[root].mx, val);
    if (tree[root].l == pos && tree[root].r == pos)
    {
        return ;
    }
    int mid = (tree[root].l + tree[root].r) >> 1;
    if (pos <= mid)
    {
        insert(lson, pos, val);
    }
    else if (pos > mid)
    {
        insert(rson, pos, val);
    }
}

int main()
{
    scanf("%d%d%d", &n, &Q, &m);
    
    memset(B_pos, 0, sizeof(B_pos));
    memset(tp, 0, sizeof(tp));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &B[i]);
        B_pos[B[i]] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &K[i]);
    }
    for (int i = 1; i <= Q; i++)
    {
        scanf("%d%d", &itv[i].l, &itv[i].r);
        itv[i].pos = i;
    }
    
    sort(itv + 1, itv + Q + 1);
    build(1, 1, n);
    
    int s = 1;
    for (int i = 1; i <= Q; i++)
    {
        int r = itv[i].r;
        for (int j = s; j <= r; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                int B_i = B[j] + K[k];
                int pos = B_pos[B_i];
                if (B_i <= n && pos < j && A[pos] + A[j] > tp[pos])
                {
                    tp[pos] = A[pos] + A[j];
                    insert(1, pos, tp[pos]);
                }
                B_i = B[j] - K[k];
                pos = B_pos[B_i];
                if (B_i >= 1 && pos < j && A[pos] + A[j] > tp[pos])
                {
                    tp[pos] = A[pos] + A[j];
                    insert(1, pos, tp[pos]);
                }
            }
        }
        res = 0;
        query(1, itv[i].l, itv[i].r);
        s = r;
        ans[itv[i].pos] = res;
    }
    
    for (int i = 1; i <= Q; i++)
    {
        printf("%d\n", ans[i]);
    }
    
    return 0;
}
