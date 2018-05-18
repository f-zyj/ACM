//
//  main.cpp
//  f-NYOJ-116-士兵杀敌（二）
//
//  Created by ZYJ on 16/6/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int num[1000002];
int tree[1000002];
int n, m;

void cinDiy(int &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ;
}

void coutDiy(int a)
{
    if (a >= 10)
    {
        coutDiy(a / 10);
    }
    putchar(a % 10 + '0');
    return ;
}

int lowbit(int x)
{
    return x & (-x);
}

void add(int k, int h)
{
    while(k <= n)
    {
        tree[k] += h;
        k += lowbit(k);
    }
}

int sum(int k)
{
    int res = 0;
    while(k > 0)
    {
        res += tree[k];
        k -= lowbit(k);
    }
    return res;
}

int main()
{
    char ch[6];
    int a, b;
    
    cinDiy(n);
    cinDiy(m);
    
    for(int i = 1; i <= n; i++)
    {
        cinDiy(num[i]);
    }
    
    for(int i = 1; i <= n; i++)
    {
        add(i, num[i]);
    }
    
    while(m--)
    {
        scanf("%s", ch);
        cinDiy(a);
        cinDiy(b);
        if(ch[0] == 'Q')
        {
            coutDiy(sum(b) - sum(a - 1));
            putchar('\n');
        }
        else
        {
            add(a, b);
        }
    }
    
    return 0;
}