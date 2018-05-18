//
//  main.cpp
//  f-欧拉路
//
//  Created by ZYJ on 16/6/11.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <vector>

//无向图欧拉路径O(E)

/*
 * INIT:adj[][]置为图的邻接表；cnt[a]为a点的邻接点数
 * CALL:alpath(0);  注意：不要有自向边
 */

//const int V = 10000;
//int adj[V][V];
//int idx[V][V];
//int cnt[V];
//int stk[V];
//int top = 0;
//
//int path(int v)
//{
//    for (int w; cnt[v] > 0; v = w)
//    {
//        stk[top++] = v;
//        w = adj[v][--cnt[v]];
//        adj[w][idx[w][v]] = adj[w][--cnt[w]];
//        //处理的是无向图——边是双向边，删除v->w后，还要处理删除w->v
//    }
//    return v;
//}
//
//void elpath(int b, int n)
//{
//    int i, j;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < cnt[i]; j++)
//        {
//            idx[i][adj[i][j]] = j;
//        }
//    }
//    std::cout << b;
//    for (top = 0; path(b) == b && top != 0; )
//    {
//        b = stk[--top];
//        std::cout << '-' << b;
//    }
//    std::cout << std::endl;
//}

//有向图欧拉路径

/*
 * POJ 2337
 * 给出n个小写字母组成的单词，要求将n个单词连接起来。使得前一个单词的最后一个字母和
 * 后一个单词的第一个字母相同。输出字典序最小解
 */

//struct Edge
//{
//    int to;
//    int next;
//    int index;
//    bool flag;
//}edge[2010];
//
//int head[30];
//int tot;
//
//void init()
//{
//    tot = 0;
//    memset(head, -1, sizeof(head));
//}
//
//void addEdge(int u, int v, int index)
//{
//    edge[tot].to = v;
//    edge[tot].next = head[u];
//    edge[tot].index = index;
//    edge[tot].flag = false;
//    head[u] = tot++;
//    return ;
//}
//
//std::string str[1010];
//int in[30];
//int out[30];
//int cnt;
//int ans[1010];
//
//void dfs(int u)
//{
//    for (int i = head[u]; i != -1; i = edge[i].next)
//    {
//        if (!edge[i].flag)
//        {
//            edge[i].flag = true;
//            dfs(edge[i].to);
//            ans[cnt++] = edge[i].index;
//        }
//    }
//    return ;
//}
//
//int main(int argc, const char * argv[])
//{
////    freopen("in.txt", "r", stdin);
////    freopen("out.txt", "w", stdout);
//    int T, n;
//    std::cin >> T;
//    while (T--)
//    {
//        std::cin >> n;
//        for (int i = 0; i < n; i++)
//        {
//            std::cin >> str[i];
//        }
//        std::sort(str, str + n);    //要输出字典序最小的解，先按照字典序排序
//        init();
//        memset(in, 0, sizeof(in));
//        memset(out, 0, sizeof(out));
//        int start = 100;
//        for (int i = n - 1; i >= 0; i--)    //字典序大的先加入
//        {
//            int u = str[i][0] - 'a';
//            int v = str[i][str[i].length() - 1] - 'a';
//            addEdge(u, v, i);
//            out[u]++;
//            in[v]++;
//            if (n < start)
//            {
//                start = u;
//            }
//            if (v < start)
//            {
//                start = v;
//            }
//        }
//        int ccOne = 0;
//        int ccTwo = 0;
//        for (int i = 0; i < 26; i++)
//        {
//            if (out[i] - in[i] == 1)
//            {
//                ccOne++;
//                start = 1;  //如果有一个出度比入度大1的点，就从这个点出发，否则从最小的点出发
//            }
//            else if (out[i] - in[i] == -1)
//            {
//                ccTwo++;
//            }
//            else if (out[i] - in[i] != 0)
//            {
//                ccOne = 3;
//            }
//        }
//        if (!((ccOne == 0 && ccTwo == 0) || (ccOne == 1 && ccTwo == 1)))
//        {
//            std::cout << "***" << '\n';
//            continue;
//        }
//        cnt = 0;
//        dfs(start);
//        if (cnt != n)   //判断是否连通
//        {
//            std::cout << "***" << '\n';
//            continue;
//        }
//        for (int i = cnt - 1; i >= 0; i--)
//        {
//            std::cout << str[ans[i]];
//            if (i > 0)
//            {
//                std::cout << '.';
//            }
//            else
//            {
//                std::cout << '\n';
//            }
//        }
//    }
//
//    return 0;
//}

// 无向图欧拉回路

/*
 * SGU 101
 */

