//
//  main.cpp
//  f-HDU-1846-Brave Game
//
//  Created by ZYJ on 2017/9/21.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

#define _MAX 1111

int a[_MAX];
int b[_MAX];

int bash(int N, int K)
{
    if (N % (K + 1) == 0)
    {
        return 2;
    }
    return 1;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d%d", a + i, b + i);
    }
    for (int i = 0; i < T; i++)
    {
        if (bash(a[i], b[i]) == 1)
        {
            printf("first\n");
        }
        else
        {
            printf("second\n");
        }
    }
    
    return 0;
}
