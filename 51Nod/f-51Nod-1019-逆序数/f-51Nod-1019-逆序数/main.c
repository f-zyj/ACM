//
//  main.c
//  f-51Nod-1009-逆序数
//
//  Created by ZYJ on 16/4/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
//#define _MAX 50001
//long ans = 0;
//
////将有序的A[first..mid]和A[mid + 1..last]归并为有序的B[first..last]
//void Merge(long *A, long *B, int first, int mid, int last)
//{
//    int i = first, j = mid + 1;
//    int cur = first;
//    while (i <= mid && j <= last)
//    {
//        if (A[i] <= A[j])
//        {
//            B[cur++] = A[i++];
//        }
//        else
//        {
//            B[cur++] = A[j++];
//            ans += mid - i + 1; //核心代码，逆序数增加
//        }
//    }
//    while (i <= mid)
//    {
//        B[cur++] = A[i++];
//    }
//    while (j <= last)
//    {
//        B[cur++] = A[j++];
//    }
//}
//
////将A[first..last]归并排序为B[first..last]
//void MSort(long *A, long *B, int first, int last)
//{
//    int mid;
//    if (first < last)
//    {
//        mid = (first + last) / 2;
//        MSort(B, A, first, mid);
//        MSort(B, A, mid + 1, last);
//        Merge(A, B, first, mid, last);
//    }
//    return ;
//}
//
//int main(int argc, const char * argv[])
//{
//    int N, i = 1;
//    long A[_MAX];
//    long B[_MAX];
//    scanf("%d", &N);
//    for (; i <= N; i++)
//    {
//        scanf("%ld", &A[i]);
//        B[i] = A[i];
//    }
//    
//    MSort(A, B, 1, N);
//    
//    printf("%ld\n", ans);
//    return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//#define _MAX 50001
//long ans = 0;
//
////将有序的A[first..mid]和A[mid + 1..last]归并为有序的B[first..last]
//void Merge(long *A, long *B, int first, int mid, int last)
//{
//    int i = first, j = mid + 1;
//    int cur = first;
//    while (i <= mid && j <= last)
//    {
//        if (A[i] <= A[j])
//        {
//            B[cur++] = A[i++];
//        }
//        else
//        {
//            B[cur++] = A[j++];
//            ans += mid - i + 1; //核心代码，逆序数增加
//        }
//    }
//    while (i <= mid)
//    {
//        B[cur++] = A[i++];
//    }
//    while (j <= last)
//    {
//        B[cur++] = A[j++];
//    }
//}
//
////将A中相邻长度为s的子序列两两归并到B中
//void MergePass(long *A, long *B, int k, int N)
//{
//    int i = 1, j;
//    while (i <= N - 2 * k + 1)
//    {
//        Merge(A, B, i, i + k - 1, i + 2 * k - 1);
//        i = i + 2 * k;
//    }
//    if (i < N - k + 1)
//    {
//        Merge(A, B, i, i + k - 1, N);
//    }
//    else
//    {
//        for (j = i; j <= N; j++)
//        {
//            B[j] = A[j];
//        }
//    }
//}
//
//void MSort(long *A, int N)
//{
//    long *B = (long *)malloc(sizeof(long) * N);
//    int k = 1;
//    while (k < N)
//    {
//        MergePass(A, B, k, N);
//        k *= 2;
//        MergePass(B, A, k, N);
//        k *= 2;
//    }
//    return ;
//}
//
//int main(int argc, const char * argv[])
//{
//    int N, i = 1;
//    long A[_MAX];
//    scanf("%d", &N);
//    for (; i <= N; i++)
//    {
//        scanf("%ld", &A[i]);
//    }
//    
//    MSort(A, N);
//    
//    printf("%ld\n", ans);
//    return 0;
//}


#include <stdio.h>
#include <stdlib.h>
int count=0;

void merge(int *a, int *b, int m, int mid, int n)
{
    int i,j,s;
    i=s=m;
    j = mid+1;
    while(i<=mid&&j<=n)
    {
        if(a[i]<=a[j])
            b[s++] = a[i++];
        else
        {
            b[s++] = a[j++];
            count += (mid-i+1);
        }
    }
    while(i<=mid)
        b[s++] = a[i++];
    while(j<=n)
        b[s++] = a[j++];
    return ;
}

void Mergesort(int *a, int *b, int i, int j)
{
    int mid;
    if(i < j)
    {
        mid = (i+j)/2;
        Mergesort(b, a, i, mid);
        Mergesort(b, a, mid+1, j);
        merge(a,b,i,mid,j);
    }
    return ;
}

int main()
{
    int N = 0;
    int i;
    int a[50001];
    int b[50001];
    scanf("%d", &N);
    for(i=0; i<N; ++i)
    {
        scanf("%d", &a[i]); b[i] = a[i];
    }
    Mergesort(a, b, 0, N - 1);
    printf("%d\n", count);
    return 0;
}
