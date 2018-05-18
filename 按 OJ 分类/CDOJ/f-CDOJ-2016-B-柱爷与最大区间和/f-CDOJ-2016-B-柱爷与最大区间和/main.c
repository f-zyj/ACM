//
//  main.c
//  f-CDOJ-2016-B-柱爷与最大区间和
//
//  Created by ZYJ on 16/5/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
//#define MAX(a, b) a > b ? a : b
//#define MAXSIZE 8
//#define INF 0x3f3f3f3f
//
//int main(int argc, const char * argv[])
//{
//    int i, j;
//    int N;
//    int A[MAXSIZE];
//    int sumA = 0, sumB = 0; //正序／逆序
//    int ans = -INF;
//    int dp[MAXSIZE];
//    for (i = 0; i < MAXSIZE; i++)
//    {
//        dp[i] = -INF;
//    }
//    
//    scanf("%d", &N);
//    for (i = 1; i <= N; i++)
//    {
//        scanf("%d", A + i);
//    }
//    
//    for (i = 1; i < N - 1; i++)
//    {
//        sumA = sumA + A[i];
//        dp[i] = MAX(dp[i - 1], sumA);
//        sumA = sumA > 0 ? sumA : 0;
//        
//        for (j = i + 1; j <= N; j++)
//        {
//            dp[j] = -INF;
//        }
//        
//        sumB = 0;
//        for (j = N; j > (A[i] < 0 || A[i + 1] < 0 ? i : N); j--)
//        {
//            sumB = sumB + A[j];
//            dp[j] = MAX(dp[j + 1], sumB);
//            sumB = sumB > 0 ? sumB : 0;
//        }
//        
//        ans = MAX(ans, dp[i] + dp[i + 1]);
//    }
//    
//    printf("%d\n", ans);
//    return 0;
//}

#include <stdio.h>
#define MAX(a, b) a > b ? a : b
#define MAXSIZE 500005
#define INF 0x3f3f3f3f

int main(int argc, const char * argv[])
{
    int i;
    int N;
    int A[MAXSIZE];
    int sumA, sumB, sumBB; //正序／逆序
    int ans;
    int B[MAXSIZE] = {0};
    
    while (~scanf("%d", &N))
    {
        ans = sumA = sumB = sumBB = -INF;
        
        for (i = 1; i <= N; i++)
        {
            scanf("%d", A + i);
        }
        
        B[N + 1] = -INF;
        for (i = N; i > 2; i--)
        {
            sumA = sumA > 0 ? sumA + A[i] : A[i];
            B[i] = MAX(B[i + 1], sumA);
        }
        for (i = 1; i < N - 1; i++)
        {
            sumB = sumB > 0 ? sumB + A[i] : A[i];
            sumBB = sumB > sumBB ? sumB : sumBB;
            
            if (sumBB + B[i + 2] > ans)
            {
                ans = sumBB + B[i + 2]; //中间隔着i + 1
            }
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}

