//
//  main.c
//  f-51Nod-1289-大鱼吃小鱼
//
//  Created by qingyun on 16/5/16.
//  Copyright © 2016年 qingyun. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int N;
    int A[100001], B[100001];
    int C[100001];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", A + i, B + i);
    }
    
    int m = N;
    int top = -1;
    for (int i = 0; i < N; i++)
    {
        if (B[i] == 1)
        {
            C[++top] = A[i];
        }
        else
        {
            while (top != -1)
            {
                m--;
                if (C[top] < A[i])
                {
                    top--;
                }
                else
                {
                    break;
                }
            }
        }
    }
    
    printf("%d\n", m);
    return 0;
}
