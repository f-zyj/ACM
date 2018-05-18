//
//  main.c
//  f-51Nod-1134-最长递增子序列
//
//  Created by ZYJ on 16/4/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
//#define MAX(a, b) a > b ? a : b
//
//int main(int argc, const char * argv[])
//{
//    int maxLen = 0, N, A[50001], B[50001] = {0}, i, j;
//    scanf("%d", &N);
//    scanf("%d", A);
//    B[0] = 1;
//    for (i = 1; i < N; i++)
//    {
//        scanf("%d", A + i);
//        maxLen = 0;
//        for (j = i - 1; j >= 0; j--)
//        {
//            if (A[j] <= A[i])
//            {
//                maxLen = MAX(maxLen, B[j]);
//            }
//        }
//        B[i] = maxLen + 1;
//    }
//    maxLen = 0;
//    for (i = 0; i < N; i++)
//    {
//        maxLen = MAX(maxLen, B[i]);
//    }
//    printf("%d\n", maxLen);
//    return 0;
//}


#include <stdio.h>
#define MAXSIZE 50001
#define MAX(a, b) a > b ? a : b
int A[MAXSIZE];
int B[MAXSIZE]; //最长子序列

//从当前序列中返回第一个键值大于A的数的下标
int upper_bound(int len, int A)
{
    int i = 0;
    for (; i < len; i++)
    {
        if (B[i] > A)
        {
            return i;
        }
    }
    return i;
}

int list(int n)
{
    int len = 1;
    B[0] = A[0];
    for (int i = 1; i < n; i++)
    {
        B[A[i] > B[len - 1] ? len++ : upper_bound(len, A[i])] = A[i];
    }
    return len;
}
int main(int argc, const char * argv[])
{
    int N, i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", A + i);
    }
    printf("%d\n", list(N));
    return 0;
}
