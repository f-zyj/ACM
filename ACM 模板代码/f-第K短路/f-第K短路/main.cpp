//
//  main.cpp
//  f-第K短路
//
//  Created by ZYJ on 16/6/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//WHU 1603
#include <iostream>
#include <vector>
#include <queue>
using namespace::std;

//Dijkstra

/*
 * Dijkstra变形，可以证明每个点经过的次数为小于等于K，
 * 所有Dijkstra的数组dist由一维变为二维，记录经过该点
 * 1次、2次......k次的最小值
 * 输出dist[n - 1][k]即可
 */

//int g[1010][1010];
//int n, m, x;
//const int INF = 0x3f3f3f3f;
//int vis[1010];
//int dist[1010][20];
//
//int main(int argc, const char * argv[])
//{
//    while (cin >> n >> m >> x)
//    {
//        //初始化
//        memset(g, 0x3f, sizeof(g));
//        memset(dist, 0x3f, sizeof(dist));
//        memset(vis, 0, sizeof(vis));
//        for (int i = 0; i < m; i++)
//        {
//            int p, q, r;
//            cin >> p >> q >> r;
//            if (r < g[p][q])
//            {
//                g[p][q] = r;
//            }
//        }
//        dist[1][0] = 0;
//        dist[0][0] = INF;
//        
//        while (1)
//        {
//            int k = 0;
//            for (int i = 1; i <= n; i++)
//            {
//                if (vis[i] < x && dist[i][vis[i]] < dist[k][0])
//                {
//                    k = i;
//                }
//            }
//            if (k == 0)
//            {
//                break;
//            }
//            if (k == n && vis[n] == x - 1)
//            {
//                break;
//            }
//            for (int i = 1; i <= n; i++)
//            {
//                if (vis[i] < x && dist[k][vis[k]] + g[k][i] < dist[i][x])
//                {
//                    dist[i][x] = dist[k][vis[k]] + g[k][i];
//                    for (int j = x; j > 0; j--)
//                    {
//                        if (dist[i][j] < dist[i][j - 1])
//                        {
//                            swap(dist[i][j], dist[i][j - 1]);
//                        }
//                    }
//                }
//            }
//            vis[k]++;
//        }
//        
//        if (dist[n][x - 1] < INF)
//        {
//            cout << dist[n][x - 1] << endl;
//        }
//        else
//        {
//            cout << -1 << endl;
//        }
//    }
//    return 0;
//}

//A*

/*
 * A* 估价函数  fi为到当前点走过的路经长度，hi为该点到终点的长度
 * gi = hi + fi
 */

int n, m, x, ct;
int g[1010][1010];
int gr[1010][1010];
int dist[1010];
int vis[1010];
const int INF = 0x3f3f3f3f;

struct node
{
    int id;
    int fi;
    int gi;
    friend bool operator < (node a, node b)
    {
        if (a.gi == b.gi)
        {
            return a.fi > b.fi;
        }
        return a.gi > b.gi;
    }
} s[20000010];

int init()
{
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i <= n; i++)
    {
        vis[i] = 1;
    }
    dist[n - 1] = 0;
    for (int i = 0; i < n; i++)
    {
        int k = n;
        for (int j = 0; j < n; j++)
        {
            if (vis[j] && dist[j] < dist[k])
            {
                k = j;
            }
        }
        if (k == n)
        {
            break;
        }
        vis[k] = 0;
        for (int j = 0; j < n; j++)
        {
            if (vis[j] && dist[k] + gr[k][j] < dist[j])
            {
                dist[j] = dist[k] + gr[k][j];
            }
        }
    }
    return 1;
}

int solve()
{
    if (dist[0] == INF)
    {
        return -1;
    }
    ct = 0;
    s[ct].id = 0;
    s[ct].fi = 0;
    s[ct++].gi = dist[0];
    int cnt = 0;
    while (ct)
    {
        int id = s[0].id;
        int fi = s[0].fi;
        
        if (id == n - 1)
        {
            cnt++;
        }
        if (cnt == x)
        {
            return fi;
        }
        pop_heap(s, s + ct);
        ct--;
        for (int j = 0; j < n; j++)
        {
            if (g[id][j] < INF)
            {
                s[ct].id = j;
                s[ct].fi = fi + g[id][j];
                s[ct].gi = s[ct].fi + dist[j];
                ct++;
                push_heap(s, s + ct);
            }
        }
    }
    return -1;
}

int main()
{
    while (cin >> n >> m >> x)
    {
        memset(g, 0x3f, sizeof(g));
        memset(gr, 0x3f, sizeof(gr));
        
        for (int i = 0; i < n; i++)
        {
            int p, q, r;
            cin >> p >> q >> r;
            p--;
            q--;
            g[p][q] = g[p][q] <= r ? g[p][q] : r;
            gr[q][p] = gr[q][p] <= r ? gr[q][p] : r;
        }
        init();
        cout << solve() << endl;
    }
    
    return 0;
}

