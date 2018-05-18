//
//  main.cpp
//  f-求逆元
//
//  Created by ZYJ on 16/7/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

///*
// *  扩展欧几里得法（求ax + by = gcd）
// */
////  返回d = gcd(a, b);和对应于等式ax + by = d中的x、y
//long long extendGcd(long long a, long long b, long long &x, long long &y)
//{
//    if (a == 0 && b == 0)
//    {
//        return -1;  //  无最大公约数
//    }
//    if (b == 0)
//    {
//        x = 1;
//        y = 0;
//        return a;
//    }
//    long long d = extendGcd(b, a % b, y, x);
//    y -= a / b * x;
//    return d;
//}
//
////  求逆元 ax = 1(mod n)
//long long modReverse(long long a, long long n)
//{
//    long long x, y;
//    long long d = extendGcd(a, n, x, y);
//    if (d == 1)
//    {
//        return (x % n + n) % n;
//    }
//    else
//    {
//        return -1;  //  无逆元
//    }
//}

///*
// *  简洁写法
// *  只能求a < m的情况，且a与m互质
// *  求ax = 1(mod m)的x值，即逆元(0 < a < m)
// */
//
//long long inv(long long a, long long m)
//{
//    if (a == 1)
//    {
//        return 1;
//    }
//    return inv(m % a, m) * (m - m / a) % m;
//}

/*
 *  欧拉函数法
 *  mod为素数，而且a和m互质
 */
//  快速幂取模
long long powM(long long a, long long b, long long m)
{
    long long tmp = 1;
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a % m;
    }
    
    tmp = powM(a, a >> 1, m);
    tmp = tmp * tmp % m;
    
    if (b & 1)
    {
        tmp = tmp * a % m;
    }
    
    return tmp;
}

long long inv(long long a, long long m)
{
    return powM(a, m - 2, m);
}

int main()
{
    
}
