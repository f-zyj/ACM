//
//  main.cpp
//  ICPC Asia Regional Qingdao Online-1009-Smallest Minimum Cut
//
//  Created by ZYJ on 2017/9/19.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 10000;
const ll INF = 1ll << 60;
const int MOD = 100001;
const int MAXM = 500000;

int n, m;
int level[MAXN], que[MAXN];
int head[MAXN], lon;

ll min(ll a, ll b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

struct EDGE
{
    int next, to;
    ll c;
} e[MAXM];

void edgeini()
{
    memset(head, -1, sizeof(head));
    lon = -1;
}

void edgemake(int from, int to, ll c)
{
    e[++lon].c = c;
    e[lon].to = to;
    e[lon].next = head[from];
    head[from] = lon;
}

void make(int from, int to, ll c)
{
    edgemake(from, to, c);
    edgemake(to, from, 0);
}

bool makelevel(int s, int t)
{
    memset(level, 0, sizeof(level));
    int front = 1, end = 0;
    que[++end] = s;
    level[s] = 1;
    while (front <= end)
    {
        int u = que[front++];
        if (u == t)
        {
            return true;
        }
        for (int k = head[u]; k != -1; k = e[k].next)
        {
            int v = e[k].to;
            if (!level[v] && e[k].c)
            {
                que[++end] = v;
                level[v] = level[u] + 1;
            }
        }
    }
    
    return false;
}

ll dfs(int now, int t, ll maxf)
{
    if (now == t || maxf == 0)
    {
        return maxf;
    }
    ll ret = 0;
    for (int k = head[now]; k != -1; k = e[k].next)
    {
        int u = e[k].to;
        if (level[u] == level[now] + 1 && e[k].c)
        {
            ll f = dfs(u, t, min(e[k].c, maxf - ret));
            e[k].c -= f;
            e[k^1].c += f;
            ret += f;
            if (ret == maxf)
            {
                return ret;
            }
        }
    }
    if (ret == 0)
    {
        level[now] = 0;
    }
    return ret;
}

ll maxflow(int s, int t)
{
    ll ret = 0;
    while (makelevel(s, t))
    {
        ret += dfs(s, t, INF);
    }
    return ret;
}

int main()
{
    int cas;
    scanf("%d", &cas);
    
    int sum = 0;
    int s, t;
    int u, v;
    ll w;
    
    while (cas--)
    {
        sum++;
        
        scanf("%d%d", &n, &m);
        scanf("%d%d", &s, &t);
        
        edgeini();
        
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%lld", &u, &v, &w);
            make(u, v, w * MOD + 1);
        }
        printf("%lld\n", maxflow(s, t) % MOD);
    }
    
    return 0;
}
