//
//  main.cpp
//  f-最佳点割集
//
//  Created by ZYJ on 16/7/20.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

#define MAXN 100
#define inf 1000000000

int max_flow(int n, int mat[][MAXN], int source, int sink)
{
    int v[MAXN], c[MAXN], p[MAXN], ret = 0, i, j;
    for (;;)
    {
        for (i = 0; i < n; i++)
        {
            v[i] = c[i] = 0;
        }
        for (c[source] = inf; ;)
        {
            for (j = -1, i = 0; i < n; i++)
            {
                if (!v[i] && c[i] && (j == -1 || c[i] > c[j]))
                {
                    j = i;
                }
            }
            if (j < 0)
            {
                return ret;
            }
            if (j == sink)
            {
                break;
            }
            for (v[j] = 1, i = 0; i < n; i++)
            {
                if (mat[j][i] > c[i] && c[j] > c[i])
                {
                    c[i] = mat[j][i] < c[j] ? mat[j][i] : c[j], p[i] = j;
                }
            }
        }
        for (ret += j = c[i = sink]; i != source; i = p[i])
        {
            mat[p[i]][i] -= j, mat[i][p[i]] += j;
        }
    }
}

int best_vertex_cut(int n, int mat[][MAXN], int *cost, int source, int sink, int *set, int &mincost)
{
    int m0[MAXN][MAXN], m[MAXN][MAXN], i, j, k, ret = 0, last;
    if (source == sink || mat[source][sink])
    {
        return -1;
    }
    for (i = 0; i < n + n; i++)
    {
        for (j = 0; j < n + n; j++)
        {
            m0[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (mat[i][j])
            {
                m0[i][n + j] = inf;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        m0[n + i][i] = cost[i];
    }
    for (i = 0; i < n + n; i++)
    {
        for (j = 0; j < n + n; j++)
        {
            m[i][j] = m0[i][j];
        }
    }
    mincost = last = max_flow(n + n, m, source, n + sink);
    for (k = 0; k < n && last; k++)
    {
        if (k != source && k != sink)
        {
            for (i = 0; i < n + n; i++)
            {
                for (j = 0; j < n + n; j++)
                {
                    m[i][j] = m0[i][j];
                }
            }
            m[n + k][k] = 0;
            if (max_flow(n + n, m, source, n + sink) == last - cost[k])
            {
                set[ret++] = k;
                m0[n + k][k] = 0;
                last -= cost[k];
            }
        }
    }
    return ret;
}