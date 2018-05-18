//
//  main.cpp
//  f-蓝桥-ALGO-16-进制转换
//
//  Created by ZYJ on 2017/6/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

stack<char> sc;

int main()
{
    int N, b;
    scanf("%d%d",&N, &b);
    
    int a = N;
    if (-b <= 9)
    {
        while (a)
        {
            if (a % b >= 0)
            {
                sc.push('0' + a % b);
                a /= b;
            }
            else
            {
                sc.push('0' + a % b - b);
                a = a / b + 1;
            }
        }
    }
    else
    {
        while (a)
        {
            if (a % b >= 0)
            {
                if (a % b <= 9)
                {
                    sc.push('0' + a % b);
                }
                else
                {
                    sc.push('A' + (a % b - 10));
                }
                a /= b;
            }
            else
            {
                if (a % b - b <= 9)
                {
                    sc.push('0' + a % b - b);
                }
                else
                {
                    sc.push('A' + a % b - b - 10);
                }
                a = a / b + 1;
            }
        }
    }
    
    printf("%d=", N);
    while (!sc.empty())
    {
        a = sc.top();
        sc.pop();
        putchar(a);
    }
    printf("(base%d)\n", b);
    
    return 0;
}
