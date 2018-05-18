//
//  main.cpp
//  f-所有数位相加
//
//  Created by ZYJ on 16/7/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 *  所有数位相加
 *  dig(x) := x                         if 0 <= x <= 9
 *  dig(x) := dig(sum of digits of x)   if x >= 10
 */

//  模拟

int dig(int x)
{
    if ( x < 10 )
    {
        return x;
    }
    int sum = 0;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }
    return dig(sum);
}

//  方法二:公式 【不太明白...】

int dig_(int x)
{
    return (x + 8) % 9 + 1;
}

int main(int argc, const char * argv[])
{
    int a;
    while (cin >> a)
    {
        cout << dig(a) << '\n';
        cout << dig_(a) << '\n';
    }
    std::cout << "Hello, World!\n";
    return 0;
}
