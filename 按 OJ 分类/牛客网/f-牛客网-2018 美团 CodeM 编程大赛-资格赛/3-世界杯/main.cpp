//
//  main.cpp
//  f-牛客网-2018 美团 CodeM 编程大赛-资格赛
//
//  Created by ZYJ on 2018/6/7.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 20;
const int MAGIC = 16;

double F[MAXN][MAXN];
double dp[MAXN][5];

int main()
{
    for (int i = 1; i <= MAGIC; i++)
    {
        for (int j = 1; j <= MAGIC; j++)
        {
            scanf("%lf", F[i] + j);
        }
    }
    memset(dp, 0, sizeof(0));
    
    //  第一轮胜出概率
    for (int i = 1; i <= MAGIC; i++)
    {
        if (i % 2 == 1)
        {
            dp[i][1] = F[i][i + 1];
        }
        else
        {
            dp[i][1] = F[i][i - 1];
        }
    }
    
    for (int i = 2; i <= 4; i++)
    {
        int sub = 1 << i;
        for (int j = 1; j <= MAGIC; j++)
        {
            for (int k = 1; k <= MAGIC; k++)
            {
                //  在同一组才能开战
                if ((j - 1) / sub == (k - 1) / sub)
                {
                    //  假如 4 人一组，必须一个是 12 一个是 34
                    if ((j - 1) / (sub / 2) != (k - 1) / (sub / 2))
                    {
                        dp[j][i] += dp[j][i - 1] * dp[k][i - 1] * F[j][k];
                    }
                }
            }
        }
    }
    
    for (int j = 1; j <= MAGIC; j++)
    {
        printf("%.10f%c", dp[j][4], j == MAGIC ? '\n' : ' ');
    }
    
    return 0;
}
