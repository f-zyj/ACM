//
//  main.cpp
//  f-最大流
//
//  Created by ZYJ on 16/7/19.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//  Dinic最大流

///*
// *  Dinic 最大流 O(V^2 * E)
// *  INIT: ne=2; head[]置为0; addedge()加入所有弧; 
// *  CALL: flow(n, s, t);
// */
//#define typec int               //  type of cost
//const typec inf = 0x3f3f3f3f;   // max of cost
//const typec E = 10010;
//const typec N = 1010;
//
//struct edge
//{
//    int x, y, nxt;
//    typec c;
//} bf[E];
//int ne, head[N], cur[N], ps[N], dep[N];
//
//void addedge(int x, int y, typec c)
//{   //  add an arc(x->y, c);    vertex:0~n-1;
//    bf[ne].x = x;
//    bf[ne].y = y;
//    bf[ne].c = c;
//    bf[ne].nxt = head[x];
//    head[x] = ne++;
//    bf[ne].x = y;
//    bf[ne].y = x;
//    bf[ne].c = 0;
//    bf[ne].nxt = head[y];
//    head[y] = ne++;
//    return ;
//}
//
//typec flow(int n, int s, int t)
//{
//    typec tr, res = 0;
//    int i, j, k, f, r, top;
//    while (1)
//    {
//        memset(dep, -1, n * sizeof(int));
//        for (f = dep[ps[0] = s] = 0, r = 1; f != r;)
//        {
//            for (i = ps[f++], j = head[i]; j; j = bf[j].nxt)
//            {
//                if (bf[j].c && -1 == dep[k = bf[j].y])
//                {
//                    dep[k] = dep[i] + 1;
//                    ps[r++] = k;
//                    if (k == t)
//                    {
//                        f = r;
//                        break;
//                    }
//                }
//            }
//        }
//        if (-1 == dep[t])
//        {
//            break;
//        }
//        memcpy(cur, head, n * sizeof(int));
//        for (i = s, top = 0; ;)
//        {
//            if (i == t)
//            {
//                for (k = 0, tr = inf; k < top; ++k)
//                {
//                    if (bf[ps[k]].c < tr)
//                    {
//                        tr = bf[ps[f = k]].c;
//                    }
//                }
//                for (k = 0; k < top; ++k)
//                {
//                    bf[ps[k]].c -= tr, bf[ps[k]^1].c += tr;
//                }
//                res += tr;
//                i = bf[ps[top = f]].x;
//            }
//            for (j = cur[i]; cur[i]; j = cur[i] = bf[cur[i]].nxt)
//            {
//                if (bf[j].c && dep[i] + 1 == dep[bf[j].y])
//                {
//                    break;
//                }
//            }
//            if (cur[i])
//            {
//                ps[top++] = cur[i];
//                i = bf[cur[i]].y;
//            }
//            else
//            {
//                if (0 == top)
//                {
//                    break;
//                }
//                dep[i] = -1;
//                i = bf[ps[--top]].x;
//            }
//        }
//    }
//    return res;
//}


//  HLPP算法

