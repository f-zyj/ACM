//
//  main.cpp
//  f-百度2016实习-乘法表
//
//  Created by ZYJ on 2018/3/23.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

ll solve (ll n, ll m, ll k)
{
    ll l = 0, r = n * m + 1;
    while (r - l > 1)
    {
        ll mid = (l + r) / 2;
        ll cnt = 0;
        for (int i = 1; i <= m; i++)
        {
            cnt += min (mid / i, n);
        }
        if (cnt >= k)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    
    return r;
}

ll n, m, k;

int main ()
{
    while (cin >> n >> m >> k)
    {
        cout << solve (n, m, k) << endl;
    }
    
    return 0;
}
