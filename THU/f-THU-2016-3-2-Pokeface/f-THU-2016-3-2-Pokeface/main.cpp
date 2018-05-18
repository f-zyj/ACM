//
//  main.cpp
//  f-THU-2016-3-2-Pokeface
//
//  Created by ZYJ on 2016/12/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e6 + 5;

struct point
{
    int w;
    bool flag;

    point()
    {
        flag = 0;
    }
};

struct Btree
{
    point A[MAXN * 20];
    int N;
    Btree()
    {
        N = 0;
    }
    int init(int l, int r, int k)   //  初始化函数
    {
        if (l > r)
        {
            return 0;
        }
        if (l == r)
        {
            return A[k].w = 1;
        }
        int mid = (l + r) >> 1;
        return A[k].w = init(l, mid, k << 1) + init(mid + 1, r, (k << 1) + 1);
    }
    void _insert(int L, int R, int l, int r, int k)
    {
        int n = R - L + 1;
        if (l < L)
        {
            l = L;
        }
        if (r > R)
        {
            r = R;
        }
        if (L == l && R == r)
        {
            A[k].flag = !A[k].flag;
            A[k].w = n - A[k].w;
            return ;
        }
        int mid = (L + R) >> 1;
        if (A[k].flag)
        {
            if (l - 1 >= L)
            {
                _insert(mid + 1, R, r + 1, R, (k << 1) + 1);
            }
            if (r + 1 <= R)
            {
                _insert(L, mid, L, l - 1, k << 1);
            }
            A[k].flag = 0;
            A[k].w = A[k << 1].w + A[(k << 1) + 1].w;
        }
        else
        {
            if (l <= mid)
            {
                _insert(L, mid, l, r, k << 1);
            }
            if (r > mid)
            {
                _insert(mid + 1, R, l, r, (k << 1) + 1);
            }
            A[k].w = A[k << 1].w + A[(k << 1) + 1].w;
        }
    }
    int _Query(int L, int R, int l, int r, int k)
    {
        int n = R - L + 1;
        if (l <= L && r >= R)
        {
            return A[k].w;
        }
        int mid = (L + R) >> 1;
        int sum = 0;
        if (A[k].flag)
        {
            if (l <= mid)
            {
                sum += _Query(L, mid, l, r, k << 1);
            }
            if (r > mid)
            {
                sum += _Query(mid + 1, R, l, r, (k << 1) + 1);
            }
            sum = n - sum;
        }
        else
        {
            if (l <= mid)
            {
                sum += _Query(L, mid, l, r, k << 1);
            }
            if (r > mid)
            {
                sum += _Query(mid + 1, R, l, r, (k << 1) + 1);
            }
        }
        return sum;
    }
    void insert(int l, int r)
    {
        _insert(1, N, l, r, 1);
    }
    int Query(int l, int r)
    {
        return _Query(1, N, l, r, 1);
    }
} T;

int main ()
{
    int M;
    scanf("%d%d", &T.N, &M);
    T.init(1, T.N, 1);
    
    char s[2];
    int l, r;
    for (int i = 0; i < M; i++)
    {
        scanf("%s%d%d", s, &l, &r);
        if (s[0] == 'Q')
        {
            printf("%d\n", T.Query(l, r));
        }
        else
        {
            T.insert(l, r);
        }
    }
    
    return 0;
}
