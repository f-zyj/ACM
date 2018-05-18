//
//  main.cpp
//  f-51Nod-1616-最小集合
//
//  Created by ZYJ on 2017/7/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e6 + 10;

int n;
int cnt = 0, mx = 0;
int vis[MAXN];

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

int kgcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    if (!(a & 1) && !(b & 1))
    {
        return kgcd(a >> 1, b >> 1) << 1;
    }
    else if (!(b & 1))
    {
        return kgcd(a, b >> 1);
    }
    else if (!(a & 1))
    {
        return kgcd(a >> 1, b);
    }
    else
    {
        return kgcd(abs(a - b), min(a, b));
    }
}

int main(int argc, const char * argv[])
{
    scan_d(n);
    
    int x;
    for (int i = 0; i < n; i++)
    {
        scan_d(x);
        if (!vis[x])
        {
            cnt++;
            vis[x] = 1;
            mx = max(mx, x);
        }
    }
    
    int tmp;
    for (int i = 1; i <= mx; i++)
    {
        if (vis[i])
        {
            continue;
        }
        tmp = 0;
        for (int j = i; j <= mx; j += i)
        {
            if (vis[j])
            {
                tmp = kgcd(tmp, j);
            }
        }
        if (tmp == i)
        {
            cnt++;
        }
    }
    
    cout << cnt << '\n';
    
    return 0;
}
