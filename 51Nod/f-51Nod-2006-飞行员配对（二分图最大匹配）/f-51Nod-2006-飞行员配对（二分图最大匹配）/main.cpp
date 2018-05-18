//
//  main.cpp
//  f-51Nod-2006-飞行员配对（二分图最大匹配）
//
//  Created by ZYJ on 2017/6/20.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

//  网络流模型
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

const int MAXN = 105;
const int MAXE = 1e5 + 10;
const int INF = 0x3f3f3f3f;

struct edge
{
    int v;
    int next, flow, op; //  opposite
};

int n, m;
int ans, tot;
int st, ed;     //  超级源点与超级汇点
int dis[MAXN];
int head[MAXN];
int path[MAXN];
bool vis[MAXN];
edge map[MAXE];
queue<int> que;
stack<int> sta;

void add_edge(int x, int y, int flow)
{
    tot++;
    map[tot].v = y;
    map[tot].flow = flow;
    map[tot].next = head[x];
    head[x] = tot;
    map[tot].op = tot + 1;
    tot++;
    map[tot].v = x;
    map[tot].flow = 0;
    map[tot].next = head[y];
    head[y] = tot;
    map[tot].op = tot - 1;
}

void init()
{
    ans = tot = 0;
    memset(head, 0, sizeof(head));
    
    st = 0;
    ed = n + 1;
    for (int i = 1; i <= m; i++)
    {
        add_edge(st, i, 1);
    }
    for (int i = m + 1; i <= n; i++)
    {
        add_edge(i, ed, 1);
    }
}

bool SPFA()
{
    memset(vis, false, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    
    vis[st] = true;
    dis[st] = 0;
    while (!que.empty())
    {
        que.pop();
    }
    
    que.push(st);
    
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        vis[u] = false;
        
        for (int t = head[u]; t; t = map[t].next)
        {
            int v = map[t].v;
            if (dis[u] + 1 < dis[v] && map[t].flow)
            {
                dis[v] = dis[u] + 1;
                if (!vis[v])
                {
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
    }
    
    if (dis[ed] < INF)
    {
        return true;
    }
    return false;
}

void Dinic()
{
    while (!sta.empty())
    {
        sta.pop();
    }
    sta.push(st);
    
    int x, last = 1;
    while (last)
    {
        while (last != sta.size())
        {
            sta.pop();
        }
        x = sta.top();
        if (x != ed)
        {
            int t = head[x];
            while (t && (dis[x] + 1 != dis[map[t].v] || map[t].flow == 0))
            {
                t = map[t].next;
            }
            if (t == 0)
            {
                dis[x] = INF;
                sta.pop();
                last--;
            }
            else
            {
                path[last] = t;
                sta.push(map[t].v);
                last++;
            }
        }
        else
        {
            int min_flow = INF;
            for (int i = 1; i < last; i++)
            {
                if (map[path[i]].flow < min_flow)
                {
                    min_flow = map[path[i]].flow;
                }
            }
            ans += min_flow;
            
            int tmp = 0;
            for (int i = last - 1; i > 0; i--)
            {
                map[path[i]].flow -= min_flow;
                map[map[path[i]].op].flow += min_flow;
                if (map[path[i]].flow == 0)
                {
                    tmp = i;
                }
            }
            last = tmp;
        }
    }
}

void solve()
{
    while (SPFA())
    {
        Dinic();
    }
}

int main()
{
    scanf("%d%d", &m, &n);
    
    init();
    
    int x, y;
    while (scanf("%d%d", &x, &y), x != -1 && y != -1)
    {
        add_edge(x, y, 1);
    }
    
    solve();
    
    if (ans == 0)
    {
        printf("No Solution!\n");
    }
    else
    {
        printf("%d\n", ans);
    }
    
    return 0;
}

//  匈牙利算法
//#include <cstdlib>
//#include <cstdio>
//#include <cstring>
//#include <iostream>
//
//using namespace std;
//
//const int MAXN = 105;
//const int MAXE = 1e5 + 10;
//
//struct edge
//{
//    int v;
//    int nt;
//};
//
//int n, m;
//int ans, tot;
//int head[MAXN];
//int match[MAXN];
//bool flag[MAXN];
//edge map[MAXE];
//
//void add_edge(int x, int y)
//{
//    tot++;
//    map[tot].v = y;
//    map[tot].nt = head[x];
//    head[x] = tot;
//}
//
//void init()
//{
//    memset(head, 0, sizeof(head));
//    memset(match, 0, sizeof(match));
//    
//    ans = tot = 0;
//}
//
//bool dfs(int x)
//{
//    for (int e = head[x]; e; e = map[e].nt)
//    {
//        int v = map[e].v;
//        if (!flag[v])
//        {
//            flag[v] = true;
//            if (match[v] == 0 || dfs(match[v]))
//            {
//                match[v] = x;
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//void hungary()
//{
//    for (int i = 1; i <= m; i++)
//    {
//        memset(flag, false, sizeof(flag));
//        if (dfs(i))
//        {
//            ans++;
//        }
//    }
//}
//
//int main()
//{
//    init();
//    
//    scanf("%d%d", &m, &n);
//    
//    int x, y;
//    while (scanf("%d%d", &x, &y), x != -1  &&  y != -1)
//    {
//        add_edge(x, y);
//    }
//    
//    hungary();
//    
//    printf("%d\n", ans);
//    
//    return 0;
//}
