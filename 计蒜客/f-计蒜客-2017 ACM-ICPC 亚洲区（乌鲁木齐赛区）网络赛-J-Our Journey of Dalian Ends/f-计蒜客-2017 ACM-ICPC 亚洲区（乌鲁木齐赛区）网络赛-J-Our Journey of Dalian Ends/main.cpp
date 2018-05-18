//
//  main.cpp
//  f-计蒜客-2017 ACM-ICPC 亚洲区（乌鲁木齐赛区）网络赛-J-Our Journey of Dalian Ends
//
//  Created by ZYJ on 2017/9/9.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

const ll INF = 1e15 + 7;
const int MAXN = 5005;

struct Edge
{
    int from;
    int to;
    int cap;
    int flow;
    int cost;
};

struct MCMF
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[MAXN];
    int inq[MAXN];
    int p[MAXN];
    int a[MAXN];
    ll dis[MAXN];
    
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < MAXN; i++)
        {
            G[i].clear();
        }
        edges.clear();
    }
    
    void AddEdge(int from, int to, int cap, int cost)
    {
        edges.push_back((Edge){from, to, cap, 0, cost});
        edges.push_back((Edge){to, from, 0, 0, -cost});
        int m = (int)edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    
    bool BellmanFord(int s, int t, int &flow, ll &cost)
    {
        for (int i = 0; i <= n; i++)
        {
            dis[i] = INF;
        }
        
        memset(inq, 0, sizeof(inq));
        dis[s] = 0, inq[s] = 1, p[s] = 0;
        a[s] = 0x3f3f3f3f;
        queue<int> q;
        q.push(s);
        
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (int i = 0; i < G[u].size(); i++)
            {
                Edge &e = edges[G[u][i]];
                if (e.cap > e.flow && dis[e.to] > dis[u] + e.cost)
                {
                    dis[e.to] = dis[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to])
                    {
                        q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        
        if (dis[t] == INF)
        {
            return false;
        }
        
        flow += a[t];
        cost += (ll)dis[t] * a[t];
        int u = t;
        while (u != s)
        {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
            u = edges[p[u]].from;
        }
        
        return true;
    }
    
    ll Mincost(int s, int t)
    {
        int flow = 0;
        ll cost = 0;
        while (BellmanFord(s, t, flow, cost));
        if (flow < 2)
        {
            return -1;
        }
        
        return cost;
    }
} g;

int m, cnt;
string a, b;
map<string, int> msi;

void init()
{
    msi.clear();
    
    msi["Dalian"] = 1;
    msi["Shanghai"] = 2;
    msi["Xian"] = 3;
    
    cnt = 4;
}

int main(int argc, const char * argv[])
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        init();
        g.init(MAXN - 1);
        scanf("%d", &m);
        
        int x;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> x;
            if (!msi[a])
            {
                msi[a] = cnt++;
            }
            if (!msi[b])
            {
                msi[b] = cnt++;
            }
            
            g.AddEdge(msi[a] * 2 + 1, msi[b] * 2, 1, x);
            g.AddEdge(msi[b] * 2 + 1, msi[a] * 2, 1, x);
        }
        for (int i = 1; i < cnt; i++)
        {
            g.AddEdge(i * 2, i * 2 + 1, 1, 0);
        }
        g.AddEdge(0, 1 * 2, 1, 0);
        g.AddEdge(0, 3 * 2, 1, 0);
        
        printf("%lld\n", g.Mincost(0, 4));
    }
    
    return 0;
}
