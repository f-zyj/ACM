//
//  main.cpp
//  f-主席树
//
//  Created by ZYJ on 16/7/21.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

///*
// *  给出一个序列,查询区间内有多少个不相同的数
// */
//const int MAXN = 30010;
//const int M = MAXN * 100;
//int n, q, tot;
//int a[MAXN];
//int T[MAXN], lson[M], rson[M], c[M];
//
//int build(int l, int r)
//{
//    int root = tot++;
//    c[root] = 0;
//    if (l != r)
//    {
//        int mid = (l + r) >> 1;
//        lson[root] = build(l, mid);
//        rson[root] = build(mid + 1, r);
//    }
//    return root;
//}
//
//int update(int root, int pos, int val)
//{
//    int newroot = tot++, tmp = newroot;
//    c[newroot] = c[root] + val;
//    int l = 1, r = n;
//    while (l < r)
//    {
//        int mid = (l + r) >> 1;
//        if (pos <= mid)
//        {
//            lson[newroot] = tot++;
//            rson[newroot] = rson[root];
//            newroot = lson[newroot];
//            root = lson[root];
//            r = mid;
//        }
//        else
//        {
//            rson[newroot] = tot++;
//            lson[newroot] = lson[root];
//            newroot = rson[newroot];
//            root = rson[root];
//            l = mid + 1;
//        }
//        c[newroot] = c[root] + val;
//    }
//    return tmp;
//}
//
//int query(int root, int pos)
//{
//    int ret = 0;
//    int l = 1, r = n;
//    while (pos < r)
//    {
//        int mid = (l + r) >> 1;
//        if (pos <= mid)
//        {
//            r = mid;
//            root = lson[root];
//        }
//        else
//        {
//            ret += c[lson[root]];
//            root = rson[root];
//            l = mid + 1;
//        }
//    }
//    return ret + c[root];
//}
//
//int main()
//{
//    //  freopen("in.txt", "r", stdin);
//    //  freopen("out.txt", "w", stdout);
//    while (scanf("%d", &n) == 1)
//    {
//        tot = 0;
//        for (int i = 1; i <= n; i++)
//        {
//            scanf("%d", &a[i]);
//        }
//        T[n + 1] = build(1, n);
//        map<int,int> mp;
//        for (int i = n; i >= 1; i--)
//        {
//            if (mp.find(a[i]) == mp.end())
//            {
//                T[i] = update(T[i + 1], i, 1);
//            }
//            else
//            {
//                int tmp = update(T[i + 1], mp[a[i]], -1);
//                T[i] = update(tmp, i, 1);
//            }
//            mp[a[i]] = i;
//        }
//        scanf("%d", &q);
//        while (q--)
//        {
//            int l, r;
//            scanf("%d%d", &l, &r);
//            printf("%d\n", query(T[l], r));
//        }
//    }
//    return 0;
//}


/*
 *  静态区间第k大
 */
