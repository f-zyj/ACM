//
//  main.cpp
//  f-HDU-1385-Minimum Transport Cost
//
//  Created by ZYJ on 2016/11/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

/*
 *  Floyd算法，求从任意节点i到任意节点j的最短路径
 *  cost[][]:初始化为INF（cost[i][i]：初始化为0）
 */
const int MAXN = 110;
const int INF = 0x1f1f1f1f;

int val[MAXN];
int cost[MAXN][MAXN];
int lowcost[MAXN][MAXN];
int path[MAXN][MAXN];

void Floyd(int n)
{
    memcpy(lowcost, cost, sizeof(cost));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            path[i][j] = j;
        }
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int temp = lowcost[i][k] + lowcost[k][j] + val[k];
                if (lowcost[i][j] > temp)
                {
                    lowcost[i][j] = temp;
                    path[i][j] = path[i][k];
                }
                else if (lowcost[i][j] == temp && path[i][j] > path[i][k])
                {
                    path[i][j] = path[i][k];
                }
            }
        }
    }
    return ;
}

int main(int argc, const char * argv[])
{
    int N;
    while (cin >> N, N != 0)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                scanf("%d", cost[i] + j);
                if (cost[i][j] == -1)
                {
                    cost[i][j] = INF;
                }
            }
        }
        
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", val + i);
        }
        
        Floyd(N);
        
        int st, ed;
        while (cin >> st >> ed)
        {
            if (st + ed == -2)
            {
                break;
            }
            printf("From %d to %d :\nPath: ", st, ed);
            int u = st;
            printf("%d", st);
            while (u != ed)
            {
                printf("-->%d", path[u][ed]);
                u = path[u][ed];
            }
            printf("\nTotal cost : %d\n\n", lowcost[st][ed]);
        }
    }
    
    return 0;
}
