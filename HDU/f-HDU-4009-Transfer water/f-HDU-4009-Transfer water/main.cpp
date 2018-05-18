//
//  main.cpp
//  f-HDU-4009-Transfer water
//
//  Created by ZYJ on 2016/11/6.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

/*
 *  最小树形图
 *  int型
 *  复杂度O(NM)
 *  点从0开始
 */
const int INF = 0x3f3f3f3f;
const int MAXN = 1010;
const int MAXM = 1000010;

struct Edge
{
    int u, v, cost;
};

Edge edge[MAXM];

int pre[MAXN], id[MAXN], visit[MAXN], in[MAXN];

int zhuliu(int root, int n, int m)
{
    int res = 0, v;
    while (1)
    {
        memset(in, 0x3f, sizeof(in));
        
        for (int i = 0; i < m; i++)
        {
            if (edge[i].u != edge[i].v && edge[i].cost < in[edge[i].v])
            {
                pre[edge[i].v] = edge[i].u;
                in[edge[i].v] = edge[i].cost;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i != root && in[i] == INF)
            {
                return -1;  //  不存在最小树形图
            }
        }
        int tn = 0;
        memset(id, -1, sizeof(id));
        memset(visit, -1, sizeof(visit));
        in[root] = 0;
        for (int i = 0; i < n; i++)
        {
            res += in[i];
            v = i;
            while (visit[v] != i && id[v] == -1 && v != root)
            {
                visit[v] = i;
                v = pre[v];
            }
            if (v != root && id[v] == -1)
            {
                for (int u = pre[v]; u != v ; u = pre[u])
                {
                    id[u] = tn;
                }
                id[v] = tn++;
            }
        }
        if (tn == 0)
        {
            break;  //  没有有向环
        }
        for (int i = 0; i < n; i++)
        {
            if (id[i] == -1)
            {
                id[i] = tn++;
            }
        }
        for (int i = 0; i < m; i++)
        {
            v = edge[i].v;
            edge[i].u = id[edge[i].u];
            edge[i].v = id[edge[i].v];
            if (edge[i].u != edge[i].v)
            {
                edge[i].cost -= in[v];
            }
        }
        n = tn;
        root = id[root];
    }
    return res;
}

//  结点坐标
struct Node
{
    int x;
    int y;
    int z;
} node[MAXN];

int getDis(Node a, Node b)
{
    return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
}

int main()
{
    int n, X, Y, Z;
    int num, key;
    while (cin >> n >> X >> Y >> Z, n + X + Y + Z)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &node[i].x, &node[i].y, &node[i].z);
        }
        
        int pos = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num);
            while (num--)
            {
                scanf("%d", &key);
                edge[pos].cost = getDis(node[i], node[--key]) * Y;
                if (node[key].z > node[i].z)
                {
                    edge[pos].cost += Z;
                }
                edge[pos].u = i;
                edge[pos++].v = key;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            edge[pos].u = n;
            edge[pos].v = i;
            edge[pos++].cost = node[i].z * X;
        }
        
        printf("%d\n", zhuliu(n, n + 1, pos));
    }
    
    return 0;
}
