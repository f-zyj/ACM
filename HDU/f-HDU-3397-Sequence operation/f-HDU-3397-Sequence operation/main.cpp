//
//  main.cpp
//  f-HDU-3397-Sequence operation
//
//  Created by ZYJ on 2017/1/19.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

#define lson u << 1
#define rson u << 1 | 1

using namespace std;

const int MAXN = 100010;

int dat[MAXN];

struct node
{
    int left, right;
    int lo, ro, mo; //  1:左端点为起点最长连续数目，右端点为终点最长连续数目，区间最长连续数目
    int lz, rz, mz; //  0:左端点为起点最长连续数目，右端点为终点最长连续数目，区间最长连续数目
    int res;        //  区间1的个数
    int COVER, XOR;
} T[MAXN << 2];

void makeXOR(int u)
{   //  翻转操作
    swap(T[u].lo, T[u].lz);
    swap(T[u].ro, T[u].rz);
    swap(T[u].mo, T[u].mz);
    T[u].res = T[u].right - T[u].left + 1 - T[u].res;
}

void PushUp(int u)
{
    if (T[u].left == T[u].right)
    {
        return ;
    }
    int len = T[u].right - T[u].left + 1;
    T[u].lo = T[lson].lo;
    T[u].ro = T[rson].ro;
    if (T[u].lo == (len + 1) >> 1)
    {
        T[u].lo += T[rson].lo;
    }
    if (T[u].ro == len >> 1)
    {
        T[u].ro += T[lson].ro;
    }
    T[u].mo = max(T[lson].mo, T[rson].mo);
    T[u].mo = max(T[u].mo, T[lson].ro + T[rson].lo);
    
    T[u].lz = T[lson].lz;
    T[u].rz = T[rson].rz;
    if (T[u].lz == (len + 1) >> 1)
    {
        T[u].lz += T[rson].lz;
    }
    if (T[u].rz == len >> 1)
    {
        T[u].rz += T[lson].rz;
    }
    T[u].mz = max(T[lson].mz, T[rson].mz);
    T[u].mz = max(T[u].mz, T[lson].rz + T[rson].lz);
    
    T[u].res = T[lson].res + T[rson].res;
}

void PushDown(int u)
{
    if (T[u].left == T[u].right)
    {
        return ;
    }
    if (T[u].COVER != -1)
    {
        int len = T[u].right - T[u].left + 1;
        T[lson].COVER = T[rson].COVER = T[u].COVER;
        T[lson].XOR = T[rson].XOR = 0;
        
        T[lson].lo = T[lson].ro = T[lson].mo = T[u].COVER ? (len + 1) >> 1 : 0;
        T[lson].lz = T[lson].rz = T[lson].mz = T[u].COVER ? 0 : (len + 1) >> 1;
        T[lson].res = T[u].COVER ? (len + 1) >> 1 : 0;
        
        T[rson].lo = T[rson].ro = T[rson].mo = T[u].COVER ? len >> 1 : 0;
        T[rson].lz = T[rson].rz = T[rson].mz = T[u].COVER ? 0 : len >> 1;
        T[rson].res = T[u].COVER ? len >> 1 : 0;
        
        T[u].COVER = -1;
    }
    if (T[u].XOR)
    {
        T[u].XOR = 0;
        T[lson].XOR ^= 1;
        T[rson].XOR ^= 1;
        makeXOR(lson);
        makeXOR(rson);
    }
}

void Build(int u, int l, int r)
{
    T[u].left = l;
    T[u].right = r;
    T[u].COVER = -1;
    T[u].XOR = 0;
    if (l == r)
    {
        T[u].lo = T[u].ro = T[u].mo = (dat[l] == 1);
        T[u].lz = T[u].rz = T[u].mz = (dat[l] == 0);
        T[u].res = dat[l];
        T[u].COVER = dat[l];
        return ;
    }
    int mid = (l + r) >> 1;
    Build(lson, l, mid);
    Build(rson, mid + 1, r);
    PushUp(u);
}

void Update(int u, int l, int r, int op)
{
    PushDown(u);
    if (l <= T[u].left && T[u].right <= r)
    {
        if (op < 2)
        {
            //  覆盖操作
            int len = T[u].right - T[u].left + 1;
            T[u].COVER = op;
            T[u].lo = T[u].ro = T[u].mo = op ? len : 0;
            T[u].lz = T[u].rz = T[u].mz = op ? 0 : len;
            T[u].res = op ? len : 0;
        }
        else
        {
            T[u].XOR = 1;
            makeXOR(u);
        }
    }
    else
    {
        if (l <= T[lson].right)
        {
            Update(lson, l, r, op);
        }
        if (r >= T[rson].left)
        {
            Update(rson, l, r, op);
        }
        PushUp(u);
    }
}

int Query(int u, int l, int r, int op)
{
    PushDown(u);
    if (l <= T[u].left && T[u].right <= r)
    {
        if (op == 3)
        {
            return T[u].res;
        }
        else
        {
            return T[u].mo;
        }
    }
    else
    {
        if (r <= T[lson].right)
        {
            return Query(lson, l, r, op);
        }
        if (l >= T[rson].left)
        {
            return Query(rson, l, r, op);
        }
        if (op == 3)
        {
            return Query(lson, l, T[lson].right, op) + Query(rson, T[rson].left, r, op);
        }
        
        //  合并思想
        int ret = min(T[lson].ro, T[lson].right - l + 1) + min(T[rson].lo, r - T[rson].left + 1);
        int ans = max(Query(lson, l, T[lson].right, op), Query(rson, T[rson].left, r, op));
        return max(ans, ret);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    
    while (t--)
    {
        int n, m;
        int cmd, a, b;
        
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", dat + i);
        }
        Build(1, 1, n);
        
        while (m--)
        {
            scanf("%d%d%d", &cmd, &a, &b);
            a++, b++;
            if (cmd < 3)
            {
                Update(1, a, b, cmd);
            }
            else
            {
                printf("%d\n", Query(1, a, b, cmd));
            }
        }
    }
    
    return 0;
}
