//
//  main.cpp
//  f-一般图匹配带花树
//
//  Created by ZYJ on 16/7/13.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int maxn = 300;
int N;
bool G[maxn][maxn];
int match[maxn];
bool InQueue[maxn], InPath[maxn], InBlossom[maxn];
int head, tail;
int Queue[maxn];
int start, finish;
int NewBase;
int father[maxn], Base[maxn];
int Count;

void CreateGraph()
{
    int u, v;
    memset(G, 0, sizeof(G));
    scanf("%d", &N);
    while (scanf("%d%d",&u,&v) != EOF)
    {
        G[u][v] = G[v][u] = 1;
    }
}

void Push(int u)
{
    Queue[tail++] = u;
    InQueue[u] = 1;
}

int Pop()
{
    int res = Queue[head++];
    return res;
}

int FindCommonAncestor (int u, int v)
{
    memset(InPath, 0, sizeof(InPath));
    while (true)
    {
        u = Base[u];
        InPath[u] = 1;
        if (u == start)
        {
            break;
        }
        u = father[match[u]];
    }
    while (true)
    {
        v = Base[v];
        if (InPath[v])
        {
            break;
        }
        v = father[match[v]];
    }
    return v;
}

void ResetTrace(int u)
{
    int v;
    while (Base[u] != NewBase)
    {
        v = match[u];
        InBlossom[Base[u]] = InBlossom[Base[v]] = 1;
        u = father[v];
        if (Base[u] != NewBase)
        {
            father[u] = v;
        }
    }
}

void BlossomContract(int u, int v)
{
    NewBase = FindCommonAncestor(u, v);
    memset(InBlossom, 0, sizeof(InBlossom));
    ResetTrace(u);
    ResetTrace(v);
    if (Base[u] != NewBase)
    {
        father[u]=v;
    }
    if (Base[v] != NewBase)
    {
        father[v]=u;
    }
    for (int tu=1; tu <= N; tu++)
    {
        if (InBlossom[Base[tu]])
        {
            Base[tu] = NewBase;
            if (!InQueue[tu])
            {
                Push(tu);
            }
        }
    }
}

void FindAugmentingPath()
{
    memset(InQueue, 0, sizeof(InQueue));
    memset(father, 0, sizeof(father));
    for (int i = 1; i <= N; i++)
    {
        Base[i] = i;
    }
    head = tail = 1;
    Push(start);
    finish = 0;
    while (head < tail)
    {
        int u = Pop();
        for (int v = 1; v <= N; v++)
        {
            if (G[u][v] && (Base[u] != Base[v]) && match[u] != v)
            {
                if ((v == start) || ((match[v] > 0) && father[match[v]] > 0))
                {
                    BlossomContract(u, v);
                }
                else if (father[v] == 0)
                {
                    father[v] = u;
                    if (match[v] > 0)
                    {
                        Push(match[v]);
                    }
                    else
                    {
                        finish = v;
                        return ;
                    }
                }
            }
        }
    }
}

void AugmentPath()
{
    int u, v, w;
    u = finish;
    while (u > 0)
    {
        v = father[u];
        w = match[v];
        match[v] = u;
        match[u] = v;
        u = w;
    }
}

void Edmonds()
{
    memset(match, 0, sizeof(match));
    for (int u = 1; u <= N; u++)
    {
        if (match[u] == 0)
        {
            start = u;
            FindAugmentingPath();
            if (finish > 0)
            {
                AugmentPath();
            }
        }
    }
}

void PrintMatch()
{
    Count = 0;
    for (int u = 1; u <= N; u++)
    {
        if (match[u] > 0)
        {
            Count++;
        }
    }
    printf("%d\n", Count);
    for (int u = 1; u <= N; u++)
    {
        if (u < match[u])
        {
            printf("%d %d\n", u, match[u]);
        }
    }
}

int main()
{
    CreateGraph();
    Edmonds();      //  进行匹配
    PrintMatch();   //  输出匹配
    return 0;
}