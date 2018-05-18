//
//  main.cpp
//  f-LCA
//
//  Created by ZYJ on 16/7/14.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

//  DFS + ST算法

///*
// *  DFS + ST在线算法
// */
//const int MAXN = 10010;
//int rmq[2 * MAXN];          //  rmq数组,就是欧拉序列对应的深度序列
//
//struct ST
//{
//    int mm[2*MAXN];
//    int dp[2*MAXN][20];     //  最小值对应的下标
//    void init(int n)
//    {
//        mm[0] = -1;
//        for (int i = 1; i <= n; i++)
//        {
//            mm[i] = ((i & (i - 1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
//            dp[i][0] = i;
//        }
//        for (int j = 1; j <= mm[n]; j++)
//        {
//            for (int i = 1; i + (1 << j) - 1 <= n; i++)
//            {
//                dp[i][j] = rmq[dp[i][j - 1]] < rmq[dp[i + (1 << (j - 1))][j - 1]] ? dp[i][j - 1] : dp[i + (1 << (j - 1))][j - 1];
//            }
//        }
//    }
//    int query(int a,int b)  //  查询[a,b]之间最小值的下标
//    {
//        if (a > b)
//        {
//            swap(a, b);
//        }
//        int k = mm[b - a + 1];
//        return rmq[dp[a][k]] <= rmq[dp[b - (1 << k) + 1][k]] ? dp[a][k] : dp[b - (1 << k) + 1][k];
//    }
//};
//
////  边的结构体定义
//struct Edge
//{
//    int to, next;
//};
//
//Edge edge[MAXN * 2];
//
//int tot, head[MAXN];
//int F[MAXN * 2];        //  欧拉序列,就是dfs遍历的顺序,长度为2*n-1,下标从1开始
//int P[MAXN];            //  P[i]表示点i在F中第一次出现的位置
//int cnt;
//ST st;
//
//void init()
//{
//    tot = 0;
//    memset(head, -1, sizeof(head));
//}
//
//void addedge(int u, int v)   //  加边,无向边需要加两次
//{
//    edge[tot].to = v;
//    edge[tot].next = head[u];
//    head[u] = tot++;
//}
//
//void dfs(int u, int pre, int dep)
//{
//    F[++cnt] = u;
//    rmq[cnt] = dep;
//    P[u] = cnt;
//    for (int i = head[u]; i != -1; i = edge[i].next)
//    {
//        int v = edge[i].to;
//        if (v == pre)
//        {
//            continue;
//        }
//        dfs(v, u, dep + 1);
//        F[++cnt] = u;
//        rmq[cnt] = dep;
//    }
//}
//
//void LCA_init(int root, int node_num)   //  查询LCA前的初始化
//{
//    cnt = 0;
//    dfs(root, root, 0);
//    st.init(2 * node_num - 1);
//}
//
//int query_lca(int u, int v)             //  查询u,v的lca编号
//{
//    return F[st.query(P[u], P[v])];
//}
//
//bool flag[MAXN];
//
//int main()
//{
//    int T;
//    int N;
//    int u, v;
//    scanf("%d", &T);
//    while(T--)
//    {
//        scanf("%d", &N);
//        init();
//        memset(flag, false, sizeof(flag));
//        for (int i = 1; i < N; i++)
//        {
//            scanf("%d%d", &u, &v);
//            addedge(u, v);
//            addedge(v, u);
//            flag[v] = true;
//        }
//        int root;
//        for (int i = 1; i <= N; i++)
//        {
//            if (!flag[i])
//            {
//                root = i;
//                break;
//            }
//        }
//        LCA_init(root, N);
//        scanf("%d%d", &u, &v);
//        printf("%d\n", query_lca(u, v));
//    }
//    return 0;
//}

//  离线Tarjan算法

