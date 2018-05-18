//
//  main.cpp
//  f-大数平方根（字符串数组表示）
//
//  Created by ZYJ on 16/7/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

void Sqrt(char *str)
{
    double i, r, n;
    int j, l, size, num, x[1000];
    size = (int)strlen(str);
    if (size == 1 && str[0] == '0')
    {
        cout << "0\n";
        return;
    }
    if (size % 2 == 1)
    {
        n = str[0] - 48;
        l = -1;
    }
    else
    {
        n = (str[0] - 48) * 10 + str[1] - 48;
        l = 0;
    }
    r = 0;
    num = 0;
    while (true)
    {
        i = 0;
        while (i * (i + 20 * r) <= n)
        {
            i++;
        }
        i--;
        n -= i * (i + 20 * r);
        r = r * 10 + i;
        x[num] = (int)i;
        num++;
        l += 2;
        if (l >= size)
        {
            break;
        }
        n = n * 100 + (double)(str[l] - 48) * 10 + (double)(str[l + 1] - 48);
    }
    for(j = 0; j < num; j++)
    {
        cout << x[j];
    }
    putchar('\n');
}

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
