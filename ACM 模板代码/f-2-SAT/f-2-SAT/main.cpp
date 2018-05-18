//
//  main.cpp
//  f-2-SAT
//
//  Created by ZYJ on 16/7/18.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

/*
 *  2-sat 问题
 *  N个集团,每个集团2个人,现在要想选出尽量多的人,
 *  且每个集团只能选出一个人。如果两人有矛盾,他们不能同时被选中
 *  问最多能选出多少人
 */
const int MAXN = 3010;
int n, m;
int g[3010][3010], ct[3010], f[3010];
int x[3010], y[3010];
int prev[MAXN], low[MAXN], stk[MAXN], sc[MAXN];
int cnt[MAXN];
int cnt0, ptr, cnt1;
void dfs(int w)
{
    int min(0);
    prev[w] = cnt0++;
    low[w] = prev[w];
    min = low[w];
    stk[ptr++] = w;
    for (int i = 0; i < ct[w]; ++i)
    {
        int t = g[w][i];
        if (prev[t] == -1)
        {
            dfs(t);
        }
        if (low[t] < min)
        {
            min = low[t];
        }
    }
    if (min < low[w])
    {
        low[w] = min;
        return ;
    }
    do
    {
        int v = stk[--ptr];
        sc[v] = cnt1;
        low[v] = MAXN;
    } while(stk[ptr] != w);
    ++cnt1;
    return ;
}

void Tarjan(int N)
{   //  传入N为点数,结果保存在sc数组中,同一标号的点在同一个强连通分量内,
    //  强连通分量数为cnt1
    cnt0 = cnt1 = ptr = 0;
    int i;
    for (i = 0; i < N; ++i)
    {
        prev[i] = low[i] = -1;
    }
    for (i = 0; i < N; ++i)
    {
        if (prev[i] == -1)
        {
            dfs(i);
        }
    }
    return ;
}

int solve()
{
    Tarjan(n);
    for (int i = 0; i < n; i++)
    {
        if (sc[i] == sc[f[i]])
        {
            return 0;
        }
    }
    return 1;
}

int check(int Mid)
{
    for (int i = 0; i < n; i++)
    {
        ct[i] = 0;
    }
    for (int i = 0; i < Mid; i++)
    {
        g[f[x[i]]][ct[f[x[i]]]++] = y[i];
        g[f[y[i]]][ct[f[y[i]]]++] = x[i];
    }
    return solve();
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF && n + m)
    {
        for (int i = 0; i < n; i++)
        {
            int p, q;
            scanf("%d%d", &p, &q);
            f[p] = q, f[q] = p;
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &x[i], &y[i]);
        }
        n *= 2;
        int Min = 0, Max = m + 1;
        while (Min + 1 < Max)
        {
            int Mid = (Min + Max) / 2;
            if (check(Mid))
            {
                Min = Mid;
            }
            else
            {
                Max = Mid;
            }
        }
        printf("%d\n", Min);
    }
    return 0;
}