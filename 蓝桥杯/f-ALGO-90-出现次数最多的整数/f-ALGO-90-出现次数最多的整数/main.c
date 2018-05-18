//
//  main.c
//  f-ALGO-90-出现次数最多的整数
//
//  Created by ZYJ on 16/3/13.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
typedef struct
{
    int num;
    int time;
} NUM[30];

int main(int argc, const char * argv[])
{
    NUM n;
    int N, i = 1, S, j = 0, maxTime = 0, key = 0;
    scanf("%d", &N);
    if (N <= 0)
    {
        return 0;
    }
    scanf("%d", &S);
    n[0].num = S;
    n[0].time = 1;
    for (; i < N; i++)
    {
        n[i].time = 0;
    }
    for (i = 1; i < N; i++)
    {
        scanf("%d", &S);
        if (S != n[j].num)
        {
            n[++j].num = S;
            n[j].time++;
            continue;
        }
        n[j].time++;
    }
    maxTime = n[0].time;
    for (i = 0; i <= j; i++)
    {
        if (n[i].time == 0)
        {
            break;
        }
        if (maxTime < n[i].time)
        {
            key = i;
            maxTime = n[i].time;
        }
    }
    printf("%d\n", n[key].num);
    return 0;
}
