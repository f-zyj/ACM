//
//  main.cpp
//  f-有向图强连通分支
//
//  Created by ZYJ on 16/7/18.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

/*
 *  有向图强连通分支(dfs/bfs邻接阵)O(n^2)
 *  返回分支数,id返回1..分支数的值
 *  传入图的大小n和邻接阵mat,不相邻点边权0
 */
#define MAXN 100
int find_components(int n, int mat[][MAXN], int* id)
{
    int ret = 0, a[MAXN], b[MAXN], c[MAXN], d[MAXN], i, j, k, t;
    for (k = 0; k < n; id[k++] = 0);
    for (k = 0; k < n; k++)
    {
        if (!id[k])
        {
            for (i = 0; i < n; i++)
            {
                a[i] = b[i] = c[i] = d[i] = 0;
            }
            a[k] = b[k] = 1;
            for (t = 1; t;)
            {
                for (t = i = 0; i < n; i++)
                {
                    if (a[i] && !c[i])
                    {
                        for (c[i] = t = 1, j = 0; j < n; j++)
                        {
                            if (mat[i][j] && !a[j])
                            {
                                a[j] = 1;
                            }
                        }
                    }
                    if (b[i] && !d[i])
                    {
                        for (d[i] = t = 1, j = 0; j < n; j++)
                        {
                            if (mat[j][i] && !b[j])
                            {
                                b[j] = 1;
                            }
                        }
                    }
                }
            }
            for (ret++, i = 0; i < n; i++)
            {
                if (a[i] & b[i])
                {
                    id[i] = ret;
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
