//
//  main.cpp
//  f-SHU-“盛大游戏杯”第15届上海大学程序设计联赛夏季赛暨上海高校金马五校赛-F-A序列
//
//  Created by ZYJ on 2017/7/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 *  递增（默认）
 *  递减
 *  非递增
 *  非递减 (1)>= && <  (2)<  (3)>=
 */
const int MAXN = 5e5 + 10;

int a[MAXN], f[MAXN], d[MAXN], d_[MAXN];   //  d[i] 用于记录 a[0...i] 以 a[i] 结尾的最大长度

int bsearch(const int *f, int size, const int &a)
{
    int l = 0, r = size - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a > f[mid - 1] && a <= f[mid])  //  (1)
        {
            return mid;
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

int LIS(const int *a, int *d, const int &n)
{
    int i, j, size = 1;
    f[0] = a[0];
    d[0] = 1;
    for (i = 1; i < n; ++i)
    {
        if (a[i] <= f[0])               //  (2)
        {
            j = 0;
        }
        else if (a[i] > f[size - 1])    //  (3)
        {
            j = size++;
        }
        else
        {
            j = bsearch(f, size, a[i]);
        }
        f[j] = a[i];
        d[i] = j + 1;
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
        LIS(a, d, n);
        reverse(a, a + n);
        LIS(a, d_, n);
        
        int res = 1;
        for (int i = 0; i < n; i++)
        {
            if (d[i] <= d_[n - i - 1])
            {
                res = max(res, (d[i] << 1) - 1);
            }
            else
            {
                res = max(res, (d_[n - i - 1] << 1) - 1);
            }
        }
        
        cout << res << '\n';
    }
    
    return 0;
}
