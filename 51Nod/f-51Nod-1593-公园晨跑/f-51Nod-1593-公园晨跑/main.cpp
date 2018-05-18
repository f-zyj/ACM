//
//  main.cpp
//  f-51Nod-1593-公园晨跑
//
//  Created by ZYJ on 2017/7/26.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <string.h>

#define lson rt << 1
#define rson rt << 1 | 1

using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct point
{
    int pos;
    ll mx;
    
    point()
    {
        mx = -INF;
    }
};

struct Seg
{
    int root, pos, n;
    ll mx, key;
    point A[MAXN << 3];
    
    Seg()
    {
        root = 1;
    }
    
    void push_up(point &a, int rt)
    {
        if (A[lson].mx > A[rson].mx)
        {
            a.mx = A[lson].mx;
            a.pos = A[lson].pos;
        }
        else
        {
            a.mx = A[rson].mx;
            a.pos = A[rson].pos;
        }
    }
    
    void update(int x, int l, int r, int rt)
    {
        if (x > r || x < l)
        {
            return ;
        }
        if (l == r)
        {
            A[rt].mx = key;
            A[rt].pos = x;
            return ;
        }
        int m = (l + r) >> 1;
        update(x, l, m, lson);
        update(x, m + 1, r, rson);
        push_up(A[rt], rt);
    }
    void update(int x, ll k)
    {
        key = k;
        update(x, 0, n, root);
    }
    
    void query(int l, int r, int L, int R, int rt)
    {
        if (R < l || L > r)
        {
            return ;
        }
        if (L >= l && R <= r)
        {
            if (A[rt].mx > mx)
            {
                mx = A[rt].mx;
                pos = A[rt].pos;
            }
            return ;
        }
        int M = (L + R) >> 1;
        query(l, r, L, M, lson);
        query(l, r, M + 1, R, rson);
    }
    
    int query(int l, int r)
    {
        mx = -INF;
        query(l, r, 0, n, root);
        return pos;
    }
} segA, segB;

ll A[MAXN << 1];
ll B[MAXN << 1];

int n, m;
ll h;

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

template <class T>
inline void print_d(T x)
{
    if (x > 9)
    {
        print_d(x / 10);
    }
    putchar(x % 10 + '0');
}

int main ()
{
    scan_d(n), scan_d(m);
    int len = n << 1;
    for (int i = 1; i <= n; i++)
    {
        scan_d(A[i]);
        A[i + n] = A[i];
    }
    for (int i = 1; i < len; i++)
    {
        A[i] += A[i - 1];
    }
    memcpy(B, A, sizeof(A));
    
    for (int i = 0; i < n; i++)
    {
        scan_d(h);
        h = h << 1;
        A[i] += h;
        B[i] -= h;
        A[i + n] += h;
        B[i + n] -= h;
    }
    
    segA.n = len - 1;
    segB.n = len - 1;
    for (int i = 0; i < len; i++)
    {
        segA.update(i, A[i]);
        segB.update(i, -B[i]);
    }
    
    int l, r;
    while (m--)
    {
        scan_d(l), scan_d(r);
        l--;
        r--;
        if (l <= r)
        {
            int tmp = r + 1;
            r = n + l - 1;
            l = tmp;
        }
        else
        {
            swap(l, r);
            l++;
            r--;
        }
        
        int mx = segA.query(l, r);
        int mn = segB.query(l, r);
        if (mx == mn)
        {
            int tmp = -1, tmp_;
            if (mx > l)
            {
                tmp = segA.query(l, mx - 1);
            }
            if (mx < r)
            {
                tmp_ = segA.query(mx + 1, r);
                if (tmp == -1|| A[tmp] < A[tmp_])
                {
                    tmp = tmp_;
                }
            }
            ll ans1 = A[tmp] - B[mn];
            
            tmp = -1;
            if (mn > l)
            {
                tmp = segB.query(l, mn - 1);
            }
            if (mn < r)
            {
                tmp_ = segB.query(mn + 1, r);
                if (tmp == -1 || B[tmp] > B[tmp_])
                {
                    tmp = tmp_;
                }
            }
            ll ans2 = A[mx] - B[tmp];
            print_d(max(ans1, ans2));
            putchar(10);
        }
        else
        {
            print_d(A[mx] - B[mn]);
            putchar(10);
        }
    }
    
    return 0;
}
