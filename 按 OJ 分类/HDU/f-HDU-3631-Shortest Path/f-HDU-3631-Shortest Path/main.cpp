//
//  main.cpp
//  f-HDU-3631-Shortest Path
//
//  Created by ZYJ on 2016/11/26.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 310
#define INF 0xFFFFFFF

int n, m, Q, cnt, flag;
int vis[MAXN];
int weight[MAXN][MAXN];

void init()
{
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for (int j = 0; j < n; j++)
        {
            weight[i][j] = INF;
        }
        weight[i][i] = 0;
    }
}

void floyd(int s)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            weight[i][j] = min(weight[i][s] + weight[s][j], weight[i][j]);
        }
    }
}

int main()
{
    int x, s, e, v;
    cnt = 1;
    flag = 1;
    while (scanf("%d%d%d", &n, &m, &Q), n + m + Q)
    {
        init();
        
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &s, &e, &v);
            if (weight[s][e] > v)
            {
                weight[s][e] = v;
            }
        }
        //  输出格式要求，没两组结果间有一个空行
        if (!flag)
        {
            printf("\n");
        }
        else
        {
            flag = 0;
        }
        printf("Case %d:\n", cnt++);
        for (int i = 0; i < Q; i++)
        {
            scanf("%d", &x);
            if (!x)
            {
                scanf("%d", &s);
                if (!vis[s])
                {
                    vis[s] = 1;
                    floyd(s);   /*  更新dis   */
                }
                else
                {
                    printf("ERROR! At point %d\n", s);
                }
            }
            else
            {
                scanf("%d%d", &s, &e);
                if (!vis[s] || !vis[e])
                {
                    printf("ERROR! At path %d to %d\n", s, e);
                }
                else
                {
                    if (weight[s][e] == INF)
                    {
                        printf("No such path\n");
                    }
                    else
                    {
                        printf("%d\n", weight[s][e]);
                    }
                }
            }
        }
    }
    
    return 0;
}
