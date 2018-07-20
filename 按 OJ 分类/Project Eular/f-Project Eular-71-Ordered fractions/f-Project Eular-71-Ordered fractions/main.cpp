//
//  main.cpp
//  f-Project Eular-71-Ordered fractions
//
//  Created by ZYJ on 2018/7/20.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <iostream>

using namespace std;

/*
 *  428570/999997
 *  a/b 为 ans，初始 0/1
 *  设 p/q < 3/7，则 7p < 3q
 *  分母减小，7p < 3q - 1，则 p 最大为 floor((3q - 1) / 7)
 *  枚举 q，取小于 3/7 的最大 p/q 给 a/b
 */
void solve(int x, int y, int &a, int &b, int d)
{
    for (int q = 2; q <= d; q++)
    {
        int p = (int)((x * q - 1) / y);
        if (a * q < b * p)
        {
            a = p;
            b = q;
        }
    }
}

int main()
{
    int a = 0, b = 1, d = 1000000;
    int x = 3, y = 7;
    
    solve(x, y, a, b, d);
    
    printf("%d/%d\n", a, b);
    
    return 0;
}
