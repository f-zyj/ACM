//
//  main.cpp
//  f-51Nod-1119-机器人走方格 V2
//
//  Created by ZYJ on 16/8/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;

//  返回d = gcd(a,b); 和对应于等式ax + by = d中的x,y
ll extend_gcd(ll a, ll b, ll &x, ll &y)
{
    if (a == 0 && b == 0)
    {
        return -1;  //  无最大公约数
    }
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extend_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

//  求逆元素
//  ax = 1(mod n)
ll mod_reverse(ll a, ll n)
{
    ll x, y;
    ll d = extend_gcd(a, n, x, y);
    if (d == 1)
    {
        return (x % n + n) % n;
    }
    else
    {
        return -1;
    }
}

ll c(ll m, ll n)
{
    ll i, t_1, t_2;
    t_1 = t_2 = 1;
    for (i = n; i >= n - m + 1; i--)
    {
        t_1 = t_1 * i % mod;
    }
    for (i = 1; i <= m; i++)
    {
        t_2 = t_2 * i % mod;
    }
    return  t_1 * mod_reverse(t_2, mod) % mod;  //  转换为逆元
}

int main()
{
    ll n, m, ans;
    cin >> m >> n;
    ans = c(min(m - 1, n - 1), m + n - 2);
    cout << ans << endl;
    return 0;
}