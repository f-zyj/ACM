//
//  main.cpp
//  f-51Nod-1800-汉诺塔
//
//  Created by ZYJ on 2017/7/30.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 1111;

int len;
char n[MAXN];
char m[MAXN];
int a[MAXN];
int f[MAXN];

int cal()
{
    int tot = 0;
    for (int i = 0; i < len; i++)
    {
        tot = tot * 10 + n[i] - '0';
    }
    
    return tot;
}

int main()
{
    scanf("%s%s", n, m);
    
    len = (int)strlen(m);
    for (int i = 0; i < len; i++)
    {
        a[len - i] = m[i] - '0';
    }
    
    f[1] = 1;
    int tot = 1, cnt = 0;
    for (; len > 1 || a[1]; cnt++)
    {
        if (a[1] & 1)
        {
            for (int i = 1; i <= tot; i++)
            {
                f[i] *= 2;
            }
            for (int i = 1; i <= tot; i++)
            {
                if (f[i] > 9)
                {
                    f[i + 1]++;
                    f[i] -= 10;
                }
            }
            if (f[tot + 1])
            {
                tot++;
            }
        }
        for (int i = len, z = 0; i; i--)
        {
            z = z * 10 + a[i];
            a[i] = z >> 1;
            z &= 1;
        }
        if (!a[len])
        {
            len--;
        }
    }
    
    len = (int)strlen(n);
    if (len <= 3 && cnt > cal())
    {
        puts("0");
    }
    else
    {
        for (int i = tot; i; i--)
        {
            printf("%c", f[i] + '0');
        }
        putchar(10);
    }
    
    return 0;
}
