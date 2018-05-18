//
//  main.cpp
//  f-HDU-3308-LCIS
//
//  Created by ZYJ on 2017/1/19.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

#define lson root << 1
#define rson root << 1 | 1

using namespace std;

const int MAXN = 1e5 + 10;

struct SegmentTree
{
    int left, right, mid;
    int mx, lx, rx;     //  mx 区间最长，lx 以左端点为起点最长，rx 以右端点为起点最长
    int dist()
    {
        return right - left + 1;
    }
} L[MAXN * 4];

int A[MAXN];

void PushUp(int root)
{
    L[root].lx = L[lson].lx +
        ((L[lson].lx == L[lson].dist() && A[L[rson].left] > A[L[lson].right]) ? L[rson].lx : 0);
    L[root].rx = L[rson].rx +
        ((L[rson].rx == L[rson].dist() && A[L[rson].left] > A[L[lson].right]) ? L[lson].rx : 0);
    L[root].mx = max(max(L[lson].mx, L[rson].mx),
                     A[L[rson].left] > A[L[lson].right] ? (L[lson].rx + L[rson].lx) : 0);
}

void build(int root, int left, int right)
{
    L[root].left = left;
    L[root].right = right;
    L[root].mid = (left + right) / 2;
    if (left == right)
    {
        L[root].lx = L[root].rx = L[root].mx = 1;
        return ;
    }
    build(lson, left, L[root].mid);
    build(rson, L[root].mid + 1, right);
    PushUp(root);
}

void update(int root, int pos, int k)
{
    if (L[root].left == L[root].right)
    {
        L[root].lx = L[root].rx = L[root].mx = 1;
        return ;
    }
    if (pos <= L[root].mid)
    {
        update(lson, pos, k);
    }
    else
    {
        update(rson, pos, k);
    }
    PushUp(root);
}

int query(int root, int left, int right)
{
    if (left == L[root].left && right == L[root].right)
    {
        return L[root].mx;
    }
    if (right <= L[root].mid)
    {
        return query(lson,left,right);
    }
    else if (left > L[root].mid)
    {
        return query(rson, left, right);
    }
    else
    {
        int ltmp = query(lson, left, L[root].mid);
        int rtmp = query(rson, L[root].mid + 1, right);
        int sum = 0;
        if (A[L[rson].left] > A[L[lson].right])
        {
            sum = min(L[root].mid - left + 1, L[lson].rx) + min(right - L[root].mid, L[rson].lx);
        }
        return max(max(ltmp, rtmp), sum);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    
    int n, m;
    char str[10];
    
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &A[i]);
        }
        build(1, 0, n - 1);
        
        int a, b;
        while (m--)
        {
            scanf("%s%d%d", str, &a, &b);
            if (str[0] == 'Q')
            {
                printf("%d\n", query(1, a, b));
            }
            else
            {
                A[a] = b;
                update(1, a, b);
            }
        }
    }
    
    return 0;
}
