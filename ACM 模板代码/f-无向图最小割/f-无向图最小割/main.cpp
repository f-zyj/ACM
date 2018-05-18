//
//  main.cpp
//  f-无向图最小割
//
//  Created by ZYJ on 16/7/18.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

//  无向图最小割

/*
 *  INIT: 初始化邻接矩阵g[][]
 *  CALL: res = mincut(n);
 *  注: Stoer-Wagner Minimum Cut;
 *  找边的最小集合，若其被删去则图变得不连通（我们把这种形式称为最小割问题）
 */
#define typec int               //  type of res
const typec inf = 0x3f3f3f3f;   //  max of res
const typec maxw = 1000;        //  maximum edge weight
const typec V = 10010;
typec g[V][V], w[V];
int a[V], v[V], na[V];

typec minCut(int n)
{
    int i, j, pv, zj;
    typec best = maxw * n * n;
    for (i = 0; i < n; i++)
    {
        v[i] = i;   //  vertex: 0 ~ n-1
    }
    while (n > 1)
    {
        for (a[v[0]] = 1, i = 1; i < n; i++)
        {
            a[v[i]] = 0;
            na[i - 1] = i;
            w[i] = g[v[0]][v[i]];
        }
        for (pv = v[0], i = 1; i < n; i++)
        {
            for (zj = -1, j = 1; j < n; j++)
            {
                if (!a[v[j]] && (zj < 0 || w[j] > w[zj]))
                {
                    zj = j;
                }
            }
            a[v[zj]] = 1;
            if (i == n - 1)
            {
                if (best > w[zj])
                {
                    best = w[zj];
                }
                for (i = 0; i < n; i++)
                {
                    g[v[i]][pv] = g[pv][v[i]] += g[v[zj]][v[i]];
                }
                v[zj] = v[--n];
                break;
            }
            pv = v[zj];
            for (j = 1; j < n; j++)
            {
                if(!a[v[j]])
                {
                    w[j] += g[v[zj]][v[j]];
                }
            }
        }
    }
    return best;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
