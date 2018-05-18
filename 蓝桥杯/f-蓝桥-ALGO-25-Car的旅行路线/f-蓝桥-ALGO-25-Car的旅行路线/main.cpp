//
//  main.cpp
//  f-蓝桥-ALGO-25-Car的旅行路线
//
//  Created by ZYJ on 2017/6/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 1111;
const int MAXS = 111;
const int INF = 0x3f3f3f3f;

struct city
{
    int x[4], y[4];
    int t;
} C[MAXS];

int s, t, A, B;
double cost[MAXN][MAXN];
double lowcost[MAXN][MAXN];

double getCost(int x1, int y1, int x2, int y2, int t)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) * t;
}

void Floyd(int n)
{
    memcpy(lowcost, cost, sizeof(cost));
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (lowcost[i][j] > lowcost[i][k] + lowcost[k][j])
                {
                    lowcost[i][j] = lowcost[i][k] + lowcost[k][j];
                }
            }
        }
    }
}

void get_fourth_node(int x1, int y1, int x2, int y2, int x3, int y3, int &x4, int &y4)
{
    if ((x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2) == 0)
    {
        swap(x1, x2);
        swap(y1, y2);
    }
    else if ((x1 - x3) * (x2 - x3) + (y1 - y3) * (y2 - y3) == 0)
    {
        swap(x1, x3);
        swap(y1, y2);
    }
    x4 = x2 + x3 - x1;
    y4 = y2 + y3 - y1;
}

int main(int argc, const char * argv[])
{
    memset(cost, 0x3f, sizeof(cost));
    
    cin >> s >> t >> A >> B;
    if (A == B)
    {
        printf("0.0\n");
        return 0;
    }
    for (int i = 0; i < s; i++)
    {
        cin >> C[i].x[0] >> C[i].y[0];
        cin >> C[i].x[1] >> C[i].y[1];
        cin >> C[i].x[2] >> C[i].y[2];
        cin >> C[i].t;
        get_fourth_node(C[i].x[0], C[i].y[0], C[i].x[1], C[i].y[1], C[i].x[2], C[i].y[2], C[i].x[3], C[i].y[3]);

        for (int j = 0; j < 4; j++)
        {
            for (int k = j + 1; k < 4; k++)
            {
                cost[i * 4 + j][i * 4 + k] = cost[i * 4 + k][i * 4 + j] =
                        getCost(C[i].x[j], C[i].y[j], C[i].x[k], C[i].y[k], C[i].t);
            }
        }
    }
    
    for (int i = 0; i < s; i++)
    {
        for (int j = i + 1; j < s; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                for (int l = 0; l < 4; l++)
                {
                    cost[i * 4 + k][j * 4 + l] = cost[j * 4 + l][i * 4 + k] =
                    getCost(C[i].x[k], C[i].y[k], C[j].x[l], C[j].y[l], t);
                }
            }
        }
    }
    
    Floyd(4 * s);
    
    double res = INF;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            res = min(res, lowcost[A * 4 - 4 + i][B * 4 - 4 + j]);
        }
    }

    printf("%.1f\n", res);
    
    return 0;
}
