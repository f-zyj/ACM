//
//  main.cpp
//  f-无向图连通分支
//
//  Created by ZYJ on 16/7/18.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

/*
 *  无向图连通分支(dfs/bfs邻接阵)
 *  DFS / BFS / 并查集
 *  返回分支数,id返回1.分支数的值
 *  传入图的大小n和邻接阵mat,不相邻点边权0
 */
#define MAXN 100

void search(int n, int mat[][MAXN], int* dfn, int* low, int now, int& cnt, int& tag, int* id, int* st, int& sp)
{
    int i, j;
    dfn[st[sp++]=now] = low[now] = ++cnt;
    for (i = 0; i < n; i++)
    {
        if (mat[now][i])
        {
            if (!dfn[i])
            {
                search(n, mat, dfn, low, i, cnt, tag, id, st, sp);
                if (low[i] < low[now])
                {
                    low[now]=low[i];
                }
            }
            else if (dfn[i] < dfn[now])
            {
                for (j = 0; j < sp && st[j] != i; j++)
                {
                    if (j < cnt && dfn[i] < low[now])
                    {
                        low[now] = dfn[i];
                    }
                }
            }
        }
    }
    if (low[now] == dfn[now])
    {
        for (tag++; st[sp] != now; id[st[--sp]] = tag);
    }
}

int find_components(int n, int mat[][MAXN], int* id)
{
    int ret = 0, i, cnt, sp, st[MAXN], dfn[MAXN], low[MAXN];
    for (i = 0; i < n; dfn[i++] = 0);
    for (sp = cnt = i = 0; i < n; i++)
    {
        if (!dfn[i])
        {
            search(n, mat, dfn, low, i, cnt, ret, id, st, sp);
        }
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}