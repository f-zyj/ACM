//
//  main.cpp
//  f-51Nod-1352-集合计数
//
//  Created by ZYJ on 16/8/11.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

typedef long long ll;

using namespace std;

ll N, A, B;
ll x, y;

ll extgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}

ll solve()
{
    ll ans = 0;
    ll d = extgcd(A, B, x, y);
    ll C = A * B / d;   //  最小公倍数
    
    if ((1 + N) % d)    //  无解
    {
        return 0;
    }
    else
    {
        x = x * ((1 + N) / d);
        ll r = B / d;
        x = (x % r + r) % r;
        if (x == 0)     //  x最小为r
        {
            x += r;
        }
        ll res = N - (x) * A;
        if (res < 0)
        {
            return 0;
        }
        else
        {
            ans++;
            ans += res / C; //  拆解成多少份儿C
        }
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while(T--)
    {
        scanf("%lld %lld %lld", &N, &A, &B);
        cout << solve() << endl;
    }
    return 0;
}
