//
//  main.cpp
//  f-POJ-1985-Cow Marathon
//
//  Created by ZYJ on 16/8/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstring>
#include <cstdio>
#include <queue>

#define MAXN 30010

using namespace std;

struct node
{
    int from, to, val, next;
} edge[MAXN];

bool vis[MAXN]; //  是否使用过
int dist[MAXN]; //  最远距离
int head[MAXN]; //  结点连边指向
int edgenum;    //  添加边数
int ans;        //  结果
int s;          //  最远两点的其中一点

void init()
{
    memset(head, -1, sizeof(head));
    edgenum = 0;
    return ;
}

void addedge(int x, int y, int z)
{
    edge[edgenum].from = x;
    edge[edgenum].to = y;
    edge[edgenum].val = z;
    edge[edgenum].next = head[x];
    head[x] = edgenum++;
    return ;
}

void bfs(int x)
{
    queue<int> que;
    ans = 0;
    memset(vis, false, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    
    que.push(x);                //  入队列
    vis[x] = true;              //  x使用过后置为true
    while (que.size())
    {
        int a = que.front();    //  访问队首
        que.pop();
        for (int i = head[a]; i != -1; i = edge[i].next)
        {
            int b = edge[i].to; //  i路径的另一端
            //  从x结点到b结点的距离小于x到a结点的距离+a和b直接的距离
            if (!vis[b] && dist[b] < dist[a] + edge[i].val)
            {
                dist[b] = dist[a] + edge[i].val;    //  更新距离
                if (ans < dist[b])                  //  如果ans小于此距离
                {
                    ans = dist[b];                  //  更新最远距离
                    s = b;                          //  更新最远点
                }
                vis[b] = true;                      //  b使用过后置为true
                que.push(b);                        //  入队列
            }
        }
    }
}

int main()
{
    int a, b, c, n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        init();
        char d;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d %c", &a, &b, &c, &d);
            addedge(a, b, c);
            addedge(b, a, c);
        }
        bfs(1); //  因为路径是唯一的，所以从任意一点查找最远的一定是最远两点其中一点
        bfs(s); //  s为其中最远一点，然后从s出发找另一点
        printf("%d\n", ans);    //  ans即为最远距离
    }
    
    return 0;
}
