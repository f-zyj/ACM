//
//  main.cpp
//  f-CF-Codeforces Round #420 (Div. 2)-D-Okabe and City
//
//  Created by ZYJ on 2017/6/27.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1e5;
const int OFFSET = 1e4 + 10;
const int INF = 0x3f3f3f3f;
const int DIR[4][2] = {{0, 1}, {0, -1},
                       {1, 0}, {-1, 0}};

int cnt = 1;

struct edge
{
    int to, cost;
    edge() {}
    edge(int to_, int cost_) : to(to_), cost(cost_) {}
};

void add_edge(vector<edge> G[], int r, int c)
{
    G[cnt].push_back(edge(r + OFFSET, 1));
    G[cnt].push_back(edge(r + 1 + OFFSET, 1));
    G[cnt].push_back(edge(r - 1 + OFFSET, 1));
    G[cnt].push_back(edge(c + 2 * OFFSET, 1));
    G[cnt].push_back(edge(c + 1 + 2 * OFFSET, 1));
    G[cnt].push_back(edge(c - 1 + 2 * OFFSET, 1));
    
    G[r + OFFSET].push_back(edge(cnt, 0));
    G[r + 1 + OFFSET].push_back(edge(cnt, 0));
    G[r - 1 + OFFSET].push_back(edge(cnt, 0));
    G[c + 2 * OFFSET].push_back(edge(cnt, 0));
    G[c + 1 + 2 * OFFSET].push_back(edge(cnt, 0));
    G[c - 1 + 2 * OFFSET].push_back(edge(cnt, 0));
    cnt++;
}

int n, m, k;
int dis[MAXN];
int vis[MAXN];
pii p[MAXN];
vector<edge> E[MAXN];
map<pii, int> mpi;

void dijkstra(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    
    dis[s] = 0;
    pq.push(pii(0, s));
    pii tmp;
    
    while (!pq.empty())
    {
        tmp = pq.top();
        pq.pop();
        int u = tmp.second;
        if (vis[u])
        {
            continue;
        }
        vis[u] = 1;
        for (int i = 0; i < E[u].size(); i++)
        {
            edge e = E[u][i];
            if (dis[e.to] > dis[u] + e.cost)
            {
                dis[e.to] = dis[u] + e.cost;
                pq.push(pii(dis[e.to], e.to));
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    cin >> n >> m >> k;
    
    int r, c;
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d", &r, &c);
        add_edge(E, r, c);
        p[i] = make_pair(r, c);
        mpi[p[i]] = i;
    }
    
    pii t;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int x = p[i].first + DIR[j][0];
            int y = p[i].second + DIR[j][1];
            t = make_pair(x, y);
            if (mpi[t])
            {
                E[i].push_back(edge(mpi[t], 0));
            }
        }
    }
    
    t = make_pair(n, m);
    if (!mpi[t])
    {
        E[n + OFFSET].push_back(edge(k + 1, 0));
        E[m + 2 * OFFSET].push_back(edge(k + 1, 0));
    }
    
    dijkstra(mpi[pii(1, 1)]);
    
    int ans;
    if (mpi[t])
    {
        ans = dis[mpi[t]];
    }
    else
    {
        ans = dis[k + 1];
    }
    
    if (ans == INF)
    {
        ans = -1;
    }
    
    cout << ans << '\n';
    
    return 0;
}
