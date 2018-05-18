//
//  main.cpp
//  f-51Nod-1136-欧拉函数
//
//  Created by ZYJ on 16/7/26.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

long long euler(long long x)
{
    long long i, res = x;
    for (i = 2; i < (int)sqrt(x * 1.0) + 1; i++)
    {
        if (!(x % i))
        {
            res = res / i * (i - 1);
            while (!(x % i))
            {
                x /= i;     //  保证i一定是素数
            }
        }
    }
    if (x > 1)
    {
        res = res / x * (x - 1);
    }
    return res;
}

int main(int argc, const char * argv[])
{
    long long N;
    while (cin >> N)
    {
        cout << euler(N) << '\n';
    }
    return 0;
}
