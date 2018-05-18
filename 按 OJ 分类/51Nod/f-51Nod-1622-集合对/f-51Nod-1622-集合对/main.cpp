//
//  main.cpp
//  f-51Nod-1622-集合对
//
//  Created by ZYJ on 2017/7/5.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

ll a, b, ab;

ll QPow(ll x, ll n)
{
    ll ret = 1;
    ll tmp = x % MOD;
    
    while (n)
    {
        if (n & 1)
        {
            ret = (ret * tmp) % MOD;
        }
        tmp = tmp * tmp % MOD;
        n >>= 1;
    }
    
    return ret;
}

int main(int argc, const char * argv[])
{
    cin >> a >> b >> ab;
    cout << QPow(2, ab) << '\n';
    
    return 0;
}
