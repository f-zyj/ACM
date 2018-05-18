//
//  main.cpp
//  f-HDU-1839-Delay Constrained Maximum Capacity Path
//
//  Created by ZYJ on 2016/11/26.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 10005;
const int MAXE = 50005;

struct Edge
{
    int v, next, cap, time;
} E[MAXE * 2];

int n, m, t;
int size;
int head[MAXN];
int cap[MAXE];
int lowcost[MAXN];
int Time[MAXN];
int limit;
bool vis[MAXN];

void init()
{
    size = 0;
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v, int c, int d)
{
    E[size].v = v;
    E[size].cap = c;
    E[size].time = d;
    E[size].next = head[u];
    head[u] = size++;
}

int Dijkstra(int src)
{
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i)
    {
        lowcost[i] = INF;
    }
    lowcost[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int e = head[u]; e != -1; e = E[e].next)
        {
            if (E[e].cap >= limit)  //  路径限制
            {
                int tmp = lowcost[u] + E[e].time;
                if (lowcost[E[e].v] > tmp)
                {
                    lowcost[E[e].v] = tmp;
                    if (!vis[E[e].v])
                    {
                        vis[E[e].v] = true;
                        q.push(E[e].v);
                    }
                }
            }
        }
    }
    return lowcost[n];
}

int main()
{
    int T;
    scanf("%d", &T);
    
    int u, v, c, d;
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &t);
        init();
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d%d", &u, &v, &c, &d);
            cap[i] = c;
            addEdge(u, v, c, d);
            addEdge(v, u, c, d);
        }
        //  从大到小排序方便后续二分
        sort(cap, cap + m, greater<int>());
        
        //  二分求解
        int left = 0, right = m - 1, mid;
        while (left < right)
        {
            mid = (left + right) >> 1;
            limit = cap[mid];
            int tmp = Dijkstra(1);
            if (tmp == INF || tmp > t)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        
        printf("%d\n", cap[left]);
    }
    
    return 0;
}
