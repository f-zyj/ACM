//
//  main.cpp
//  f-HDU-1394-Minimum Inversion Number
//
//  Created by ZYJ on 2017/1/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 5555;

int sum[MAXN << 2];

void pushUp(int root)
{
    sum[root] = sum[root << 1] + sum[root << 1 | 1];
}

void build(int root, int l, int r)
{
    sum[root] = 0;
    
    if (l == r)
    {
        return ;
    }
    int m = (l + r) >> 1;
    build(root << 1, l, m);
    build(root << 1 | 1, m + 1, r);
}

void update(int root, int val, int l, int r)
{
    if (l == r)
    {
        sum[root]++;
        return ;
    }
    
    int m = (l + r) >> 1;
    if (val <= m)
    {
        update(root << 1, val, l, m);
    }
    else
    {
        update(root << 1 | 1, val, m + 1, r);
    }
    pushUp(root);
    
}

int query(int L, int R, int l, int r, int root)
{
    if (L <= l && r <= R)
    {
        return sum[root];
    }
    
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m)
    {
        ret += query(L, R, l, m, root << 1);
    }
    if (R > m)
    {
        ret += query(L, R, m + 1, r, root << 1 | 1);
    }
    return ret;
}

int A[MAXN];

int main(int argc, const char * argv[])
{
    int n;
    
    while (~scanf("%d", &n))
    {
        build(1, 0, n - 1);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", A + i);
            sum += query(A[i], n - 1, 0, n - 1, 1);
            update(1, A[i], 0, n - 1);
        }
        int ret = sum;
        for (int i = 0; i < n; i++)
        {
            sum += n - A[i] - A[i] - 1;
            ret = min(ret, sum);
        }
        
        printf("%d\n", ret);
    }
    
    return 0;
}
