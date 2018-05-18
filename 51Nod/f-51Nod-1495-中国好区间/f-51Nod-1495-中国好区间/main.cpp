//
//  main.cpp
//  f-51Nod-1495-中国好区间
//
//  Created by ZYJ on 2017/7/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>

using namespace std;
typedef long long ll;

const int MAXN = 1e7 + 10;

ll n, k, T, b, c, p;
ll res = 0;
ll a[MAXN];

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = (a[i - 1] * b + c);
        if (a[i] >= p)
        {
            a[i] %= p;
        }
    }

    int l = 1, r = 1, cnt = 0;;
    while (r <= n)
    {
        if (a[r] >= T)
        {
            cnt++;
        }
        if (cnt == k)
        {
            break;
        }
        r++;
    }
    
    while (r <= n && r - l + 1 >= k)
    {
        res += (n - r + 1);
        if (a[l] >= T)
        {
            while (r <= n)
            {
                r++;
                if (a[r] >= T)
                {	
                    break;
                }
            }
        }
        l++;
    }
}

int main()
{
    scanf("%lld%lld%lld%lld%lld%lld%lld",
            &n, &k, &T, a, &b, &c, &p);
    
    solve();
    
    printf("%lld\n", res);
    
    return 0;
}
