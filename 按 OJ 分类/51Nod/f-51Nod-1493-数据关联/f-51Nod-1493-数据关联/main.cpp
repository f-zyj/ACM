//
//  main.cpp
//  f-51Nod-1493-数据关联
//
//  Created by ZYJ on 2017/7/23.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, m;
ll a[MAXN], b[MAXN];

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
    scan_d(m), scan_d(n);
    
    ll sum_a = 0, sum_b = 0;
    for (int i = 0; i < m; i++)
    {
        scan_d(a[i]);
        sum_a += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        scan_d(b[i]);
        sum_b += b[i];
    }
    sort(a, a + m);
    sort(b, b + n);
    
    ll ans = INF;
    ll sum = 0;
    for (ll i = 0; i < m - 1; i++)
    {
        if (sum_b <= a[i])
        {
            sum += (m - i) * sum_b;
            ans = min(ans, sum);
            break;
        }
        sum += a[i];
    }
    ans = min(ans, sum + sum_b);
    
    sum = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        if (sum_a <= b[i])
        {
            sum += (n - i) * sum_a;
            ans = min(ans, sum);
        }
        sum += b[i];
    }
    ans = min(ans, sum + sum_a);
    
    printf("%lld\n", ans);
    
    return 0;  
}
