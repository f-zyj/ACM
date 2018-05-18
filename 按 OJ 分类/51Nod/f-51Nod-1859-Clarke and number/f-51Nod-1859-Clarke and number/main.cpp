//
//  main.cpp
//  f-51Nod-1859-Clarke and number
//
//  Created by ZYJ on 2017/8/4.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>

using namespace std;

typedef long long ll;

const ll INF = 1e10;    //  ll 开方后约为 1e9

ll x, k;

ll sqrt(ll x)
{
    ll l = -1, r = INF, m;
    while (r - l > 1)
    {
        m = (l + r) >> 1;
        if (m * m > x)
        {
            r = m;
        }
        else if (m * m < x)
        {
            l = m;
        }
        else
        {
            return m;
        }
    }
    
    return l;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld", &x, &k);
        
        if (x == 0)
        {
            printf("0\n");
            continue;
        }
        
        ll y = sqrt(x);
        if (k == 1)
        {
            if (x == 1)
            {
                printf("1\n");
                continue;
            }
            if (y * y == x)
            {
                printf("%lld\n", y * 2 - 1);
            }
            else
            {
                printf("%lld\n", y * 2);
            }
        }
        else
        {
            if (x == 1 || x == 3)
            {
                printf("-1\n");
            }
            else if (x == 2)
            {
                printf("1\n");
            }
            else if (x == 5)
            {
                printf("3\n");
            }
            else
            {
                ll t = sqrt(x - 1);
                if (y * y == x || t * t == x - 1)
                {
                    printf("%lld\n", y * 2 - 2);
                }
                else
                {
                    printf("%lld\n", y * 2 - 1);
                }
            }
        }
    }
    
    return 0;
}