//const int MAXN = 100010;
//const int M = MAXN * 30;
//int n, q, m, tot;
//int a[MAXN], t[MAXN];
//int T[MAXN], lson[M], rson[M], c[M];
//
//void Init_hash()
//{
//    for (int i = 1; i <= n; i++)
//    {
//        t[i] = a[i];
//    }
//    sort(t + 1, t + 1 + n);
//    m = (int)(unique(t + 1, t + 1 + n) - t - 1);
//}
//
//int build(int l, int r)
//{
//    int root = tot++; c[root] = 0;
//    if (l != r)
//    {
//        int mid = (l + r) >> 1;
//        lson[root] = build(l, mid);
//        rson[root] = build(mid + 1, r);
//    }
//    return root;
//}
//
//int hash_(int x)
//{
//    return (int)(lower_bound(t + 1, t + 1 + m, x) - t);
//}
//
//int update(int root, int pos, int val)
//{
//    int newroot = tot++, tmp = newroot;
//    c[newroot] = c[root] + val;
//    int l = 1, r = m;
//    while (l < r)
//    {
//        int mid = (l + r) >> 1;
//        if (pos <= mid)
//        {
//            lson[newroot] = tot++;
//            rson[newroot] = rson[root];
//            newroot = lson[newroot];
//            root = lson[root];
//            r = mid;
//        }
//        else
//        {
//            rson[newroot] = tot++;
//            lson[newroot] = lson[root];
//            newroot = rson[newroot];
//            root = rson[root];
//            l = mid + 1;
//        }
//        c[newroot] = c[root] + val;
//    }
//    return tmp;
//}
//
//int query(int left_root, int right_root, int k)
//{
//    int l = 1, r = m;
//    while ( l < r)
//    {
//        int mid = (l + r) >> 1;
//        if (c[lson[left_root]] - c[lson[right_root]] >= k )
//        {
//            r = mid;
//            left_root = lson[left_root];
//            right_root = lson[right_root];
//        }
//        else
//        {
//            l = mid + 1;
//            k -= c[lson[left_root]] - c[lson[right_root]];
//            left_root = rson[left_root];
//            right_root = rson[right_root];
//        }
//    }
//    return l;
//}
//
//int main()
//{
//    //  freopen("in.txt","r",stdin);
//    //  freopen("out.txt","w",stdout);
//    while (scanf("%d%d", &n, &q) == 2)
//    {
//        tot = 0;
//        for (int i = 1; i <= n; i++)
//        {
//            scanf("%d", &a[i]);
//        }
//        Init_hash();
//        T[n + 1] = build(1, m);
//        for (int i = n; i; i--)
//        {
//            int pos = hash_(a[i]);
//            T[i] = update(T[i + 1], pos, 1);
//        }
//        while (q--)
//        {
//            int l, r, k;
//            scanf("%d%d%d", &l, &r, &k);
//            printf("%d\n", t[query(T[l], T[r + 1], k)]);
//        }
//    }
//    return 0;
//}

//  树上路径点权第k大

/*
 *  LCA + 主席树
 */
