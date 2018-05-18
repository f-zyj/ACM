//
//  main.c
//  f-51Nod-1066-Bash游戏
//
//  Created by ZYJ on 16/4/20.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#define _MAX 10000
int a[_MAX];
int b[_MAX];

//N取模(K + 1)等于0则后手赢，否则先手赢
//N % (K + 1) == 0 说明最后一定会遇见[K + 1]的情况，即后手赢
//否则说明最后会遇见[1, ..., k]的情况，即先手赢
int bash(int N, int K)
{
    if (N % (K + 1) == 0)
        return 2;
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
            printf("A\n");
        }
        else
        {
            printf("B\n");
        }
    }
    return 0; 
}