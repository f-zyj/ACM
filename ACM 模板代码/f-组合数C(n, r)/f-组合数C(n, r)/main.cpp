//
//  main.cpp
//  f-组合数C(n, r)
//
//  Created by ZYJ on 16/7/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

//  组合数C(n, r)

int com(int n, int r)   //  return C(n, r)
{
    if (n - r > r)
    {
        r = n - r;      //  C(n, r) = C(n, n - r)
    }
    int i, j, s = 1;
    for (i = 0, j = 1; i < r; ++i)
    {
        s *= (n - i);
        for (; j <= r && s % j == 0; ++j)
        {
            s /= j;
        }
    }
    return s;
}

int main(int argc, const char * argv[])
{
    
    std::cout << "Hello, World!\n";
    return 0;
}
