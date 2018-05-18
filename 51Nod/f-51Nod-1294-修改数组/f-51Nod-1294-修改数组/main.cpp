//
//  main.cpp
//  f-51Nod-1294-修改数组
//
//  Created by ZYJ on 2016/10/19.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 10;

int A[MAXN];

/*
 *  递增/递减/非递增/非递减
 */
int f[MAXN];
int d[MAXN];   //  d[i]用于记录a[0...i]的最大长度

int bsearch(const int *f, int size, const int &a)
{
    int l = 0, r = size - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a >= f[mid - 1] && a < f[mid])
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

int LIS(const int *a, const int &n)
{
    int i, j, size = 1;
    f[0] = a[0];
    d[0] = 1;
    for (i = 1; i < n; ++i)
    {
        if (a[i] < f[0])
        {
            j = 0;
        }
        else if (a[i] >= f[size - 1])
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

int main(int argc, const char * argv[])
{
     freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int N;
    cin >> N;
    
    int a;
    int pos = 0;
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &a);
        a -= i;
        if (a >= 0)
        {
            A[pos++] = a;
        }
    }
    
    if (pos == 0)
    {
        cout << N << '\n';
    }
    else
    {
        cout << N - LIS(A, pos) << '\n';
    }
    
    return 0;
}
