//
//  main.cpp
//  f-曼哈顿最小生成树
//
//  Created by ZYJ on 16/6/9.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//POJ-3241  求曼哈顿最小生成树上第K大的边

#include <iostream>
#include <algorithm>

const int MAXN = 100010;
const int INF = 0x3f3f3f3f;

struct Point
{
    int x;
    int y;
    int id;
}poi[MAXN];

bool cmp(Point a, Point b)
{
    if (a.x != b.x)
    {
        return a.x < b.x;
    }
    else
    {
        return a.y < b.y;
    }
}

//树状数组，找y - x大于当前的，但是y + x最小的
struct BIT
{
    int minVal;
    int pos;
    void init()
    {
        minVal = INF;
        pos = -1;
    }
}bit[MAXN];

//所有有效边
struct Edge
{
    int u;
    int v;
    int d;
}edge[MAXN << 2];

bool cmpEdge(Edge a, Edge b)
{
    return a.d < b.d;
}

int tot;
int n;
int F[MAXN];

int find(int x)
{
    if (F[x] == -1)
    {
        return x;
    }
    else
    {
        return F[x] = find(F[x]);
    }
}

void addEdge(int u, int v, int d)
{
    edge[tot].u = u;
    edge[tot].v = v;
    edge[tot++].d = d;
    return ;
}

int lowbit(int x)
{
    return x & (-x);    //???
}

//更新bit
void update(int i, int val, int pos)
{
    while (i > 0)
    {
        if (val < bit[i].minVal)
        {
            bit[i].minVal = val;
            bit[i].pos = pos;
        }
        i -= lowbit(i);
    }
    return ;
}

//查询[i, m]的最小值位置
int ask(int i, int m)
{
    int minVal = INF;
    int pos = -1;
    while (i <= m)
    {
        if (bit[i].minVal < minVal)
        {
            minVal = bit[i].minVal;
            pos = bit[i].pos;
        }
        i += lowbit(i);
    }
    return pos;
}

int dist(Point a, Point b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void ManhattanMinimumSpanningTree(int n, Point p[])
{
    int a[MAXN], b[MAXN];
    tot = 0;
    for (int dir = 0; dir < 4; dir++)
    {
        //变换4种坐标
        if (dir == 1 || dir == 3)
        {
            for (int i = 0; i < n; i++)
            {
                std::swap(p[i].x, p[i].y);
            }
        }
        else if (dir == 2)
        {
            for (int i = 0; i < n; i++)
            {
                p[i].x = -p[i].x;
            }
        }
        std::sort(p, p + n, cmp);
        for (int i = 0; i < n; i++)
        {
            a[i] = b[i] = p[i].y - p[i].x;
        }
        std::sort(b, b + n);
        int m = (int)(std::unique(b, b + n) - b);
        for (int i = 1; i <= m; i++)
        {
            bit[i].init();
        }
        for (int i = n - 1; i >= 0; i--)
        {
            int pos = (int)(std::lower_bound(b, b + m, a[i]) - b + 1);
            int ans = ask(pos, m);
            if (ans != -1)
            {
                addEdge(p[i].id, p[ans].id, dist(p[i], p[ans]));
            }
            update(pos, p[i].x + p[i].y, i);
        }
    }
    return ;
}

int solve(int k)
{
    ManhattanMinimumSpanningTree(n, poi);
    memset(F, -1, sizeof(F));
    std::sort(edge, edge + tot, cmpEdge);
    for (int i = 0; i < tot; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int tOne = find(u);
        int tTwo = find(v);
        if (tOne != tTwo)
        {
            F[tOne] = tTwo;
            k--;
            if (k == 0)
            {
                return edge[i].d;
            }
        }
    }
    return -1;
}

int main(int argc, const char * argv[])
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int k;
    while ((std::cin >> n >> k) && n)
    {
        for (int i = 0; i < n; i++)
        {
            std::cin >> poi[i].x >> poi[i].y;
            poi[i].id = i;
        }
        std::cout << solve(n - k) << std::endl;
    }
    
    return 0;
}
