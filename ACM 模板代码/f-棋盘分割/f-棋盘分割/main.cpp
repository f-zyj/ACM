//
//  main.cpp
//  f-棋盘分割
//
//  Created by ZYJ on 16/7/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

/*
 *  棋盘分割
 *  将一个8*8的棋盘进行如下分割:将原棋盘割下一块矩形棋盘并使剩下部 
 *  分也是矩形,再将剩下的部分继续如此分割,这样割了(n-1)次后,连同最 
 *  后剩下的矩形棋盘共有n块矩形棋盘。(每次切割都只能沿着棋盘格子的边 
 *  进行) 原棋盘上每一格有一个分值,一块矩形棋盘的总分为其所含各格分
 *  值之和。现在需要把棋盘按上述规则分割成n块矩形棋盘,并使各矩形棋 
 *  盘总分的均方差最小。 均方差...,其中平均值...,xi为第i块矩形棋盘的
 *  总分。请编程对给出的棋盘及 n,求出 O'的最小值。
 */
#define min(a, b) ((a) < (b) ? (a) : (b))
const int oo = 10000000;

int map[8][8];
double C[16][8][8][8][8];   //  c[k][si][ei][sj][ej]: 对矩阵
//  map[si...sj][ei...ej]分割成k个矩形(切割k-1刀)的结果
double ans;                 //  平均值
int n;                      //  分成n块矩形棋盘

void input(void);
void reset(void);
double caluate(int i1, int j1, int i2, int j2);
void dp(int m, int si, int sj, int ei, int ej);

int main()
{
    int m, i, j, k, l;
    while (scanf("%d", &n) != EOF)
    {
        input();
        reset();
        for (m = 1; m <= n; m++)
        {
            for (i = 0; i < 8; i++)
            {
                for (j = 0; j < 8; j++)
                {
                    for (k = 0; k < 8; k++)
                    {
                        for (l = 0; l < 8; l++)
                        {
                            if ((k - i + 1) * (l - j + 1) < m)
                            {
                                C[m][i][j][k][l] = oo;
                            }
                            else
                            {
                                if (m == 1)
                                {
                                    C[m][i][j][k][l] = pow((caluate(i, j, k, l) - ans), 2);
                                }
                                else
                                {
                                    dp(m, i, j, k, l);
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%.3lf\n", sqrt(C[n][0][0][7][7] / n));
    }
    return 0;
}

void input()
{
    int i, j;
    double sum = 0;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            scanf("%d", &map[i][j]);
            sum += map[i][j];
        }
    }
    ans = sum / double(n);  //  平均值
}

void reset()
{
    int i, j, k, l, m;
    for (m = 0; m <= n; m++)
    {
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                for (k = 0; k < 8; k++)
                {
                    for (l = 0; l < 8; l++)
                    {
                            C[m][i][j][k][l] = 0;
                    }
                }
            }
        }
    }
    return ;
}

double caluate(int i1, int j1, int i2, int j2)
{
    double sum = 0;
    int i, j;
    for (i = i1; i <= i2; i++)
    {
        for (j = j1; j <= j2; j++)
        {
            sum += map[i][j];
        }
    }
    return sum;
}

void dp(int m, int si, int sj, int ei, int ej)
{
    int i, j;
    double mins = oo;
    for (j = sj; j < ej; j++)
    {   //  竖刀
        mins = min(mins, C[1][si][sj][ei][j] + C[m - 1][si][j + 1][ei][ej]);
        mins = min(mins, C[m - 1][si][sj][ei][j] + C[1][si][j + 1][ei][ej]);
    }
    for (i = si; i < ei; i++)
    {   // 横刀
        mins = min(mins, C[1][si][sj][i][ej] + C[m - 1][i + 1][sj][ei][ej]);
        mins = min(mins, C[m - 1][si][sj][i][ej] + C[1][i + 1][sj][ei][ej]);
    }
    C[m][si][sj][ei][ej] = mins;
    return ;
}
