//
//  main.cpp
//  f-HDU-1576-A÷B
//
//  Created by ZYJ on 2017/9/4.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MOD = 9973;

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

int modeq(int a, int b, int n)
{
    int x, y;
    extgcd(b, a, x, y);     //  bx + ay = gcd(b, a) = 1
    x = (1ll * x * n % a + a) % a;
    
    return x;
}

int n, B;

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> n >> B;
    
        printf("%d\n", modeq(MOD, B, n));
    }
    
    return 0;
}
