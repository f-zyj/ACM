//
//  main.cpp
//  f-SHU-“盛大游戏杯”第15届上海大学程序设计联赛夏季赛暨上海高校金马五校赛-M-风力观测
//
//  Created by ZYJ on 2017/7/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

#define clr(a, b) memset(a, b, sizeof(a))
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

using namespace std;

const int MAXN = 1e5 + 10;

int n, q;
int a[MAXN];
int mx[MAXN << 2];
int mn[MAXN << 2];
int val[MAXN << 2];

void pushdown(int rt)
{
    if (mx[rt] || mn[rt])
    {
        int tmp = val[rt << 1] + mx[rt];
        if (tmp > 0)
        {
            mx[rt << 1] = max(mx[rt << 1], tmp);
        }
        tmp = val[rt << 1] + mn[rt];
        if (tmp < 0)
        {
            mn[rt << 1] = min(mn[rt << 1], val[rt << 1] + mn[rt]);
        }
        tmp = val[rt << 1 | 1] + mx[rt];
        if (tmp > 0)
        {
            mx[rt << 1 | 1] = max(mx[rt << 1 | 1], tmp);
        }
        tmp = val[rt << 1 | 1] + mn[rt];
        if (tmp < 0)
        {
            mn[rt << 1 | 1] = min(mn[rt << 1 | 1], tmp);
        }
        val[rt << 1] += val[rt];
        val[rt << 1 | 1] += val[rt];
        mx[rt] = mn[rt] = val[rt] = 0;
    }
}

void update(int L, int R, int A, int l = 1, int r = n, int rt = 1)
{
    if (L <= l && r <= R)
    {
        val[rt] += A;
        if (val[rt] > 0)
        {
            mx[rt] = max(mx[rt], val[rt]);
        }
        else
        {
            mn[rt] = min(mn[rt], val[rt]);
        }
        return ;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if (L <= m)
    {
        update(L, R, A, lson);
    }
    if (R > m)
    {
        update(L, R, A, rson);
    }
}

void query(int &mx_, int &mn_, int x, int l = 1, int r = n, int rt = 1)
{
    if (l == r)
    {
        mx_ = mx[rt];
        mn_ = mn[rt];
        return ;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if (x <= m)
    {
        query(mx_, mn_, x, lson);
    }
    else
    {
        query(mx_, mn_, x, rson);
    }
}

template <class T>
inline bool scan_d(T &ret)
{
    char c;
    int sgn;
    if (c = getchar(), c == EOF)
    {
        return 0; //EOF
    }
    while (c != '-' && (c < '0' || c > '9'))
    {
        c = getchar();
    }
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0');
    }
    ret *= sgn;
    return 1;
}

int main()
{
    int T;
    scan_d(T);
    while (T--)
    {
        scan_d(n), scan_d(q);
        clr(mx, 0);
        clr(mn, 0);
        clr(val, 0);
        
        for (int i = 1; i <= n; i++)
        {
            scan_d(a[i]);
        }
        
        int opt, L, R, A;
        int mx_, mi_;
        while (q--)
        {
            scan_d(opt);
            if (opt == 1)
            {
                scan_d(L), scan_d(R), scan_d(A);
                update(L, R, A);
            }
            else
            {
                scan_d(A);
                query(mx_, mi_, A);
                printf("%d\n", max(abs(mx_ + a[A]), abs(mi_ + a[A])));
            }
        }
    }
    
    return 0;
}
