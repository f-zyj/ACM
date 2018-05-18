//
//  main.cpp
//  f-字符串 HASH
//
//  Created by ZYJ on 16/6/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

//字符串 Hash

/*
 * 字符串 Hash
 * 注意：mod选择足够大的质数（至少大于字符串个数）
 */

unsigned int hashA(char *url, int mod)
{
    unsigned int n = 0;
    char *b = (char *)&n;
    for (int i = 0; url[i]; i++)
    {
        b[i % 4] ^= url[i];
    }
    return n % mod;
}

unsigned int hashB(char *url, int mod)
{
    unsigned int h = 0;
    unsigned int g;
    while (*url)
    {
        h = (h << 4) + *url++;
        g = h & 0xF0000000;
        if (g)
        {
            h ^= (g >> 24);
        }
        h &= ~g;
    }
    return h % mod;
}

unsigned int hashC(char *p, int prime = 25013)
{
    unsigned int h = 0;
    unsigned int g;
    for (; *p; p++)
    {
        h = (h << 4) + *p;
        g = h & 0xF0000000;
        if (g)
        {
            h ^= (g >> 24);
            h ^= g;
        }
    }
    return h % prime;
}

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
