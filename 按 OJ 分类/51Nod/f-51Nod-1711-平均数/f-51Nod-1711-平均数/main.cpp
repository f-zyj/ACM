//
//  main.cpp
//  f-51Nod-1711-平均数
//
//  Created by ZYJ on 2017/7/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const double ESP = 1e-5;

struct note
{
    double val;
    int pos;
} a[MAXN];

bool cmp(note a, note b)
{
    return a.val < b.val;
}

inline int lowbit(int t)
{
    return t & (-t);
}

int n;
ll k;
ll sum[MAXN];
int dct[MAXN];
int t[MAXN];

void add(int x)
{
    for (; x <= n; x += lowbit(x))
    {
        t[x]++;
    }
}

ll find(int x)
{
    ll ans = 0;
    for (; x; x -= lowbit(x))
    {
        ans += t[x];
    }
    
    return ans;
}

bool check(double m)
{
    a[0].val = a[0].pos = 0;
    for (int i = 1; i <= n; i++)
    {
        a[i].val = sum[i] - m * i;
        a[i].pos = i;
    }
    sort(a, a + n + 1, cmp);
    
    int cnt = 0;
    ll x = 0;
    //  discretize
    for (int i = 0; i <= n; i++)
    {
        if (!i || a[i].val != a[i - 1].val)
        {
            cnt++;
        }
        dct[a[i].pos] = cnt;
    }
    
    memset(t, 0, sizeof(t));
    add(dct[0]);
    for (int i = 1; i <= n; i++)
    {
        x += find(dct[i]);
        add(dct[i]);
    }
    if (x >= k)
    {
        return 1;
    }
    return 0;
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
    scan_d(n), scan_d(k);
    
    ll mx = 0;
    for (int i = 1; i <= n; i++)
    {
        scan_d(sum[i]);
        mx = max(mx, sum[i]);
        sum[i] += sum[i - 1];
    }
    
    double l = 0, r = mx, m;
    while (r - l > ESP)
    {
        m = (l + r) / 2;
        if (check(m))
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    
    printf("%lf\n", l);
    
    return 0;
}
