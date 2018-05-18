//
//  main.cpp
//  f-NYOJ-1250-机器人
//
//  Created by ZYJ on 2017/5/5.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll ans = exgcd(b, a%b, x, y);
    ll temp = x;
    x = y;
    y = temp - a/b*y;
    return ans;
}

int main()
{
    int K;
    cin >> K;
    
    ll X, Y, S, T;
    while (K--)
    {
        scanf("%lld%lld%lld%lld", &X, &Y, &S, &T);
        
        ll a, b;
        ll g = exgcd(X, Y, a, b);
        ll c = a * T / g;
        ll d = b * T / g;
        a *= S / g;
        b *= S / g;
        if (S % g == 0 && T % g == 0)
        {
            bool flag = 0;
            for (int i = -2; i <= 2; i++)
            {
                ll x, y;
                x = a + X / g * i;
                y = b - Y / g * i;
                for (int j = -2; j <= 2; j++)
                {
                    ll x_, y_;
                    x_ = c + X / g * j;
                    y_ = d - Y / g * j;
                    if ((x + y_) % 2 == 0 && (x_ + y) % 2 == 0)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag)
            {
                puts("Y");
            }
            else
            {
                puts("N");
            }
        }
        else
        {
            puts("N");
        }
    }
    
    return 0;
}
