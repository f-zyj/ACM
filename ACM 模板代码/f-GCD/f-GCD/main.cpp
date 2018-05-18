//
//  main.cpp
//  f-GCD
//
//  Created by ZYJ on 16/6/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

//  GCD最大公约数
int gcd(int x, int y)
{
    if (!x || !y)
    {
        return x > y ? x : y;
    }
    for (int t; t = x % y, t; x = y, y = t);
    return y;
}

//  快速GCD
int kgcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    if (!(a & 1) && !(b & 1))
    {
        return kgcd(a >> 1, b >> 1) << 1;
    }
    else if (!(b & 1))
    {
        return kgcd(a, b >> 1);
    }
    else if (!(a & 1))
    {
        return kgcd(a >> 1, b);
    }
    else
    {
        return kgcd(abs(a - b), min(a, b));
    }
}

//  扩展GCD

/*
 *  求x，y使得gcd(a, b) = a * x + b * y;
 */
int extgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = extgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return d;
}

int main(int argc, const char * argv[])
{
    int a, b;
    while (cin >> a >> b)
    {
        cout << gcd(a, b) << '\n';
    }
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
