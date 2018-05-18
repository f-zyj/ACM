//
//  main.cpp
//  f-HDU-2722-Here We Go(relians) Again
//
//  Created by ZYJ on 2016/12/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int MAXN = 100;
const int MAXV = 445;
const int MAXE = MAXV * MAXV / 2;
const int MAXL = 2520;

struct Edge
{
    int v, next, w;
} E[MAXE];

int n;
int m;
int vn;
int size;
int head[MAXV];
int lowcost[MAXV];

void addEdge(int u, int v, int w)
{
    E[size].v = v;
    E[size].w = w;
    E[size].next = head[u];
    head[u] = size++;
}

void init()
{
    vn = (m + 1) * (n + 1);
    size = 0;
    memset(head, -1, sizeof(head));
}

void Dijkstra(int src)
{
    memset(lowcost, 0x3f, sizeof(lowcost));
    
    lowcost[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push(make_pair(lowcost[src],src));
    
    while (!q.empty())
    {
        pii x = q.top();
        q.pop();
        int u = x.second;
        if (lowcost[u] != x.first)
        {
            continue;
        }
        for (int e = head[u]; e != -1; e = E[e].next)
        {
            int tmp = lowcost[u] + E[e].w;
            if (lowcost[E[e].v] > tmp)
            {
                lowcost[E[e].v] = tmp;
                q.push(make_pair(tmp, E[e].v));
            }
        }
    }
}

int main()
{
    char str[MAXN];
    
    int u, w;
    while (~scanf("%d%d%*c", &n, &m) && n + m)
    {
        init();
        
        for (int i = 1; i <= n * 2 + 1; ++i)
        {
            fgets(str, MAXN, stdin);
            int len = (int)strlen(str);
            if (i & 1)
            {
                for (int j = 0, k = 1; j < len; j += 4, ++k)
                {
                    u = (m + 1) * (i / 2) + k;
                    w = str[j] - '0';
                    if (w == 0)
                    {
                        continue;
                    }
                    if (str[j + 2] == '*')
                    {
                        addEdge(u, u + 1, MAXL / w);
                        addEdge(u + 1, u, MAXL / w);
                    }
                    else if (str[j + 2] == '<')
                    {
                        addEdge(u + 1, u, MAXL / w);
                    }
                    else
                    {
                        addEdge(u, u + 1, MAXL / w);
                    }
                }
            }
            else
            {
                for (int j = 0, k = 1; j < len; j += 4, ++k)
                {
                    u = (m + 1) * (i / 2 - 1) + k;
                    w = str[j] - '0';
                    if (w == 0)
                    {
                        continue;
                    }
                    if (str[j + 2] == '*')
                    {
                        addEdge(u, u + m + 1, MAXL / w);
                        addEdge(u + m + 1, u, MAXL / w);
                    }
                    else if (str[j + 2] == 'v')
                    {
                        addEdge(u, u + m + 1, MAXL / w);
                    }
                    else if (str[j + 2] == '^')
                    {
                        addEdge(u + m + 1, u, MAXL / w);
                    }
                }
            }
        }
        
        Dijkstra(1);
        
        if (lowcost[vn] != INF)
        {
            printf("%d blips\n", lowcost[vn]);
        }
        else
        {
            puts("Holiday");
        }
    }
    
    return 0;
}
