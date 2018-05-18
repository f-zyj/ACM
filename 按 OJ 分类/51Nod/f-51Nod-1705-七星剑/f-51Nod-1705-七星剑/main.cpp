//
//  main.cpp
//  f-51Nod-1705-七星剑
//
//  Created by ZYJ on 2017/7/7.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 105;
const int MAXM = 8;
const double ESP = 1e-9;
const long long INF = 0x3f3f3f3f3f3f3f3f;

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

int N;
int C[MAXN];
int lose_[MAXM][MAXN];
double prob[MAXM][MAXN];
double dp[MAXM];

int main()
{
    scan_d(N);
    for (int i = 1; i <= N; i++)
    {
        scan_d(C[i]);
    }
    
    int flag;
    for (int i = 1; i < MAXM; i++)
    {
        flag = 0;
        for (int j = 1; j <= N; j++)
        {
            scanf("%lf", prob[i] + j);
            flag |= abs(prob[i][j]) > ESP;
        }
        if (!flag)
        {
            puts("-1");
            return 0;
        }
    }
    
    int x;
    for (int i = 1; i < MAXM; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scan_d(x);
            lose_[i][j] = i - 1 - x;
        }
    }
    
    dp[0] = 0;
    double tmp;
    for (int i = 1; i < MAXM; i++)
    {
        dp[i] = INF;
        for (int j = 1; j <= N; j++)
        {
            if (prob[i][j])
            {
                tmp = (dp[i - 1] + C[j] - (1 - prob[i][j]) * dp[lose_[i][j]]) / prob[i][j];
                dp[i] = min(dp[i], tmp);
            }
        }
    }
    
    printf("%.10lf\n", dp[MAXM - 1]);
    
    return 0;
}
