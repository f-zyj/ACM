//
//  main.cpp
//  f-51Nod-1364-最大字典序排列
//
//  Created by ZYJ on 2017/6/16.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

#define lson  root << 1
#define rson  root << 1 | 1
#define ll long long
#define clr(a, b) memset(a, b, sizeof(a))

using namespace std;

const int MAXN = 1e5 + 10;

int N, K;
int a[MAXN];

struct node
{
    int l, r, mid;
    int pos, sum;
    int max;
} tree[MAXN << 2];

void push_up(int root)
{
    if (tree[lson].max >= tree[rson].max)
    {
        tree[root].max = tree[lson].max;
        tree[root].pos = tree[lson].pos;
    }
    else
    {
        tree[root].max = tree[rson].max;
        tree[root].pos = tree[rson].pos;
    }
    tree[root].sum = tree[lson].sum + tree[rson].sum;
}

void build_tree(int root, int l, int r)
{
    tree[root].l = l;
    tree[root].r = r;
    tree[root].mid = (l + r) >>1;
    tree[root].sum = 0;
    
    if (l == r)
    {
        tree[root].sum = 1;
        tree[root].max = a[l];
        tree[root].pos = l;
        return ;
    }
    
    build_tree(lson, l, tree[root].mid);
    build_tree(rson, tree[root].mid + 1, r);
    push_up(root);
}

int Max, Pos;

//  结点更新
void update(int root, int pos)
{
    if (tree[root].l >= pos && tree[root].r <= pos)
    {
        tree[root].max = 0;
        tree[root].sum = 0;
        return ;
    }
    int mid = tree[root].mid;
    if (pos <= mid)
    {
        update(lson, pos);
    }
    else
    {
        update(rson, pos);
    }
    push_up(root);
}

//  查找最大值及其位置，值相等，取较小位置
void query(int root, int l, int r)
{
    if (tree[root].l >= l && tree[root].r <= r)
    {
        if (Max < tree[root].max)
        {
            Max = tree[root].max;
            Pos = tree[root].pos;
        }
        return ;
    }
    int mid = tree[root].mid;
    if (l <= mid)
    {
        query(lson, l, r);
    }
    if (r > mid)
    {
        query(rson, l, r);
    }
    push_up(root);
}

//  结点查找
int query_k(int root, int k)
{
    if (tree[root].l == tree[root].r)
    {
        return tree[root].l;
    }
    if (tree[lson].sum >= k)
    {
        return query_k(lson, k);
    }
    else
    {
        return query_k(rson, k - tree[lson].sum);
    }
}

//  区间求和
int query_sum(int root, int l, int r)
{
    if (tree[root].l >= l && tree[root].r <= r)
    {
        return tree[root].sum;
    }
    
    int ans = 0;
    if (l <= tree[root].mid)
    {
        ans += query_sum(lson, l, r);
    }
    if (r > tree[root].mid)
    {
        ans += query_sum(rson, l, r);
    }
    return ans;
}

int main()
{
    while (cin >> N >> K)
    {
        a[0] = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", a + i);
        }
        build_tree(1, 1, N);
        
        int cnt = 1;
        while (K > 0 && cnt <= N)
        {
            Max = 0, Pos = N;
            if (cnt + K >= N)
            {
                query(1, 1, N);
                update(1, Pos);
                K -= query_sum(1, 1, Pos);
                
                printf("%d\n", Max);
            }
            else
            {
                int pos = query_k(1, K + 1);
                query(1, 1, pos);
                update(1, Pos);
                K -= query_sum(1, 1, Pos);
                
                printf("%d\n", Max);
            }
            a[Pos] = -1;
            cnt++;
        }
        
        for (int i = 1; i <= N; i++)
        {
            if (a[i] != -1)
            {
                printf("%d\n", a[i]);
            }
        }
    }
    
    return 0;
}
