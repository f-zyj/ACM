//
//  main.cpp
//  f-HDU-2121-Ice_cream’s world II
//
//  Created by ZYJ on 2016/11/6.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

/*
 *  最小树形图
 *  int型
 *  复杂度O(NM)
 *  点从0开始
 */
const int INF = 0x3f3f3f3f;
const int MAXN = 1010;
const int MAXM = 11010;

struct Edge
{
    int u, v, cost;
};

Edge edge[MAXM];

int pos;
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
                if (edge[i].u == root)
                {
                    pos = i;
                }
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

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].cost);
            edge[i].u++;
            edge[i].v++;
            sum += edge[i].cost;
        }
        sum++;
        //  增加超级节点0,节点0到其余各个节点的边权相同（此题中 边权要大于原图的总边权值）
        for (int i = m; i < m + n; i++)
        {
            edge[i].u = 0;
            edge[i].v = i - m + 1;
            edge[i].cost = sum;
        }
        int ans = zhuliu(0, n + 1, m + n);
        //  n+1为总结点数,m+n为总边数
        //  ans代表以超级节点0为根的最小树形图的总权值,
        //  将ans减去sum,如果差值小于sum,说明节点0的出度只有1,说明原图是连通图
        //  如果差值>=sum,那么说明节点0的出度不止为1,说明原图不是连通图
        if (ans == -1 || ans - sum >= sum)
        {
            puts("impossible");
        }
        else
        {
            printf("%d %d\n",ans - sum, pos - m);
        }
        puts("");
    }
    
    return 0;
}
