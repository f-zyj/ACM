//
//  main.cpp
//  f-51Nod-1038-X^A Mod P
//
//  Created by ZYJ on 2017/9/28.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cmath>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 100100;

ll qk_pow(ll a, ll b, ll mod)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1)
        {
            ret = ret * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ret;
}

ll ex_gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        ll r = ex_gcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    }
}

vector<ll> a;

bool check(ll g, ll p)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (qk_pow(g, (p - 1) / a[i], p) == 1)
        {
            return 0;
        }
    }
    
    return 1;
}

//  求解原根
ll primitive_root(ll p)
{
    ll tmp = p - 1;
    for (int i = 2; i <= tmp / i; i++)
    {
        if (tmp % i == 0)
        {
            a.push_back(i);
            while (tmp % i == 0)
            {
                tmp /= i;
            }
        }
    }
    if (tmp != 1)
    {
        a.push_back(tmp);
    }
    
    ll g = 1;
    while (true)
    {
        if (check(g, p))
        {
            return g;
        }
        ++g;
    }
}

struct sa
{
    ll x;
    int id;

    bool operator < (const sa &b) const
    {
        if (x == b.x)
        {
            return id < b.id;
        }
        return x < b.x;
    }
} rec[MAXN];

//  求解离散对数
ll discerte_log(ll x, ll n, ll m)
{
    int s = (int)(sqrt((double)m + 0.5));
    while ((ll)s * s <= m)
    {
        s++;
    }
    
    ll cur = 1;
    sa tmp;
    for (int i = 0; i < s; i++)
    {
        tmp.x = cur;
        tmp.id = i;
        rec[i] = tmp;
        cur = cur * x % m;
    }
    
    sort(rec, rec + s);
    ll mul = qk_pow(cur, m - 2, m) % m;
    cur = 1;
    
    for (int i = 0; i < s; i++)
    {
        ll more = n * cur % m;
        tmp.x = more;
        tmp.id = -1;
        int j = (int)(lower_bound(rec, rec + s, tmp) - rec);
        if (rec[j].x == more)
        {
            return i * s + rec[j].id;
        }
        
        cur = cur * mul % m;
    }
    
    return -1;
}

//  求解n次剩余
vector<ll> residue(ll p, ll n, ll a)
{
    vector<ll> ret;
    if (a == 0)
    {
        ret.push_back(0);
        return ret;
    }
    
    ll g = primitive_root(p);
    ll m = discerte_log(g, a, p);
    
    if (m == -1)
    {
        return ret;
    }
    
    ll A = n, B = p - 1, C = m, x, y;
    ll G = ex_gcd(A, B, x, y);
    if (C % G != 0)
    {
        return ret;
    }
    
    x = x * (C / G) % B;
    ll delta = B / G;
    for (int i = 0; i < G; i++)
    {
        x = ((x + delta) % B + B) % B;
        ret.push_back(qk_pow(g, x, p));
    }
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    
    return ret;
}

ll P, A, B;

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        a.clear();
        scanf("%lld%lld%lld", &P, &A, &B);
        
        vector<ll> ans;
        ans = residue(P, A, B);
        
        if (ans.empty())
        {
            puts("No Solution");
        }
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                printf("%lld ", ans[i]);
            }
            putchar(10);
        }
    }
    
    return 0;
}

