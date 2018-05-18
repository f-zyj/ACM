//
//  main.cpp
//  f-51Nod-1640-天气晴朗的魔法
//
//  Created by ZYJ on 16/8/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>

typedef long long ll;
using namespace std;

const int MAXN = 1e5 + 10;
const int MAXM = 2 * MAXN;

int F[MAXN];    //  并查集
int MAXW = 0;

struct edge
{
    int u;      //  起点
    int v;      //  终点
    int w;      //  权值
} Edge[MAXM];   //  存储边信息

int tol = 0;    //  边数

void addEdge(int u, int v, int w)
{
    Edge[tol].u = u;
    Edge[tol].v = v;
    Edge[tol++].w = w;
    return ;
}

//  从小到大排
bool cmp_0(edge a, edge b)
{
    return a.w < b.w;
}

//  从大到小排
bool cmp_1(edge a, edge b)
{
    return a.w > b.w;
}

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

//  最小生成树
int Kruskal_0(int n)  //  传入点数，返回最小生成树的最大边权值，如果不连通返回-1
{
    memset(F, -1, sizeof(F));
    sort(Edge, Edge + tol, cmp_0);
    int cnt = 0;    //  计算加入边数
    int ans = 0;
    for (int i = 0; i < tol; i++)
    {
        int u = Edge[i].u;
        int v = Edge[i].v;
        int w = Edge[i].w;
        int tOne = find(u);
        int tTwo = find(v);
        if (tOne != tTwo)
        {
            if (ans < w)
            {
                ans = w;
            }
            F[tOne] = tTwo;
            cnt++;
        }
        if (cnt == n - 1)
        {
            break;
        }
    }
    if (cnt < n - 1)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

//  最大生成树（有最大边权限制）
ll Kruskal_1(int n)  //  传入点数，返回最大生成树的权值，如果不连通返回-1
{
    memset(F, -1, sizeof(F));
    sort(Edge, Edge + tol, cmp_1);
    int cnt = 0;    //  计算加入边数
    ll ans = 0;
    for (int i = 0; i < tol; i++)
    {
        if (Edge[i].w > MAXW)
        {
            continue;
        }
        int u = Edge[i].u;
        int v = Edge[i].v;
        int w = Edge[i].w;
        int tOne = find(u);
        int tTwo = find(v);
        if (tOne != tTwo)
        {
            ans += w;
            F[tOne] = tTwo;
            cnt++;
        }
        if (cnt == n - 1)
        {
            break;
        }
    }
    if (cnt < n - 1)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int N, M;
    cin >> N >> M;
    
    int A, B, V;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B >> V;
        addEdge(A, B, V);
    }
    
    MAXW = Kruskal_0(N);
    
    ll ans = Kruskal_1(N);
    
    cout << ans << '\n';
    
    return 0;
}
