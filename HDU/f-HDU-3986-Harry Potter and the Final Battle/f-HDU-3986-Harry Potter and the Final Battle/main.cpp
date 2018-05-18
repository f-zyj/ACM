////
////  main.cpp
////  f-HDU-3986-Harry Potter and the Final Battle
////
////  Created by ZYJ on 2016/11/25.
////  Copyright © 2016年 ZYJ. All rights reserved.
////
//  TLE
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
///*
// *  单源最短路径，Dijkstra算法，邻接矩阵形式，复杂度为O(n^2)
// *  求出源beg到所有点的最短路径，传入图的顶点数和邻接矩阵cost[][]
// *  返回各点的最短路径lowcost[]，路径pre[]，pre[i]记录beg到i路径上的父节点，pre[beg] = -1
// *  可更改路径权类型，但是权值必须为非负，下标0~n-1
// */
//const int MAXN = 1010;
//const int INF = 0x3f3f3f3f; //  表示无穷
//bool vis[MAXN];
//int pre[MAXN];
//
//void Dijkstra(int cost[][MAXN], int lowcost[], int n, int beg, int flag)
//{
//    if (flag)
//    {
//        memset(pre, -1, sizeof(pre));
//    }
//    for (int i = 0; i < n; i++)
//    {
//        lowcost[i] = INF;
//        vis[i] = false;
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
//                if (flag)
//                {
//                    pre[i] = k; //  只标记最短路上的父节点
//                }
//            }
//        }
//    }
//}
//
//int cost[MAXN][MAXN];
//int cost_[MAXN][MAXN];
//int lowcost[MAXN];
//
//int main(int argc, const char * argv[])
//{
//    int T;
//    cin >> T;
//    
//    int n, m;
//    while (T--)
//    {
//        memset(cost, 0x3f, sizeof(cost));
//        memset(cost_, 0x3f, sizeof(cost_));
//        
//        cin >> n >> m;
//        int x, y, w;
//        for (int i = 0; i < m; i++)
//        {
//            scanf("%d%d%d", &x, &y, &w);
//            x--, y--;
//            if (w < cost[x][y])
//            {
//                if (cost[x][y] < cost_[x][y])
//                {
//                    cost_[x][y] = cost_[y][x] = cost[x][y];
//                }
//                cost[x][y] = cost[y][x] = w;
//            }
//            else if (w < cost_[x][y])
//            {
//                cost_[x][y] = cost_[y][x] = w;
//            }
//        }
//        
//        Dijkstra(cost, lowcost, n, 0, 1);
//        
//        int ans = lowcost[n - 1];
//        for (int i = n - 1; i != 0 && i != -1; i = pre[i])
//        {
//            int temp = cost[i][pre[i]];
//            cost[i][pre[i]] = cost[pre[i]][i] = cost_[i][pre[i]];
//            Dijkstra(cost, lowcost, n, 0, 0);
//            ans = max(ans, lowcost[n - 1]);
//            cost[i][pre[i]] = cost[pre[i]][i] = temp;
//        }
//        
//        if (ans == INF)
//        {
//            puts("-1");
//        }
//        else
//        {
//            printf("%d\n", ans);
//        }
//    }
//    
//    return 0;
//}

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

/*
 *  时间复杂度O(kE)
 *  队列实现，有时候改成栈实现会更快，较容易修改
 */

const int MAXN = 1010;
const int INF = 0x3f3f3f3f;

struct Edge
{
    int v;
    int cost;
    bool used;
    Edge(int _v = 0, int _cost = 0, int _used = 0) : v(_v), cost(_cost), used(_used) {}
};

vector<Edge> E[MAXN];

void addEdge(int u, int v, int w)
{
    E[u].push_back(Edge(v, w, true));
}

bool vis[MAXN];     //  在队列标志
int cnt[MAXN];      //  每个点的入列队次数
int dist[MAXN];
int pre[MAXN];
int pre_[MAXN];
bool flag;

bool SPFA(int start, int n)
{
    memset(vis, false, sizeof(vis));
    memset(dist, 0x3f, sizeof(dist));
    
    vis[start] = true;
    dist[start] = 0;
    queue<int> que;
    
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
            if (E[u][i].used)
            {
                int v = E[u][i].v;
                if (dist[v] > dist[u] + E[u][i].cost)
                {
                    dist[v] = dist[u] + E[u][i].cost;
                    if (flag)
                    {
                        pre[v] = u;
                        pre_[v] = i;
                    }
                    if (!vis[v])
                    {
                        vis[v] = true;
                        que.push(v);
                        if (++cnt[v] > n)
                        {
                            return false;   //  cnt[i]为入队列次数，用来判定是否存在负环回路
                        }
                    }
                }
            }
        }
    }
    
    return true;
}

void init()
{
    flag = true;
    memset(pre, -1, sizeof(pre));
    memset(pre_, -1, sizeof(pre_));
    
    for (int i = 0; i < MAXN; i++)
    {
        E[i].clear();
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    
    int n, m;
    while (T--)
    {
        init();
        
        scanf("%d%d", &n, &m);
        
        int u, v, w;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        
        SPFA(1, n);
        flag = false;
        
        if (dist[n] == INF)
        {
            puts("-1");
            continue;
        }
        
        int ans = -1;
        int p = n;
        
        while (pre[p] != -1)
        {
            E[pre[p]][pre_[p]].used = false;
            SPFA(1, n);
            if (dist[n] == INF)
            {
                ans = -1;
                break;
            }
            if (dist[n] > ans)
            {
                ans = dist[n];
            }
            E[pre[p]][pre_[p]].used = true;
            p = pre[p];
        }
        
        printf("%d\n", ans);
    }
    return 0;
}
