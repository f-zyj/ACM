//
//  main.cpp
//  f-HDU-2017 多校训练赛5-1006-Rikka with Graph
//
//  Created by ZYJ on 2017/8/8.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

ll n, m;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld", &n, &m);
        if (m >= n - 1)
        {
            ll sum = n * (n - 1) / 2;
            if (m > sum)
            {
                printf("%lld\n", sum * 2);
            }
            else
            {
                ll ans = (sum - m) * 2ll + m;
                printf("%lld\n", ans * 2);
            }
        }
        else
        {
            ll sum = n * (n - 1) / 2;
            ll ans = m + m * (m - 1) + n * 1ll * (sum - m - m * (m - 1) / 2);
            printf("%lld\n", ans * 2);
        }
    }
    
    return 0;
}
