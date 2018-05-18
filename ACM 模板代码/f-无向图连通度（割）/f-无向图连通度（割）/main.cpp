//
//  main.cpp
//  f-无向图连通度（割）
//
//  Created by ZYJ on 16/6/14.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

//无向图连通度（割）

/*
 * INIT: edge[][]邻接矩阵；vis[],pre[],anc[],deg[]置为0；
 * CALL: dfs(0, -1, 1, n);
 * k = deg[0], deg[i] + 1(i = 1...n - 1)为删除该节点后得到的连通图个数
 * 注意: 0作为根比较特殊
 */

const int V = 1010;
int edge[V][V];
int anc[V];
int pre[V];
int vis[V];
int deg[V];

void dfs(int cur, int father, int dep, int n)
{
    //vertex:0 ~ n - 1
    int cnt = 0;
    vis[cur] = 1;
    pre[cur] = anc[cur] = dep;
    for (int i = 0; i < n; i++)
    {
        if (edge[cur][i])
        {
            if (i != father && 1 == vis[i])
            {
                if (pre[i] < anc[cur])
                {
                    anc[cur] = pre[i];  //back edge
                }
            }
            if (0 == vis[i])            //tree edge
            {
                dfs(i, cur, dep + 1, n);
                cnt++;  //分支个数
                if (anc[i] < anc[cur])
                {
                    anc[cur] = anc[i];
                }
                if ((cur == 0 && cnt > 1) || (cnt != 0 && anc[i] >= pre[cur]))
                {
                    deg[cur]++; //link degree of a vertex
                }
            }
        }
    }
    vis[cur] = 2;
    return ;
}

int main(int argc, const char * argv[])
{
    
    std::cout << "Hello, World!\n";
    return 0;
}
