//
//  main.cpp
//  f-51Nod-1442-士兵的旅行
//
//  Created by ZYJ on 2017/9/4.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 1010;

struct edge
{
    int to, cap, rev;
    
    edge(int a, int b, int c)
    {
        to = a;
        cap = b;
        rev = c;
    }
};

int level[MAXN];
int iter[MAXN];
vector<edge> veg[MAXN];

void add_edge(int from, int to, int cap)
{
    veg[from].push_back(edge(to, cap, (int)veg[to].size()));
    veg[to].push_back(edge(from, 0, (int)veg[from].size() - 1));
}

void bfs(int s)
{
    memset(level, -1, sizeof(level));
    
    queue<int> que;
    level[s] = 0;
    que.push(s);
    
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        for (int i = 0; i < veg[v].size(); i++)
        {
            edge &e = veg[v][i];
            if (e.cap > 0 && level[e.to] < 0)
            {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f)
{
    if (v == t)
    {
        return f;
    }
    
    for (int &i = iter[v]; i < veg[v].size(); i++)
    {
        edge &e = veg[v][i];
        if (e.cap > 0 && level[v] < level[e.to])
        {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0)
            {
                e.cap -= d;
                veg[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    
    return 0;
}

int max_flow(int s, int t)
{
    int flow = 0, f;
    while (1)
    {
        bfs(s);
        if (level[t] < 0)
        {
            return flow;
        }
        
        memset(iter, 0, sizeof(iter));
        while ((f = dfs(s, t, INF)) > 0)
        {
            flow += f;
        }
    }
}

int n, m;
int A[MAXN];
int B[MAXN];

int main()
{
    for (int i = 0; i < MAXN; i++)
    {
        veg[i].clear();
    }
    
    scanf("%d%d", &n, &m);
    
    int sum1 = 0, sum2 = 0, a, b;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        add_edge(i, i + n, INF);
        add_edge(0, i, a);
        sum1 += a;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        add_edge(i + n, 2 * n + 1, a);
        sum2 += a;
    }
    
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        add_edge(a, b + n, INF);
        add_edge(b, a + n, INF);
    }
    
    int ans = max_flow(0, 2 * n + 1);
    if (ans == sum2 && sum1 == sum2)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    
    return 0;
}
