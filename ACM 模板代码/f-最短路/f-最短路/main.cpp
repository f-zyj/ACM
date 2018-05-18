//
//  main.cpp
//  f-最短路
//
//  Created by ZYJ on 16/6/6.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace::std;

//Dijkstra 单源最短路，邻接矩阵形式

/*
 * 单源最短路径，Dijkstra算法，邻接矩阵形式，复杂度为O(n^2)
 * 求出源beg到所有点的最短路径，传入图的顶点数和邻接矩阵cost[][]
 * 返回各点的最短路径lowcost[]，路径pre[]，pre[i]记录beg到i路径上的父节点，pre[beg] = -1
 * 可更改路径权类型，但是权值必须为非负
 */

//const int MAXN = 1010;
//#define typec int
//const typec INF = 0x3f3f3f3f; //表示无穷
//bool vis[MAXN];
//int pre[MAXN];
//
//void Dijkstra(typec cost[][MAXN], typec lowcost[], int n, int beg)
//{
//    for (int i = 0; i < n; i++)
//    {
//        lowcost[i] = INF;
//        vis[i] = false;
//        pre[i] = -1;
//    }
//    lowcost[beg] = 0;
//    for (int j = 0; j < n; j++)
//    {
//        int k = -1;
//        int min = INF;
//        for (int i = 0; i < n; i++)
//        {
//            if (!vis[i] && lowcost[i] < min)
//            {
//                min = lowcost[i];
//                k = i;
//            }
//        }
//        if (k == -1)
//        {
//            break;
//        }
//        vis[k] = true;
//        for (int i = 0; i < n; i++)
//        {
//            if (!vis[i] && lowcost[k] + cost[k][i] < lowcost[i])
//            {
//                lowcost[i] = lowcost[k] + cost[k][i];
//                pre[i] = k;
//            }
//        }
//    }
//}

//Dijkstar 算法 ＋ 堆优化

/* 
 * 使用优先队列优化Dijkstra算法
 * 复杂度O(ElongE)
 * 注意对vector<Edge>E[MAXN]进行初始化后加边
 */
 
//const int INF = 0x3f3f3f3f;
//const int MAXN = 1000010;
//
//struct qNode
//{
//    int v;
//    int c;
//    qNode(int _v = 0, int _c = 0) : v(_v), c(_c){}
//    bool operator < (const qNode &r)const
//    {
//        return c > r.c;
//    }
//};
//
//struct Edge
//{
//    int v;
//    int cost;
//    Edge(int _v = 0, int _cost = 0) : v(_v), cost(_cost){}
//};
//
//vector<Edge>E[MAXN];
//bool vis[MAXN];
//int dist[MAXN];
//
//void Dijkstra(int n, int start) //点的编号从1开始
//{
//    memset(vis, false, sizeof(vis));
//    memset(dist, 0x3f, sizeof(dist));
//    priority_queue<qNode>que;
//    
//    while (!que.empty())
//    {
//        que.pop();
//    }
//    dist[start] = 0;
//    que.push(qNode(start, 0));
//    qNode tmp;
//    
//    while (!que.empty())
//    {
//        tmp = que.top();
//        que.pop();
//        int u = tmp.v;
//        if (vis[u])
//        {
//            continue;
//        }
//        vis[u] = true;
//        for (int i = 0; i < E[u].size(); i++)
//        {
//            int v = E[tmp.v][i].v;
//            int cost = E[u][i].cost;
//            if (!vis[v] && dist[v] > dist[u] + cost)
//            {
//                dist[v] = dist[u] +cost;
//                que.push(qNode(v, dist[v]));
//            }
//        }
//    }
//}
//
//void addEdge(int u, int v, int w)
//{
//    E[u].push_back(Edge(v, w));
//}

//单源最短路 BellmanFord算法

/*
 * 单源最短路BellmanFord算法，复杂度O(VE)
 * 可以处理负边权图
 * 可以判断是否存在负环回路，返回true，当且仅当图中不包含从源点可达的负权回路
 * vector<Edge>E;先E.clear()初始化，然后加入所有边
 */

//const int INF = 0x3f3f3f3f;
//const int MAXN = 550;
//int dist[MAXN];
//struct Edge
//{
//    int u;
//    int v;
//    int cost;
//    Edge(int _u = 0, int _v = 0, int _cost = 0) : u(_u), v(_v), cost(_cost){}
//};
//
//vector<Edge>E;
//
//bool BellmanFord(int start, int n)  //编号从1开始
//{
//    memset(dist, 0x3f, sizeof(dist));
//    dist[start] = 0;
//    for (int i = 1; i < n; i++)     //最多做n - 1次
//    {
//        bool flag = false;
//        for (int j = 0; j < E.size(); j++)
//        {
//            int u = E[j].u;
//            int v = E[j].v;
//            int cost = E[j].cost;
//            if (dist[v] > dist[u] + cost)
//            {
//                dist[v] = dist[u] + cost;
//                flag = true;
//            }
//        }
//        if (!flag)                  //无负环回路
//        {
//            return true;
//        }
//    }
//    for (int j = 0; j < E.size(); j++)
//    {
//        if (dist[E[j].v] > dist[E[j].u] + E[j].cost)
//        {
//            return false;           //有负环回路
//        }
//    }
//    return true;                    //无负环回路
//}

//单源最短路 SPFA

/*
 * 时间复杂度O(kE)
 * 队列实现，有时候改成栈实现会更快，较容易修改
 */

const int MAXN = 1010;
const int INF = 0x3f3f3f3f;

struct Edge
{
    int v;
    int cost;
    Edge(int _v = 0, int _cost = 0) : v(_v), cost(_cost){}
};

vector<Edge>E[MAXN];

void addEdge(int u, int v, int w)
{
    E[u].push_back(Edge(v, w));
}

bool vis[MAXN];     //在队列标志
int cnt[MAXN];      //每个点的入列队次数
int dist[MAXN];

bool SPFA(int start, int n)
{
    memset(vis, false, sizeof(vis));
    memset(dist, 0x3f, sizeof(dist));
    
    vis[start] = true;
    dist[start] = 0;
    queue<int>que;
    
    while (!que.empty())
    {
        que.pop();
    }
    que.push(start);
    memset(cnt, 0, sizeof(cnt));
    cnt[start] = 1;
    
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        vis[u] = false;
        
        for (int i = 0; i < E[u].size(); i++)
        {
            int v = E[u][i].v;
            if (dist[v] > dist[u] + E[u][i].cost)
            {
                dist[v] = dist[u] + E[u][i].cost;
                if (!vis[v])
                {
                    vis[v] = true;
                    que.push(v);
                    if (++cnt[v] > n)
                    {
                        return false;   //cnt[i]为入队列次数，用来判定是否存在负环回路
                    }
                }
            }
        }
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
