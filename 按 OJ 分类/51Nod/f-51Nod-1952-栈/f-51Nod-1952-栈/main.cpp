//
//  main.cpp
//  f-51Nod-1952-栈
//
//  Created by ZYJ on 2017/9/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 1e7 + 10;

ll n, A, B, C, a, b, mod;
ll x[MAXN];
deque<ll> s, s_;

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

signed main()
{
    scan_d(n), scan_d(A), scan_d(B), scan_d(C), scan_d(x[0]), scan_d(a), scan_d(b), scan_d(mod);
    
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        x[i] = (x[i - 1] * a + b) % mod;
        if (x[i] % (A + B + C) < A || s.size() < 2)
        {
            s.push_back(i);
            if (s_.empty() || x[s_.back()] <= x[i])
            {
                s_.push_back(i);
            }
            ans = (ans + x[s_.back()]) % MOD;
        }
        else if (A <= x[i] % (A + B + C) && x[i] % (A + B + C) < A + B)
        {
            s.push_front(i);
            while (!s_.empty() && x[s_.front()] < x[i])
            {
                s_.pop_front();
            }
            s_.push_front(i);
            ans = (ans + x[s_.back()]) % MOD;
        }
        else
        {
            if (s_.back() == s.back())
            {
                s_.pop_back();
            }
            s.pop_back();
            if (!s_.empty())
            {
                ans = (ans + x[s_.back()]) % MOD;
            }
        }
    }
    
    printf("%lld", ans);
    
    return 0;
}
