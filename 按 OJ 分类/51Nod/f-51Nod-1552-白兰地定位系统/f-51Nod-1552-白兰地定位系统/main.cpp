//
//  main.cpp
//  f-51Nod-1552-白兰地定位系统
//
//  Created by ZYJ on 2017/7/31.
//  Copyright ? 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, m;
ll a[MAXN];
ll b[MAXN];

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
    scan_d(m);
    int x;
    for (int i = 1; i <= m; i++)
    {
        scan_d(x);
        b[x]++;
        if (x == 1 || x == n)
        {
            b[x]++;
        }
    }
    
    ll mx = 0, mn = INF;
    for (int i = 1; i <= n; i++)
    {
        mx = max(mx, b[i]);
        mn = min(mn, b[i]);
    }
    
    if (mn == mx)
    {
        int flag = 0;
        for (int i = 1; i <= n - 2; i++)
        {
            if (a[i + 1] - a[i] != a[i + 2] - a[i + 1])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            puts("-1");
        }
        else
        {
            printf("%lld", (a[n] - a[1]) * mn - (a[2] - a[1]));
        }
    }
    else
    {
        ll ans = 0;
        for (int i = 2; i <= n; i++)
        {
            ans += (a[i] - a[i - 1]) * min(b[i], b[i - 1]);
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
