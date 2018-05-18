//
//  main.cpp
//  f-HDU-1162-Eddy's picture
//
//  Created by ZYJ on 2016/11/1.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>

#define mem(a, b) memset(a, b, sizeof(a))

using namespace std;

struct land
{
    float x;
    float y;
};

/*
 * Prim求MST
 * 耗费矩阵cost[][]，初始化为INF，标号从0开始，0 ~ n－1
 * 返回最小生成树的权值，返回-1表示原图不连通
 */

const int INF = 0x3f3f3f3f;
const int MAXN = 110;
bool vis[MAXN];
double lowc[MAXN];
double cost[MAXN][MAXN];
struct land L[MAXN];

//  修正cost（添加边）
void updata(int x, int y, double v)
{
    cost[x - 1][y - 1] = v;
    cost[y - 1][x - 1] = v;
    return ;
}

double Prim(double cost[][MAXN], int n)   //  0 ~ n - 1
{
    double ans = 0;
    memset(vis, false, sizeof(vis));
    vis[0] = true;
    for (int i = 1; i < n; i++)
    {
        lowc[i] = cost[0][i];
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
            return -1;  //  原图不连通
        }
        ans += minc;
        vis[p] = true;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && lowc[j] > cost[p][j])
            {
                lowc[j] = cost[p][j];
            }
        }
    }
    return ans;
}

int main(int argc, const char * argv[])
{
    int C;
    
    while (cin >> C)
    {
        //  double不能用mem(cost, 0x3f)来初始化
        for (int i = 0; i < C; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cost[i][j] = INF;
            }
        }
        mem(vis, 0);
        
        for (int i = 1; i <= C; i++)
        {
            scanf("%f%f", &L[i].x, &L[i].y);
        }
        
        for (int i = 1; i <= C; i++)
        {
            for (int j = i; j <= C; j++)
            {
                double dis = sqrt(pow(L[i].x - L[j].x, 2) + pow(L[i].y - L[j].y, 2));
                //  cout << res << '\n';
//                if (dis >= 10 && dis <= 1000)
//                {
                    updata(i, j, dis);
//                }
            }
        }
        
        double ans = Prim(cost, C);
//        if (ans == -1)
//        {
            cout << "oh!\n";
//        }
//        else
//        {
            printf("%.2f\n", ans);
//        }
    }
    
    return 0;
}
