//
//  main.cpp
//  f-Floyd求最小环
//
//  Created by ZYJ on 16/7/18.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

const int INF = 1000000000;
const int N = 110;
int n, m;       //  n:节点个数, m:边的个数
int g[N][N];    //  无向图
int dist[N][N]; //  最短路径
int r[N][N];    //  r[i][j]: i到j的最短路径的第一步
int out[N], ct; //  记录最小环
int solve(int i, int j, int k)
{   //  记录最小环
    ct = 0;
    while (j != i)
    {
        out[ct++] = j;
        j = r[i][j];
    }
    out[ct++] = i;
    out[ct++] = k;
    return 0;
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        int i, j, k;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                g[i][j] = INF;
                r[i][j] = i;
            }
        }
        for (i = 0; i < m; i++)
        {
            int x, y, l;
            scanf("%d%d%d", &x, &y, &l);
            --x;
            --y;
            if (l < g[x][y])
            {
                g[x][y] = g[y][x] = l;
            }
        }
        memmove(dist, g, sizeof(dist));
        int Min = INF;              //  最小环
        for (k=0; k < n; k++)
        {                           //  Floyd
            for (i = 0; i < k; i++) //  一个环中的最大结点为k(编号最大)
            {
                if (g[k][i] < INF)
                {
                    for (j = i + 1; j < k; j++)
                    {
                        if (dist[i][j] < INF && g[k][j] < INF && Min > dist[i][j] + g[k][i] + g[k][j])
                        {
                            Min = dist[i][j] + g[k][i] + g[k][j];
                            solve(i, j, k);     //  记录最小环
                        }
                    }
                }
            }
            for (i = 0; i < n; i++)
            {
                if (dist[i][k] < INF)
                {
                    for (j = 0; j < n; j++)
                    {
                        if (dist[k][j] < INF && dist[i][j] > dist[i][k]+dist[k][j])
                        {
                            dist[i][j] = dist[i][k] + dist[k][j];
                            r[i][j] = r[k][j];
                        }
                    }
                }
            }
        }
        if (Min < INF)
        {
            for (ct--; ct >= 0; ct--)
            {
                printf("%d", out[ct] + 1);
                if (ct)
                {
                    printf(" ");
                }
            }
        }
        else
        {
            printf("No solution.");
        }
        printf("\n");
    }
    return 0;
}

