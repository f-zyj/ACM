//
//  main.cpp
//  f-51Nod-1035-最长的循环节
//
//  Created by ZYJ on 16/8/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int euler(int n)
{
    int res = n, a = n;
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            res = res / i * (i - 1);
            while (a % i == 0)
            {
                a /= i;
            }
        }
    }
    if (a > 1)
    {
        res = res / a * (a - 1);
    }
    return res;
}

int res[1005];  //  循环节长度

int main()
{
    memset(res, 0, sizeof(res));
    
    int i, temp, j, k, n;
    
    for (temp = 1; temp <= 1000; temp++)
    {
        i = temp;
        while (i % 2 == 0)
        {
            i /= 2;
        }
        while (i % 5 == 0)
        {
            i /= 5;
        }
        k = euler(i);
        n = 1;
        for (j = 1; j <= i; j++)
        {
            n *= 10;
            n %= i;
            if (n == 1)
            {
                res[temp] = j;
                break;
            }
        }
    }
    
    int max_re;
    
    while (cin >> n)
    {
        max_re = 1;
        for (i = 1; i <= n; i++)
        {
            if (res[i] > res[max_re])
            {
                max_re = i;
            }
        }
        cout << max_re << endl;
    }
    return 0;
}