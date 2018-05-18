//
//  main.cpp
//  f-51Nod-1053-最大M子段和 V2
//
//  Created by ZYJ on 2017/9/6.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 2e6 + 10;

template <class T>
inline bool scan_d(T &ret)
{
    char c;
    int sgn;
    if (c = getchar(), c == EOF)
    {
        return 0;   //  EOF
    }
    while (c != '-' && (c < '0' || c > '9'))
    {
        c = getchar();
    }
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0');
    }
    ret *= sgn;
    return 1;
}

ll A[MAXN];
int n, m, now;
int pre[MAXN];
int net[MAXN];
set<pair<ll, int> > a;

void _erase(int x)
{
    int l = pre[x], r = net[x];
    if (l)
    {
        net[l] = r;
    }
    if (r)
    {
        pre[r] = l;
    }
}

int main()
{
    scan_d(n), scan_d(m);
    
    int cnt = 0;
    ll tmp = 0, ans = 0;
    //  将相邻正数和负数分别合并
    for (int i = 1, x; i <= n; ++i)
    {
        scan_d(x);
        if ((tmp < 0 && x > 0) || (tmp > 0 && x < 0))
        {
            now += tmp > 0;
            A[++cnt] = tmp;
            a.insert(make_pair(abs(tmp), cnt));
            tmp = 0;
        }
        tmp += x;
        ans += x > 0 ? x : 0;
    }
    now += tmp > 0;
    A[++cnt] = tmp;
    a.insert(make_pair(abs(tmp), cnt));
    
    //  构造链表结构
    for (int i = 1; i <= cnt; ++i)
    {
        pre[i] = i - 1;
        net[i] = i + 1;
    }
    net[cnt] = A[0] = 0;
    
    while (now > m)
    {
        int x = (*a.begin()).second;
        a.erase(a.begin());
        if ((A[x] < 0 && (!pre[x] || !net[x])) || !A[x])
        {
            continue;
        }
        
        a.erase(make_pair(abs(A[pre[x]]), pre[x]));
        a.erase(make_pair(abs(A[net[x]]), net[x]));
        
        ans -= abs(A[x]);
        A[x] = A[x] + A[pre[x]] + A[net[x]];
        
        _erase(pre[x]);
        _erase(net[x]);
        a.insert(make_pair(abs(A[x]), x));
        now--;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
