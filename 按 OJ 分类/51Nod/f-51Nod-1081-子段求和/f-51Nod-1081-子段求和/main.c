//
//  main.c
//  f-51Nod-1081-子段求和
//
//  Created by ZYJ on 16/4/21.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define _MAX 50005

int main(int argc, const char * argv[])
{
    int N, A[_MAX], i = 0, j = 0, Q, B[_MAX], C[_MAX];
    long long sum, AA[_MAX] = {0};
    scanf("%d", &N);
    for (; i < N; i++)
    {
        scanf("%d", A + i);
        if (i == 0)
        {
            AA[i] = A[i];
        }
        else
        {
            AA[i] = A[i] + AA[i - 1];
        }
    }
    scanf("%d", &Q);
    for (; j < Q; j++)
    {
        scanf("%d %d", B + j, C + j);
    }
    for (i = 0; i < Q; i++)
    {
        if (B[i] == 1)
        {
            sum = AA[B[i] + C[i] - 2];
        }
        else
        {
            sum = AA[B[i] + C[i] - 2] - AA[B[i] - 2];
        }
        printf("%lld\n", sum);
    }
    return 0;
}
