//
//  main.cpp
//  f-UVALive-7500-Boxes and Balls
//
//  Created by ZYJ on 2017/11/22.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n;

int main()
{
    int T;
    cin >> T;
    
    for (int ce = 1; ce <= T; ce++)
    {
        scanf("%lld", &n);
        ll l = 0, r = 2e9, m, sum, ans = 0;
        while (l <= r)
        {
            m = (l + r) >> 1;
            sum = (1 + m) * m / 2;
            if (sum <= n)
            {
                ans = sum;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        
        printf("Case #%d: %lld\n", ce, ans);
    }
    
    return 0;
}
