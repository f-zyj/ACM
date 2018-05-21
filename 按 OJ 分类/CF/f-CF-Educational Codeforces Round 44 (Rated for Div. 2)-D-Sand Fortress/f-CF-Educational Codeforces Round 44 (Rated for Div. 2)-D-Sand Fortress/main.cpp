//
//  main.cpp
//  f-CF-Educational Codeforces Round 44 (Rated for Div. 2)-D-Sand Fortress
//
//  Created by ZYJ on 2018/5/22.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long int ll;

double cal(double x)
{
    return x * (x + 1) / 2;
}

ll n, H;

bool check(ll m)
{
    if (m <= H)
    {
        return cal(m) >= n;
    }
    
    double cnt = cal(H) + H;
    ll x = m - H - 1;
    cnt += H * x;
    
    if (x % 2 == 0)
    {
        cnt += 2 * cal(x / 2);
    }
    else
    {
        cnt += cal(x / 2) + cal((x + 1) / 2);
    }
    
    return cnt >= n;
}

int main()
{
    cin >> n >> H;
    
    ll l = 1, h = n;
    while (l + 1 < h)
    {
        ll m = (l + h) >> 1;
        if (check(m))
        {
            h = m;
        }
        else
        {
            l = m;
        }
    }
    
    cout << h << endl;
    
    return 0;
}