///*
// *  HLPP 最大流 O(V^3)
// *  INIT: network g; g.build(nv, ne); 
// *  CALL: res = g.maxflow(s, t);
// *  注意: 不要加入指向源点的边, 可能死循环.
// */
//#define typef int               //  type of flow
//const typef inf = 0x3f3f3f3f;   //  max of flow
//const typef N = 10010;
//
//typef minf(typef a, typef b)
//{
//    return a < b ? a : b;
//}
//
//struct edge
//{
//    int u, v;
//    typef cuv, cvu, flow;
//    edge (int x = 0, int y = 0, typef cu = 0, typef cv = 0, typef f = 0) : u(x), v(y), cuv(cu), cvu(cv), flow(f) {}
//    int other(int p)
//    {
//        return p == u ? v : u;
//    }
//    typef cap(int p)
//    {
//        return p == u ? cuv - flow : cvu + flow;
//    }
//    void addflow(int p, typef f)
//    {
//        flow += (p == u ? f : -f);
//        return ;
//    }
//};
//
//struct vlist
//{
//    int lv, next[N], idx[2 * N], v;
//    void clear(int cv)
//    {
//        v = cv;
//        lv = -1;
//        memset(idx, -1, sizeof(idx));
//    }
//    void insert(int n, int h)
//    {
//        next[n] = idx[h];
//        idx[h] = n;
//        if (lv < h)
//        {
//            lv = h;
//        }
//    }
//    int remove()
//    {
//        int r = idx[lv];
//        idx[lv] = next[idx[lv]];
//        while (lv >= 0 && idx[lv] == -1)
//        {
//            lv--;
//        }
//        return r;
//    }
//    bool empty()
//    {
//        return lv < 0;
//    }
//};
//
//struct network
//{
//    vector<edge>eg;
//    vector<edge*>net[N];
//    vlist list;
//    typef e[N];
//    int v, s, t, h[N], hn[2 * N], cur[N];
//    void push(int);
//    void relabel(int);
//    void build(int, int);
//    typef maxflow(int, int);
//};
//
//void network::push(int u)
//{
//    edge* te = net[u][cur[u]];
//    typef ex = minf(te->cap(u), e[u]);
//    int p = te->other(u);
//    if (e[p] == 0 && p != t)
//    {
//        list.insert(p, h[p]);
//    }
//    te->addflow(u, ex);
//    e[u] -= ex;
//    e[p] += ex;
//    return ;
//}
//
//void network::relabel(int u)
//{
//    int i, p, mh = 2 * v, oh = h[u];
//    for (i = (int)net[u].size() - 1; i >= 0; i--)
//    {
//        p = net[u][i]->other(u);
//        if (net[u][i]->cap(u) != 0 && mh > h[p] + 1)
//        {
//            mh = h[p] + 1;
//        }
//    }
//    hn[h[u]]--;
//    hn[mh]++;
//    h[u] = mh;
//    cur[u] = (int)net[u].size() - 1;
//    if (hn[oh] != 0 || oh >= v + 1)
//    {
//        return ;
//    }
//    for (i = 0; i < v; i++)
//    {
//        if (h[i] > oh && h[i] <= v && i != s)
//        {
//            hn[h[i]]--;
//            hn[v+1]++;
//            h[i] = v + 1;
//        }
//    }
//    return ;
//}
//
//typef network::maxflow(int ss, int tt)
//{
//    s = ss; t = tt;
//    int i, p, u; typef ec;
//    for (i = 0; i < v; i++)
//    {
//        net[i].clear();
//    }
//    for (i = (int)eg.size() - 1; i >= 0; i--)
//    {
//        net[eg[i].u].push_back(&eg[i]);
//        net[eg[i].v].push_back(&eg[i]);
//    }
//    memset(h, 0, sizeof(h));
//    memset(hn, 0, sizeof(hn));
//    memset(e, 0, sizeof(e));
//    e[s] = inf;
//    for (i = 0; i < v; i++)
//    {
//        h[i] = v;
//    }
//    queue<int> q;
//    q.push(t);
//    h[t] = 0;
//    while (!q.empty())
//    {
//        p = q.front();
//        q.pop();
//        for (i = (int)net[p].size() - 1; i >= 0; i--)
//        {
//            u = net[p][i]->other(p);
//            ec = net[p][i]->cap(u);
//            if (ec != 0 && h[u] == v && u != s)
//            {
//                h[u] = h[p] + 1;
//                q.push(u);
//            }
//        }
//    }
//    for (i = 0; i < v; i++)
//    {
//        hn[h[i]]++;
//    }
//    for (i = 0; i < v; i++)
//    {
//        cur[i] = (int)net[i].size()-1;
//    }
//    list.clear(v);
//    for (; cur[s] >= 0; cur[s]--)
//    {
//        push(s);
//    }
//    while (!list.empty())
//    {
//        for (u = list.remove(); e[u] > 0; )
//        {
//            if (cur[u] < 0)
//            {
//                relabel(u);
//            }
//            else if (net[u][cur[u]]->cap(u) > 0 && h[u] == h[net[u][cur[u]]->other(u)] + 1)
//            {
//                push(u);
//            }
//            else
//            {
//                cur[u]--;
//            }
//        }
//    }
//    return e[t];
//}
//
//void network::build(int n, int m)
//{
//    v = n;
//    eg.clear();
//    int a, b, i;
//    typef l;
//    for (i = 0; i < m; i++)
//    {
//        cin >> a >> b >> l;
//        eg.push_back(edge(a, b, l, 0));     //  vertex: 0 ~ n-1
//    }
//    return ;
//}

//  SAP邻接矩阵形式

