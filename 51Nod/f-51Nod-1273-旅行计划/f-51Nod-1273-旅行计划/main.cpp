//
//  main.cpp
//  f-51Nod-1273-旅行计划
//
//  Created by ZYJ on 2017/4/16.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

#define pb push_back

using namespace std;

const int MAXN = 1e5 + 10;

struct node
{
    int to, next;
} edge[MAXN];

int tot = 0;
int head[MAXN], deep[MAXN];

void add(int u, int v)
{
    edge[++tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot;
}

struct node2
{
    int x, d, cnt;
    
    node2(int x_, int d_, int cnt_ = 0) : x(x_), d(d_), cnt(cnt_) {}
    
    bool operator < (const node2 &b) const
    {
        return d > b.d || (d == b.d && x < b.x);
    }
};

vector<node2> vn2;

int pre[MAXN];

//  遍历树，存储 pre[]，将叶子结点与其深度入 vn2
void dfs(int x, int pr)
{
    pre[x] = pr;
    bool flag = false;
    for (int i = head[x]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == pr)
        {
            continue;
        }
        else
        {
            flag = true;
        }
        deep[v] = deep[x] + 1;
        dfs(v, x);
    }
    if (!flag)
    {
        vn2.pb(node2(x, deep[x]));
    }
}

bool cmp(node2 a, node2 b)
{
    return a.cnt > b.cnt || (a.cnt == b.cnt && a.x < b.x);
}

bool vis[MAXN];

int main()
{
    int N, K;
    cin >> N >> K;
    
    int v;
    for (int i = 1; i < N; i++)
    {
        scanf("%d", &v);
        add(v, i);
        add(i, v);
    }
    
    deep[K] = 1;
    vis[K] = 1;
    dfs(K, -1);
    
    sort(vn2.begin(), vn2.end());           //  根据深度从大到小排序
    for (int i = 0; i < vn2.size(); i++)    //  获取叶子结点到根路径对应未访问结点数
    {
        node2 leaf = vn2[i];
        int x = leaf.x, cnt = 0;
        while (x != -1)
        {
            if (!vis[x])
            {
                cnt++;
                vis[x] = 1;
            }
            else
            {
                break;
            }
            x = pre[x];
        }
        vn2[i].cnt = cnt;
    }
    
    printf("%d\n", K);
    sort(vn2.begin(), vn2.end(), cmp);      //  根据未访问节点数排序
    for (int i = 0; i < vn2.size(); i++)
    {
        if (vn2[i].cnt)
        {
            printf("%d\n", vn2[i].x);
        }
    }
    
    return 0;
}
