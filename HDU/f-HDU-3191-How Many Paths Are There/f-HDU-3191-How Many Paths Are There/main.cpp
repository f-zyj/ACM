//
//  main.cpp
//  f-HDU-3191-How Many Paths Are There
//
//  Created by ZYJ on 2016/12/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 55;

struct Edge
{
    int to, w;
};

struct node
{
    int v, dist;
    int tag;
    bool friend operator < (const node &a, const node &b)
    {
        if (a.dist != b.dist)
        {
            return a.dist > b.dist;
        }
        return a.v > b.v;
    }
};

priority_queue<node> Q;
vector<Edge> graph[MAXN];

int cnt[MAXN][3];   //  cnt[v][1]存储最短路径数，cnt[v][2]存储次短路径数
int vis[MAXN][3];   //  同理，vis存状态
int dis[MAXN][3];   //  dis[v][1]存储最短，dis[v][2]存储次短
int N, M, A, B, L;

void init()
{
    for (int i = 0; i < MAXN; i++)
    {
        cnt[i][1] = cnt[i][2] = 0;
        vis[i][1] = vis[i][2] = 0;
        dis[i][1] = dis[i][2] = INF;
    }
}

void Dijstra(int st, int ed)
{
    dis[st][1] = 0;
    cnt[st][1] = 1;
    node q, p;
    p.dist = 0;
    p.tag = 1;
    p.v = st;
    Q.push(p);
    while (!Q.empty())
    {
        q = Q.top();
        Q.pop();
        if (vis[q.v][q.tag])
        {
            continue;
        }
        vis[q.v][q.tag] = 1;
        for (int i = 0; i < graph[q.v].size(); i++)
        {
            int v = graph[q.v][i].to;
            int w = graph[q.v][i].w;
            //  找到一条比“最短”更短的路
            if (!vis[v][1] && dis[v][1] > q.dist + w)
            {
                //  把“最短“变为”次短“
                if (dis[v][1] != INF)
                {
                    dis[v][2] = dis[v][1];
                    cnt[v][2] = cnt[v][1];
                    p.dist = dis[v][2];
                    p.tag = 2;
                    p.v = v;
                    Q.push(p);
                }
                //  更新”最短“
                dis[v][1] = q.dist + w;
                cnt[v][1] = cnt[q.v][q.tag];
                p.tag = 1;
                p.dist = dis[v][1];
                p.v = v;
                Q.push(p);
            }
            //  找到一条”最短“，更新”最短条数“
            else if (!vis[v][1] && dis[v][1] == q.dist + w)
            {
                cnt[v][1] += cnt[q.v][q.tag];
            }
            //  找到一条比”最短“长，比”次短“短的路，更新”次短“
            else if (!vis[v][2] && dis[v][2] > q.dist + w)
            {
                dis[v][2] = q.dist + w;
                cnt[v][2] = cnt[q.v][q.tag];
                p.tag = 2;
                p.dist = dis[v][2];
                p.v = v;
                Q.push(p);
            }
            //  找到一条”次短“，更新”次短条数“
            else if (!vis[v][2] && dis[v][2] == q.dist + w)
            {
                cnt[v][2] += cnt[q.v][q.tag];
            }
        }
    }
}

int main()
{
    Edge temp;
    int st, ed;
    while (~scanf("%d%d%d%d", &N, &M, &st, &ed))
    {
        init();
        for (int i = 0; i < MAXN; i++)
        {
            graph[i].clear();
        }
        
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d%d", &A, &B, &L);
            temp.to = B;
            temp.w = L;
            graph[A].push_back(temp);
        }
        
        Dijstra(st, ed);
        
        printf("%d %d\n", dis[ed][2], cnt[ed][2]);
    }
    
    return 0;
}
