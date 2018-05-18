//
//  main.cpp
//  f-51Nod-1766-树上的最远点对
//
//  Created by ZYJ on 2017/7/5.
//  Copyright ? 2017年 ZYJ. Aint rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>

#define lson  root << 1
#define rson  root << 1 | 1
#define clr(a, b) memset(a, b, sizeof(a))

using namespace std;

const int MAXN = 1e5 + 10;

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

template <class T>
void print_d(T a)
{   //  输出外挂
    if (a < 0)
    {
        putchar('-');
        a = -a;
    }
    if (a >= 10)
    {
        print_d(a / 10);
    }
    putchar(a % 10 + '0');
}

int rmq[2 * MAXN];

struct ST
{
    int mm[2 * MAXN];
    int dp[2 * MAXN][20];     //  最小值对应的下标
    void init(int n)
    {
        mm[0] = -1;
        for (int i = 1; i <= n; i++)
        {
            mm[i] = ((i & (i - 1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
            dp[i][0] = i;
        }
        for (int j = 1; j <= mm[n]; j++)
        {
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
            {
                dp[i][j] = rmq[dp[i][j - 1]] < rmq[dp[i + (1 << (j - 1))][j - 1]] ? dp[i][j - 1] : dp[i + (1 << (j - 1))][j - 1];
            }
        }
    }
    int query(int a, int b)  //  查询[a,b]之间最小值的下标
    {
        if (a > b)
        {
            swap(a, b);
        }
        int k = mm[b - a + 1];
        return rmq[dp[a][k]] <= rmq[dp[b - (1 << k) + 1][k]] ? dp[a][k] : dp[b - (1 << k) + 1][k];
    }
};

struct Edge
{
    int to,next;
    int w;
};

Edge edge[MAXN * 2];

int tot, cnt;
int head[MAXN];
int F[MAXN * 2];
int P[MAXN];
int dis[MAXN];
ST st;

void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w)
{
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void dfs(int u, int pre, int dep)
{
    F[++cnt] = u;
    rmq[cnt] = dep;
    P[u] = cnt;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == pre)
        {
            continue;
        }
        dis[v] = dis[u] + edge[i].w;
        dfs(v, u, dep + 1);
        F[++cnt] = u;
        rmq[cnt] = dep;
    }
}

void LCA_init(int root, int node_num)   //  查询LCA前的初始化
{
    cnt = 0;
    dfs(root, root, 0);
    st.init(2 * node_num - 1);
}

int query_lca(int u, int v)             //  查询u,v的lca编号
{
    return F[st.query(P[u], P[v])];
}

int get_dis(int a, int b)
{
    int lca = query_lca(a, b);
    return dis[a] + dis[b] - dis[lca] - dis[lca];
}

struct node
{
    int l, r;
    int s, t;   //  l~r 所构成的虚树的直径的两端点
    int len;
} tree[MAXN << 2];

void cal(int root, int a, int b)
{
    int len = get_dis(a, b);
    if (tree[root].len < len)
    {
        tree[root].len = len;
        tree[root].s = a;
        tree[root].t = b;
    }
}

void push_up(int root)
{
    cal(root, tree[lson].s, tree[rson].s);
    cal(root, tree[lson].s, tree[rson].t);
    cal(root, tree[lson].t, tree[rson].s);
    cal(root, tree[lson].t, tree[rson].t);
    cal(root, tree[lson].s, tree[lson].t);
    cal(root, tree[rson].s, tree[rson].t);
}

void build(int root, int l, int r)
{
    tree[root].l = l;
    tree[root].r = r;
    tree[root].len = tree[root].s = tree[root].t = 0;
    
    if (l == r)
    {
        tree[root].s = tree[root].t = l;
        return ;
    }
    
    int m = (tree[root].l + tree[root].r) >> 1;
    build(lson, l, m);
    build(rson, m + 1, r);
    push_up(root);
}

int from, to;

void get_ft(int a, int b, int &len)
{
    if (get_dis(a, b) > len)
    {
        len = get_dis(a, b);
        from = a;
        to = b;
    }
}

void query(int root, int l, int r, int &ta, int &tb)
{
    ta = tb = -1;
    if (tree[root].l >= l && tree[root].r <= r)
    {
        ta = tree[root].s;
        tb = tree[root].t;
        return ;
    }
    
    int mid = (tree[root].l + tree[root].r) >> 1;
    if (r <= mid)
    {
        query(lson, l, r, ta, tb);
    }
    else if (l > mid)
    {
        query(rson, l, r, ta, tb);
    }
    else
    {
        int ls, lt, rs, rt, len = -1;
        query(lson, l, mid, ls, lt);
        query(rson, mid + 1, r, rs, rt);
        get_ft(ls, rt, len);
        get_ft(ls, rs, len);
        get_ft(lt, rt, len);
        get_ft(lt, rs, len);
        get_ft(ls, lt, len);
        get_ft(rs, rt, len);
        ta = from, tb = to;
    }
}

int n, m;

int main()
{
    init();
    
    scan_d(n);
    
    int u, v, w;
    for (int i = 1; i < n; i++)
    {
        scan_d(u), scan_d(v), scan_d(w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    
    LCA_init(1, n);
    build(1, 1, n);
    
    scan_d(m);
    
    int ta1, tb1, ta2, tb2, ans;
    for (int i = 0; i < m; i++)
    {
        ans = 0;
        scan_d(u), scan_d(v);
        query(1, u, v, ta1, tb1);
        scan_d(u), scan_d(v);
        query(1, u, v, ta2, tb2);
        
        ans = max(ans, get_dis(ta1, ta2));
        ans = max(ans, get_dis(ta1, tb2));
        ans = max(ans, get_dis(tb1, ta2));
        ans = max(ans, get_dis(tb1, tb2));
        print_d(ans);
        putchar(10);
    }
    
    return 0;
}
