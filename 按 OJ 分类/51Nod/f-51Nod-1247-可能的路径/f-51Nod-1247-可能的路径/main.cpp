//
//  main.cpp
//  f-51Nod-1247-可能的路径
//
//  Created by ZYJ on 16/8/9.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

typedef long long ll;
using namespace std;

ll kgcd(ll a, ll b)
{
    if (!a)
    {
        return b;
    }
    else if (!b)
    {
        return a;
    }
    else if (!(a & 1) && !(b & 1))
    {
        return kgcd(a >> 1, b >> 1) << 1;
    }
    else if (!(b & 1))
    {
        return kgcd(a, b >> 1);
    }
    else if (!(a & 1))
    {
        return kgcd(a >> 1, b);
    }
    else
    {
        return kgcd(abs(a - b), min(a, b));
    }
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    ll a, b, x, y;
    while (T--)
    {
//        scanf("%lld %lld %lld %lld", &a, &b, &x, &y);
        cin >> a >> b >> x >> y;
        if (kgcd(a, b) == kgcd(x, y))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    
    return 0;
}
