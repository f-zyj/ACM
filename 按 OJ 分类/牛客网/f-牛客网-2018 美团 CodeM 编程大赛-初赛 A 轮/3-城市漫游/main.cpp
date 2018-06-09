//
//  main.cpp
//  f-牛客网-2018 美团 CodeM 编程大赛-初赛 A 轮
//
//  Created by ZYJ on 2018/6/9.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

#define lson rt << 1
#define rson lson | 1

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

struct node
{
    int id;
    int to;
    ll cost;
} Q;

struct nn
{
    int l, r, mn;
} PP[MAXN << 4];

int n, cnt;
int x[MAXN], y[MAXN];
int wx[MAXN][2];
int pre[MAXN << 2];
int front_edge[MAXN][2];
ll z[MAXN], tree[MAXN << 2];
bool vis[MAXN << 1];
vector<node> vn[MAXN];

void add_edge(int x_, int y_, ll z_, int id)
{
    Q.cost = z_;
    Q.id = id;
    Q.to = y_;
    vn[x_].push_back(Q);
    Q.to = x_;
    vn[y_].push_back(Q);
}

int lowit(int x)
{
    return x & (-x);
}

void add(int a, ll b)
{
    for (; a <= n; a += lowit(a))
    {
        tree[a] += b;
    }
}

ll query(int rt)
{
    ll ans = 0;
    for (; rt; rt -= lowit(rt))
    {
        ans += tree[rt];
        ans %= MOD;
    }
    
    return ans;
}

void create(int l, int r, int rt)
{
    PP[rt].l = l;
    PP[rt].r = r;
    
    if (l == r)
    {
        PP[rt].mn = wx[pre[l]][0];
        return ;
    }
    
    int m = (l + r) >> 1;
    create(l, m, lson);
    create(m + 1, r, rson);
    PP[rt].mn = min(PP[lson].mn, PP[rson].mn);
}

int LCA(int l, int r, int rt)
{
    if (l == PP[rt].l && r == PP[rt].r)
    {
        return PP[rt].mn;
    }
    
    int m = (PP[rt].l + PP[rt].r) >> 1;
    if (l > m)
    {
        return LCA(l, r, rson);
    }
    else if (r <= m)
    {
        return LCA(l, r, lson);
    }
    else
    {
        return min(LCA(l, m, lson), LCA(m + 1, r, rson));
    }
}

void dfs(int rt)
{
    vis[rt] = false;
    wx[rt][0] = ++cnt;
    pre[cnt] = rt;
    
    for (int i = 0; i < vn[rt].size(); i++)
    {
        if (vis[vn[rt][i].to])
        {
            front_edge[vn[rt][i].id][0] = cnt;
            add(cnt, vn[rt][i].cost);
            
            dfs(vn[rt][i].to);
            
            front_edge[vn[rt][i].id][1] = cnt;
            add(cnt, -vn[rt][i].cost);
            wx[rt][1] = ++cnt;
            pre[cnt] = rt;
        }
    }
    
    wx[rt][1] = cnt;
    pre[cnt] = rt;
}

ll m;

int main()
{
    scanf("%d", &n);
    
    ll sum = 0, l;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d%lld%lld", &x[i], &y[i], &z[i], &l);
        
        //  先每条边跑偶数次，且保证至少 l 次
        if (l % 2 == 0)
        {
            sum += z[i] * l;
            sum %= MOD;
            l = 1;
        }
        else
        {
            sum += z[i] * (l + 1);
            sum %= MOD;
            l = -1;
        }
        z[i] *= l;                      //  对于奇数的情况多跑了一次
        
        add_edge(x[i], y[i], z[i], i);  //  初始建树
    }
    
    int S, T, tmp;
    scanf("%lld", &m);
    //  n == 1 时结果均为 0
    if (n == 1)
    {
        while (m--)
        {
            scanf("%d%d", &S, &T);
            printf("0\n");
        }
        
        return 0;
    }
    
    memset(vis, true, sizeof(vis));
    memset(tree, 0, sizeof(tree));
    n = 2 * n - 2;
    cnt = 0;
    
    dfs(1);
    create(1, n, 1);
    
    while (m--)
    {
        scanf("%d%d", &S, &T);
        
        S = wx[S][0];
        T = wx[T][0];
        if (S < T)
        {
            tmp = LCA(S, T, 1);
        }
        else
        {
            tmp = LCA(T, S, 1);
        }
        
        ll ans = query(S - 1) - 2 * query(tmp - 1) + query(T - 1);
        ans += sum;
        ans %= MOD;
        ans += MOD;
        ans %= MOD;
        printf("%lld\n", ans);
    }
    
    return 0;
}
