//
//  main.cpp
//  f-HDU-5512-Pagodas
//
//  Created by ZYJ on 2017/9/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

//  AC 模版通过
#include <iostream>

using namespace std;

int n, a, b;

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
    int T;
    cin >> T;
    
    int res, x, y;
    for (int i = 1; i <= T; i++)
    {
        cin >> n >> a >> b;
        
        res = extgcd(a, b, x, y);
        
        if ((n / res) & 1)
        {
            printf("Case #%d: Yuwgna\n", i);
        }
        else
        {
            printf("Case #%d: Iaka\n", i);
        }
    }
    
    return 0;
}
