//
//  main.cpp
//  f-51Nod-1630-B君的竞技场
//
//  Created by ZYJ on 2017/7/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 22;

int x, y;
double a[] = {2, 0, 1};
double b[] = {2, 1, -1};
double dp[MAXN][MAXN][MAXN << 1];

void get_dp(int x, int y, double z[], double w[])
{
    dp[x][y][0] = max(dp[x][y][0], z[0] + w[0] - 1);
    for (int i = 1; i <= z[0]; i++)
    {
        for (int j = 1; j <= w[0]; j++)
        {
            dp[x][y][i + j - 1] += z[i] * w[j];
        }
    }
}

double get_res(int x, int y)
{
    double ret = 0;
    for (int i = 1; i <= dp[x][y][0]; i++)
    {
        ret += dp[x][y][i] / i;
    }
    
    return ret;
}

int main()
{
    scanf("%d%d", &x, &y);
    
    dp[0][0][0] = dp[0][0][1] = 1;
    
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (i > 0)
            {
                get_dp(i, j, dp[i - 1][j], b);
            }
            if (j > 0)
            {
                get_dp(i, j, dp[i][j - 1], a);
            }
        }
    }
 
    double res = 0;
    for (int i = 0; i < y; i++)
    {
        get_dp(i, x, dp[i][x - 1], a);
        res += get_res(i, x) * x;
    }
    for (int i = 0; i < x; i++)
    {
        get_dp(y, i, dp[y - 1][i], b);
        res += get_res(y, i) * i;
    }
    
    printf("%f\n", res);
    
    return 0;
}
