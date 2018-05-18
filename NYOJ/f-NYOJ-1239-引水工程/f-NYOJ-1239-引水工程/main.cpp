//
//  main.cpp
//  f-NYOJ-1239-引水工程
//
//  Created by ZYJ on 2017/5/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 333;
const int MAXM = 1e5;

int map[MAXN][MAXN];
vector<int> tree[MAXN];

int F[MAXN];

struct Edge
{
    int u;
    int v;
    int w;
} edge[MAXM];

int tol;
int vis[MAXN];

void init()
{
    tol = 0;
    for (int i = 0; i < MAXN; i++)
    {
        tree[i].clear();
    }
    memset(vis, 0, sizeof(vis));
}

void addEdge(int u, int v, int w)
{
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
}

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

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

int Kruskal(int n)
{
    for (int i = 0; i <= n; i++)
    {
        F[i] = i;
    }
    sort(edge, edge + tol, cmp);
    
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < tol; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        int tOne = find(u);
        int tTwo = find(v);
        if (tOne != tTwo)
        {
            ans += w;
            F[tOne] = tTwo;
            cnt++;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        if (cnt == n - 1)
        {
            break;
        }
    }
    if (cnt < n - 1)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

int ans;
int value[MAXN];

void dfs(int root)
{
    for (int i = 0; i < tree[root].size(); i++)
    {
        int tmp = tree[root][i];
        if (!vis[tmp])
        {
            vis[tmp] = 1;
            if (value[tmp] < map[root][tmp])
            {
                ans += value[tmp] - map[root][tmp];
            }
            dfs(tmp);
        }
    }
}

int main()
{
    int K;
    cin >> K;
    
    int N;
    while (K--)
    {
        init();
        cin >> N;
        
        int minValue = INF;
        int root = -1;
        for (int i = 0; i < N; i++)
        {
            cin >> value[i];
            if (value[i] < minValue)
            {
                minValue = value[i];
                root = i;
            }
        }
        vis[root] = 1;
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> map[i][j];
                if (i != j)
                {
                    addEdge(i, j, map[i][j]); 
                }	
            }
        }
        
        ans = Kruskal(N);
        ans += minValue; 
        
        dfs(root);
        
        cout << ans << '\n';
    }
    
    return 0;
}
