//
//  main.cpp
//  f-牛客网-2018 美团 CodeM 编程大赛-资格赛
//
//  Created by ZYJ on 2018/6/7.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 5e5 + 10;
const int MAGIC = 49;

struct node
{
    int v, c;
    
    node(int v_ = 0, int c_ = 0) : v(v_), c(c_) {}
    
    bool operator < (const node &r)const
    {
        return c > r.c;
    }
};

struct edge
{
    int v, cost;
    
    edge(int v_ = 0, int cost_ = 0) : v(v_), cost(cost_) {}
};

int n, m;
int dis[MAXN];
int cnt[MAXN];
bool vis[MAXN];
vector<edge> E[MAXN];

void Dijkstra(int n, int start)
{
    memset(vis, false, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    
    priority_queue<node> pqn;

    dis[start] = 0;
    pqn.push(node(start, 0));
    
    node tmp;
    while (!pqn.empty())
    {
        tmp = pqn.top();
        pqn.pop();
        
        int u = tmp.v;
        //  保证有补救措施
        if (!cnt[u + 1])
        {
            continue;
        }
        
        if (vis[u])
        {
            continue;
        }
        
        vis[u] = true;
        for (int i = 0; i < E[u].size(); i++)
        {
            int v = E[tmp.v][i].v;
            int cost = E[u][i].cost;
            if (!vis[v] && dis[v] > dis[u] + cost)
            {
                dis[v] = dis[u] + cost;
                pqn.push(node(v, dis[v]));
            }
        }
    }
}

void addedge(int u, int v, int w)
{
    E[u].push_back(edge(v, w));
}

bool dfs(int u)
{
    if (u == n * MAGIC + 2)
    {
        return cnt[u] = 1;
    }
    
    int flag = 0;
    size_t sz = E[u].size();
    for (int i = 0; i < sz; i++)
    {
        int v = E[u][i].v;
        if (!vis[v])
        {
            vis[v] = 1;
            if (dfs(v))
            {
                flag = 1;
            }
        }
        else
        {
            if (cnt[v])
            {
                flag = 1;
            }
        }
    }
    
    return cnt[u] = flag;
}

int main()
{
    scanf("%d%d", &n, &m);
    
    int x, y, c, ts_h, ts_m, td_h, td_m;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d%d:%d%d:%d", &x, &y, &c, &ts_h, &ts_m, &td_h, &td_m);
        
        //  拆点，半小时一个点，先拆做 MAGIC 个点
        int ts_id = ts_h * 2 + (ts_m / 30) + 1;
        int td_id = td_h * 2 + (td_m / 30) + 1;
        //  如果某站直达终点则不需要考虑延时半小时
        for (int j = td_id + (y == n ? 0 : 1); j <= MAGIC; j++)
        {
            addedge((x - 1) * MAGIC + ts_id, (y - 1) * MAGIC + j, c);
        }
    }
    
    //  n * MAGIC + 1 号点为源点，在任何时刻由源点到达北京代价为 0
    //  n * MAGIC + 2 号点为汇点，在任何时刻由小城到达汇点代价为 0
    for (int i = 1; i <= MAGIC; i++)
    {
        addedge(n * MAGIC + 1, i, 0);
        addedge((n - 1) * MAGIC + i, n * MAGIC + 2, 0);
    }
    
    //  从源点开始搜索
    vis[n * MAGIC + 1] = 1;
    dfs(n * MAGIC + 1);
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = MAGIC; j >= 1; j--)
        {
            cnt[(i - 1) * MAGIC + j] += cnt[(i - 1) * MAGIC + j + 1];
        }
    }

    memset(vis, 0, sizeof(vis));
    Dijkstra(n * MAGIC + 2, n * MAGIC + 1);
    
    if (dis[n * MAGIC + 2] == INF)
    {
        cout << "-1\n";
    }
    else
    {
        cout << dis[n * MAGIC + 2] << "\n";
    }
    
    return 0;
}
