//
//  main.cpp
//  f-HDU-2112-HDU Today
//
//  Created by ZYJ on 2016/11/12.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <string>
//#include <cstring>
//#include <vector>
//#include <queue>
//#include <map>
//
//using namespace std;
//
///*
// *  使用优先队列优化Dijkstra算法
// *  复杂度O(ElongE)
// *  注意对vector<Edge> E[MAXN]进行初始化后加边
// */
//
//const int INF = 0x3f3f3f3f;
//const int MAXN = 10010;
//
//struct qNode
//{
//    int v;
//    int c;
//    qNode(int _v = 0, int _c = 0) : v(_v), c(_c) {}
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
//    Edge(int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
//};
//
//vector<Edge> E[MAXN];
//bool vis[MAXN];
//int dist[MAXN];
//
//void Dijkstra(int n, int start)     //  点的编号从1开始
//{
//    memset(vis, false, sizeof(vis));
//    memset(dist, 0x3f, sizeof(dist));
//    priority_queue<qNode> que;
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
//
//const int MAXS = 31;
//
//map<string, int> m;
//map<string, int>::iterator it;
//
//int main(int argc, const char * argv[])
//{
//    int N;
//    char start[MAXS], end[MAXS];
//    char s[MAXS], e[MAXS];
//    int t;
//    
//    while (cin >> N, N != -1)
//    {
//        m.clear();
//        for (int i = 0; i <= N; i++)
//        {
//            E[i].clear();
//        }
//        
//        scanf("%s %s", start, end);
//        m[start] = 0;
//        m[end] = 1;
//        
//        int pos = 2;
//        for (int i = 0; i < N; i++)
//        {
//            scanf("%s %s %d", s, e, &t);
//            it = m.find(s);
//            if (it == m.end())
//            {
//                m[s] = pos++;
//            }
//            it = m.find(e);
//            if (it == m.end())
//            {
//                m[e] = pos++;
//            }
//            addEdge(m[s], m[e], t);
//            addEdge(m[e], m[s], t);
//        }
//        
//        Dijkstra(pos, 0);
//        
//        if (dist[1] == INF)
//        {
//            printf("-1\n");
//        }
//        else
//        {
//            printf("%d\n", dist[1]);
//        }
//    }
//    
//    return 0;
//}


#include <iostream>
#include <cstring>
#include <map>

using namespace std;

/*
 *  单源最短路径，Dijkstra算法，邻接矩阵形式，复杂度为O(n^2)
 *  求出源beg到所有点的最短路径，传入图的顶点数和邻接矩阵cost[][]
 *  返回各点的最短路径lowcost[]，路径pre[]，pre[i]记录beg到i路径上的父节点，pre[beg] = -1
 *  可更改路径权类型，但是权值必须为非负，下标0~n-1
 */
const int MAXN = 160;
const int INF = 0x3f3f3f3f; //  表示无穷
const int MAXS = 31;
bool vis[MAXN];
int pre[MAXN];

void Dijkstra(int cost[][MAXN], int lowcost[], int n, int beg)
{
    for (int i = 0; i < n; i++)
    {
        lowcost[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    lowcost[beg] = 0;
    for (int j = 0; j < n; j++)
    {
        int k = -1;
        int min = INF;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && lowcost[i] < min)
            {
                min = lowcost[i];
                k = i;
            }
        }
        if (k == -1)
        {
            break;
        }
        vis[k] = true;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && lowcost[k] + cost[k][i] < lowcost[i])
            {
                lowcost[i] = lowcost[k] + cost[k][i];
                pre[i] = k;
            }
        }
    }
}

map<string, int> m;
map<string, int>::iterator it;
int cost[MAXN][MAXN];
int lowcost[MAXN];

int main(int argc, const char * argv[])
{
    int N;
    char start[MAXS], end[MAXS];
    char s[MAXS], e[MAXS];
    int t;
    
    while (cin >> N, N != -1)
    {
        m.clear();
        memset(cost, 0x3f, sizeof(cost));
        
        scanf("%s %s", start, end);
        m[start] = 0;
        m[end] = 1;
        
        int pos = 2;
        for (int i = 0; i < N; i++)
        {
            scanf("%s %s %d", s, e, &t);
            it = m.find(s);
            if (it == m.end())
            {
                m[s] = pos++;
            }
            it = m.find(e);
            if (it == m.end())
            {
                m[e] = pos++;
            }
            cost[m[s]][m[e]] = cost[m[e]][m[s]] = t;
        }
        
        if (m[start])
        {
            printf("0\n");
            continue;
        }
        
        Dijkstra(cost, lowcost, pos, 0);
        
        if (lowcost[1] == INF)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", lowcost[1]);
        }
    }
    
    return 0;
}
