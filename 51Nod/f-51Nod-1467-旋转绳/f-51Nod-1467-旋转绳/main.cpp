//
//  main.cpp
//  f-51Nod-1467-旋转绳
//
//  Created by ZYJ on 2017/7/1.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 10;

int n, m;
int pos[MAXN];

struct snag
{
    int x, pos;
    bool operator < (const snag &b) const
    {
        return x < b.x;
    }
} sg[MAXN];

int bs(int x)
{
    int l = 1, r = n, res = n + 1;
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (sg[m].x > x)
        {
            res = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return res;
}

template <class T>
inline bool scan_d(T &ret)
{
    char c;
    int sgn;
    if (c = getchar(), c == EOF)
    {
        return 0; //EOF
    }
    while (c != '-' && (c < '0' || c > '9'))
    {
        c = getchar();
    }
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0');
    }
    ret *= sgn;
    return 1;
}

template <class T>
inline void out_d(T a)
{   //  输出外挂
    if (a < 0)
    {
        putchar('-');
        a = -a;
    }
    if (a >= 10)
    {
        out_d(a / 10);
    }
    putchar(a % 10 + '0');
}

int main()
{
    scan_d(n), scan_d(m);
    for (int i = 1; i <= n; i++)
    {
        scan_d(sg[i].x);
        sg[i].pos = i;
    }
    sort(sg + 1, sg + n + 1);
    for (int i = 1; i <= n; i++)
    {
        pos[sg[i].pos] = i;
    }
    
    int x, flag, now, len;
    for (int i = 1; i <= m; i++)
    {
        scan_d(x), scan_d(len);
        
        x = pos[x];
        flag = 1;
        now = bs(len + sg[x].x) - 1;
        len -= sg[now].x - sg[x].x;
        flag = -1;
        x = now;
        while (len)
        {
            if (flag == 1)
            {
                now = bs(len + sg[x].x) - 1;
            }
            else
            {
                now = bs(sg[x].x - len);
            }
            if (now && sg[now - 1].x == sg[x].x - len)
            {
                now--;
            }
            if (now == x)
            {
                break;
            }
            int y = abs(sg[now].x - sg[x].x);
            if ((len / y) & 1)
            {
                x = now;
                flag = -flag;
            }
            len %= y;
        }
        
        out_d(sg[x].pos);
        putchar(10);
    }
    
    return 0;
}
