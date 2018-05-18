//
//  main.cpp
//  f-HDU-2363-Cycling
//
//  Created by ZYJ on 2016/12/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 110;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll h[MAXN], h_[MAXN];
ll cost[MAXN][MAXN];
ll lowcost[MAXN];

/*
 *  单源最短路径，Dijkstra算法，邻接矩阵形式，复杂度为O(n^2)
 *  求出源beg到所有点的最短路径，传入图的顶点数和邻接矩阵cost[][]
 *  返回各点的最短路径lowcost[]，路径pre[]，pre[i]记录beg到i路径上的父节点，pre[beg] = -1
 *  可更改路径权类型，但是权值必须为非负，下标0~n-1
 */
bool vis[MAXN];
int pre[MAXN];

void Dijkstra(int n, int beg, ll low, ll high)
{
    for (int i = 0; i < n; i++)
    {
        lowcost[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    lowcost[beg] = 0;
    for (int j = 0; j < n; j++)
    {
        int k = -1;
        ll min = INF;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && lowcost[i] < min && h[i] >= low && h[i] <= high)
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
            if (h[i] < low || h[i] > high)
            {
                continue;
            }
            if (!vis[i] && lowcost[k] + cost[k][i] < lowcost[i])
            {
                lowcost[i] = lowcost[k] + cost[k][i];
                pre[i] = k;
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    int t;
    cin >> t;
    
    int n, m;
    while (t--)
    {
        memset(cost, 0x3f, sizeof(cost));
        
        cin >> n >> m;
        ll MAX_H = 0, MIN_H = INF;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", h + i);
            h_[i] = h[i];
            MAX_H = max(MAX_H, h[i]);
            MIN_H = min(MIN_H, h[i]);
        }
        sort(h_, h_ + n);
        
        int u, v, w;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            u--;
            v--;
            cost[u][v] = cost[v][u] = w;
        }
        
        bool flag;
        ll left = 0, mid, right = MAX_H - MIN_H + 1;
        ll ans = INF, diff = INF, res;
        while (left <= right)
        {
            mid = (left + right) / 2;
            res = INF;
            flag = false;
            for (int i = 0; h_[i] + mid <= MAX_H && i < n; i++)
            {
                ll low = h_[i];
                ll high = low + mid;
                Dijkstra(n, 0, low, high);
                if (lowcost[n - 1] != INF)
                {
                    flag = true;
                    res = min(res, lowcost[n - 1]);
                }
            }
            if (flag)
            {
                right = mid - 1;
                diff = mid;
                ans = res;
            }
            else
            {
                left = mid + 1;
            }
        }
        
        printf("%lld %lld\n", diff, ans);
    }
    
    return 0;
}
