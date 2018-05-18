//
//  main.c
//  f-ALGO-116-最大的算式
//
//  Created by ZYJ on 16/4/8.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
////求积
//void product(int *n, int *p, int N)
//{
//    int i = 0;
//    for (; i < N - 1; i++)
//    {
//        p[i] = n[i] * n[i + 1];
//    }
//    return ;
//}
//
////检索第i大的数据
//int retMax(int *p, int N)
//{
//    int i = 0, max = -1, j = N - 1;
//    for (; i < N - 1; i++)
//    {
//        if (p[i] > max)
//        {
//            max = p[i];
//            j = i;
//        }
//    }
//    return j;
//}
//
//int main(int argc, const char * argv[])
//{
//    int N, K, i = 0, j, k, S = 0;
//    long long P = 1;
//    int num[15], pro[15], flag[15] = {0};
//    scanf("%d %d", &N, &K);
//    for (; i < N; i++)
//    {
//        scanf("%d", &num[i]);
//    }
//    product(num, pro, N);
//    k = K;
//    while (k--)
//    {
//        j = retMax(pro, N);
//        pro[j] = -1;
//        flag[j] = 1;
//    }
//    //down调试代码
//    if (K == 0)
//    {
//        for (i = 0; i < N - 1; i++)
//        {
//            printf("%d", num[i]);
//            printf("+");
//        }
//        printf("%d\n", num[N - 1]);
//        goto H;
//    }
//    for (i = 0; i < N - 1; i++)
//    {
//        if (flag[i] == 0 && (i == 0 || flag[i - 1] != 0))
//        {
//            printf("(");
//        }
//        printf("%d", num[i]);
//        if (i != 0 && flag[i - 1] == 0 && flag[i] != 0)
//        {
//            printf(")");
//        }
//        if (flag[i])
//        {
//            printf("*");
//        }
//        else
//        {
//            printf("+");
//        }
//    }
//    printf("%d", num[N - 1]);
//    if (flag[N - 2] == 0)
//    {
//        printf(")");
//    }
//    printf("\n");
//H:
//    //up调试代码
//    for (i = 0; i < N - 1; i++)
//    {
//        if (flag[i] == 0)
//        {
//            S += num[i];
//        }
//        else if (flag[i] && i != 0 && flag[i - 1] == 0)
//        {
//            S += num[i];
//        }
//        else if (S != 0)
//        {
//            P *= S * num[i];
//            S = 0;
//        }
//        else
//        {
//            P *= num[i];
//        }
//    }
//    if (flag[N - 2] == 0)
//    {
//        S += num[N - 1];
//        P *= S;
//    }
//    else if (S != 0)
//    {
//        P *= S * num[N - 1];
//    }
//    else
//    {
//        P *= num[i];
//    }
//    printf("%lld\n", P);
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#define min(a, b) a > b ? b : a
#define max(a, b) a > b ? a : b

long long dp[16][16] = {0};   //dp[i][j]表示前i个数中有j个乘号时，所得最大值
int sum[16] = {0};    //sum[i]表示前i个数之和

int main()
{
    int N, K, i = 1, j, k, t;
    scanf("%d %d", &N, &K);
    int num[16];
    for (; i <= N; i++)
    {
        scanf("%d", &num[i]);
        sum[i] = sum[i - 1] + num[i];
    }
    //如果没有乘号的情况/连加情况
    for (i = 1; i <= N; i++)
    {
        dp[i][0] = sum[i];
    }
    //dp
    for (i = 2; i <= N; i++)
    {
        t = min(i - 1, K);
        for (j = 1; j <= t; j++)
        {
            for (k = 2; k <= i; k++)    //k为这个乘号的位置
            {
                dp[i][j] = max(dp[i][j], dp[k - 1][j - 1] * (sum[i] - sum[k - 1])); //求前i个数有j个乘号的情况中最大的情况
            }
        }
    }
    printf("%lld\n", dp[N][K]);
    return 0;
}