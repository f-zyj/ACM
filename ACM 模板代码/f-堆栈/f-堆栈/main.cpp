//
//  main.cpp
//  f-堆栈
//
//  Created by ZYJ on 16/7/23.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

const int MAXSIZE = 10000;
int a[MAXSIZE], heapsize;

inline void swap(int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    return ;
}

inline int Parent(int i)
{
    return i >> 1;
}

inline int Left(int i)
{
    return 1 << i;
}

inline int Right(int i)
{
    return (1 << i) + 1;    //  保持堆的性质
}

void MaxHeapify(int i)
{
    int l = Left(i), r = Right(i), largest;
    if (l <= heapsize && a[l] > a[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (r <= heapsize && a[r] > a[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(i, largest);
        MaxHeapify(largest);
    }
    return ;
}

void BuildMaxHeap(int *arr, int n)
{
    heapsize = n;
    for (int i = heapsize / 2; i > 0; --i)
    {
        MaxHeapify(i);
    }
    return ;
}

void HeapSort(int *arr, int n)
{
    BuildMaxHeap(arr, n);
    for (int i = n; i > 1; --i)
    {
        swap(1, i);
        heapsize--;
        MaxHeapify(1);
    }
    return ;
}