//
//  main.cpp
//  f-51Nod-1967-路径定向
//
//  Created by ZYJ on 2017/7/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> pii;
typedef vector<int>::iterator vi_it;

const int MAXN = 1e6 + 100;

int n, m, x, y;
int dg[MAXN], flag[MAXN];
vector<int> node;   //  dg[i] & 1 = 1
vector<int> G[MAXN];
vector<pii> edges;

void dfs(int x)
{
    vi_it it;
    for (it = G[x].begin(); it != G[x].end(); it++)
    {
        if (flag[*it])
        {
            continue;
        }
        pii e = edges[*it];
        if ((e).fi != x)
        {
            flag[*it] = 2;
        }
        else
        {
            flag[*it] = 1;
        }
        dfs(e.fi == x ? e.se : e.fi);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        edges.push_back({x, y});
        G[x].push_back(i);
        G[y].push_back(i);
        dg[x]++;
        dg[y]++;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (dg[i] & 1)
        {
            node.push_back(i);
        }
    }
    
    int cnt = m;
    for (int i = 0; i < node.size(); i += 2)
    {
        x = node[i];
        y = node[i + 1];
        edges.push_back({x, y});
        G[x].push_back(cnt);
        G[y].push_back(cnt);
        cnt++;
    }
    
    for (int i = 1; i <= n; i++)
    {
        dfs(i);
    }
    
    cout << n - node.size() << endl;
    for (int i = 0; i < m; i++)
    {
        if (flag[i] == 1)
        {
            putchar('0');
        }
        else
        {
            putchar('1');
        }
    }
    
    return 0;
}
