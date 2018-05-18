//
//  main.c
//  f-NYOJ-26-孪生素数问题
//
//  Created by ZYJ on 16/5/24.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define MAXSIZE 1000100
int numA[MAXSIZE] = {1, 1};  //1非质数，0质数
int numB[MAXSIZE];

int main(int argc, const char * argv[])
{
    int N;
    scanf("%d", &N);
    
    int key = 0;
    for (int i = 2; i < MAXSIZE; i++)
    {
        if (!numA[i])
        {
            numB[key++] = i;
        }
        for (int j = 0; i * numB[j] < MAXSIZE && j < key; j++)
        {
            numA[i * numB[j]] = 1;
            if (!(i % numB[j]))
            {
                break;
            }
        }
    }
    
    while (N--)
    {
        int m, ans = 1;
        scanf("%d", &m);
        for (int i = 1; i < key; i++)
        {
            if (numB[i] > m)
            {
                break;
            }
            if (!numA[numB[i] - 2])
            {
                ans++;
            }
        }
        if (m < 3)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", ans);
        }
    }
    
    return 0;
}
