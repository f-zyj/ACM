//
//  main.c
//  f-51Nod-1049-最大子段和
//
//  Created by ZYJ on 16/4/18.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
//#define _MAX 50001
//#define max(a, b) a > b ? a : b
//
//long long MaxSub(long *a, int N)
//{
//    long long All[N], Start[N], i;
//    Start[0] = a[0];
//    All[0] = a[0];
//    for (i = 1; i < N; i++)
//    {
//        Start[i] = max(a[i], Start[ i - 1] + a[i]);
//        All[i] = max(Start[i], All[i - 1]);
//    }
//    if (All[N - 1] < 0)
//    {
//        return 0;
//    }
//    return All[N - 1];
//    
//}
//
//int main(int argc, const char * argv[])
//{
//    int N, i;
//    long a[_MAX];
//    scanf("%d", &N);
//    for (i = 0; i < N; i++)
//    {
//        scanf("%ld", &a[i]);
//    }
//    printf("%lld\n", MaxSub(a, N));
//    return 0;
//}


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX(a,b) ((a>b) ? (a) : (b))
int N;
int a[50001];

long long solve()
{
    long long i,s=0,max=0;
    for(i=0; i<N; ++i)
    {
        s+=a[i];
        if(s>0)
            max = MAX(max, s);
        else
            s = 0;
    }
    return max;
}

int main()
{
    int i;
    scanf("%d", &N);
    for(i=0; i<N; ++i)
    {
        scanf("%d", &a[i]);
    }
    printf("%lld", solve());
    return 0;
}