///*
// *  SAP算法(矩阵形式) 
// *  结点编号从0开始
// */
//const int MAXN = 1100;
//int maze[MAXN][MAXN];
//int gap[MAXN], dis[MAXN], pre[MAXN], cur[MAXN];
//
//int sap(int start, int end, int nodenum)
//{
//    memset(cur, 0, sizeof(cur));
//    memset(dis, 0, sizeof(dis));
//    memset(gap, 0, sizeof(gap));
//    int u = pre[start] = start, maxflow = 0, aug = -1;
//    gap[0] = nodenum;
//    while (dis[start] < nodenum)
//    {
//    loop:
//        for (int v = cur[u]; v < nodenum; v++)
//        {
//            if (maze[u][v] && dis[u]==dis[v] + 1)
//            {
//                if (aug == -1 || aug > maze[u][v])
//                {
//                    aug=maze[u][v];
//                }
//                pre[v]=u;
//                u=cur[u]=v;
//                if (v == end)
//                {
//                    maxflow += aug;
//                    for (u = pre[u]; v != start; v = u, u = pre[u])
//                    {
//                        maze[u][v] -= aug;
//                        maze[v][u] += aug;
//                    }
//                    aug = -1;
//                }
//                goto loop;
//            }
//        }
//        int mindis = nodenum - 1;
//        for (int v = 0; v < nodenum; v++)
//        {
//            if (maze[u][v] && mindis > dis[v])
//            {
//                cur[u] = v;
//                mindis = dis[v];
//            }
//        }
//        if ((--gap[dis[u]]) == 0)
//        {
//            break;
//        }
//        gap[dis[u] = mindis + 1]++;
//        u = pre[u];
//    }
//    return maxflow;
//}

//  SAP临街矩阵形式2

///*
// *  SAP邻接矩阵形式
// *  点的编号从0开始
// *  增加个flow数组,保留原矩阵maze,可用于多次使用最大流 
// */
//const int MAXN = 1100;
//int maze[MAXN][MAXN];
//int gap[MAXN], dis[MAXN], pre[MAXN], cur[MAXN];
//int flow[MAXN][MAXN];           //  存最大流的容量
//
//int sap(int start, int end, int nodenum)
//{
//    memset(cur, 0, sizeof(cur));
//    memset(dis, 0, sizeof(dis));
//    memset(gap, 0, sizeof(gap));
//    memset(flow, 0, sizeof(flow));
//    int u = pre[start] = start, maxflow = 0, aug = -1;
//    gap[0] = nodenum;
//    while (dis[start] < nodenum)
//    {
//    loop:
//        for (int v = cur[u]; v < nodenum; v++)
//        {
//            if (maze[u][v] - flow[u][v] && dis[u] == dis[v] + 1)
//            {
//                if (aug == -1 || aug > maze[u][v] - flow[u][v])
//                {
//                    aug = maze[u][v] - flow[u][v];
//                }
//                pre[v] = u;
//                u = cur[u] = v;
//                if (v == end)
//                {
//                    maxflow += aug;
//                    for (u = pre[u]; v != start; v = u, u = pre[u])
//                    {
//                        flow[u][v] += aug;
//                        flow[v][u] -= aug;
//                    }
//                    aug = -1;
//                }
//                goto loop;
//            }
//        }
//        int mindis = nodenum - 1;
//        for (int v = 0; v < nodenum; v++)
//        {
//            if (maze[u][v] - flow[u][v] && mindis > dis[v])
//            {
//                cur[u] = v;
//                mindis = dis[v];
//            }
//        }
//        if ((--gap[dis[u]]) == 0)
//        {
//            break;
//        }
//        gap[dis[u] = mindis + 1]++;
//        u = pre[u];
//    }
//    return maxflow;
//}

//  ISAP邻接表形式

