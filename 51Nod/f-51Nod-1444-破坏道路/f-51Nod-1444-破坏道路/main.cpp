//
//  main.cpp
//  f-51Nod-1444-破坏道路
//
//  Created by ZYJ on 2017/6/25.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 3333;

int n, m;
int s1, t1, l1;
int s2, t2, l2;
int vis[MAXN];
int dis[MAXN][MAXN];
vector<int> vi[MAXN];

//  O(n^2) 获取任意两点间最短距离
void bfs()
{
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        
        queue<int> qi;
        qi.push(i);
        vis[i] = 1;
        
        while (!qi.empty())
        {
            int u = qi.front();
            qi.pop();
            
            int size = (int)vi[u].size();
            for (int j = 0; j < size; j++)
            {
                int v = vi[u][j];
                if (!vis[v])
                {
                    vis[v] = 1;
                    dis[i][v] = dis[i][u] + 1;
                    qi.push(v);
                }
            }
        }
    }
}

bool charge(int s1, int t1, int s2, int t2, int i, int j)
{
    return dis[s1][i] + dis[i][j] + dis[j][t1] <= l1 && dis[s2][i] + dis[i][j] + dis[j][t2] <= l2;
}

int main()
{
    cin >> n >> m;
    
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &a, &b);
        vi[a].push_back(b);
        vi[b].push_back(a);
    }
    
    scanf("%d%d%d", &s1, &t1, &l1);
    scanf("%d%d%d", &s2, &t2, &l2);
    
    bfs();
    
    int ans = dis[s1][t1] + dis[s2][t2];
    if (dis[s1][t1] > l1 || dis[s2][t2] > l2)
    {
        printf("-1\n");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (charge(s1, t1, s2, t2, i, j))
                {
                    ans = min(ans, dis[s1][i] + dis[i][j] + dis[j][t1] + dis[s2][i] + dis[j][t2]);
                }
                if (charge(t1, s1, t2, s2, i, j))
                {
                    ans = min(ans, dis[t1][i] + dis[i][j] + dis[j][s1] + dis[t2][i] + dis[j][s2]);
                }
                if (charge(s1, t1, t2, s2, i, j))
                {
                    ans = min(ans, dis[s1][i] + dis[i][j] + dis[j][t1] + dis[t2][i] + dis[j][s2]);
                }
                if (charge(t1, s1, s2, t2, i, j))
                {
                    ans = min(ans, dis[t1][i] + dis[i][j] + dis[j][s1] + dis[s2][i] + dis[j][t2]);
                }
            }
        }
        
        printf("%d\n", m - ans);
    }
    
    return 0;
}
