//
//  main.cpp
//  f-EOJ-大学生程序设计邀请赛（华东师范大学）-G-铁路修复计划
//
//  Created by ZYJ on 2017/5/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

/*
 *  Kruskal算法求MST
 *  对边操作，并排序
 *  切记：初始化赋值问题（tol）
 */

const int MAXN = 100010;   //  最大点数
const int MAXM = MAXN;     //  最大边数
const double ESP = 1e-8;
const int RIGHT_MAX = 1000000;

int F[MAXN];    //  并查集使用

struct Edge
{
    int u;      //  起点
    int v;      //  终点
    double w;      //  权值
} edge[MAXM], edge0[MAXM], edge1[MAXM];   //  存储边的信息

int tol, tol0 = 0, tol1 = 0;        //  边数，加边前赋值为0

void addEdge(int u, int v, double w)
{
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
    return ;
}

void addEdge0(int u, int v, double w)
{
    edge0[tol0].u = u;
    edge0[tol0].v = v;
    edge0[tol0++].w = w;
    return ;
}

void addEdge1(int u, int v, double w)
{
    edge1[tol1].u = u;
    edge1[tol1].v = v;
    edge1[tol1++].w = w;
    return ;
}

bool cmp(Edge a, Edge b)
{
    //  排序函数，将边按照权值从小到大排序
    return a.w < b.w;
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

long long M;

double Kruskal(int n)  //  传入点数，返回最小生成树的权值，如果不连通则返回-1
{
    for (int i = 0; i <= n; i++)
    {
        F[i] = i;
    }
    sort(edge, edge + tol, cmp);
    
    int cnt = 0;    //  计算加入的边数
    double ans = 0;
    for (int i = 0; i < tol; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        double w = edge[i].w;
        int tOne = find(u);
        int tTwo = find(v);
        if (tOne != tTwo)
        {
            ans += w;
            if (ans > M)
            {
                return -1;
            }
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
        return -1;  //  不连通
    }
    else
    {
        return ans;
    }
}

int n, m;

bool charge(double mid)
{
    tol = 0;
    for (int i = 0; i < tol0; i++)
    {
        addEdge(edge0[i].u, edge0[i].v, edge0[i].w);
    }
    for (int i = 0; i < tol1; i++)
    {
        addEdge(edge1[i].u, edge1[i].v, edge1[i].w * mid);
    }
    double res = Kruskal(n);
    if (res < 0)
    {
        return false;
    }
    return true;
}

int main(int argc, const char * argv[])
{
    cin >> n >> m >> M;
    
    int u, v, t, f;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d%d", &u, &v, &t, &f);
        if (f)
        {
            addEdge1(u, v, t);
        }
        else
        {
            addEdge0(u, v, t);
        }
    }
    
    double left = 1, right = RIGHT_MAX, mid;
    while (fabs(right - left) > ESP)
    {
        mid = (left + right) / 2;
        if (charge(mid))
        {
            left = mid;
        }
        else
        {
            right = mid - ESP;
        }
    }
    
    printf("%.6f\n", left);
    
    return 0;
}
