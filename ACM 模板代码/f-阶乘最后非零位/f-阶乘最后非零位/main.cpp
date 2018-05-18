//
//  main.cpp
//  f-阶乘最后非零位
//
//  Created by ZYJ on 16/7/11.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

/*
 *  阶乘最后非零位 复杂度O(nlongn)
 *  返回改为，n以字符串方式传入
 */
#define MAXN 10000

const int mod[20] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8, 4, 4, 8, 4, 6, 8, 8, 6, 8, 2};

int lastDigit(char *buf)
{
    int len = (int)strlen(buf);
    int a[MAXN], i, c, ret = 1;
    if (len == 1)
    {
        return mod[buf[0] - '0'];
    }
    for (i = 0; i < len; i++)
    {
        a[i] = buf[len - 1 - i] - '0';
    }
    for (; len; len -= !a[len - 1])
    {
        ret = ret * mod[a[1] % 2 * 10 + a[0]] % 5;
        for (c = 0, i = len - 1; i >= 0; i--)
        {
            c = c * 10 + a[i];
            a[i] = c / 5;
            c %= 5;
        }
    }
    return ret + ret % 2 * 5;
}

int main(int argc, const char * argv[])
{
    
    std::cout << "Hello, World!\n";
    return 0;
}