//  主席树部分
//const int MAXN = 200010;
//const int M = MAXN * 40;
//int n, q, m, TOT;
//int a[MAXN], t[MAXN];
//int T[MAXN], lson[M], rson[M], c[M];
//void Init_hash()
//{
//    for (int i = 1; i <= n; i++)
//    {
//        t[i] = a[i];
//    }
//    sort(t + 1, t + 1 + n);
//    m = (int)(unique(t + 1, t + n + 1) - t - 1);
//    return ;
//}
//
//int build(int l, int r)
//{
//    int root = TOT++;
//    c[root] = 0;
//    if (l != r)
//    {
//        int mid = (l + r) >> 1;
//        lson[root] = build(l, mid);
//        rson[root] = build(mid + 1, r);
//    }
//    return root;
//}
//
//int hash_(int x)
//{
//    return (int)(lower_bound(t + 1, t + 1 + m, x) - t);
//}
//
//int update(int root, int pos, int val)
//{
//    int newroot = TOT++, tmp = newroot;
//    c[newroot] = c[root] + val;
//    int l = 1, r = m;
//    while (l < r)
//    {
//        int mid = (l + r) >> 1;
//        if (pos <= mid)
//        {
//            lson[newroot] = TOT++;
//            rson[newroot] = rson[root];
//            newroot = lson[newroot];
//            root = lson[root];
//            r = mid;
//        }
//        else
//        {
//            rson[newroot] = TOT++;
//            lson[newroot] = lson[root];
//            newroot = rson[newroot];
//            root = rson[root];
//            l = mid + 1;
//        }
//        c[newroot] = c[root] + val;
//    }
//    return tmp;
//}
//
//int query(int left_root, int right_root, int LCA, int k)
//{
//    int lca_root = T[LCA];
//    int pos = hash_(a[LCA]);
//    int l = 1, r = m;
//    while (l < r)
//    {
//        int mid = (l + r) >> 1;
//        int tmp = c[lson[left_root]] + c[lson[right_root]] - 2 * c[lson[lca_root]] + (pos >= l && pos <= mid);
//        if (tmp >= k)
//        {
//            left_root = lson[left_root];
//            right_root = lson[right_root];
//            lca_root = lson[lca_root];
//            r = mid;
//        }
//        else
//        {
//            k -= tmp;
//            left_root = rson[left_root];
//            right_root = rson[right_root];
//            lca_root = rson[lca_root];
//            l = mid + 1;
//        }
//    }
//    return l;
//}
//
////  LCA部分
//int rmq[2 * MAXN];  //  rmq数组,就是欧拉序列对应的深度序列
//
//struct ST
//{
//    int mm[2 * MAXN];
//    int dp[2 * MAXN][20];   //  最小值对应的下标
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
//        return ;
//    }
//    int query(int a, int b) //  查询[a,b]之间最小值的下标
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
//int tot, head[MAXN];
//int F[MAXN * 2];    //  欧拉序列,就是dfs遍历的顺序,长度为2*n-1,下标从1开始
//int P[MAXN];        //  P[i]表示点i在F中第一次出现的位置
//int cnt;
//ST st;
//
//void init()
//{
//    tot = 0;
//    memset(head, -1, sizeof(head));
//    return ;
//}
//
//void addedge(int u, int v)  //  加边,无向边需要加两次
//{
//    edge[tot].to = v;
//    edge[tot].next = head[u];
//    head[u] = tot++;
//    return ;
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
//    return ;
//}
//
//void LCA_init(int root, int node_num)   //  查询LCA前的初始化
//{
//    cnt = 0;
//    dfs(root, root, 0);
//    st.init(2 * node_num - 1);
//    return ;
//}
//
//int query_lca(int u, int v)              //  查询u,v的lca编号
//{
//    return F[st.query(P[u], P[v])];
//}
//
//void dfs_build(int u, int pre)
//{
//    int pos = hash_(a[u]);
//    T[u] = update(T[pre], pos, 1);
//    for (int i = head[u]; i != -1; i = edge[i].next)
//    {
//        int v = edge[i].to;
//        if (v == pre)
//        {
//            continue;
//        }
//        dfs_build(v, u);
//    }
//    return ;
//}
//
//
//int main()
//{
//    //  freopen("in.txt", "r", stdin);
//    //  freopen("out.txt", "w", stdout);
//    while (scanf("%d%d", &n, &q) == 2)
//    {
//        for (int i = 1; i <= n; i++)
//        {
//            scanf("%d", &a[i]);
//        }
//        Init_hash();
//        init();
//        TOT = 0;
//        int u, v;
//        for (int i = 1; i < n; i++)
//        {
//            scanf("%d%d", &u, &v);
//            addedge(u, v);
//            addedge(v, u);
//        }
//        LCA_init(1, n);
//        T[n + 1] = build(1, m);
//        dfs_build(1, n + 1);
//        int k;
//        while (q--)
//        {
//            scanf("%d%d%d", &u, &v, &k);
//            printf("%d\n", t[query(T[u], T[v], query_lca(u, v), k)]);
//        }
//    }
//    return 0;
//}

//  动态区间第k大

/*
 *  树状数组套主席树
 */
const int MAXN = 60010;
const int M = 2500010;
int n, q, m, tot;
int a[MAXN], t[MAXN];
int T[MAXN], lson[M], rson[M],c[M];
int S[MAXN];

struct Query
{
    int kind;
    int l, r, k;
} query[10010];

void Init_hash(int k)
{
    sort(t, t + k);
    m = (int)(unique(t, t + k) - t);
    return ;
}

int hash_(int x)
{
    return (int)(lower_bound(t, t + m, x) - t);
}

int build(int l, int r)
{
    int root = tot++;
    c[root] = 0;
    if (l != r)
    {
        int mid = (l + r) / 2;
        lson[root] = build(l, mid);
        rson[root] = build(mid + 1, r);
    }
    return root;
}

