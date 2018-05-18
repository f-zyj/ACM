//
//  main.c
//  f-NYOJ-18-The Triangle
//
//  Created by ZYJ on 16/5/18.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define MAX(a, b) a > b ? a : b

int main(int argc, const char * argv[])
{
    int N;
    int num[5051], value[5051];
    
    while(~scanf("%d", &N))
    {
        int key = 1;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                scanf("%d", num + key);
                value[key] = num[key];
                key++;
            }
        }
        
        for (int i = N - 1; i > 0; i--)
        {
            for (int j = i; j > 0; j--)
            {
                value[i * (i - 1) / 2 + j] += MAX(value[(1 + i) * i / 2 + j], value[(1 + i) * i / 2 + j + 1]);
            }
        }
        
        printf("%d\n", value[1]);
    }
    
    return 0;
}
