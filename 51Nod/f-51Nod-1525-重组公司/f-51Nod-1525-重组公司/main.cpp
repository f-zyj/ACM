//
//  main.cpp
//  f-51Nod-1525-重组公司
//
//  Created by ZYJ on 2017/7/9.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 2e5 + 10;

int n, q;
int fat[MAXN];
int pre[MAXN];

int find(int x)
{
    return x == fat[x] ? x : fat[x] = find(fat[x]);
}

void merge_1(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        fat[y] = x;
    }
}

void merge_2(int x, int y)
{
    for (int i = y, p; i >= x && pre[i] >= x; i = p)
    {
        p = pre[i];
        fat[find(p)] = fat[find(i)];
        pre[i] = pre[p];
    }
}

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

void init()
{
    for (int i = 1; i <= n; ++i)
    {
        fat[i] = i;
        pre[i] = i - 1;
    }
}

int main()
{
    scan_d(n), scan_d(q);
    
    init();
    
    int t, x, y;
    while (q--)
    {
        scan_d(t), scan_d(x), scan_d(y);
        
        if (t == 1)
        {
            merge_1(x, y);
        }
        else if (t == 2)
        {
            merge_2(x, y);
        }
        else
        {
            if (find(x) == find(y))
            {
                puts("YES");
            }
            else
            {
                puts("NO");
            }
        }
    }
    
    return 0;
}
