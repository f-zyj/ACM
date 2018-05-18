//
//  main.cpp
//  f-51Nod-1810-连续区间
//
//  Created by ZYJ on 2017/7/29.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 5;

int n;
ll ans = 0;
int a[MAXN];
int b[MAXN << 2];
int mx[MAXN];
int mn[MAXN];

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

void solve(int l, int r)
{
    int m = (l + r) / 2;
    mx[m] = mn[m] = a[m];
    for (int i = m - 1; i >= l; i--)
    {
        mx[i] = max(a[i], mx[i + 1]);
        mn[i] = min(a[i], mn[i + 1]);
    }
    mx[m + 1] = mn[m + 1] = a[m + 1];
    for (int i = m + 2; i <= r; i++)
    {
        mx[i] = max(a[i], mx[i - 1]);
        mn[i] = min(a[i], mn[i - 1]);
    }
    
    for (int i = m; i >= l; i--)
    {
        int j = i + mx[i] - mn[i];
        if (j > m && j <= r && mx[i] > mx[j] && mn[i] < mn[j])
        {
            ans++;
        }
    }
    for (int i = m + 1; i <= r; i++)
    {
        int j = i - (mx[i] - mn[i]);
        if (j >= l && j <= m && mx[j] < mx[i] && mn[j] > mn[i])
        {
            ans++;
        }
    }
    
    //  确定左边包含最大查右边最小范围
    int l_ = m + 1, r_ = m;
    for (int i = m; i >= l; i--)
    {
        while (r_ < r && mx[r_ + 1] < mx[i])
        {
            r_++;
            b[mn[r_] + r_ + MAXN]++;
        }
        while (l_ <= r_ && mn[l_] > mn[i])
        {
            b[mn[l_] + l_ + MAXN]--;
            l_++;
        }
        ans += b[mx[i] + i + MAXN];
    }
    while (l_ <= r_)
    {
        b[mn[l_] + l_ + MAXN]--;
        l_++;
    }
    
    //  确定右边包含最大查左边最小范围
    l_ = m + 1, r_ = m;
    for (int j = m + 1; j <= r; j++)
    {
        while (l_ > l && mx[l_ - 1] < mx[j])
        {
            l_--;
            b[mn[l_] - l_ + MAXN]++;
        }
        while (r_ >= l_ && mn[r_] > mn[j])
        {
            b[mn[r_] - r_ + MAXN]--;
            r_--;
        }
        ans += b[mx[j] - j + MAXN];
    }
    while (l_ <= r_)
    {
        b[mn[r_] - r_ + MAXN]--;
        r_--;
    }
    
    if (l == r)
    {
        ans++;
        return ;
    }
    solve(l, m);
    solve(m + 1, r);
}

int main()
{
    scan_d(n);
    for (int i = 1; i <= n; i++)
    {
        scan_d(a[i]);
    }
    solve(1, n);
    
    printf("%lld\n", ans);
    
    return 0;
}
