//
//  main.cpp
//  f-最小生成树
//
//  Created by ZYJ on 16/6/8.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
using namespace::std;

//Prim算法

/*
 * Prim求MST
 * 耗费矩阵cost[][]，标号从0开始，0 ~ n－1
 * 返回最小生成树的权值，返回-1表示原图不连通
 */

//const int INF = 0x3f3f3f3f;
//const int MAXN = 110;
//bool vis[MAXN];
//int lowc[MAXN];
//
//int Prim(int cost[][MAXN], int n)   //0 ~ n - 1
//{
//    int ans = 0;
//    memset(vis, false, sizeof(vis));
//    vis[0] = true;
//    for (int i = 1; i < n; i++)
//    {
//        lowc[i] = cost[0][i];
//    }
//    for (int i = 1; i < n; i++)
//    {
//        int minc = INF;
//        int p = -1;
//        for (int j = 0; j < n; j++)
//        {
//            if (!vis[j] && minc > lowc[j])
//            {
//                minc = lowc[j];
//                p = j;
//            }
//        }
//        if (minc == INF)
//        {
//            return -1;  //原图不连通
//        }
//        ans += minc;
//        vis[p] = true;
//        for (int j = 0; j < n; j++)
//        {
//            if (!vis[j] && lowc[j] > cost[p][j])
//            {
//                lowc[j] = cost[p][j];
//            }
//        }
//    }
//    return ans;
//}

//Kruskal算法

/*
 * Kruskal算法求MST
 * 对边操作，并排序
 */

const int MAXN = 110;   //最大点数
const int MAXM = 10000; //最大边数

int F[MAXN];    //并查集使用
struct Edge
{
    int u;      //起点
    int v;      //终点
    int w;      //权值
} edge[MAXM];   //存储边的信息

int tol;        //边数，加边前赋值为0

void addEdge(int u, int v, int w)
{
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
    return ;
}

bool cmp(Edge a, Edge b)
{
    //排序函数，将边按照权值从小到大排序
    return a.w < b.w;
}

int find(int x)
{
    if (F[x] == -1)
    {
        return x;
    }
    else
    {
        return F[x] = find(F[x]);
    }
}

int Kruskal(int n)  //传入点数，返回最小生成树的权值，如果不连通则返回-1
{
    memset(F, -1, sizeof(F));
    sort(edge, edge + tol, cmp);
    int cnt = 0;    //计算加入的边数
    int ans = 0;
    for (int i = 0; i < tol; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        int tOne = find(u);
        int tTwo = find(v);
        if (tOne != tTwo)
        {
            ans += w;
            F[tOne] = tTwo;
            cnt++;
        }
        if (cnt == n - 1)
        {
            break;
        }
    }
    if (cnt < n - 1)
    {
        return -1;  //不连通
    }
    else
    {
        return ans;
    }
    
}

int main(int argc, const char * argv[])
{
    
    std::cout << "Hello, World!\n";
    return 0;
}
