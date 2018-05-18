//
//  main.cpp
//  f-HDU-3367-Pseudoforest
//
//  Created by ZYJ on 2016/11/4.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

/*
 *  Kruskal算法求MST
 *  对边操作，并排序
 */

const int MAXN = 10010;     //  最大点数
const int MAXM = 100010;    //  最大边数

int F[MAXN];    //  并查集使用
int flag[MAXN]; //  标记是否有环

struct Edge
{
    int u;      //  起点
    int v;      //  终点
    int w;      //  权值
} edge[MAXM];   //  存储边的信息

int tol;        //  边数，加边前赋值为0!!!!!!!

void addEdge(int u, int v, int w)
{
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
    return ;
}

bool cmp(Edge a, Edge b)
{
    //  排序函数，将边按照权值从大到小排序
    return a.w > b.w;
}

int find(int x)
{
    if (F[x] == x)
    {
        return x;
    }
    else
    {
        return F[x] = find(F[x]);
    }
}

int Kruskal(int n)  //  传入点数，返回最小生成树的权值，如果不连通则返回-1
{
    for (int i = 0; i <= n; i++)
    {
        F[i] = i;
    }
    sort(edge, edge + tol, cmp);
    
    int ans = 0;
    for (int i = 0; i < tol; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        int fu = find(u);
        int fv = find(v);
        //  两个都有环则不合并
        if (flag[fu] && flag[fv])
        {
            continue;
        }
        //  合并
        ans += w;
        F[fu] = fv;
        
        if (flag[fv] || flag[fu] || fv == fu)
        {
            flag[fv] = 1;
        }

    }
    
    return ans;
}

int main(int argc, const char * argv[])
{
    int n, m;
    int u, v, w;
    
    while (cin >> n >> m, n != 0 || m != 0)
    {
        tol = 0;
        memset(flag, 0, sizeof(flag));
        
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
        }
        
        int res = Kruskal(n);
        cout << res << '\n';
    }
    
    return 0;
}
