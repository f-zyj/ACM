//
//  main.cpp
//  f-51Nod-1519-拆方块
//
//  Created by ZYJ on 2017/7/8.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 5;

int n;
int h[MAXN];
int a[MAXN];
int b[MAXN];

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            scan_d(h[i]);
        }
        
        a[0] = b[n - 1] = 1;
        for (int i = 1; i < n; i++)
        {
            a[i] = min(a[i - 1] + 1, h[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            b[i] = min(b[i + 1] + 1, h[i]);
        }
        
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res = max(res, min(a[i], b[i]));
        }
        printf("%d\n", res);
    }
    
    return 0;
}
