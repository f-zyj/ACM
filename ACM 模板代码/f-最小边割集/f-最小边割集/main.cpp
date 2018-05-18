//
//  main.cpp
//  f-最小边割集
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

int min_edge_cut(int n, int mat[][MAXN], int source, int sink, int set[][2])
{
    int m0[MAXN][MAXN], m[MAXN][MAXN], i, j, k, l, ret = 0, last;
    if (source == sink)
    {
        return -1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            m0[i][j] = (mat[i][j] != 0);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            m[i][j] = m0[i][j];
        }
    }
    last = max_flow(n, m, source, sink);
    for (k = 0; k < n && last; k++)
    {
        for (l = 0; l < n && last; l++)
        {
            if (m0[k][l])
            {
                for (i = 0; i < n + n; i++)
                {
                    for (j = 0; j < n + n; j++)
                    {
                        m[i][j] = m0[i][j];
                    }
                }
                m[k][l] = 0;
                if (max_flow(n, m, source, sink) < last)
                {
                    set[ret][0] = k;
                    set[ret++][1] = l;
                    m0[k][l] = 0;
                    last--;
                }
            }
        }
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
