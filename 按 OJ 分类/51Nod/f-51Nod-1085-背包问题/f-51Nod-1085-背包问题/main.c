//
//  main.c
//  f-51Nod-1085-背包问题
//
//  Created by ZYJ on 16/4/21.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define _MAX 102
#define MAX(a, b) a > b ? a : b

int dp[_MAX][_MAX * _MAX];

int KanpSack(int N, int *Wi, int *Pi, int W)
{
    int i, j;
    for (i = 0; i <= N; i++)
    {
        dp[i][0] = 0;
    }
    for (j = 0; j <= W; j++)
    {
        dp[0][j] = 0;
    }
    
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= W; j++)
        {
            if (j < Wi[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = MAX(dp[i - 1][j], dp[i - 1][j - Wi[i]] + Pi[i]);
            }
        }
    }
    
    return dp[N][W];
}

int main(int argc, const char * argv[])
{
    int N, W, Wi[_MAX], Pi[_MAX], i = 1;
    scanf("%d %d", &N, &W);
    for (; i <= N; i++)
    {
        scanf("%d %d", Wi + i, Pi + i);
    }
    printf("%d\n", KanpSack(N, Wi, Pi, W));
    return 0;
}
