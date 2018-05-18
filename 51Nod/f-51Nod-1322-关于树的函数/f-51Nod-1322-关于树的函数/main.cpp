//
//  main.cpp
//  f-51Nod-1322-关于树的函数
//
//  Created by ZYJ on 2017/4/28.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

typedef long long ll;
typedef tuple<int, int> tii;

const int MAXN = 4e3 + 10;

int N;
int n;    //  A1集合结点数
ll res = 0;

vector<int> tree[MAXN];
vector<int> tree_[MAXN];
tii tmp;

struct edge
{
    int u;
    int v;
} tr[MAXN], tr_[MAXN];

int vis[MAXN];

tii dfs_(int last, int root)
{
    int cnt = 0, m = 0;
    if (vis[root])
    {
        cnt++;
    }
    m++;
    int a, b;
    for (int i = 0; i < tree_[root].size(); i++)
    {
        if (tree_[root][i] != last)
        {
            tmp = dfs_(root, tree_[root][i]);
            tie(a, b) = tmp;
            cnt += a;
            m += b;
        }
    }
    if (m == N)
    {
        return make_tuple(cnt, m);
    }
    long long maxRes = 0;
    maxRes = max(maxRes, (ll)cnt * cnt);
    maxRes = max(maxRes, (ll)(n - cnt) * (n - cnt));
    maxRes = max(maxRes, (ll)(m - cnt) * (m - cnt));
    maxRes = max(maxRes, (ll)(N - m - n + cnt) * (N - m - n + cnt));
    res += maxRes;
    
    return make_tuple(cnt, m);
}

void dfs(int last, int root)
{
    vis[root] = 1;
    n++;
    for (int i = 0; i < tree[root].size(); i++)
    {
        if (tree[root][i] != last)
        {
            dfs(root, tree[root][i]);
        }
    }
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    cin >> N;
    
    int u, v;
    for (int i = 1; i < N; i++)
    {
        scanf("%d%d", &u, &v);
        u++, v++;
        tree[u].push_back(v);
        tree[v].push_back(u);
        tr[i].u = u;
        tr[i].v = v;
    }
    for (int i = 1; i < N; i++)
    {
        scanf("%d%d", &u, &v);
        u++, v++;
        tree_[u].push_back(v);
        tree_[v].push_back(u);
        tr_[i].u = u;
        tr_[i].v = v;
    }
    
    for (int i = 1; i < N; i++)
    {
        n = 0;
        memset(vis, 0, sizeof(vis));
        dfs(tr[i].v, tr[i].u);
        dfs_(-1, 1);
    }
    
    cout << res << '\n';
    
    return 0;
}
