//
//  main.c
//  f-51Nod-1079-中国剩余定理
//
//  Created by ZYJ on 16/4/20.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int N, i = 0, j = 0;
    int P[11], M[11];
    long long sum = 0, K, acc = 1;
    scanf("%d", &N);
    for (; i < N; i++)
    {
        scanf("%d %d", P + i, M + i);
        acc *= P[i];
    }
    
    for (i = 0; i < N; i++)
    {
        for (j = 1; j < 100000; j++)
        {
            if (acc / P[i] * j % P[i] == 1)
            {
                sum += acc / P[i] * j * M[i];
                break;
            }
        }
    }
    
    K = sum % acc;
    printf("%lld\n", K);
    return 0;
}