//struct Edge
//{
//    int to;
//    int next;
//    int index;
//    int dir;
//    bool flag;
//} edge[220];
//
//int head[10];   //前驱
//int tot;
//
//void init()
//{
//    memset(head, -1, sizeof((head)));
//    tot = 0;
//}
//
//void addEdge(int u, int v, int index)
//{
//    edge[tot].to = v;
//    edge[tot].next = head[u];
//    edge[tot].index = index;
//    edge[tot].dir = 0;
//    edge[tot].flag = false;
//    head[u] = tot++;
//    edge[tot].to = u;
//    edge[tot].next = head[v];
//    edge[tot].index = index;
//    edge[tot].dir = 1;
//    edge[tot].flag = false;
//    head[v] = tot++;
//    return ;
//}
//
//int du[10];
//std::vector<int>ans;
//
//void dfs(int u)
//{
//    for (int i = head[u]; i != -1; i = edge[i].next)
//    {
//        if (!edge[i].flag)
//        {
//            edge[i].flag = true;
//            edge[i ^ 1].flag = true;
//            dfs(edge[i].to);
//            ans.push_back(i);   //容器尾部插入i
//        }
//    }
//    return ;
//}
//
//int main()
//{
//    //freopen("in.txt", "r", stdin);
//    //freopen("out.txt", "w", stdout);
//    int n;
//    while (std::cin >> n)
//    {
//        init();
//        int u, v;
//        memset(du, 0, sizeof(du));
//        
//        for (int i = 1; i <= n; i++)
//        {
//            std::cin >> u >> v;
//            addEdge(u, v, i);
//            du[u]++;
//            du[v]++;
//        }
//        int s = -1;
//        int cnt = 0;
//        
//        for (int i = 0; i <= 6; i++)
//        {
//            if (du[i] & 1)
//            {
//                cnt++;
//                s = i;
//            }
//            if (du[i] > 0 && s == -1)
//            {
//                s = i;
//            }
//        }
//        
//        if (cnt != 0 && cnt != 2)
//        {
//            std::cout << "No solution" << '\n';
//            continue;
//        }
//        ans.clear();
//        dfs(s);
//        if (ans.size() != n)
//        {
//            std::cout << "No solution" << '\n';
//            continue;
//        }
//        
//        for (int i = 0; i < ans.size(); i++)
//        {
//            printf("%d ", edge[ans[i]].index);
//            if (edge[ans[i]].dir == 0)
//            {
//                std::cout << "-" << '\n';
//            }
//            else
//            {
//                std::cout << "+" << '\n';
//            }
//        }
//    }
//    return 0;
//}

// 混合图欧拉路径

/*
 * POJ 1637
 * 本题保证了连通，故不需要判断连通，否则要判断连通
 */

//const int MAXN = 210;
//const int MAXM = 20100;     //最大流ISAP部分
//const int INF = 0x3f3f3f3f;
//
//struct Edge
//{
//    int to;
//    int next;
//    int cap;
//    int flow;
//}edge[MAXM];
//
//int tol;
//int head[MAXN];
//int gap[MAXN];
//int dep[MAXN];
//int pre[MAXN];
//int cur[MAXN];
//
//void init()
//{
//    tol = 0;
//    memset(head, -1, sizeof(head));
//    return ;
//}
//
//void addEdge(int u, int v, int w, int rw = 0)
//{
//    edge[tol].to = v;
//    edge[tol].cap = w;
//    edge[tol].next = head[u];
//    edge[tol].flow = 0;
//    head[u] = tol++;
//    edge[tol].to = u;
//    edge[tol].cap = rw;
//    edge[tol].next = head[v];
//    edge[tol].flow = 0;
//    head[v] = tol++;
//    return ;
//}
//
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
//            int MIN = INF;
//            for (int i = pre[u]; i != -1; i = pre[edge[i ^ 1].to])
//            {
//                if (MIN > edge[i].cap - edge[i].flow)
//                {
//                    MIN = edge[i].cap - edge[i].flow;
//                }
//            }
//            for (int i = pre[u]; i != -1; i = pre[edge[i ^ 1].to])
//            {
//                edge[i].flow += MIN;
//                edge[i ^ 1].flow -= MIN;
//            }
//            u = start;
//            ans += MIN;
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
//        int MIN = N;
//        for (int i = head[u]; i != -1; i = edge[i].next)
//        {
//            if (edge[i].cap - edge[i].flow && dep[edge[i].to] < MIN)
//            {
//                MIN = dep[edge[i].to];
//                cur[u] = i;
//            }
//        }
//        gap[dep[u]]--;
//        if (!gap[dep[u]])
//        {
//            return ans;
//        }
//        dep[u] = MIN + 1;
//        gap[dep[u]]++;
//        if (u != start)
//        {
//            u = edge[pre[u] ^ 1].to;
//        }
//    }
//    return ans;
//}
//
////the end of 最大流部分
//
//int in[MAXN];
//int out[MAXN];
//
//int main()
//{
//    //freopen("in.txt", "r", stdin);
//    //freopen("out.txt", "w", stdout);
//    int T;
//    int n, m;
//    std::cin >> T;
//    while (T--)
//    {
//        std::cin >> n >> m;
//        init();
//        int u, v, w;
//        memset(in, 0, sizeof(in));
//        memset(out, 0, sizeof(out));
//        
//        while (m--)
//        {
//            std::cin >> u >> v >> w;
//            out[u]++;
//            in[v]++;
//            if (w == 0)
//            {
//                addEdge(u, v, 1);   //双向
//            }
//        }
//        bool flag = true;
//        for (int i = 1; i <= n; i++)
//        {
//            if (out[i] - in[i] > 0)
//            {
//                addEdge(0, i, (out[i] - in[i]) / 2);
//            }
//            else if (in[i] - out[i] > 0)
//            {
//                addEdge(i, n + 1, (in[i] - out[i]) / 2);
//            }
//            if ((out[i] - in[i]) & 1)
//            {
//                flag = false;
//            }
//        }
//        if (!flag)
//        {
//            std::cout << "impossible" << '\n';
//            continue;
//        }
//        sap(0, n + 1, n + 2);
//        for (int i = head[0]; i != -1; i = edge[i].next)
//        {
//            if (edge[i].cap > 0 && edge[i].cap > edge[i].flow)
//            {
//                flag = false;
//                break;
//            }
//        }
//        if (flag)
//        {
//            std::cout << "possible" << '\n';
//        }
//        else
//        {
//            std::cout << "impossible" << '\n';
//        }
//    }
//    
//    return 0;
//}
