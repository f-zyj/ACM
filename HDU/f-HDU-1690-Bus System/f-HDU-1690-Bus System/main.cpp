//
//  main.cpp
//  f-HDU-1690-Bus System
//
//  Created by ZYJ on 2016/12/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAXF = 4;
const int MAXN = 105;

ll L[MAXF], C[MAXF];
ll X[MAXN];
ll cost[MAXN][MAXN];

ll getC(ll dis)
{
    if (dis > 0 && dis <= L[0])
    {
        return C[0];
    }
    if (dis > L[0] && dis <= L[1])
    {
        return C[1];
    }
    if (dis > L[1] && dis <= L[2])
    {
        return C[2];
    }
    if (dis > L[2] && dis <= L[3])
    {
        return C[3];
    }
    return INF;
}

void floyd(int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    int n, m;
    for (int i = 1; i <= T; i++)
    {
        cin >> L[0] >> L[1] >> L[2] >> L[3];
        cin >> C[0] >> C[1] >> C[2] >> C[3];
        cin >> n >> m;
        
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", X + j);
        }
        
        memset(cost, 0x3f, sizeof(cost));
        
        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                cost[j][k] = cost[k][j] = getC(abs(X[j] - X[k]));
            }
        }
        
        floyd(n);
        
        int u, v;
        printf("Case %d:\n", i);
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            if (cost[u - 1][v - 1] != INF)
            {
                printf("The minimum cost between station %d and station %d is %lld.\n",
                       u, v, cost[u - 1][v - 1]);
            }
            else
            {
                printf("Station %d and station %d are not attainable.\n", u, v);
            }
        }
    }
    
    return 0;
}
