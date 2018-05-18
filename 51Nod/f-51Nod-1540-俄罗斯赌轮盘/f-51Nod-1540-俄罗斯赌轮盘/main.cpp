//
//  main.cpp
//  f-51Nod-1540-俄罗斯赌轮盘
//
//  Created by ZYJ on 2017/7/30.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

typedef long long ll;

int p;
ll n, k, x;
string s = "";


int main()
{
    scanf("%lld%lld%d", &n, &k, &p);
    
    ll tmp = k - n / 2;
    if (tmp < 0)
    {
        tmp = 0;
    }
    
    while (p--)
    {
        scanf("%lld", &x);
        if (k == 0)
        {
            s.push_back('.');
        }
        else if (k == 1)
        {
            if (x == n)
            {
                s.push_back('X');
            }
            else
            {
                s.push_back('.');
            }
        }
        else
        {
            ll t1 = n - 2 * (k - 1);
            ll t2 = n - (1 + (tmp - 1) * 2);
            if (n & 1)
            {
                if (x == n)
                {
                    s.push_back('X');
                }
                else
                {
                    if (x < t1)
                    {
                        s.push_back('.');
                    }
                    else if ((x - t1) & 1)
                    {
                        s.push_back('X');
                    }
                    else if (x >= t2)
                    {
                        s.push_back('X');
                    }
                    else
                    {
                        s.push_back('.');
                    }
                }
            }
            else
            {
                if (x < t1)
                {
                    s.push_back('.');
                }
                else if (!((x - t1) & 1))
                {
                    s.push_back('X');
                }
                else if (x >= t2)
                {
                    s.push_back('X');
                }
                else
                {
                    s.push_back('.');
                }
            }
        }
    }
    s.push_back(10);
    
    cout << s;
    
    return 0;
}
