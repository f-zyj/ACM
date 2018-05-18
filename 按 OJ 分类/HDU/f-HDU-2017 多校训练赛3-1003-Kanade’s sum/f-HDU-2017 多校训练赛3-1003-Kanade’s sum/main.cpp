//
//  main.cpp
//  f-HDU-2017 多校训练赛3-1003-Kanade’s sum
//
//  Created by ZYJ on 2017/8/1.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 10;

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

int n, k;
int s0, t0;
ll ans = 0;
int a[MAXN], pos[MAXN];
int pre[MAXN], ntp[MAXN];
int s[MAXN], t[MAXN];

void erase(int x)
{
    int pp = pre[x];
    int nn = ntp[x];
    if (pre[x])
    {
        ntp[pre[x]] = nn;
    }
    if (ntp[x] <= n)
    {
        pre[ntp[x]] = pp;
    }
    pre[x] = ntp[x] = 0;
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        pre[i] = i - 1;
        ntp[i] = i + 1;
    }
    ans = 0;
    for (int num = 1; num <= n - k + 1; num++)
    {
        int p = pos[num];
        s0 = t0 = 0;
        for (int d = p; d && s0 <= k + 1; d = pre[d])
        {
            s[++s0] = d;
        }
        for (int d = p; d != n + 1 && t0 <= k + 1; d = ntp[d])
        {
            t[++t0] = d;
        }
        s[++s0] = 0;
        t[++t0] = n + 1;
        for (int i = 1; i < s0; i++)
        {
            if (k + 1 - i <= t0 - 1 && k + 1 - i >= 1)
            {
                ans += (t[k + 1 - i + 1] - t[k + 1 - i]) * 1ll * (s[i] - s[i + 1]) * num;
            }
        }
        
        erase(p);
    }
}

int main()
{
    int T;
    scan_d(T);
    while (T--)
    {
        scan_d(n), scan_d(k);
        for (int i = 1; i <= n; i++)
        {
            scan_d(a[i]);
            pos[a[i]] = i;
        }
        
        solve();
        
        cout << ans << endl;
    }
    
    return 0;
}
