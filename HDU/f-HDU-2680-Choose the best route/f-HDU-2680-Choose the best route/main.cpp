//
//  main.cpp
//  f-HDU-2680-Choose the best route
//
//  Created by ZYJ on 2016/11/21.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1010;
const int INF = 0x3f3f3f3f;

bool vis[MAXN];
int pre[MAXN];
int lowcost[MAXN];
int map[MAXN][MAXN];

void dijkstra(int n, int beg)
{
    memset(lowcost, 0x3f, sizeof(lowcost));
    memset(vis, false, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    lowcost[beg] = 0;
    
    for (int j = 0; j < n; j++)
    {
        int k = -1;
        int min = INF;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && lowcost[i] < min)
            {
                min = lowcost[i];
                k = i;
            }
        }
        if (k == -1)
        {
            break;
        }
        vis[k] = true;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && lowcost[k] + map[k][i] < lowcost[i])
            {
                lowcost[i] = lowcost[k] + map[k][i];
                pre[i] = k;
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    int n, m, s;
    while (cin >> n >> m >> s)
    {
        int p, q, t;
        memset(map, 0x3f, sizeof(map));
        
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &p, &q, &t);
            p--;
            q--;
            if (t < map[q][p])
            {
                map[q][p] = t;
            }
        }
        
        dijkstra(n, s - 1);
        
        int w;
        cin >> w;
        
        int res, ans = INF;
        for (int i = 0; i < w; i++)
        {
            scanf("%d", &res);
            res--;
            if (lowcost[res] < ans)
            {
                ans = lowcost[res];
            }
        }
        
        if (ans == INF)
        {
            cout << "-1\n";
        }
        else
        {
            cout << ans << '\n';
        }
    }
    
    return 0;
}
