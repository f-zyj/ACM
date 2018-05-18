//
//  main.cpp
//  f-HDU-2874-Connections between cities
//
//  Created by ZYJ on 2016/11/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 10010;

int rmq[2 * MAXN];          //  rmq数组,就是欧拉序列对应的深度序列
int dir[MAXN];
int vis[MAXN];

struct ST
{
    int mm[2 * MAXN];
    int dp[2 * MAXN][20];     //  最小值对应的下标
    void init(int n)
    {
        mm[0] = -1;
        for (int i = 1; i <= n; i++)
        {
            mm[i] = ((i & (i - 1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
            dp[i][0] = i;
        }
        for (int j = 1; j <= mm[n]; j++)
        {
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
            {
                dp[i][j] = rmq[dp[i][j - 1]] < rmq[dp[i + (1 << (j - 1))][j - 1]] ? dp[i][j - 1] : dp[i + (1 << (j - 1))][j - 1];
            }
        }
    }
    int query(int a,int b)  //  查询[a,b]之间最小值的下标
    {
        if (a > b)
        {
            swap(a, b);
        }
        int k = mm[b - a + 1];
        return rmq[dp[a][k]] <= rmq[dp[b - (1 << k) + 1][k]] ? dp[a][k] : dp[b - (1 << k) + 1][k];
    }
};

//  边的结构体定义
struct Edge
{
    int u, v, w, next;
};

Edge edge[MAXN * 2];

int tot, head[MAXN];
int F[MAXN * 2];        //  欧拉序列,就是dfs遍历的顺序,长度为2*n-1,下标从1开始
int P[MAXN];            //  P[i]表示点i在F中第一次出现的位置
int cnt;
ST st;

void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
    memset(dir, 0, sizeof(dir));
    memset(vis, 0, sizeof(vis));
}

void addedge(int u, int v, int w)   //  加边,无向边需要加两次
{
    edge[tot].u = u;
    edge[tot].v = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void dfs(int u, int pre, int dep)
{
    vis[u] = 1;
    F[++cnt] = u;
    rmq[cnt] = dep;
    P[u] = cnt;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v == pre || vis[v])
        {
            continue;
        }
        dir[v] = dir[u] + edge[i].w;
        dfs(v, u, dep + 1);
        F[++cnt] = u;
        rmq[cnt] = dep;
    }
}

void LCA_init(int node_num)             //  查询LCA前的初始化
{
    cnt = 0;
    st.init(2 * node_num - 1);
}

int query_lca(int u, int v)             //  查询u,v的lca编号
{
    return F[st.query(P[u], P[v])];
}

int pre[MAXN];

int find(int x)
{
    if (x != pre[x])
    {
        pre[x] = find(pre[x]);
    }
    return pre[x];
}

void join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    
    if (fx != fy)
    {
        pre[fx] = pre[fy];
    }
}

int main()
{
    int N, M, Q;
    int u, v, w;
    while (~scanf("%d%d%d", &N, &M, &Q))
    {
        
        init();
        for (int i = 0; i <= N; i++)
        {
            pre[i] = i;
        }
        
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
            addedge(v, u, w);
            join(u, v);
        }

        for (int i = 1; i <= N; i++)
        {
            if (!vis[i])
            {
                dfs(i, i, 0);
            }
        }
        
        LCA_init(N);
        
        for (int i = 0; i < Q; i++)
        {
            scanf("%d%d", &u, &v);
            if (find(u) != find(v))
            {
                printf("Not connected\n");
            }
            else
            {
                int lca = query_lca(u, v);
                printf("%d\n", dir[u] + dir[v] - 2 * dir[lca]);
            }
        }
    }
    
    return 0;
}
