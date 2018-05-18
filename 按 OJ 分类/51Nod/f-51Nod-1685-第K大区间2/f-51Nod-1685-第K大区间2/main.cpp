//
//  main.cpp
//  f-51Nod-1685-第K大区间2
//
//  Created by ZYJ on 2017/8/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n;
ll k;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int sum[MAXN];
int tree[2][MAXN * 3];

void add(int rt, int x, int y = 1)
{
    if (x <= 0)
    {
        return ;
    }
    int tmp = 3 * n;
    for (; x <= tmp; x += x & -x)
    {
        tree[rt][x] += y;
    }
}

int get_sum(int rt, int x)
{
    if (x <= 0)
    {
        return 0;
    }
    int ret = 0;
    for (; x; x -= x & -x)
    {
        ret += tree[rt][x];
    }
    return ret;
}

ll check(int x)
{
    ll ret = 0;
    memset(tree, 0, sizeof(tree));
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + (a[i] >= x);
        c[i] = 2 * sum[i] - i + n;  //  +n 是偏移一下，以防负数
    }
    
    add(0, n);
    for (int i = 1; i <= n; i++)
    {
        add(i & 1, c[i]);
        ret += get_sum((i + 1) & 1, c[i] - 1);
    }
    return ret;
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
    for (int i = 1; i <= n; i++)
    {
        scan_d(a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    
    int l = 1, r = n + 1, m;
    while (l + 1 < r)
    {
        m = (l + r) >> 1;
        if (check(b[m]) >= k)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    
    printf("%d\n", b[l]);
    
    return 0;
}
