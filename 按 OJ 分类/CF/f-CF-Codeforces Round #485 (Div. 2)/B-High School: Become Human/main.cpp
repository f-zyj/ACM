//
//  main.cpp
//  f-CF-Codeforces Round #485 (Div. 2)
//
//  Created by ZYJ on 2018/5/29.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long x, y;

int main(int argc, const char * argv[])
{
#if DEBUG
    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    freopen("/Users/zyj/Desktop/output.txt", "w", stdout);
#endif

    cin >> x >> y;

    if (y * log10(x) < x * log10(y))
    {
        cout << "<" << '\n';
    }
    else if (y * log10(x) > x * log10(y))
    {
        cout << ">" << '\n';
    }
    else
    {
        cout << "=" << '\n';
    }
    
    return 0;
}
