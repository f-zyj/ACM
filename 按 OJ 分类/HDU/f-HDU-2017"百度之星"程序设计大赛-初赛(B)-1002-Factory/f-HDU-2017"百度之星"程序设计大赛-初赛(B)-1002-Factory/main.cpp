//
//  main.cpp
//  f-HDU-2017"百度之星"程序设计大赛-初赛(B)-1002-Factory
//
//  Created by ZYJ on 2017/8/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int MAXN = 100010;
const int INF = 0x3f3f3f3f;
const int MAGIC = 20;

struct edge
{
    int x, w;
    edge(int x, int w) : x(x), w(w) {}
};

vector<edge> ve[MAXN];
vector<int> vi[MAXN];

int n, m;
int dep[MAXN];
int hed[MAXN];
int pre[MAXN][MAGIC];

void dfs(int x, int p)
{
    hed[x] = hed[p] + 1;
    pre[x][0] = p;
    for (int i = 1; i < MAGIC; ++i)
    {
        pre[x][i] = pre[pre[x][i - 1]][i - 1];
    }
    int y;
    for (int i = 0; i < ve[x].size(); ++i)
    {
        y = ve[x][i].x;
        if (y == p)
        {
            continue;
        }
        dep[y] = dep[x] + ve[x][i].w;
        dfs(y, x);
    }
}

int lca(int x, int y)
{
    if (hed[x] < hed[y])
    {
        swap(x, y);
    }
    int d = hed[x] - hed[y];
    for (int i = 0; i < MAGIC; ++i)
    {
        if ((d >> i) & 1)
        {
            x = pre[x][i];
        }
    }
    if (x == y)
    {
        return x;
    }
    for (int i = MAGIC - 1; i >= 0; --i)
    {
        if (pre[x][i] != pre[y][i])
        {
            x = pre[x][i];
            y = pre[y][i];
        }
    }
    
    return pre[x][0];
}

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

int main()
{
    int T;
    scan_d(T);
    while (T--)
    {
        scan_d(n), scan_d(m);
        for (int i = 1; i <= n; ++i)
        {
            ve[i].clear();
        }
        for (int i = 1; i <= m; ++i)
        {
            vi[i].clear();
        }
        int u, v, w;
        for (int i = 1; i < n; ++i)
        {
            scan_d(u), scan_d(v), scan_d(w);
            ve[u].push_back(edge(v, w));
            ve[v].push_back(edge(u, w));
        }
        int G, x;
        for (int i = 1; i <= m; ++i)
        {
            scan_d(G);
            for (int j = 0; j < G; ++j)
            {
                scan_d(x);
                vi[i].push_back(x);
            }
        }
        
        dfs(1, 0);
        
        int Q, ans;
        scan_d(Q);
        while (Q--)
        {
            scanf("%d%d", &u, &v);
            ans = INF;
            for (auto x : vi[u])
            {
                for (auto y : vi[v])
                {
                    ans = min(ans, dep[x] + dep[y] - 2 * dep[lca(x, y)]);
                }
            }
            
            printf("%d\n", ans);
        }
    }
    
    return 0;
}