///*
// *  给出一颗有向树，Q个查询
// *  输出查询结果中每个点出现次数
// *  复杂度O(n + Q);
// */
//const int MAXN = 1010;
//const int MAXQ = 500010;    //  查询数的最大值
//
////  并查集部分
//int F[MAXN];                //  需要初始化为-1
//
//int find(int x)
//{
//    if (F[x] == -1)
//    {
//        return x;
//    }
//    return F[x] = find(F[x]);
//}
//
//void bing(int u, int v)
//{
//    int t1 = find(u);
//    int t2 = find(v);
//    if (t1 != t2)
//    {
//        F[t1] = t2;
//    }
//}
//
//bool vis[MAXN];             //  访问标记
//int ancestor[MAXN];         //  祖先
//struct Edge
//{
//    int to, next;
//} edge[MAXN * 2];
//int head[MAXN],tot;
//
//void addedge(int u, int v)
//{
//    edge[tot].to = v;
//    edge[tot].next = head[u];
//    head[u] = tot++;
//}
//
//struct Query
//{
//    int q, next;
//    int index;              //  查询编号
//} query[MAXQ * 2];
//
//int answer[MAXQ];           //  存储最后的查询结果,下标0~Q-1
//int h[MAXQ];
//int tt;
//int Q;
//
//void add_query(int u, int v, int index)
//{
//        query[tt].q = v;
//        query[tt].next = h[u];
//        query[tt].index = index;
//        h[u] = tt++;
//        query[tt].q = u;
//        query[tt].next = h[v];
//        query[tt].index = index;
//        h[v] = tt++;
//}
//
//void init()
//{
//    tot = 0;
//    memset(head, -1, sizeof(head));
//    tt = 0;
//    memset(h, -1, sizeof(h));
//    memset(vis, false, sizeof(vis));
//    memset(F, -1, sizeof(F));
//    memset(ancestor, 0, sizeof(ancestor));
//}
//
//void LCA(int u)
//{
//    ancestor[u] = u;
//    vis[u] = true;
//    for (int i = head[u]; i != -1; i = edge[i].next)
//    {
//        int v = edge[i].to;
//        if (vis[v])
//        {
//            continue;
//        }
//        LCA(v);
//        bing(u, v);
//        ancestor[find(u)] = u;
//    }
//    for (int i = h[u]; i != -1; i = query[i].next)
//    {
//        int v = query[i].q;
//        if (vis[v])
//        {
//            answer[query[i].index] = ancestor[find(v)];
//        }
//    }
//}
//
//bool flag[MAXN];
//int Count_num[MAXN];
//    
//int main()
//{
//    int n;
//    int u, v, k;
//    while (scanf("%d", &n) == 1)
//    {
//        init();
//        memset(flag, false, sizeof(flag));
//        for (int i = 1; i <= n; i++)
//        {
//            scanf("%d:(%d)", &u, &k);
//            while (k--)
//            {
//                scanf("%d", &v);
//                flag[v] = true;
//                addedge(u,v);
//                addedge(v,u);
//            }
//        }
//        scanf("%d", &Q);
//        for (int i = 0; i < Q; i++)
//        {
//            char ch;
//            cin >> ch;
//            scanf("%d %d)", &u, &v);
//            add_query(u, v, i);
//        }
//        int root;
//        for (int i = 1; i <= n; i++)
//        {
//            if (!flag[i])
//            {
//                root = i;
//                break;
//            }
//        }
//        LCA(root);
//        memset(Count_num, 0, sizeof(Count_num));
//        for (int i = 0; i < Q; i++)
//        {
//            Count_num[answer[i]]++;
//        }
//        for (int i = 1; i <= n; i++)
//        {
//            if (Count_num[i] > 0)
//            {
//                printf("%d:%d\n", i, Count_num[i]);
//            }
//        }
//    }
//    return 0;
//}

//  LCA倍增法

/*
 * POJ 1330
 * LCA 在线算法 */
const int MAXN = 10010;
const int DEG = 20;

struct Edge
{
    int to, next;
} edge[MAXN * 2];

int head[MAXN], tot;
void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}

int fa[MAXN][DEG];      //  fa[i][j]表示结点i的第2^j个祖先
int deg[MAXN];          //  深度数组

void BFS(int root)
{
    queue<int>que;
    deg[root] = 0;
    fa[root][0] = root;
    que.push(root);
    while (!que.empty())
    {
        int tmp = que.front();
        que.pop();
        for (int i = 1; i < DEG; i++)
        {
            fa[tmp][i] = fa[fa[tmp][i - 1]][i - 1];
        }
        for (int i = head[tmp]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if (v == fa[tmp][0])
            {
                continue;
            }
            deg[v] = deg[tmp] + 1;
            fa[v][0] = tmp;
            que.push(v);
        }
    }
}

int LCA(int u, int v)
{
    if (deg[u] > deg[v])
    {
        swap(u, v);
    }
    int hu = deg[u], hv = deg[v];
    int tu = u, tv = v;
    for (int det = hv-hu, i = 0; det ; det >>= 1, i++)
    {
        if (det & 1)
        {
            tv = fa[tv][i];
        }
    }
    if (tu == tv)
    {
        return tu;
    }
    for (int i = DEG - 1; i >= 0; i--)
    {
        if (fa[tu][i] == fa[tv][i])
        {
            continue;
        }
        tu = fa[tu][i];
        tv = fa[tv][i];
    }
    return fa[tu][0];
}

bool flag[MAXN];

int main()
{
    int T;
    int n;
    int u, v;
    scanf("%d", &T);
    
    while(T--)
    {
        scanf("%d", &n);
        init();
        memset(flag, false, sizeof(flag));
        for (int i = 1; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
            flag[v] = true;
        }
        int root;
        for (int i = 1; i <= n; i++)
        {
            if (!flag[i])
            {
                root = i;
                break;
            }
        }
        BFS(root);
        scanf("%d%d", &u, &v);
        printf("%d\n", LCA(u, v));
    }
    return 0;
}