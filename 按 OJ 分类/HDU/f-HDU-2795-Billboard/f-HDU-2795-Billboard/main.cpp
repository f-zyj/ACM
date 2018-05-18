//
//  main.cpp
//  f-HDU-2795-Billboard
//
//  Created by ZYJ on 2017/1/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 200000 + 10;

int h, w, n;
int a[MAXN << 2];

void build(int l, int r, int u)
{
    a[u] = w;
    if (l == r)
    {
        return ;
    }
    int m = (l + r) >> 1;
    build(l, m, u << 1);
    build(m + 1, r, u << 1 | 1);
}

int query(int x, int l, int r, int u)
{
    if (l == r)
    {
        a[u] -= x;
        return l;
    }
    
    int res = 0;
    int m = (l + r) >> 1;
    if (a[u << 1] >= x)
    {
        res = query(x, l, m, u << 1);
    }
    else
    {
        res = query(x, m + 1, r, u << 1 | 1);
    }
    a[u] = max(a[u << 1], a[u << 1 | 1]);
    
    return res;
}

int main()
{
    while (~scanf("%d%d%d", &h, &w, &n))
    {
        if (h > n)
        {
            h = n;
        }
        build(1, h, 1);
        
        int x;
        while (n--)
        {
            scanf("%d", &x);
            if (a[1] < x)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", query(x, 1, h, 1));
            }
        }
    }
    
    return 0;
}
