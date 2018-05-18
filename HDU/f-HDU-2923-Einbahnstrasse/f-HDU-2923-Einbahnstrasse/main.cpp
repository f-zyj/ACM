//
//  main.cpp
//  f-HDU-2923-Einbahnstrasse
//
//  Created by ZYJ on 2016/11/23.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <cstring>

using namespace std;

map<string, int> m;
string s;

/*
 *  单源最短路径，Dijkstra算法，邻接矩阵形式，复杂度为O(n^2)
 *  求出源beg到所有点的最短路径，传入图的顶点数和邻接矩阵cost[][]
 *  返回各点的最短路径lowcost[]，路径pre[]，pre[i]记录beg到i路径上的父节点，pre[beg] = -1
 *  可更改路径权类型，但是权值必须为非负，下标0~n-1
 */
const int MAXN = 101;
const int INF = 0x3f3f3f3f; //  表示无穷

bool vis[MAXN];
int pre[MAXN];
int cost[MAXN][MAXN];
int cost_[MAXN][MAXN];
int lowcost[MAXN];
int lowcost_[MAXN];

void Dijkstra(int cost[][MAXN], int lowcost[], int n, int beg)
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
            if (!vis[i] && lowcost[k] + cost[k][i] < lowcost[i])
            {
                lowcost[i] = lowcost[k] + cost[k][i];
                pre[i] = k;
            }
        }
    }
}

int cars[MAXN];

int main(int argc, const char * argv[])
{
    int N, C, R;
    int key = 1;
    while (cin >> N >> C >> R, N + C + R != 0)
    {
        m.clear();
        memset(cars, 0, sizeof(cars));
        
        cin >> s;
        m[s] = 1;   //  拖车所在地表示为1
        
        int pos = 2;
        for (int i = 0; i < C; i++)
        {
            cin >> s;
            if (m[s] == 0)
            {
                m[s] = pos++;
            }
            cars[m[s] - 1]++;
        }
        int tag = pos - 1;
        
        memset(cost, 0x3f, sizeof(cost));
        memset(cost_, 0x3f, sizeof(cost_));
        
        int num;
        char a, b, c, d;
        string st, ed;
        
        for (int i = 0; i < R; i++)
        {
            cin >> st >> a >> b >> num >> c >> d >> ed;
            if (m[st] == 0)
            {
                m[st] = pos++;
            }
            if (m[ed] == 0)
            {
                m[ed] = pos++;
            }

            int u = m[st] - 1;
            int v = m[ed] - 1;

            if (a == '<')
            {
                if (cost[v][u] > num)
                {
                    cost[v][u] = num;
                }
                if (cost_[u][v] > num)
                {
                    cost_[u][v] = num;
                }
            }
            if (d == '>')
            {
                if (cost[u][v] > num)
                {
                    cost[u][v] = num;
                }
                if (cost_[v][u] > num)
                {
                    cost_[v][u] = num;
                }
            }
        }
        
        Dijkstra(cost, lowcost, pos - 1, 0);
        Dijkstra(cost_, lowcost_, pos - 1, 0);
        
        int sum = 0;
        for (int i = 1; i < tag; i++)
        {
            sum += (lowcost[i] + lowcost_[i]) * cars[i];
        }
        
        printf("%d. %d\n", key++, sum);
    }
    
    return 0;
}
