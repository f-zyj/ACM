//
//  main.cpp
//  f-51Nod-1686-第K大区间
//
//  Created by ZYJ on 2016/10/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n, a[MAXN], b[MAXN];

ll mul(ll x)
{
    if (x <= 0)
    {
        return 0;
    }
    return x * (x - 1) / 2;
}

ll cala(int x)
{
    ll ret = 0;
    int i, l = 0, la = 0;
    memset(b, 0, sizeof(b));
    for (i = 1; i <= n; i++)
    {
        b[a[i]]++;
        if (b[a[i]] > x)
        {
            ret += mul(i - l - 1);
            ret -= mul(la - l - 1);
            while (b[a[i]] > x)
            {
                l++;
                b[a[l]]--;
            }
            la = i;
        }
    }
    ret += mul(i - l - 1);
    ret -= mul(la - l - 1);
    return ret;
}

int main()
{
    int i, l, r, mid;
    ll k;
    scanf("%d%lld", &n, &k);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    //  排序去重
    sort(b + 1, b + n + 1);
    r = (int)(unique(b + 1, b + n + 1) - (b + 1));
    for (i = 1; i <= n; i++)
    {
        a[i] = (int)(lower_bound(b + 1, b + r + 1, a[i]) - b);
    }
    k = mul(n) - k + 1;
    l = 0;
    r = n;
    mid = (l + r) / 2;
    while (l + 1 < r)
    {
        if (cala(mid) < k)
        {
            l = mid;
            mid = (l + r) / 2;
        }
        else
        {
            r = mid;
            mid = (l + r) / 2;
        }
    }
    printf("%d\n", r);
    
    return 0;
}
