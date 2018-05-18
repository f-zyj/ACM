//
//  main.cpp
//  f-带权值的并查集
//
//  Created by ZYJ on 16/7/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

/*
 *  INIT: makeset(n);
 *  CALL: findset(x); unin(x, y);
 */
const int N = 1010;

struct lset
{
    int p[N], rank[N], sz;
    void link(int x, int y)
    {
        if (x == y)
        {
            return ;
        }
        if (rank[x] > rank[y])
        {
            p[y] = x;
        }
        else
        {
            p[x] = y;
        }
        if (rank[x] == rank[y])
        {
            rank[y]++;
        }
        return ;
    }
    void makeset(int n)
    {
        sz = n;
        for (int i = 0; i < sz; i++)
        {
            p[i] = i;
            rank[i] = 0;
        }
        return ;
    }
    int findset(int x)
    {
        if (x != p[x])
        {
            p[x] = findset(p[x]);
        }
        return p[x];
    }
    void unin(int x, int y)
    {
        link(findset(x), findset(y));
        return ;
    }
    void compress()
    {
        for (int i = 0; i < sz; i++)
        {
            findset(i);
        }
        return ;
    }
};