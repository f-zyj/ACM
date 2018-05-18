//
//  main.cpp
//  f-HDU-1598-find the most comfortable road
//
//  Created by ZYJ on 2016/11/1.
//  Copyright &#169; 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 210;  //  最大点数
const int MAXM = 1010; //  最大边数
const int INF = 0x3f3f3f3f;

int pre[MAXN];    //  并查集使用

struct Edge
{
    int u;      //  起点
    int v;      //  终点
    int w;      //  权值
} edge[MAXM];   //  存储边的信息

int tol;        //  边数，加边前赋值为0

void addEdge(int u, int v, int w)
{
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
    return ;
}

bool cmp(Edge a, Edge b)
{
    //  排序函数，将边按照权值从小到大排序
    return a.w < b.w;
}

int find(int x)
{
    if (pre[x] == x)
    {
        return x;
    }
    else
    {
        return pre[x] = find(pre[x]);
    }
}

void join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    
    if (fx != fy)
    {
        pre[fx] = fy;
    }
}

void init(int n)
{
    for (int i = 0; i <= n; i++)
    {
        pre[i] = i;
    }
}

int main()
{
    int n, m;
    int u, v, w;
    int Q;
    int start, end;
    
    while (scanf("%d%d", &n, &m) != EOF)
    {
        tol = 0;
        
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
        }
        sort(edge, edge + tol, cmp);
        
        cin >> Q;
        while (Q--)
        {
            int res = INF;
            int temp;
            scanf("%d%d", &start, &end);
            
            for (int i = 0; i < m; i++)
            {
                init(n);
                temp = INF;
                
                int flag = 1;
                for (int j = i; j < m; j++)
                {
                    join(edge[j].u, edge[j].v);
                    if (find(start) == find(end))
                    {
                        temp = edge[j].w - edge[i].w;
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    break;
                }
                res = min(res, temp);
            }
            
            if (res == INF)
            {
                cout << "-1\n";
            }
            else
            {
                cout << res << '\n';
            }
        }
    }
    
    return 0;
}
