//
//  main.c
//  f-CDOJ-2016-C-柱爷的下凡
//
//  Created by ZYJ on 16/5/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f

int MIN(int a, int b, int c)
{
    int min = a < b ? a : b;
    return min < c ? min : c;
}

int main(int argc, const char * argv[])
{
    int T, N;
    int num, ans;
    int A, B, C, i, j, k;
    int dp[201];
    scanf("%d", &T);
    while (T--)
    {
        memset(dp, 0, sizeof(dp));
        dp[1] = 1;
        A = 1, B = 2, C = 3, ans = INF;
        scanf("%d", &N);
        for (j = 2; j < 15; j++)
        {
            for (k = j + 1; k <= 50; k++)
            {
                num = 1;
                for (i = 2; i <= N; i++)
                {
                    dp[i] = MIN(dp[i - 1], i - j >= 0 ? dp[i - j] : INF, i - k >= 0 ? dp[i - k] : INF) + 1;
                    num += dp[i];
                }
                if (ans > num)
                {
                    ans = num;
                    B = j;
                    C = k;
                }
            }
        }
        
        printf("%d %d %d\n", A, B, C);
    }
    
    return 0;
}