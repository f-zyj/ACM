//
//  main.cpp
//  f-NYOJ-108-士兵杀敌（一）
//
//  Created by ZYJ on 16/6/14.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

const int MAXN = 1000005;
int solider[MAXN];
int sum[MAXN] = {0};

void cinDiy(int &ret)
{
    char c;
    ret=0;
    while((c = getchar()) < '0' || c > '9');
    while(c >= '0' && c <= '9')
        ret = ret * 10 + (c - '0'), c = getchar();
    return ;
}

void coutDiy(int a)
{    //输出外挂
    if(a >= 10)
        coutDiy(a / 10);
    putchar(a % 10 + '0');
    return ;
}

int main(int argc, const char * argv[])
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int N, M;
    cinDiy(N);
    cinDiy(M);
    int start;
    int end;
    for (int i = 1; i <= N; i++)
    {
        cinDiy(solider[i]);
        sum[i] = solider[i] + sum[i - 1];
    }
    for (int i = 1; i <= M; i++)
    {
        cinDiy(start);
        cinDiy(end);
        coutDiy(sum[end] - sum[start - 1]);
        putchar('\n');
    }
    
    return 0;
}


//#include<stdio.h>
//
//#define MAX 1000000
//int a[MAX] = {0};
//int b[MAX] = {0};
//
//int main()
//{
//    int N, M, sum;
//    int i, p, q;
//    scanf("%d",&N);
//    scanf("%d",&M);
//    for(i = 1; i <= N; i++)
//    {
//        scanf("%d", &a[i]);
//        b[i] = a[i] + b[i - 1];
//    }
//    while(M--)
//    {
//        sum = 0;
//        scanf("%d%d", &p, &q);
//        sum = b[q] - b[p - 1];//p到q的和
//        printf("%d\n", sum);
//    }
//    return 0;
//}