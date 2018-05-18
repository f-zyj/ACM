//
//  main.cpp
//  f-51Nod-1417-天堂里的游戏
//
//  Created by ZYJ on 16/8/4.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

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
    int T;
    cin >> T;
    
    long long A, B;
    while (T--)
    {
        cin >> A >> B;
        long long C = (A + B) / 2;
        //  经过样例可以推导出公式n/m
        //  An-C(m-n) = B(m-n)-Cn
        //  m = A+B+2C n = B+C
        long long m = A + B + 2 * C;
        long long n = B + C;
        long long G = gcd(n, m);  //  最大公约数
        printf("%lld/%lld\n", n / G, m / G);
    }
    
    return 0;
}
