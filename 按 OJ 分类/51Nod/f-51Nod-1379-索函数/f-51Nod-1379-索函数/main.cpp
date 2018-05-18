//
//  main.cpp
//  f-51Nod-1379-索函数
//
//  Created by ZYJ on 2017/6/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using  namespace  std;

typedef long long ll;

const int MAGIC = 93;   //  93项刚好不会爆 ll
const int MOD = 1e9 + 7;

ll n;
ll fib[MAGIC], ans;

void init()
{
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < MAGIC; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

ll pow_mod(ll x, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

int  main()
{
    init();
    
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 0)
        {
            cout << 0 << endl;
        }
        else if (n < MAGIC)
        {
            ll len = log(fib[n]) / log(2);
            ans = pow_mod(2, len + 1);
            cout << ans - 1 << endl;
        }
        else
        {
            ll len = n * log((1 + sqrt(5)) / 2) / log(2) - log(sqrt(5)) / log(2);
            ans = pow_mod(2, len + 1);
            cout << ans - 1 << endl;
        }  
    }
    
    return 0;  
}
