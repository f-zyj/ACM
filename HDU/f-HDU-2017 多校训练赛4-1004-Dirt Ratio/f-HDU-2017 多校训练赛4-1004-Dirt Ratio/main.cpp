//
//  main.cpp
//  f-HDU-2017 多校训练赛4-1004-Dirt Ratio
//
//  Created by ZYJ on 2017/8/4.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>

#define lson rt << 1
#define rson rt << 1 | 1

using namespace std;

const int MAXN = 6e4 + 10;
const int MAXM = MAXN << 2;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;

int n;
double tmp;
int a[MAXN];
int ap[MAXN];
int tag[MAXM];
double val[MAXM];

inline void pushdown(int rt)
{
    if (tag[rt])
    {
        tag[lson] += tag[rt];
        tag[rson] += tag[rt];
        val[lson] += tag[rt];
        val[rson] += tag[rt];
        tag[rt] = 0;
    }
}

void build(int rt, int l, int r, double w)
{
    val[rt] = w * l;
    tag[rt] = 0;
    if (l == r)
    {
        return ;
    }
    
    int m = (l + r) >> 1;
    build(lson, l, m, w);
    build(rson, m + 1, r, w);
}

void update(int rt, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        tag[rt] += 1;
        val[rt] += 1;
        return ;
    }
    
    pushdown(rt);
    int m = (l + r) >> 1;
    if (ql <= m)
    {
        update(lson, l, m, ql, qr);
    }
    if (qr > m)
    {
        update(rson, m + 1, r, ql, qr);
    }
    val[rt] = min(val[lson], val[rson]);
}

void query(int rt, int l, int r, int p)
{
    if (r <= p)
    {
        if (tmp > val[rt])
        {
            tmp = val[rt];
        }
        return ;
    }
    
    pushdown(rt);
    int m = (l + r) >> 1;
    query(lson, l, m, p);
    if (p > m)
    {
        query(rson, m + 1, r, p);
    }
}

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
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int T;
    scan_d(T);
    while (T--)
    {
        scan_d(n);
        for (int i = 1; i <= n; i++)
        {
            scan_d(a[i]);
        }
        
        double l = 0, r = 1, m = -1;
        while (r - l > EPS)
        {
            m = (l + r) / 2;
            build(1, 1, n, m);
            
            int j;
            for (j = 1; j <= n; j++)
            {
                ap[j] = 0;
            }
            for (j = 1; j <= n; j++)
            {
                update(1, 1, n, ap[a[j]] + 1, j);
                tmp = INF;
                query(1, 1, n, j);
                if (tmp - m * (j + 1) <= 0)
                {
                    break;
                }
                ap[a[j]] = j;
            }
            
            if (j <= n)
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        
        printf("%.10f\n", m);
    }
    
    return 0;
}
