//
//  main.cpp
//  f-SHU-“盛大游戏杯”第15届上海大学程序设计联赛夏季赛暨上海高校金马五校赛-K-购买装备
//
//  Created by ZYJ on 2017/7/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

struct equ
{
    int a, b;
} e[MAXN], e_[MAXN];

int tmp,n,m;
int mx;

bool cmp(const equ &x, const equ &y)
{
    return x.b < y.b;
}

bool cmp_(const equ &x, const equ &y)
{
    return x.a < y.a;
}

int check(int x)
{
    int m = tmp;
    int res = 0;
    for (int i = 0; i < n && m >= e[i].b && res < mx; i++)
    {
        if (e[i].a >= x)
        {
            res++;
            m -= e[i].b;
        }
    }
    if (res == mx)
    {
        return 1;
    }
    
    return 0;
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

template <class T>
inline void print_d(T x)
{
    if (x > 9)
    {
        print_d(x / 10);
    }
    putchar(x % 10 + '0');
}

int main()
{
    int T;
    scan_d(T);
    while (T--)
    {
        scan_d(n), scan_d(m);
        tmp = m;
        for (int i = 0; i < n; i++)
        {
            scan_d(e[i].a), scan_d(e[i].b);
            e_[i] = e[i];
        }
        sort(e, e + n, cmp);
        sort(e_, e_ + n, cmp_);
        
        mx = 0;
        for (int i = 0; i < n && m >= e[i].b; i++)
        {
            mx++;
            m -= e[i].b;
        }
        printf("%d ", mx);
        
        int l = 0, r = n - 1, m;
        int res = e_[0].a;
        while (l <= r)
        {
            m = (l + r) >> 1;
            if (check(e_[m].a))
            {
                res = e_[m].a;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        
        printf("%d\n",res);
    }
    
    return 0;
}
