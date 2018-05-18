//
//  main.cpp
//  f-SPFA
//
//  Created by ZYJ on 16/7/12.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

//  SPFA(Shortest Path Faster Algorithm)

//const int INF = 0x3F3F3F3F;
//const int V = 30001;
//const int E = 150001;
//
//int pnt[E], cost[E], nxt[E];
//int e, head[V]; int dist[V]; bool vis[V];
//
//int relax(int u, int v, int c)
//{
//    if (dist[v] > dist[u] + c)
//    {
//        dist[v] = dist[u] + c;
//        return 1;
//    }
//    return 0;
//}
//
//inline void addedge(int u, int v, int c)
//{
//    pnt[e] = v;
//    cost[e] = c;
//    nxt[e] = head[u];
//    head[u] = e++;
//}
//
////此处用堆栈实现,有些时候比队列要快
//int SPFA(int src, int n)
//{
//    int i;
//    for (i = 1; i <= n; ++i)
//    {   //  顶点1...n
//        vis[i] = 0;
//        dist[i] = INF;
//    }
//    dist[src] = 0;
//    int Q[E], top = 1;
//    Q[0] = src;
//    vis[src] = true;
//    while(top)
//    {
//        int u, v;
//        u = Q[--top];
//        vis[u] = false;
//        for(i = head[u]; i != -1; i = nxt[i])
//        {
//            v = pnt[i];
//            if(1 == relax(u, v, cost[i]) && !vis[v])
//            {
//                Q[top++] = v;
//                vis[v] = true;
//            }
//        }
//    }
//    return dist[n];
//}
//
//int main()
//{
//    int n, m;
//    while (scanf("%d%d", &n, &m) != EOF)
//    {
//        int i, a, b, c;
//        e = 0;
//        memset(head, -1, sizeof(head));
//        for (i = 0; i < m; ++i)
//        {   //  b-a <= c, 有向边(a, b):c ,边的方向!!!
//            scanf("%d%d%d", &a, &b, &c);
//            addedge(a, b, c);
//        }
//        printf("%d\n", SPFA(1, n));
//    }
//    return 0;
//}

/*
 *  Bellman-Ford算法的一种队列实现,减少了不必要的冗余计算。
 *  它可以在O(kE)的时间复杂度内求出源点到其他所有点的最短路径,可以处理负边。
 *  原理:只有那些在前一遍松弛中改变了距离估计值的点,才可能引起他们的邻接点的距离估计值的改变。
 *  判断负权回路:记录每个结点进队次数,超过|V|次表示有负权。
 */
#define swap(t, a, b) (t=a, a=b, b=t) 
const int INF = 0x3F3F3F3F;
const int V = 1001;
const int E = 20001;
int pnt[E], cost[E], nxt[E];
int e, head[V], dist[V]; bool vis[V];
int cnt[V];     //  入队列次数

int relax(int u, int v, int c)
{
    if (dist[v] > dist[u] + c)
    {
        dist[v] = dist[u] + c;
        return 1;
    }
    return 0;
}

inline void addedge(int u, int v, int c)
{
    pnt[e] = v;
    cost[e] = c;
    nxt[e] = head[u];
    head[u] = e++;
}

//  此处用队列实现
int SPFA(int src, int n)
{
    int i;
    memset(cnt, 0, sizeof(cnt));    //  入队次数
    memset(vis, false, sizeof(vis));
    for (i = 1; i <= n; ++i)
    {
        dist[i] = INF;
    }
    dist[src] = 0;
    queue<int> Q;
    Q.push(src);
    vis[src] = true;
    ++cnt[src];
    while(!Q.empty())
    {
        int u, v;
        u = Q.front();
        Q.pop();
        vis[u] = false;
        for (i = head[u]; i != -1; i = nxt[i])
        {
            v = pnt[i];
            if (1 == relax(u, v, cost[i]) && !vis[v])
            {
                Q.push(v);
                vis[v] = true;
                if ((++cnt[v]) > n )
                {
                    return -1;  //  cnt[i]为入队列次数,用来判断是否存在负权回路
                }
            }
        }
    }
    if (dist[n] == INF)
    {
        return -2;              //  src与n不可达,有些题目可省!!!
    }
    return dist[n];             //  返回src到n的最短距离,根据题意不同而改变
}

int main()
{
    int n, ml, md;
    while (scanf("%d%d%d", &n, &ml, &md) != EOF)
    {
        int i, a, b, c, t;
        e = 0;
        memset(head, -1, sizeof(head));
        for (i = 0; i < ml; ++i)    //  边方向!!!
        {   //  大-小<=c,有向边(小, 大):c
            scanf("%d%d%d", &a, &b, &c);
            if (a > b)
            {
                swap(t, a, b);
            }
            addedge(a, b, c);
        }
        for (i = 0; i < md; ++i)
        {   //  大-小>=c ==> 小-大<=-c,有向边(大, 小):-c
            scanf("%d%d%d", &a, &b, &c);
            if (a < b)
            {
                swap(t, a, b);
            }
            addedge(a, b, -c);
        }
        printf("%d\n", SPFA(1, n));
    }
    return 0;
}

