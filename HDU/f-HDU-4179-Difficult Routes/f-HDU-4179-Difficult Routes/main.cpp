//
//  main.cpp
//  f-HDU-4179-Difficult Routes
//
//  Created by ZYJ on 2016/11/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

const int MAXN = 11111;
const int MAXE = 55555;
const int INF = 0x3f3f3f3f;

typedef struct
{
    int to, next;
    double cost;
} vect;

typedef struct
{
    int a, b;
} edge;

typedef struct
{
    double x, y, z;
} node;

vect E[MAXE], E_[MAXE]; //  正向图邻接表，反向图邻接表
edge e[MAXE], e_[MAXE]; //  难度等于d的边，所有边
node Node[MAXN];
int tot;
int list[MAXN], list_[MAXN];    //  邻接表头
double dis[MAXN], dis_[MAXN];

void add(int a, int b, double c)
{
    E[++tot].to = b;
    E[tot].cost = c;
    E[tot].next = list[a];
    list[a] = tot;
    E_[tot].to = a;
    E_[tot].cost = c;
    E_[tot].next = list_[b];
    list_[b] = tot;
}

double get_dis(node a, node b)
{
    double x = (a.x - b.x) * (a.x - b.x);
    double y = (a.y - b.y) * (a.y - b.y);
    double z = (a.z - b.z) * (a.z - b.z);
    return sqrt(x + y + z);
}

int get_d(node a, node b)
{
    if (a.z >= b.z)
    {
        return 0;
    }
    double x = (a.x - b.x) * (a.x - b.x);
    double y = (a.y - b.y) * (a.y - b.y);
    double z = b.z - a.z;
    return int(z * 100 / sqrt(x + y));
}

bool vis[MAXN];

void spfa(int s, int n, int list[], double dis[], vect E[])
{
    memset(vis, 0, sizeof(vis));
    
    for (int i = 0; i <= n; i++)
    {
        dis[i] = INF;
    }
    dis[s] = 0;
    vis[s] = 1;
    
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int k = list[u]; k; k = E[k].next)
        {
            int v = E[k].to;
            if (dis[v] > dis[u] + E[k].cost)
            {
                dis[v] = dis[u] + E[k].cost;
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

int main ()
{
    int n, m;
    int s, t, d;
    while (~scanf("%d %d", &n, &m) && n + m)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf %lf %lf", &Node[i].x, &Node[i].y, &Node[i].z);
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d %d" ,&e_[i].a ,&e_[i].b);
        }
        
        scanf("%d %d %d", &s, &t, &d);
        
        tot = 1;
        memset(list, 0, sizeof(list));
        memset(list_, 0, sizeof(list_));
        
        int edges = 0;
        for (int i = 1; i <= m; i++)
        {
            int a = e_[i].a;
            int b = e_[i].b;
            int d_1 = get_d(Node[a], Node[b]);
            int d_2 = get_d(Node[b], Node[a]);
            double dis = get_dis(Node[a], Node[b]);
            if (d_1 <= d)
            {
                add(a, b, dis);
            }
            if (d_2 <= d)
            {
                add(b, a, dis);
            }
            if (d_1 == d)
            {
                e[++edges].a = a;
                e[edges].b = b;
            }
            if (d_2 == d)
            {
                e[++edges].a = b;
                e[edges].b = a;
            }
        }
        
        spfa(s, n, list, dis, E);
        spfa(t, n, list_, dis_, E_);
        
        double ans = INF;
        for (int i = 1; i <= edges; i++)
        {
            double now = dis[e[i].a] + get_dis(Node[e[i].a], Node[e[i].b]) + dis_[e[i].b];
            if (ans > now)
            {
                ans = now;
            }
        }
        
        if (ans == INF)
        {
            puts("None");
        }
        else
        {
            printf("%.1lf\n", ans);
        }
    }
    
    return 0;
}
