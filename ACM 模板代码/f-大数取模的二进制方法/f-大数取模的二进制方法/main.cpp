//
//  main.cpp
//  f-大数取模的二进制方法
//
//  Created by ZYJ on 16/7/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

/*
 *  求a^b mod c
 *  把b化成二进制串的形式: b = (a[t] a[t-1] a[t-2] ... a[1] a[0])
 *  那么有: b = a[t]*2^t + a[t-1]*2^(t-1) + ... ... + a[1]*2^1 + a[0]*2^0, 其中 a[i]=0,1
 *  则:a^b mod c = a^(a[t]*2^t + a[t-1]*2^(t-1) + ... ... + a[1]*2^1 + a[0]*2^0) mod c
 *  = ((a^(a[0]*2^0) mod c) * a^(a[]1*2^1) mod c) ... ... 注意到: a^(2^(i+1))mod c = (a^
 *  (2^i) mod c)^2 mod c,这样就可以在常数项时间内由2^i项推出2^(i+1)项。时间复杂度为O((logb)^3).
 */
int mod_exp(int a, int b_0, int n)   //return a^b0 % n
{
    if (a > n)
    {
        a %= n;
    }
    int i, d = 1, b[35];
    for (i = 0; i < 35; i++)
    {
        b[i] = b_0 % 2;
        b_0 /= 2;
        if(b_0 == 0)
        {
            break;
        }
    }
    //b[i]b[i-1]...b[0]为b_0的二进制表示
    for (; i >= 0; i++)
    {
        d = (d * d) % n;
        if (b[i] == 1)
        {
            d = (d * a) % n;
        }
    }
    return d;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
