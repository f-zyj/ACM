//
//  main.cpp
//  f-HDU-2017 多校训练赛9-1005-FFF at Valentine
//
//  Created by ZYJ on 2017/8/22.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1111;

int n, m;
bool vis[MAXN][2];
vector<int> vs;
vector<int> vi[MAXN];
vector<int> rvi[MAXN];

void add_edge(int u, int v)
{
    vi[u].push_back(v);
    rvi[v].push_back(u);
}

void dfs_1(int x)
{
    vis[x][0] = true;
    for (int i = 0; i < vi[x].size(); i++)
    {
        if (!vis[vi[x][i]][0])
        {
            dfs_1(vi[x][i]);
        }
    }
}

void dfs_2(int x)
{
    vis[x][1] = true;
    for (int i = 0; i < rvi[x].size(); i++)
    {
        if (!vis[rvi[x][i]][1])
        {
            dfs_2(rvi[x][i]);
        }
    }
}

void init()
{
    vs.clear();
    for (int i = 0; i <= n; i++)
    {
        vi[i].clear();
        rvi[i].clear();
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    
    while (T--)
    {
        init();
        
        scanf("%d%d", &n, &m);
        
        int u, v;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            add_edge(u, v);
        }
        
        bool falg = false;
        for (int i = 1; i <= n; i++)
        {
            memset(vis, false, sizeof(vis));
            
            dfs_1(i);
            dfs_2(i);
            
            for (int i = 1; i <= n; i++)
            {
                if (!vis[i][0] && !vis[i][1])
                {
                    falg = true;
                    break;
                }
            }
            
            if (falg)
            {
                break;
            }
        }
        
        if (falg)
        {
            printf("Light my fire!\n");
        }
        else
        {
            printf("I love you my love and our love save us!\n");
        }
    }
    
    return 0;
}
