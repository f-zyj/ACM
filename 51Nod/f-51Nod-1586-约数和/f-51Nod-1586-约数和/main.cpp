//
//  main.cpp
//  f-51Nod-1586-约数和
//
//  Created by ZYJ on 2017/7/4.
//  Copyright ? 2017年 ZYJ. All rights reserved.
//

#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;

int n, q;
int cnt[MAXN];
ll a[MAXN];

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

template <class T>
inline void print_d(T x)
{
    if (x > 9)
    {
        print_d(x / 10);
    }
    putchar(x % 10 + '0');
}

int main()
{
    scan_d(n), scan_d(q);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            cnt[j]++;
        }
    }
    
    int odr, x, y;
    while (q--)
    {
        scan_d(odr);
        if (odr == 1)
        {
            scan_d(x), scan_d(y);
            for (int i = x, j = 1; i <= n; i += x, j++)
            {
                a[i] += y * cnt[j];
            }
        }
        else
        {
            scan_d(x);
            print_d(a[x]);
            putchar(10);
        }
    }
    
    return 0;
}
