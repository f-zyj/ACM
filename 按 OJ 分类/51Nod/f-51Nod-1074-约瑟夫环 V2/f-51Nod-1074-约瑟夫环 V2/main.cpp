//
//  main.cpp
//  f-51Nod-1074-约瑟夫环 V2
//
//  Created by ZYJ on 2017/9/14.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

unsigned long long n, k;

int main()
{
    cin >> n >> k;
    
    long long y = k % 2;
    long long x = 2, t = 0;
    long long z1 = y, z2 = x;
    while (x <= n)
    {
        z1 = y;
        z2 = x;
        t = (x - y) / (k - 1);
        if (t == 0)
        {
            t++;
        }
        y = y + t * k - ((y + t * k) / (x + t)) * (x + t);
        x += t;
    }
    
    cout << (z1 + (n - z2) * k) % n + 1 << endl;
    
    return 0;
}
