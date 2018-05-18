//
//  main.cpp
//  f-51Nod-1737-配对
//
//  Created by ZYJ on 2017/1/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;

int n;
ll wr[MAXN];    //  wr[i] i 到重心 zx 的带权路径长度

/*  树的重心
 *  初始化 vis[] son[] 为 0
 *  初始化 sz 为 INF
 */
int zx, sz;
int son[MAXN], vis[MAXN];
vector<pll> edge[MAXN];

void init()
{
    for (int i = 1; i <= n; i++)
    {
        edge[i].clear();
    }
    memset(vis, 0, sizeof(vis));
    memset(wr, 0, sizeof(wr));
    sz = INF;
    zx = -1;
}

void dfs(int r)
{
    vis[r] = 1;
    son[r] = 0;
    int tmp = 0;
    for (int i = 0; i < edge[r].size(); i++)
    {
        int v = edge[r][i].second;
        if (!vis[v])
        {
            dfs(v);
            son[r] += son[v] + 1;
            tmp = max(tmp, son[v] + 1);
        }
    }
    tmp = max(tmp, n - son[r] - 1);
    if (tmp < sz)
    {
        zx = r;
        sz = tmp;
    }
}

void dfs_(int x)
{
    vis[x] = 1;
    for (int i = 0; i < edge[x].size(); i++)
    {
        int v = edge[x][i].second;
        if (!vis[v])
        {
            wr[v] = wr[x] + edge[x][i].first;
            dfs_(v);
        }
    }
}

int main()
{
    while (~scanf("%d", &n))
    {
        init();
        
        for (int i = 0; i < n - 1; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edge[u].pb(mp(w, v));
            edge[v].pb(mp(w, u));
        }
        
        dfs(1);
        
        memset(vis, 0, sizeof(vis));
        
        dfs_(zx);
        
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += wr[i];
        }
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
