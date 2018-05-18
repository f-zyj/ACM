//
//  main.cpp
//  f-HDU-1869-六度分离
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
const int MAXN = 100;

int cost[MAXN][MAXN];
int lowcost[MAXN][MAXN];
int path[MAXN][MAXN];

void Floyd(int n)
{
    memcpy(lowcost, cost, sizeof(cost));
    memset(path, -1, sizeof(path));
    
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (lowcost[i][j] > (lowcost[i][k] + lowcost[k][j]))
                {
                    lowcost[i][j] = lowcost[i][k] + lowcost[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
    return ;
}

int main(int argc, const char * argv[])
{
    int N, M;
    while (cin >> N >> M)
    {
        memset(cost, 0x3f, sizeof(cost));
        
        int a, b;
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d", &a, &b);
            cost[a][b] = cost[b][a] = 1;
        }
        
        Floyd(N);
        
        bool flag = true;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (lowcost[i][j] > 7)
                {
                    flag = false;
                    break;
                }
            }
        }
        
        if (flag)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    
    return 0;
}

