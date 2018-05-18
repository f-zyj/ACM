//
//  main.cpp
//  f-CF-Codeforces Round #483 (Div. 2)-C-Finite or not?
//
//  Created by ZYJ on 2018/5/15.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;

ll gcd(ll x, ll y)
{
    if (!x || !y)
    {
        return x > y ? x : y;
    }
    
    for (ll t; static_cast<void>(t = x % y), t; x = y, y = t) ;
    
    return y;
}

int main(int argc, const char * argv[])
{
    cin >> n;
    while (n--)
    {
        ll p, q, b;
        scanf("%lld%lld%lld", &p, &q, &b);
        
        if (p == 0)
        {
            puts("Finite");
            continue;
        }
        
        ll g = gcd(p, q);
        q /= g;
        p /= g;
        while (q > 1)
        {
            g = gcd(q, b);
            if (g == 1)
            {
                break;
            }
            
            while (q % g == 0)
            {
                q /= g;
            }
        }
        
        if (q == 1)
        {
            puts("Finite");
        }
        else
        {
            puts("Infinite");
        }
    }
    
    return 0;
}
