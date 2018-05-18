//
//  main.c
//  f-CDOJ-2016-A-柱爷与咸鱼神功
//
//  Created by ZYJ on 16/5/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define MAXSIZE 10005
#define MAX(a, b) a > b ? a : b
int dp[5001][5001]; //dp[i][j]招式数量为i心情点数为j时最大修炼值

int main(int argc, const char * argv[])
{
    int i, j;
    int N, M;
    int T[MAXSIZE], V[MAXSIZE];
    
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= M; i++)
    {
        scanf("%d %d", T + i, V + i);
    }
    
    for (i = 0; i <= M; i++)
    {
        dp[i][0] = 0;
    }
    for (i = 0; i <= N; i++)
    {
        dp[0][i] = 0;
    }
    
    for (i = 1; i <= M; i++)
    {
        for (j = 0; j <= N; j++)
        {
            if (j < T[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = MAX(dp[i - 1][j], dp[i - 1][j - T[i]] + V[i]);
            }
        }
    }
    
    printf("%d\n", dp[M][N]);
    return 0;
}
