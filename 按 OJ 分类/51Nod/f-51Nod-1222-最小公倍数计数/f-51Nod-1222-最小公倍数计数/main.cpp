//
//  main.cpp
//  f-51Nod-1222-最小公倍数计数
//
//  Created by ZYJ on 2017/8/31.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 4e5 + 10;

int tot;
int pri[MAXN];
int miu[MAXN + 5];

ll l, r, ans;

bool bz[MAXN + 5];

void init()
{
    miu[1] = 1;
    for (int i = 2; i <= MAXN; i++)
    {
        if (!bz[i])
        {
            miu[i] = -1;
            pri[tot++] = i;
        }
        for (int j = 0; j < tot; j++)
        {
            int tmp = i * pri[j];
            if (tmp > MAXN)
            {
                break;
            }
            
            bz[tmp] = 1;
            if (i % pri[j] == 0)
            {
                miu[tmp] = 0;
                break;
            }
            
            miu[tmp] = -miu[i];
        }
    }
}

ll calc(ll n)
{
    if (!n)
    {
        return 0;
    }
    
    ans = 0;
    for (int k = 1; (ll)k * k <= n; k++)
    {
        if (miu[k] != 0)
        {
            ll m = n / ((ll)k * k), s = 0;
            for (int i = 1; (ll)i * i * i <= m; i++)
            {
                for (int j = i + 1; (ll)i * j * j <= m; j++)
                {
                    s += (m / ((ll)i * j) - j) * 6 + 3;
                }
                s += (m / ((ll)i * i) - i) * 3 + 1;
            }
            if (miu[k] == 1)
            {
                ans += s;
            }
            else
            {
                ans -= s;
            }
        }
    }
    
    return (ans + n) / 2;
}

int main()
{
    init();
    
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", calc(r) - calc(l - 1));
    
    return 0;
}
