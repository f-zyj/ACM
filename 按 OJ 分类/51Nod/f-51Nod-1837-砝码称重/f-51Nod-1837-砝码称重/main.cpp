//
//  main.cpp
//  f-51Nod-1837-砝码称重
//
//  Created by ZYJ on 2017/10/8.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    while (cin >> n)
    {
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        
        ll k = ((ll)sqrt(8 * n + 1) - 1) >> 1;
        ll s = k * (k + 1) >> 1;
        ll c = n * (n + 1) >> 1;
        ll d = (ll)sqrt(c) * (ll)sqrt(c);
        
        if (s == n || s + 1 == n || d == c || d + 1 == c)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
    
    return 0;
}
