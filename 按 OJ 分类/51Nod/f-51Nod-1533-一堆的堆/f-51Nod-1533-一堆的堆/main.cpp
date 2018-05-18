//
//  main.cpp
//  f-51Nod-1533-一堆的堆
//
//  Created by ZYJ on 2017/7/26.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 2e5 + 10;

int n;
int arr[MAXN];
int ans[MAXN];
pii a[MAXN];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int d)
{
    while (x < MAXN)
    {
        arr[x] += d;
        x += lowbit(x);
    }
}

int query(int x)
{
    int ans = 0;
    while (x)
    {
        ans += arr[x];
        x -= lowbit(x);
    }
    return ans;
}

void solve ()
{
    memset(arr, 0, sizeof (arr));
    memset(ans, 0, sizeof (ans));
    
    for (int i = 1; i <= n; )
    {
        int tmp = i;
        while (tmp <= n && a[tmp].first == a[i].first)
        {
            tmp++;
        }
        for (int j = i; j < tmp; j++)
        {
            int v = a[j].second;
            for (int k = 1; k <= n - 1 && k * (v - 1) + 2 <= n; k++)
            {
                ans[k] += query(min(n, k * v + 1)) - query(k * (v - 1) + 1);
            }
        }
        for (int j = i; j < tmp; j++)
        {
            add(a[j].second, 1);
        }
        i = tmp;
    }
}

template <class T>
inline bool scan_d(T &ret)
{
    char c;
    int sgn;
    if (c = getchar(), c == EOF)
    {
        return 0; //EOF
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

int main(void)
{
    scan_d(n);
    
    for (int i = 1; i <= n; i++)
    {
        scan_d(a[i].first);
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    
    solve();
    
    for (int i = 1; i < n - 1; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[n - 1]);
    
    return 0;
}
