//
//  main.cpp
//  f-51Nod-1406-与查询
//
//  Created by ZYJ on 2016/10/17.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

#define ll long long
#define clr(a, b) memset(a, b, sizeof(a))

using namespace std;

const int MAXN = 1e6 + 1;

// 1000001: 1111 0100 0010 0100 0001 (20位)

void in(int &res)
{
    //  输入外挂
    res = 0;
    char ch;
    if (ch >= '0' && ch <= '9')
    {
        res = ch - '0';
    }
    while ((ch = getchar()) >= '0' && ch <= '9')
    {
        res = res * 10 + (ch - '0');
    }
}

void out(int a)
{
    //  输出外挂
    if (a < 0)
    {
        putchar('-');
        a = -a;
    }
    if (a >= 10)
    {
        out(a / 10);
    }
    putchar(a % 10 + '0');
}

int cnt[MAXN + 10];

int main()
{
    int n, MAX, x;
    clr(cnt, 0);
    
    in(n);
    MAX = 0;
    for (int i = 0; i < n; i++)
    {
        in(x), MAX = max(x, MAX);
        cnt[x]++;
    }
    
    int MAX_DIG = 0;
    int tag = MAX;
    
    while (tag >>= 1)
    {
        MAX_DIG++;
    }
    
    for (int j = MAX_DIG; j >= 0 ; j--)
    {
        for (int i = 1; i <= MAX; i++)
        {
            if (i & (1 << j))
            {
                cnt[i - (1 << j)] += cnt[i];
            }
        }
    }
    cnt[0] = n;
    
    for (int i = 0; i < MAXN; i++)
    {
        out(cnt[i]);
        puts("");
    }

    return 0;
}
