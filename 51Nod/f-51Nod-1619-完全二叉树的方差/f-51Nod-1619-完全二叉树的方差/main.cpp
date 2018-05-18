//
//  main.cpp
//  f-51Nod-1619-完全二叉树的方差
//
//  Created by ZYJ on 2017/7/31.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>

#define ll long long

using namespace std;

const int MAXN = 1001;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n;
ll L = INF, R = 1;
ll ans = INF;
ll a[MAXN];
ll b[MAXN];
ll l[MAXN], r[MAXN];

//  两根相连
ll Ml(ll x, ll y)
{
    if (x < y)
    {
        swap(x, y);
    }
    ll X = 0, Y = 0;
    while ((1ll << (X + 1)) <= x)
    {
        X++;
    }
    while ((1ll << (Y + 1)) <= y)
    {
        Y++;
    }
    return max(X + Y + 1, X + X - (X && x < (1ll << (X + 1)) - (1ll << (X - 1))));
}

//  两叶相连
ll Mr(ll x, ll y)
{
    ll X = 0, Y = 0;
    while ((1ll << (X + 1)) <= x)
    {
        X++;
    }
    while ((1ll << (Y + 1)) <= y)
    {
        Y++;
    }
    return X + X + Y + Y - (X && (x < (1ll << (X + 1)) - (1ll << (X - 1))))
                         - (Y && (y < (1ll << (Y + 1)) - (1ll << (Y - 1)))) + 1;
}

ll check(ll x)
{
    ll sum = 0, ret = 0;
    for (int i = 1; i <= n; i++)
    {
        if (l[i] > x)
        {
            a[i] = l[i];
        }
        else if (r[i] < x)
        {
            a[i] = r[i];
        }
        else
        {
            a[i] = x;
        }
        sum += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ret += (a[i] * n - sum) * (a[i] * n - sum);
    }
    
    return ret;
}

bool cmp(ll x, ll y)
{
    return x > y;
}

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

int main()
{
    scan_d(n);
    for (int i = 1; i <= n; i++)
    {
        scan_d(a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scan_d(b[i]);
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n, cmp);
    
    for (int i = 1; i <= n; i++)
    {
        l[i] = Ml(a[i], b[i]);
        if (L > l[i])
        {
            L = l[i];
        }
        r[i] = Mr(a[i], b[i]);
        if (R < r[i])
        {
            R = r[i];
        }
    }
    
    for (ll i = L; i <= R; i++)
    {
        if (check(i) < ans)
        {
            ans = check(i);
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
