//
//  main.cpp
//  f-HDU-1546-Idiomatic Phrases Game
//
//  Created by ZYJ on 2016/11/21.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1010;
const int MAXL = 100;
const int INF = 0x3f3f3f3f;

bool vis[MAXN];
int pre[MAXN];
int lowcost[MAXN];
int cost[MAXN][MAXN];

void dijkstra(int n, int beg)
{
    memset(lowcost, 0x3f, sizeof(lowcost));
    memset(vis, false, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    lowcost[beg] = 0;
    
    for (int j = 0; j < n; j++)
    {
        int k = -1;
        int min = INF;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && lowcost[i] < min)
            {
                min = lowcost[i];
                k = i;
            }
        }
        if (k == -1)
        {
            break;
        }
        vis[k] = true;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && lowcost[k] + cost[k][i] < lowcost[i])
            {
                lowcost[i] = lowcost[k] + cost[k][i];
                pre[i] = k;
            }
        }
    }
}

char s[MAXL];
int sst[MAXN];
int sed[MAXN];
int val[MAXN];

void store(int n)
{
    int st = 0;
    for (int i = 0; i < 4; i++)
    {
        st *= 16;
        if (s[i] >= '0' && s[i] <= '9')
        {
            st += s[i] - '0';
        }
        else
        {
            st += s[i] - 'A' + 10;
        }
    }
    sst[n] = st;
    
    int ed = 0;
    int len = (int)strlen(s);
    for (int i = len - 4; i < len; i++)
    {
        ed *= 16;
        if (s[i] >= '0' && s[i] <= '9')
        {
            ed += s[i] - '0';
        }
        else
        {
            ed += s[i] - 'A' + 10;
        }
    }
    sed[n] = ed;
}

int main(int argc, const char * argv[])
{
    int N;
    while (cin >> N, N != 0)
    {
        memset(cost, 0x3f, sizeof(cost));
        
        for (int i = 0; i < N; i++)
        {
            scanf("%d%s", val + i, s);
            store(i);
        }
        
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (sst[i] == sed[j])
                {
                    cost[j][i] = val[j];
                }
                if (sed[i] == sst[j])
                {
                    cost[i][j] = val[i];
                }
            }
        }
        
        dijkstra(N, 0);
        
        if (lowcost[N - 1] == INF)
        {
            cout << "-1\n";
        }
        else
        {
            cout << lowcost[N - 1] << '\n';
        }
    }
    
    return 0;
}
