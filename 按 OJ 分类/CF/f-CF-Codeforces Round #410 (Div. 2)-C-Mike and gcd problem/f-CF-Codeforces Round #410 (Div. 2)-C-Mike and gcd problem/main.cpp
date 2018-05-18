//
//  main.cpp
//  f-CF-Codeforces Round #410 (Div. 2)-C-Mike and gcd problem
//
//  Created by ZYJ on 2017/4/21.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 1e6 + 10;

int a[MAXN];

int gcd(int x, int y)
{
    if (!x || !y)
    {
        return x > y ? x : y;
    }
    for (int t; t = x % y, t; x = y, y = t) ;
    return y;
}

int main(int argc, const char * argv[])
{
    int n;
    
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", a + i);
        }
        
        int gd = a[1];
        for (int i = 2; i <= n; i++)
        {
            gd = gcd(gd, a[i]);
        }
        
        printf("YES\n");
        
        if (gd != 1)
        {
            printf("0\n");
            continue;
        }
        
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] & 1)
            {
                if (i == n)
                {
                    res += 2;
                }
                else if (a[i + 1] & 1)
                {
                    res++;
                }
                else
                {
                    res += 2;
                }
                i++;
            }
        }
        
        cout << res << '\n';
    }
    
    return 0;
}
