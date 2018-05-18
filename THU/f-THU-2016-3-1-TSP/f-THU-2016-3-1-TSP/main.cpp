//
//  main.cpp
//  f-THU-2016-3-1-TSP
//
//  Created by ZYJ on 2016/12/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>

#define MAX_N 100005
#define MAX_M 1000005
#define max(a, b) ((a > b) ? (a) : (b))

using namespace std;

const int INF = 0x3f3f3f3f;

struct edge
{
    int to, w, next;
    edge()
    {
        w = to = next = 0;
    }
};

edge D[MAX_M];  //  邻接表
int head[MAX_N];//  邻接表头
int dp[MAX_M];  //  dp[i]:第i条边为开始的最长路
int num[MAX_N]; //  num[i]:以i为起点的最长路
int cnt = 1;

//  往邻接表中添加边
void add(int u, int v, int w)
{
    D[cnt].to = v;
    D[cnt].w = w;
    D[cnt].next = head[u];
    head[u] = cnt++;
}

//  树归部分
int DFS(int s)
{
    int maxn = 0;
    for (int i = head[s]; i; i = D[i].next)
    {
        if (dp[i] == -1)
        {
            dp[i] = DFS(D[i].to) + D[i].w;
        }
        maxn = max(maxn, dp[i]);
    }
    return maxn;
}

//  从起点开始查找最长路
void find(int s, int w)
{
    printf("%d\t", s);
    int minx = INF, W = 0;
    for (int i = head[s]; i; i = D[i].next)
    {
        //  保证在最长路上并且字典序最小
        if (dp[i] == w && minx > D[i].to)
        {
            W = w - D[i].w;
            minx = D[i].to;
        }
    }
    if (minx != INF)
    {
        find(minx, W);
    }
    return ;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= m; i++)
    {
        dp[i] = -1;
    }
    
    int a, b, p;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a, &b, &p);
        add(a, b, p);
    }
    
    int maxn = -1, temp = 0;
    for (int i = 1; i <= n; i++)
    {
        num[i] = DFS(i);
        if (num[i] > maxn)
        {
            maxn = num[i];
            temp = i;
        }
    }
    
    find(temp, maxn);
    printf("\n");
    
    return 0;
}
