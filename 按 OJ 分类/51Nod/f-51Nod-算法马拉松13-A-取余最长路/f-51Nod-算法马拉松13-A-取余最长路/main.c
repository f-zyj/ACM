//
//  main.c
//  f-51Nod-算法马拉松13-A-取余最长路
//
//  Created by ZYJ on 16/4/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define MAX(a, b) a > b ? a : b
#define MAXSIZE 100005

long a[4][MAXSIZE];
long b[MAXSIZE] = {0};   //第一个折点
long p;
long max = 0;

void init(int n)
{
    long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[3][i];
        if (sum >= p)
        {
            sum -= p;
        }
    }

    
    b[1] = (a[2][1] + sum) % p;
    for (int i = 2; i <= n; i++)
    {
        b[i] = (b[i - 1] + a[2][i] - a[3][i - 1] + p) % p;
    }
    return ;
}

void map(int n)
{
    long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = (sum + a[1][i] - a[2][i - 1]) % p;
        for (int j = i; j <= n; j++)
        {
            max = MAX(max, (sum + b[j]) % p);
        }
    }
    return ;
}

int main(int argc, const char * argv[])
{
    int n;
    scanf("%d %ld", &n, &p);
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%ld", a[i] + j);
        }
    }
    
    init(n);
    map(n);
    printf("%ld\n", max);

    return 0;
}
