//
//  main.cpp
//  f-HDU-5886-Tower Defence
//
//  Created by ZYJ on 2017/7/1.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>

#define X first
#define Y second
#define pii pair<int, int>
#define mp make_pair

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int N, tot;
ll ans;
int up[MAXN];
int dis1[MAXN];
int dis2[MAXN];
int head[MAXN];
int nt[MAXN * 2];
int down[MAXN][2];
pii edge[MAXN * 2];

multiset<int>::iterator it;

void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
    memset(down, 0, sizeof(down));
    memset(up, 0, sizeof(up));
    memset(dis1, 0, sizeof(dis1));
    memset(dis2, 0, sizeof(dis2));
}

void add(int u, int v, int w)
{
    edge[tot] = mp(v, w);
    nt[tot] = head[u];
    head[u] = tot++;
}

/*
 *  down[][0]:从i结点向下的最大距离
 *  down[][1]:与down[][0]无交集的向下次大距离
 *  dis1:以i为根的子树的直径
 */
void dfs1(int pre, int r)
{
    for (int i = head[r]; ~i; i = nt[i])
    {
        int x = edge[i].X, y = edge[i].Y;
        if (x == pre)
        {
            continue ;
        }
        dfs1(r, x);
        if (down[x][0] + y > down[r][0])
        {
            down[r][1] = down[r][0];
            down[r][0] = down[x][0] + y;
        }
        else if (down[x][0] + y > down[r][1])
        {
            down[r][1] = down[x][0] + y;
        }
        dis1[r] = max(dis1[r], dis1[x]);
    }
    dis1[r] = max(dis1[r], down[r][0] + down[r][1]);
}

/*
 *  up:从i结点向上的最远距离
 *  dis2:切掉以i为根的子树后的直径
 */
void dfs2(int pre, int r)
{
    if (pre != -1)
    {
        ans += max(dis1[r], dis2[r]);
    }
    
    multiset<int> ms_a, ms_b;  //  兄弟树的直径, x往各个兄弟树的最长路
    for (int i = head[r]; ~i; i = nt[i])
    {
        int x = edge[i].X, y = edge[i].Y;
        if (x == pre)
        {
            continue ;
        }
        ms_a.insert(dis1[x]);
        ms_b.insert(down[x][0] + y);
    }
    for (int i = head[r]; ~i; i = nt[i])
    {
        int x = edge[i].X, y = edge[i].Y;
        if (x == pre)
        {
            continue ;
        }
        up[x] = up[r] + y;
        if (down[x][0] + y == down[r][0])
        {
            up[x] = max(up[x], down[r][1] + y);
        }
        else
        {
            up[x] = max(up[x], down[r][0] + y);
        }
        it = ms_a.find(dis1[x]), ms_a.erase(it);
        it = ms_b.find(down[x][0] + y), ms_b.erase(it);
        dis2[x] = dis2[r];
        if (!ms_a.empty())
        {
            dis2[x] = max(dis2[x], *ms_a.rbegin());
        }
        if (ms_b.empty())
        {
            dis2[x] = max(dis2[x], up[r]);
        }
        else
        {
            dis2[x] = max(dis2[x], up[r] + *ms_b.rbegin());
        }
        if (ms_b.size() >= 2)
        {
            it = ms_b.end();
            int tmp = *--it;
            tmp += *--it;
            dis2[x] = max(dis2[x], tmp);
        }
        
        dfs2(r, x);
        
        ms_a.insert(dis1[x]);
        ms_b.insert(down[x][0] + y);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        init();
        
        scanf("%d", &N);
        
        int u, v, w;
        for (int i = 1; i < N; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        
        ans = 0;
        dfs1(-1, 1);
        dfs2(-1, 1);
    
        printf("%lld\n", ans);
    }
    
    return 0;
}
