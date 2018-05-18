//
//  main.cpp
//  f-51Nod-1456-小K的技术
//
//  Created by ZYJ on 2017/6/29.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m;
int id_val, cnt, top, ans;
int F[MAXN];    //  并查集
int id[MAXN];
int id_cnt[MAXN];
int flag[MAXN];
int dfn[MAXN];
int low[MAXN];
int vis[MAXN];
int sta[MAXN];
vector<int> vi[MAXN];

int find(int x)
{
    if (F[x] == x)
    {
        return x;
    }
    else
    {
        return F[x] = find(F[x]);
    }
}

void Tarjan(int u)
{
    sta[++top] = u;
    dfn[u] = low[u] = cnt++;
    vis[u] = 1;
    for (int i = 0; i < vi[u].size(); i++)
    {
        int v = vi[u][i];
        if (vis[v] == 0)
        {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        if (vis[v] == 1)
        {
            low[u] = min(low[u], low[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        id_val++;
        do
        {
            id[sta[top]] = id_val;
            vis[sta[top]] = -1;
        }
        while (sta[top--] != u);
    }
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            Tarjan(i);
        }
    }
    
    for (int i = 1; i <= id_val; i++)
    {
        F[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        id_cnt[id[i]]++;
    }
    for (int i = 1; i <= id_val; i++)
    {
        if (id_cnt[i] > 1)  //  说明这是一个强连通分量
        {
            flag[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < vi[i].size(); j++)
        {
            int u = id[i];
            int v = id[vi[i][j]];
            if (u != v)
            {
                int u_ = find(u);
                int v_ = find(v);
                if (u_ != v_)
                {
                    F[v_] = u_;
                    flag[u_] += flag[v_];
                }
            }
        }
    }
    
    for (int i = 1; i <= id_val; i++)
    {
        if (F[i] == i)
        {
            if (flag[i] == 0)
            {
                ans--;
            }
        }
    }
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

void init()
{
    for (int i = 1; i <= n; i++)
    {
        vi[i].clear();
    }
    
    top = -1;
    cnt = 1;
    id_val = 0;
    ans = n;
    memset(id_cnt, 0, sizeof(id_cnt));
    memset(id, 0, sizeof(id));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(vis, 0, sizeof(vis));
    memset(sta, 0, sizeof(sta));
    memset(flag, 0, sizeof(flag));
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        init();
        
        int a, b;
        for (int i = 0; i < m; i++)
        {
            scan_d(a), scan_d(b);
            vi[a].push_back(b);
        }
        
        solve();
        
        printf("%d\n", ans);
    }
    
    return 0;
}
