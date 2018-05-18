//
//  main.cpp
//  f-EOJ-大学生程序设计邀请赛（华东师范大学）-E-黑心啤酒厂
//
//  Created by ZYJ on 2017/5/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

long long gcd(long long x, long long y)
{
    if (!x || !y)
    {
        return x > y ? x : y;
    }
    for (long long t; t = x % y, t; x = y, y = t);
    return y;
}

int main(int argc, const char * argv[])
{
    long long x, n;
    while (cin >> x >> n)
    {
        for (int i = 2; i <= n; i++)
        {
            long long gd = gcd(x, i);
            long long cnt = i / gd;
            cout << cnt << '\n';
        }
    }
    
    return 0;
}
