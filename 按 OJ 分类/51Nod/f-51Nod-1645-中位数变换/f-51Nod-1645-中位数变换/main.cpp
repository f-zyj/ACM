//
//  main.cpp
//  f-51Nod-1645-中位数变换
//
//  Created by ZYJ on 2017/11/15.
//  Copyright ? 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 10;

int n;
int a[MAXN];

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
    scan_d(n);
    for (int i = 1; i <= n; i++)
    {
        scan_d(a[i]);
    }
    
    a[n + 1] = a[n];
    int len = 1, ans = 0, l = 1, r = 1;
    for (int i = 2; i <= n + 1; i++)
    {
        if (a[i] != a[i - 1])
        {
            r = i;
            len++;
        }
        else
        {
            ans = max(ans, (len - 1) >> 1);
            if (len & 1)
            {
                for (int j = l; j <= r; j++)
                {
                    a[j] = a[l];
                }
            }
            else
            {
                int mid = (l + r) >> 1;
                for (int j = l; j <= r; j++)
                {
                    a[j] = j <= mid ? a[l] : a[r];
                }
            }
            len = 1;
            l = r = i;
        }
    }
    
    printf("%d\n%d", ans, a[1]);
    for (int i = 2; i <= n; i++)
    {
        putchar(' ');
        putchar('0' + a[i]);
        
    }
    putchar(10);
    
    return 0;
}

