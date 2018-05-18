//
//  main.cpp
//  f-HDU-1535-Invitation Cards
//
//  Created by ZYJ on 2016/11/21.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int MAXP = 1e6 + 10;
const int INF = 0x3f3f3f3f;

struct Edge
{
    int v;
    int cost;
    Edge(int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
};

vector<Edge> E[MAXP];

void init()
{
    for (int i = 0; i < MAXP; i++)
    {
        E[i].clear();
    }
}

void addEdge(int u, int v, int w)
{
    E[u].push_back(Edge(v, w));
}

bool vis[MAXP];
int cnt[MAXP];
int dist[MAXP];

bool SPFA(int start, int n)
{
    memset(vis, false, sizeof(vis));
    memset(dist, 0x3f, sizeof(dist));
    memset(cnt, 0, sizeof(cnt));
    
    vis[start] = true;
    dist[start] = 0;
    queue<int> que;
    
    while (!que.empty())
    {
        que.pop();
    }
    que.push(start);
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
                        return false;
                    }
                }
            }
        }
    }
    
    return true;
}

int st[MAXP];
int ed[MAXP];
int val[MAXP];

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    
    int P, Q, sum;
    while (N--)
    {
        sum = 0;
        
        init();
        scanf("%d%d", &P, &Q);
        
        for (int i = 0; i < Q; i++)
        {
            scanf("%d%d%d", &st[i], &ed[i], &val[i]);
            addEdge(st[i], ed[i], val[i]);
        }
        
        SPFA(1, P);
        
        for (int i = 1; i <= P; i++)
        {
            sum += dist[i];
        }
        
        init();
        
        for (int i = 0; i < Q; i++)
        {
            addEdge(ed[i], st[i], val[i]);
        }
        
        SPFA(1, P);
        
        for (int i = 1; i <= P; i++)
        {
            sum += dist[i];
        }
        
        cout << sum << '\n';
    }
    
    return 0;
}
