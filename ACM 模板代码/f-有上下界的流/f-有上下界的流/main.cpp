//
//  main.cpp
//  f-有上下界的流
//
//  Created by ZYJ on 16/7/19.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

/*
 *  有上下界的最小(最大)流
 *  INIT: up[][]为容量上界; low[][]为容量下界;
 *  CALL: mf = limitflow(n,src,sink); flow[][]为流量分配; 
 *  另附: 循环流问题
 *  描述: 无源无汇的网络N,设N是具有基础有向图D=(V,A)的网络.
 *       l和c分别为容量下界和容量上界. 如果定义在A上的函数 
 *       f满足: f(v, V) = f(V, v). V中任意顶点v,
 *       l(a)<=f(a)<=c(a),则称f为网络N的循环流.
 *  解法: 添加一个源s和汇t,对于每个下限容量l不为0的边(u, v),
 *       将其下限去掉,上限改为c-l,增加两条边(u, t),(s, v),
 *       容量均为l.原网络存在循环流等价于新网络最大流是满流.
 */
const int inf = 0x3f3f3f3f;
const int N = 1010;
int up[N][N], low[N][N], flow[N][N];
int pv[N], que[N], d[N];

void maxflow(int n, int src, int sink)
{
    //  BFS增广, O(E * maxflow)
    int p, q, t, i, j;
    do
    {
        for (i = 0; i < n; pv[i++] = 0);
        pv[t = src] = src + 1;
        d[t] = inf;
        for (p = q = 0; p <= q && !pv[sink]; t = que[p++])
        {
            for (i = 0; i < n; i++)
            {
                if (!pv[i] && up[t][i] && (j = up[t][i] - flow[t][i]) > 0)
                {
                    pv[que[q++] = i] = +t + 1, d[i] = d[t] < j ? d[t] : j;
                }
                else if (!pv[i] && up[i][t] && (j = flow[i][t]) > 0)
                {
                    pv[que[q++] = i] = -t - 1, d[i] = d[t] < j ? d[t] : j;
                }
            }
        }
        for (i = sink; pv[i] && i != src;)
        {
            if (pv[i] > 0)
            {
                flow[pv[i] - 1][i] += d[sink], i = pv[i] - 1;
            }
            else
            {
                flow[i][-pv[i] - 1] -= d[sink], i = -pv[i] - 1;
            }
        }
    }
    while (pv[sink]);
    return ;
}

int limitflow(int n, int src, int sink)
{
    int i, j, sk, ks;
    if (src == sink)
    {
        return inf;
    }
    up[n][n + 1] = up[n + 1][n] = up[n][n] = up[n + 1][n + 1] = 0;
    for (i = 0; i < n; i++)
    {
        up[n][i] = up[i][n] = up[n+1][i] = up[i][n+1] = 0;
        for (j = 0; j < n; j++)
        {
            up[i][j] -= low[i][j];
            up[n][i] += low[j][i];
            up[i][n + 1] += low[i][j];
        }
    }
    sk = up[src][sink];
    ks = up[sink][src];
    up[src][sink] = up[sink][src] = inf;
    maxflow(n + 2, n, n + 1);
    for (i = 0; i < n; i++)
    {
        if (flow[n][i] < up[n][i])
        {
            return -1;
        }
    }
    flow[src][sink] = flow[sink][src] = 0;
    up[src][sink] = sk;
    up[sink][src] = ks;     //  !min:src<-sink; max:src->sink;
    maxflow(n, sink, src);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            up[i][j] += low[i][j];
            flow[i][j] += low[i][j];
        }
    }
    for (j = i = 0; i < n; j += flow[src][i++]);
    return j;
}

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
