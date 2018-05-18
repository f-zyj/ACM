//
//  main.c
//  f-蓝桥杯省A-最大比例
//
//  Created by ZYJ on 16/4/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define _MAX 1000000000000

int N, p = 0;
long long M[100], nAtor[100], dAtor[100];
double W[100];

//M原数据排序去重
void sequenceM()
{
    int len = N, i , j;
    for (i = 0; i < N - 1; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (M[i] > M[j])
            {
                M[i] ^= M[j];
                M[j] ^= M[i];
                M[i] ^= M[j];
            }
            else if (M[i] == M[j])
            {
                M[j] = _MAX;
                len--;
            }
        }
    }
    N = len;
//    for (i = 0; i < N; i++)
//    {
//        printf("%lld ", M[i]);
//    }
//    printf("\n");
    return ;
}

//约分
void reduce(int i)
{
    long long j = M[i];
    for (; j > 0; j--)
    {
        if (M[i] % j == 0 && M[i + 1] % j == 0)
        {
            dAtor[i] = M[i] / j;
            nAtor[i] = M[i + 1] / j;
            return ;
        }
    }
    return ;
}

//W数据排序去重
void sequenceW()
{
    int len = N - 1, i , j;
    for (i = 0; i < N - 2; i++)
    {
        for (j = i + 1; j < N - 1; j++)
        {
            if (W[i] > W[j])
            {
                double tempW = W[i];
                W[i] = W[j];
                W[j] = tempW;
                long long tempN = nAtor[i];
                nAtor[i] = nAtor[j];
                nAtor[j] = tempN;
                long long tempD = dAtor[i];
                dAtor[i] = dAtor[j];
                dAtor[j] = tempD;
            }
            else if (W[i] == W[j])
            {
                W[j] = _MAX;
                len--;
            }
        }
    }
    N = len;
//    for (i = 0; i < N; i++)
//    {
//        printf("%g %lld %lld\n", W[i], nAtor[i], dAtor[i]);
//    }
    return ;
}

//分别求分子、分母基数
long long NDbase(long long *Ator)
{
    long long flag = Ator[0];
    if (N == 1)
    {
        return flag;
    }
    int i = 1, j, tag = 0;  //标记flag是否为符合基数要求
    for (; i < N; i++)
    {
        for (j = 2; pow((double)flag, (double)j) <= Ator[i]; j++)
        {
            if (pow((double)flag, (double)j) == Ator[i])
            {
                tag = 1;
                break;
            }
        }
        if (tag == 1)
        {
            tag = 0;
            continue;
        }
        break;
    }
    if (i == N)
    {
        return flag;
    }
    tag = 0;
    for (flag = Ator[0] / 2; flag > 0; flag--)
    {
        for (i = 0; i < N; i++)
        {
            for (j = 2; pow((double)flag, (double)j) <= Ator[i]; j++)
            {
                if (pow((double)flag, (double)j) == Ator[i])
                {
                    tag = 1;
                    break;
                }
            }
            if (tag == 1)
            {
                tag = 0;
                continue;
            }
            break;
        }
        if (i == N)
        {
            return flag;
        }
    }
    return 0;
}

//求最大基数
void base()
{
    long long N, D;   //最大比例的分子和分母
    N = NDbase(nAtor);
    D = NDbase(dAtor);
    printf("%lld/%lld\n", N, D);
    return ;
}
//求最大比例
void pro()
{
    int i;
    sequenceM();
    for (i = 0; i < N - 1; i++)
    {
        W[i] = M[i + 1] * 1.0 / M[i];
        reduce(i);
    }
    sequenceW();
    base();
    return ;
}

int main(int argc, const char * argv[])
{
    int i = 0;
    scanf("%d", &N);
    for (; i < N; i++)
    {
        scanf("%lld", &M[i]);
    }
    pro();
    return 0;
}
