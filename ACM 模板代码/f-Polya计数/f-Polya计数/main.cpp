//
//  main.cpp
//  f-Polya计数
//
//  Created by ZYJ on 16/7/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 *  c种颜色的珠子，组成长为s的项链，项链没有方向和起始位置
 */
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main(int argc, const char * argv[])
{
    int c, s;
    while (cin >> c >> s)
    {
        int k;
        long long p[64];
        p[0] = 1;                   // power of c
        for (k = 0; k < s; k++)
        {
            p[k + 1] = p[k] * c;
        }
        // reflection part
        long long count = s & 1 ? s * p[s / 2 + 1] : (s / 2) * (p[s / 2] + p[s / 2 + 1]);
        // rotation part
        for (k = 1 ; k <= s ; k++)
        {
            count += p[gcd(k, s)];
            count /= 2 * s;
        }
        cout << count << '\n';
    }
    return 0;
}