//
//  main.cpp
//  f-51Nod-1240-莫比乌斯函数
//
//  Created by ZYJ on 16/7/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int n;

int MOD(int a, int b)
{
    return a - a / b * b;
}

int miu(int n)
{
    int cnt, k = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (MOD(n, i))
        {
            continue;
        }
        cnt = 0;
        k++;
        while (MOD(n, i) == 0)
        {
            n /= i;
            cnt++;
        }
        if (cnt >= 2)
        {
            return 0;
        }
    }
    if (n != 1)
    {
        k++;
    }
    return MOD(k, 2) ? -1 : 1;
}

int main()
{
    while (cin >> n)
    {
        cout << miu(n) << endl;
    }
    return 0;
}