//const int MAXN = 100010;    //  点数的最大值
//const int MAXM = 400010;    //  边数的最大值
//const int INF = 0x3f3f3f3f;
//
//struct Edge
//{
//    int to, next, cap, flow;
//} edge[MAXM];   //  注意是MAXM
//
//int tol;
//int head[MAXN];
//
//int gap[MAXN], dep[MAXN], pre[MAXN], cur[MAXN];
//
//void init()
//{
//    tol = 0;
//    memset(head, -1, sizeof(head));
//}
//
////  加边,单向图三个参数,双向图四个参数
//void addedge(int u, int v, int w, int rw = 0)
//{
//    edge[tol].to = v;
//    edge[tol].cap = w;
//    edge[tol].next = head[u];
//    edge[tol].flow = 0;
//    head[u] = tol++;
//    edge[tol].to = u;edge[tol].cap = rw;
//    edge[tol].next = head[v];
//    edge[tol].flow = 0;
//    head[v]=tol++;
//    return ;
//}
//
////  输入参数:起点、终点、点的总数
////  点的编号没有影响,只要输入点的总数
//int sap(int start, int end, int N)
//{
//    memset(gap, 0, sizeof(gap));
//    memset(dep, 0, sizeof(dep));
//    memcpy(cur, head, sizeof(head));
//    int u = start;
//    pre[u] = -1;
//    gap[0] = N;
//    int ans = 0;
//    while (dep[start] < N)
//    {
//        if (u == end)
//        {
//            int Min = INF;
//            for (int i = pre[u]; i != -1; i = pre[edge[i^1].to])
//            {
//                if (Min > edge[i].cap - edge[i].flow)
//                {
//                    Min = edge[i].cap - edge[i].flow;
//                }
//                for (int i = pre[u]; i != -1; i = pre[edge[i^1].to])
//                {
//                    edge[i].flow += Min;
//                    edge[i^1].flow -= Min;
//                }
//            }
//            u = start;
//            ans += Min;
//            continue;
//        }
//        bool flag = false;
//        int v = 0;
//        for (int i = cur[u]; i != -1; i = edge[i].next)
//        {
//            v = edge[i].to;
//            if (edge[i].cap - edge[i].flow && dep[v] + 1 == dep[u])
//            {
//                flag = true;
//                cur[u] = pre[v] = i;
//                break;
//            }
//        }
//        if (flag)
//        {
//            u = v;
//            continue;
//        }
//        int Min = N;
//        for (int i = head[u]; i != -1; i = edge[i].next)
//        {
//            if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
//            {
//                Min = dep[edge[i].to];
//                cur[u] = i;
//            }
//        }
//        gap[dep[u]]--;
//        if(!gap[dep[u]])
//        {
//            return ans;
//        }
//        dep[u] = Min + 1;
//        gap[dep[u]]++;
//        if (u != start)
//        {
//            u = edge[pre[u]^1].to;
//        }
//    }
//    return ans;
//}

//  ISAP+BFS 初始化+栈优化

const int MAXN = 100010;    //  点数的最大值
const int MAXM = 400010;    //  边数的最大值
const int INF = 0x3f3f3f3f;

struct Edge
{
    int to, next, cap, flow;
} edge[MAXM];               //  注意是MAXM

int tol;
int head[MAXN];
int gap[MAXN], dep[MAXN], cur[MAXN];

void init()
{
    tol = 0;
    memset(head, -1, sizeof(head));
    return ;
}

void addedge(int u, int v, int w, int rw = 0)
{
    edge[tol].to = v;
    edge[tol].cap = w;
    edge[tol].flow = 0;
    edge[tol].next = head[u];
    head[u] = tol++;
    edge[tol].to = u;
    edge[tol].cap = rw;
    edge[tol].flow = 0;
    edge[tol].next = head[v];
    head[v] = tol++;
    return ;
}

int Q[MAXN];
void BFS(int start, int end)
{
    memset(dep, -1, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    gap[0] = 1;
    int front = 0, rear = 0;
    dep[end] = 0;
    Q[rear++] = end;
    while (front != rear)
    {
        int u = Q[front++];
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if (dep[v] != -1)
            {
                continue;
            }
            Q[rear++] = v;
            dep[v] = dep[u] + 1;
            gap[dep[v]]++;
        }
    }
    return ;
}

int S[MAXN];
int sap(int start, int end, int N)
{
    BFS(start, end);
    memcpy(cur, head, sizeof(head));
    int top = 0;
    int u = start;
    int ans = 0;
    while (dep[start] < N)
    {
        if (u == end)
        {
            int Min = INF;
            int inser = 0;
            for (int i = 0; i < top; i++)
            {
                if (Min > edge[S[i]].cap - edge[S[i]].flow)
                {
                    Min = edge[S[i]].cap - edge[S[i]].flow;
                    inser = i;
                }
            }
            for (int i = 0; i < top; i++)
            {
                edge[S[i]].flow += Min;
                edge[S[i]^1].flow -= Min;
            }
            ans += Min;
            top = inser;
            u = edge[S[top]^1].to;
            continue;
        }
        bool flag = false;
        int v = 0;
        for (int i = cur[u]; i != -1; i = edge[i].next)
        {
            v = edge[i].to;
            if (edge[i].cap - edge[i].flow && dep[v] + 1 == dep[u])
            {
                flag = true;
                cur[u] = i;
                break;
            }
        }
        if(flag)
        {
            S[top++] = cur[u];
            u = v;
            continue;
        }
        int Min = N;
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            if (edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
            {
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        }
        gap[dep[u]]--;
        if (!gap[dep[u]])
        {
            return ans;
        }
        dep[u] = Min + 1;
        gap[dep[u]]++;
        if (u != start)
        {
            u = edge[S[--top]^1].to;
        }
    }
    return ans;
}