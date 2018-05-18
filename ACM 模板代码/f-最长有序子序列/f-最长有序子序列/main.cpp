//
//  main.cpp
//  f-最长有序子序列
//
//  Created by ZYJ on 16/7/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

/*
 *  递增/递减/非递增/非递减
 */
const int N = 1001;
int a[N], f[N], d[N];   //  d[i]用于记录a[0...i]的最大长度

int bsearch(const int *f, int size, const int &a)
{
    int l = 0, r = size - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a > f[mid - 1] && a <= f[mid])
        {
            return mid; //  > && <= 换为: >= && <
        }
        else if (a < f[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int LIS(const int *a, const int &n)
{
    int i, j, size = 1;
    f[0] = a[0];
    d[0] = 1;
    for (i = 1; i < n; ++i)
    {
        if (a[i] <= f[0])               //  <= 换成 <
        {
            j = 0;
        }
        else if (a[i] > f[size - 1])    //  > 换成 >=
        {
            j = size++;
        }
    }
    return size;
}

int main()
{
    int i, n;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        printf("%d\n", LIS(a, n));      // 求最大递增 / 上升子序列(如果为最大非降子序列,只需把上面的注释部分给与替换)
    }
    return 0;
}