//
//  main.cpp
//  f-HDU-1596-find the safest road
//
//  Created by ZYJ on 2016/12/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 1010;

double cost[MAXN][MAXN];
double lowcost[MAXN][MAXN];

void Floyd(int n)
{
    memcpy(lowcost, cost, sizeof(cost));
    
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (lowcost[i][j] < (lowcost[i][k] * lowcost[k][j]))
                {
                    lowcost[i][j] = lowcost[i][k] * lowcost[k][j];
                }
            }
        }
    }
    return ;
}

int main(int argc, const char * argv[])
{
    int n, q;
    
    while (cin >> n)
    {
        memset(cost, 0, sizeof(cost));
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%lf", cost[i] + j);
            }
        }
        
        Floyd(n);
        
        cin >> q;
        int st, ed;
        
        while (q--)
        {
            scanf("%d %d", &st, &ed);
            st--;
            ed--;
            if (lowcost[st][ed] == 0)
            {
                printf("What a pity!\n");
            }
            else
            {
                printf("%.3lf\n", lowcost[st][ed]);
            }
        }
    }
    
    return 0;
}
