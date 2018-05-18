//
//  main.cpp
//  ICPC Asia Regional Qingdao Online-1011-A Cubic number and A Cubic Number
//
//  Created by ZYJ on 2017/9/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 1e6;
const int MAXM = 1e4;

ll p;

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> p;
        
        bool flag = false;
        
        //  p == (a + b)^3 - b^3 p == i^3 - b^3 i 枚举 b 二分
        int i = 0;
        while (1)
        {
            i++;
            if (i > MAXM)
            {
                break;
            }
            
            ll l = 1, r = MAXN, m;
            ll a = i, ans;
            while (l <= r)
            {
                m = (l + r) >> 1;
                ans = 3 * m * m * a + 3 * m * a * a + a * a * a;
                if (ans == p)
                {
                    flag = true;
                    break;
                }
                
                if (ans < p)
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
            if (flag)
            {
                break;
            }
        }
        
        if (flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    
    return 0;
}
