//
//  main.cpp
//  f-PAT-天梯赛习题集-L3-014-周游世界
//
//  Created by ZYJ on 2017/3/27.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

/*
 *  使用优先队列优化Dijkstra算法
 *  复杂度O(ElongE)
 *  注意对vector<Edge> E[MAXN]进行初始化后加边
 */

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;

struct qNode
{
    int v;
    int c;
    qNode(int _v = 0, int _c = 0) : v(_v), c(_c) {}
    bool operator < (const qNode &r) const
    {
        return c > r.c;
    }
};

struct Edge
{
    int v;
    int cost;
    Edge(int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
};

vector<pair<Edge, int> > E[MAXN];
bool vis[MAXN];
int dist[MAXN];     //  最短路距离
int pre[MAXN];      //  父节点，记录路径
int pre_[MAXN];     //  父节点所在路线（转接点算到上一条路线）
int cnt[MAXN];      //  累计经过路线数目

void Dijkstra(int n, int start)     //  点的编号从1开始
{
    memset(vis, false, sizeof(vis));
    memset(dist, 0x3f, sizeof(dist));
    memset(pre, -1, sizeof(pre));
    memset(pre_, -1, sizeof(pre_));
    memset(cnt, -1, sizeof(cnt));
    priority_queue<qNode> que;
    
    while (!que.empty())
    {
        que.pop();
    }
    dist[start] = 0;
    que.push(qNode(start, 0));
    qNode tmp;
    
    while (!que.empty())
    {
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (int i = 0; i < E[u].size(); i++)
        {
            int v = E[u][i].first.v;
            int cost = E[u][i].first.cost;
            if (!vis[v] && dist[v] > dist[u] + cost)
            {
                dist[v] = dist[u] + cost;
                pre[v] = u;
                if (pre_[u] == -1 || E[u][i].second != pre_[u] || u == start)   //  4.1
                {
                    if (pre_[u] == -1 || u == start)    //  4.1
                    {
                        pre_[u] = E[u][i].second;
                        cnt[u] = 1;
                    }
                    pre_[v] = E[u][i].second;
                    cnt[v] = pre_[v] == pre_[u] ? cnt[u] : cnt[u] + 1;
                }
                else
                {
                    pre_[v] = pre_[u];
                    cnt[v] = cnt[u];
                }
                que.push(qNode(v, dist[v]));
            }
            else if (!vis[v] && dist[v] == dist[u] + cost)
            {
                if (E[u][i].second == pre_[u])
                {
                    if (cnt[v] > cnt[u])        //  4.1
                    {
                        pre[v] = u;
                        pre_[v] = pre_[u];
                        cnt[v] = cnt[u];
                        que.push(qNode(v, dist[v]));
                    }
                }
                else
                {
                    if (cnt[v] > cnt[u] + 1)    //  4.1
                    {
                        pre[v] = u;
                        pre_[v] = E[u][i].second;
                        cnt[v] = cnt[u] + 1;
                        que.push(qNode(v, dist[v]));
                    }
                }
            }
        }
    }
}

void addEdge(int u, int v, int w, int c)
{
    E[u].push_back(make_pair(Edge(v, w), c));
}

struct way
{
    int id;
    int cmp;
} w[MAXN];

void getWay(int ed, int mt)
{
    int m = mt;
    w[m].id = ed;
    w[m--].cmp = pre_[ed];
    while (pre[ed] != -1)
    {
        ed = pre[ed];
        w[m].id = ed;
        w[m--].cmp = pre_[ed];
    }
    w[1].id = ed;
    w[1].cmp = pre_[ed];
    if (w[1].cmp != w[2].cmp)   //  3.31
    {
        w[1].cmp = w[2].cmp;
    }
    
    int sc = w[1].cmp;
    int si = w[1].id;
    for (int i = 2; i <= mt; i++)
    {
        if (w[i].cmp != sc)
        {
            printf("Go by the line of company #%d from %04d to %04d.\n", sc, si, w[i - 1].id);
            sc = w[i].cmp;
            si = w[i - 1].id;
        }
    }
    printf("Go by the line of company #%d from %04d to %04d.\n", sc, si, w[mt].id);
}

int main()
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int N;
    cin >> N;
    
    int M, u, v;
    for (int i = 1; i <= N; i++)
    {
        scanf("%d%d", &M, &u);
        for (int j = 1; j < M; j++)
        {
            scanf("%d", &v);
            addEdge(u, v, 1, i);
            addEdge(v, u, 1, i);
            u = v;
        }
    }
    
    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        scanf("%d%d", &u, &v);
        Dijkstra(N, u);
        if (dist[v] == INF)
        {
            cout << "Sorry, no line is available.\n";
        }
        else
        {
            cout << dist[v] << '\n';
            getWay(v, dist[v] + 1);
        }
    }
    
    return 0;
}
