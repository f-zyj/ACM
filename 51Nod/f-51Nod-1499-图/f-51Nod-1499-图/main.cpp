//
//  main.cpp
//  f-51Nod-1499-图
//
//  Created by ZYJ on 2017/10/8.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

//#include <cstdio>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//
//int n, m, ans = 0;
//
//template <class T>
//inline void scan_d(T &ret)
//{
//    char c;
//    ret = 0;
//    while ((c = getchar()) < '0' || c > '9');
//    while (c >= '0' && c <= '9')
//    {
//        ret = ret * 10 + (c - '0'), c = getchar();
//    }
//}
//
//int main()
//{
//    scanf("%d%d", &n, &m);
//
//    //  全放 A 集合
//    int x, y;
//    for (int i = 1; i <= m; i++)
//    {
//        scan_d(x);
//        scan_d(y);
//        ans += abs(x - y);
//    }
//
//    //  全放 B 集合
//    int sum = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = i + 1; j <= n; j++)
//        {
//            sum += j - i;
//        }
//    }
//    ans = max(ans, sum - ans);
//
//    printf("%d\n", ans);
//
//    return 0;
//}

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1111;
const int INF = 1e9;

struct Edge
{
    int to, cap, rev;
};

int n, m, S, T;
int step[MAXN];     //  从源点到点x的距离
int iter[MAXN];     //  定点x的第几条边开始有用
int a[MAXN][MAXN];
vector<Edge> g[MAXN];

void addedge(int from, int to, int cap)
{
    g[from].push_back((Edge){to, cap, (int)g[to].size()});
    g[to].push_back((Edge){from, 0, (int)g[from].size() - 1});
}

void bfs(int S)
{
    memset(step, -1, sizeof(step));
    
    step[S] = 0;
    queue<int> q;
    q.push(S);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); ++i)
        {
            Edge &e = g[v][i];
            if (e.cap > 0 && step[e.to] < 0)
            {
                step[e.to] = step[v] + 1;
                q.push(e.to);
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
    
    for (int &i = iter[v]; i < g[v].size(); ++i)
    {
        Edge &e = g[v][i];
        if (e.cap > 0 && step[e.to] > step[v])
        {
            int d = dfs(e.to, t, min(e.cap, f));
            if (d > 0)
            {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    
    return 0;
}

int maxflow(int S, int T)
{
    int flow = 0;
    while (1)
    {
        bfs(S);
        if (step[T] < 0)
        {
            return flow;
        }
        
        memset(iter, 0, sizeof(iter));
        
        int f;
        while ((f = dfs(S, T, INF)) > 0)
        {
            flow += f;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    
    int x, y;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &x, &y);
        a[x][y] = a[y][x] = 1;
    }
    
    S = 0;
    T = n + 1;
    for (int i = 0; i <= T; ++i)
    {
        g[i].clear();
    }
    
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i != j)
            {
                addedge(i, j, abs(i - j));
                ans += abs(i - j);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (!a[i][j])
            {
                addedge(S, i, abs(i - j));
                addedge(S, j, abs(i - j));
            }
            else
            {
                addedge(i, T, abs(i - j));
                addedge(j, T, abs(i - j));
            }
        }
    }
    
    printf("%d\n", (ans - maxflow(S, T)) >> 1);
    
    return 0;
}
