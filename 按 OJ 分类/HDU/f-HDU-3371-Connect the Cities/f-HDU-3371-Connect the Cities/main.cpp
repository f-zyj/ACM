//
//  main.cpp
//  f-HDU-3371-Connect the Cities
//
//  Created by ZYJ on 2016/10/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstdlib>

using namespace std;

/*
 *  Kruskal算法求MST
 *  对边操作，并排序
 */

const int MAXN = 510;   //  最大点数
const int MAXM = 25010; //  最大边数

typedef struct Edge
{
    int u;      //  起点
    int v;      //  终点
    int w;      //  权值
} Edge;

int tol;            //  边数，加边前赋值为0
int pre[MAXN];      //  并查集使用
Edge edge[MAXM];    //  存储边的信息

void init(int n)
{
    tol = 0;
    for (int i = 0; i <= n; i++)
    {
        pre[i] = i;
    }
}

void addEdge(int u, int v, int w)
{
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
    return ;
}

//int cmp(Edge a, Edge b)
//{
//    //  排序函数，将边按照权值从小到大排序
//    return a.w < b.w;
//}

int cmp(const void *a, const void *b)
{
    //  排序函数，将边按照权值从小到大排序
    return ((Edge *)a)->w > ((Edge *)b)->w;
}

int find(int x)
{
    int r = x;
    while (pre[r] != r)
    {
        r = pre[r];
    }
    
    int i = x, j;
    while (i != r)
    {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    
    return r;
}

bool join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        pre[fx] = fy;
        return true;
    }
    return false;
}

int Kruskal(int n)  //  传入点数，返回最小生成树的权值，如果不连通则返回-1
{
//    sort(edge, edge + tol, cmp);
    qsort(edge, tol, sizeof(Edge), cmp);
    
    int cnt = 0;    //  计算加入的边数
    for (int i = 1; i <= n; i++)
    {
        if (pre[i] == i)
        {
            cnt++;
        }
    }
    int ans = 0;
    for (int i = 0; i < tol; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        if (join(u, v))
        {
            ans += w;
            cnt--;
        }
        if (cnt == 1)
        {
            break;
        }
    }
    if (cnt != 1)
    {
        return -1;  //  不连通
    }
    else
    {
        return ans;
    }
    
}

int main(int argc, const char * argv[])
{
    int T;
    scanf("%d", &T);
    
    int N, M, K;
    int A, B, C;
    
    while (T--)
    {
        scanf("%d%d%d", &N, &M, &K);
        
        init(N);
        
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d%d", &A, &B, &C);
            addEdge(A, B, C);
        }
        
        for (int i = 0; i < K; i++)
        {
            scanf("%d%d%d", &A, &B, &C);
            join(B, C);
            for (int j = 2; j < A; j++)
            {
                scanf("%d", &C);
                join(B, C);
            }
        }
        
        int ans = Kruskal(N);
        
        printf("%d\n", ans);
    }
    
    return 0;
}
