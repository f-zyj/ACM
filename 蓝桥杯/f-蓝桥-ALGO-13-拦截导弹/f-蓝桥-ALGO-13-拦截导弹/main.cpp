//
//  main.cpp
//  f-蓝桥-ALGO-13-拦截导弹
//
//  Created by ZYJ on 2017/6/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;

const int MAXN = 10;
const int INF = 0x3f3f3f3f;

int a[MAXN], f[MAXN], d[MAXN];
int vis[MAXN];

int bsearch(int *f, int size, int a)
{
    int l = 0, r = size - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a <= f[mid - 1] && a > f[mid])
        {
            return mid;
        }
        else if (a > f[mid])
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

int LIS(int *a, int n)
{
    f[0] = a[0];
    d[0] = 1;
    int j, size = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > f[0])
        {
            j = 0;
        }
        else if (a[i] <= f[size - 1])
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

list<int> li;
list<int> li_;
list<int>::iterator it;

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int cnt = 0, x;
    while (cin >> x)
    {
        a[cnt++] = x;
        li.push_back(x);
    }

    cout << LIS(a, cnt) << '\n';
    
    int res = 0;
    while (!li.empty())
    {
        res++;
        int last = INF;
        li_.clear();
        for (it = li.begin(); it != li.end(); it++)
        {
            if (*it <= last)
            {
                last = *it;
            }
            else
            {
                li_.push_back(*it);
            }
        }
        swap(li, li_);
    }
    
    cout << res << '\n';
    
    return 0;
}
