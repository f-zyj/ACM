//
//  main.c
//  f-51Nod-1018-排序
//
//  Created by ZYJ on 16/4/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define _MAX 50001

void swap(long *A, int low, int high)
{
    if (low == high)
    {
        return ;
    }
    A[low] ^= A[high];
    A[high] ^= A[low];
    A[low] ^= A[high];
    return ;
}

int Partition(long *A, int low, int high)
{
    long pivotkey = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivotkey)
        {
            high--;
        }
        swap(A, low, high);
        while (low < high && A[low] <= pivotkey)
        {
            low++;
        }
        swap(A, low, high);
    }
    return low;
}

void QSort(long *A, int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = Partition(A, low, high);
        QSort(A, low, pivot - 1);
        QSort(A, pivot + 1, high);
    }
}

void sort(long *A, int N)
{
    QSort(A, 1, N);
}

int main(int argc, const char * argv[])
{
    int N, i = 1;
    long A[_MAX];
    scanf("%d", &N);
    for (; i <= N; i++)
    {
        scanf("%ld", &A[i]);
    }
    
    sort(A, N);
    
    for (i = 1; i <= N; i++)
    {
        printf("%ld\n", A[i]);
    }
    return 0;
}