int Insert(int root, int pos, int val)
{
    int newroot = tot++, tmp = newroot;
    int l = 0, r = m - 1;
    c[newroot] = c[root] + val;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (pos <= mid)
        {
            lson[newroot] = tot++;
            rson[newroot] = rson[root];
            newroot = lson[newroot];
            root = lson[root];
            r = mid;
        }
        else
        {
            rson[newroot] = tot++;
            lson[newroot] = lson[root];
            newroot = rson[newroot];
            root = rson[root];
            l = mid + 1;
        }
        c[newroot] = c[root] + val;
    }
    return tmp;
}

int lowbit(int x)
{
    return x & (-x);
}

int use[MAXN];

void add(int x, int pos, int val)
{
    while (x <= n)
    {
        S[x] = Insert(S[x], pos, val);
        x += lowbit(x);
    }
    return ;
}
int sum(int x)
{
    int ret = 0;
    while (x > 0)
    {
        ret += c[lson[use[x]]];
        x -= lowbit(x);
    }
    return ret;
}

int Query(int left, int right, int k)
{
    int left_root = T[left - 1];
    int right_root = T[right];
    int l = 0, r = m - 1;
    for (int i = left - 1; i; i -= lowbit(i))
    {
        use[i] = S[i];
    }
    for (int i = right; i; i -= lowbit(i))
    {
        use[i] = S[i];
    }
    while (l < r)
    {
        int mid = (l + r) / 2;
        int tmp = sum(right) - sum(left - 1) + c[lson[right_root]] - c[lson[left_root]];
        if (tmp >= k)
        {
            r = mid;
            for (int i = left - 1; i; i -= lowbit(i))
            {
                use[i] = lson[use[i]];
            }
            for (int i = right; i; i -= lowbit(i))
            {
                use[i] = lson[use[i]];
            }
            left_root = lson[left_root];
            right_root = lson[right_root];
        }
        else
        {
            l = mid + 1;
            k -= tmp;
            for (int i = left - 1; i; i -= lowbit(i))
            {
                use[i] = rson[use[i]];
            }
            for (int i = right; i; i -= lowbit(i))
            {
                use[i] = rson[use[i]];
            }
            left_root = rson[left_root];
            right_root = rson[right_root];
        }
    }
    return l;
}

void Modify(int x, int p, int d)
{
    while (x <= n)
    {
        S[x] = Insert(S[x], p, d);
        x += lowbit(x);
    }
    return ;
}

int main()
{
    //  freopen("in.txt", "r", stdin);
    //  freopen("out.txt", "w", stdout);
    int Tcase;
    scanf("%d", &Tcase);
    while (Tcase--)
    {
        scanf("%d%d", &n, &q);
        tot = 0;
        m = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            t[m++] = a[i];
        }
        char op[10];
        for (int i = 0; i < q; i++)
        {
            scanf("%s", op);
            if (op[0] == 'Q')
            {
                query[i].kind = 0;
                scanf("%d%d%d", &query[i].l, &query[i].r, &query[i].k);
            }
            else
            {
                query[i].kind = 1;
                scanf("%d%d", &query[i].l, &query[i].r);
                t[m++] = query[i].r;
            }
        }
        Init_hash(m);
        T[0] = build(0, m - 1);
        for (int i = 1; i <= n; i++)
        {
            T[i] = Insert(T[i - 1], hash_(a[i]), 1);
        }
        for (int i = 1; i <= n; i++)
        {
            S[i] = T[0];
        }
        for (int i = 0; i < q; i++)
        {
            if (query[i].kind == 0)
            {
                printf("%d\n", t[Query(query[i].l, query[i].r, query[i].k)]);
            }
            else
            {
                Modify(query[i].l, hash_(a[query[i].l]), -1);
                Modify(query[i].l, hash_(query[i].r), 1);
                a[query[i].l] = query[i].r;
            }
        }
    }
    return 0;
}
