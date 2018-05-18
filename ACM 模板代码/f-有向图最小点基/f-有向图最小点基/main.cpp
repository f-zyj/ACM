//
//  main.cpp
//  f-有向图最小点基
//
//  Created by ZYJ on 16/7/18.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

/*
 *  有向图最小点基(邻接阵)O(n^2)
 *  点基B满足:对于任意一个顶点Vj,一定存在B中的一个Vi,使得Vi是Vj的前代。
 *  返回点基大小和点基 传入图的大小n和邻接阵mat,不相邻点边权0 需要调用强连通分支
 *  find_components(n, mat, id);参考有向图强连通分支
 */
#define MAXN 100
int base_vertex(int n, int mat[][MAXN], int* sets)
{
    int ret=0, id[MAXN], v[MAXN], i, j;
    j = find_components(n, mat, id);
    for (i = 0; i < j; v[i++] = 1);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (id[i] != id[j] && mat[i][j])
            {
                v[id[j] - 1] = 0;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (v[id[i] - 1])
        {
            v[id[sets[ret++] = i] - 1] = 0;
        }
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
