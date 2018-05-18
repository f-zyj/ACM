//
//  main.cpp
//  f-2016CCPC-D-Danganronpa
//
//  Created by ZYJ on 16/8/14.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>

#define MAXN 15

int A[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    
    int N;
    int key = 1;
    int i, j, s;
    int sum;
    while (T--)
    {
        scanf("%d", &N);
        sum = 0;
        for (i = 0; i < N; i++)
        {
            scanf("%d", A + i);
            sum += A[i];
        }
        for (i = 0; i < N -1; i++)
        {
            for (j = i + 1; j < N; j++)
            {
                if (A[i] > A[j])
                {
                    A[i] ^= A[j];
                    A[j] ^= A[i];
                    A[i] ^= A[j];
                }
            }
        }
        s = 0;
        for (i = N - 1; i >= 0; i--)
        {
            if (A[i] > sum / 4)
            {
                s += sum / 4;
            }
            else if (s + A[i] > sum / 2)
            {
                s = sum / 2;
                break;
            }
            else
            {
                s += A[i];
            }
        }
        printf("Case #%d: %d\n", key++, s);
    }
    
    return 0;
}
