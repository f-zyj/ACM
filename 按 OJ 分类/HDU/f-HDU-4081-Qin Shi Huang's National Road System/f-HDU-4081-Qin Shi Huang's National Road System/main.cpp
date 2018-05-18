//
//  main.cpp
//  f-HDU-4081-Qin Shi Huang's National Road System
//
//  Created by ZYJ on 2016/11/3.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 1010;

struct city
{
    double X;
    double Y;
    double P;
};

struct city City[MAXN];
double cost[MAXN][MAXN];

/*
 *  求最小生成树时，用数组MAX[i][j]表示i到j的最大边权
 *  求完后，直接枚举所有不在MST中的边，替换掉最大边权的边，更新答案
 *  点的编号从0开始
 */

const int INF = 0x3f3f3f3f;

bool vis[MAXN];
double lowc[MAXN];
int pre[MAXN];
double MAX[MAXN][MAXN];
bool used[MAXN][MAXN];

double Prim(double cost[][MAXN], int n)
{
    double ans = 0;
    memset(vis, false, sizeof(vis));
    memset(MAX, 0, sizeof(MAX));
    memset(used, false, sizeof(used));
    vis[0] = true;
    pre[0] = -1;
    lowc[0] = 0;
    
    for (int i = 1; i < n; i++)
    {
        lowc[i] = cost[0][i];
        pre[i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        double minc = INF;
        int p = -1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && minc > lowc[j])
            {
                minc = lowc[j];
                p = j;
            }
        }
        if (minc == INF)
        {
            return -1;
        }
        ans += minc;
        vis[p] = true;
        used[p][pre[p]] = used[pre[p]][p] = true;
        for (int j = 0; j < n; j++)
        {
            if (vis[j])
            {
                MAX[j][p] = MAX[p][j] = max(MAX[j][pre[p]], lowc[p]);
            }
            if (!vis[j] && lowc[j] > cost[p][j])
            {
                lowc[j] = cost[p][j];
                pre[j] = p;
            }
        }
    }
    
    return ans;
}

inline double getDis(double x, double y, double x_, double y_)
{
    return sqrt(pow((x - x_), 2) + pow((y - y_), 2));
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    int n;
    while (T--)
    {
        memset(cost, 0, sizeof(cost));
        
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf%lf", &City[i].X, &City[i].Y, &City[i].P);
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                double dis = getDis(City[i].X, City[i].Y, City[j].X, City[j].Y);
                cost[i][j] = cost[j][i] = dis;
            }
        }
        
        double res = Prim(cost, n);
        double ans = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (used[i][j])
                {
                    ans = max(ans, (City[i].P + City[j].P) / (res - cost[i][j]));
                }
                else
                {
                    ans = max(ans, (City[i].P + City[j].P) / (res - MAX[i][j]));
                }
            }
        }
        
        printf("%.2lf\n", ans);
    }
    
    return 0;
}
