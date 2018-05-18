//
//  main.cpp
//  f-51Nod-1192-Gcd表中的质数
//
//  Created by ZYJ on 2017/8/31.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 5e6 + 10;

ll ans;
int n, m;
ll a[MAXN];
int pri[MAXN];
int miu[MAXN];
bool bz[MAXN];

void init()
{
    miu[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        if (!bz[i])
        {
            pri[++pri[0]] = i;
            miu[i] = -1;
        }
        for (int j = 1; j <= pri[0]; j++)
        {
            int k = i * pri[j];
            if (k > MAXN)
            {
                break;
            }
            
            bz[k] = 1;
            if (!(i % pri[j]))
            {
                break;
            }
            
            miu[k] = -miu[i];
        }
    }
    
    for (int i = 1; i <= pri[0]; i++)
    {
        int tmp = MAXN / pri[i];
        for (int j = 1; j <= tmp; j++)
        {
            a[pri[i] * j] += miu[j];
        }
    }
    for (int i = 1; i < MAXN; i++)
    {
        a[i] += a[i - 1];
    }
}

int main()
{
    init();
    
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d%d", &n, &m);
        
        ans = 0;
        if (n > m)
        {
            swap(n, m);
        }
        for (int l = 1, r; l <= n; l = r + 1)
        {
            r = min(n / (n / l), m / (m / l));
            ll sum = (ll)(n / l) * (m / l);
            ans += sum * (a[r] - a[l - 1]);
        }
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
