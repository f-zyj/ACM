//
//  main.cpp
//  f-计蒜客-2017 计蒜之道 初赛 第六场-B-微软大楼设计方案（简单）
//
//  Created by ZYJ on 2017/6/4.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define MIN(x, y) (((x) < (y)) ? (x) : (y));
#define ABS(x, y) (((x) < (y)) ? ((y) - (x)) : ((x) - (y)))

using namespace std;

const int MAXN = 2e5 + 2e2;
const int MAXM = 2e3 + 2e2;
const int INF = 0x3f3f3f3f;

int A[MAXN];
int n, k, m;
int ans;

struct node
{
    int l;
    int r;
    int s;
} tree[MAXN * 4];

struct room
{
    int x;
    int y;
} Room[MAXM];

void query(int x)
{
    tree[x].s = MIN(tree[x * 2].s, tree[x * 2 + 1].s);
}

void build_tree(int l, int r, int x)
{
    tree[x].l = l;
    tree[x].r = r;
    if (l == r)
    {
        tree[x].s = A[l];
        return ;
    }
    int m = (l + r) / 2;
    build_tree(l, m, x * 2);
    build_tree(m + 1, r, x * 2 + 1);
    query(x);
    return ;
}

void sear(int l, int r, int x)
{
    if (l == tree[x].l && r == tree[x].r)
    {
        ans = MIN(ans, tree[x].s);
        return ;
    }
    int m = (tree[x].l + tree[x].r) / 2;
    if (l > m)
    {
        sear(l, r, x * 2 + 1);
    }
    else if (r <= m)
    {
        sear(l, r, x * 2);
    }
    else
    {
        sear(l, m, x * 2);
        sear(m + 1, r, x * 2 + 1);
    }
}

int get_dis(int x, int y)
{
    ans = INF;
    int x_, y_;
    if (Room[x].x < Room[y].x)
    {
        x_ = Room[x].x;
        y_ = Room[y].x;
    }
    else
    {
        x_ = Room[y].x;
        y_ = Room[x].x;
    }
    sear(x_, y_, 1);
    
    int t = ans;
    int res = ABS(Room[x].x, Room[y].x);
    if (res == 0)
    {
        res = res + ABS(Room[x].y, Room[y].y);
    }
    else
    {
        if (Room[x].y > t && Room[y].y > t)
        {
            res += Room[x].y + Room[y].y - t - t;
        }
        else
        {
            res = res + ABS(Room[x].y, Room[y].y);
        }
    }
    
    return res;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", A + i);
    }
    
    build_tree(1, n, 1);
    
    cin >> m;
    int res = 0, dis;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &Room[i].x, &Room[i].y);
    }
    
    for (int i = 1; i < m; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            dis = get_dis(i, j);
            if (dis <= k)
            {
                res++;
            }
        }
    }
    
    printf("%d\n", res);
    
    return 0;
}
