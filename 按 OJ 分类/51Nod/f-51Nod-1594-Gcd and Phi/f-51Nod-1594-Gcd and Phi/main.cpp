//
//  main.cpp
//  f-51Nod-1594-Gcd and Phi
//
//  Created by ZYJ on 2017/9/5.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2e6 + 5;

int n, tot;
ll ans;
ll s[MAXN];
ll f[MAXN];
int pri[MAXN];
int phi[MAXN];
int miu[MAXN];
bool vis[MAXN];

void solve()
{
    memset(vis, 0, sizeof(vis));
    memset(phi, 0, sizeof(phi));
    memset(miu, 0, sizeof(miu));
    memset(s, 0, sizeof(s));
    memset(f, 0, sizeof(f));
    ans = tot = 0;
    miu[1] = phi[1] = 1;
    
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            pri[tot++] =i ;
            miu[i] = -1;
            phi[i] = i - 1;
        }
        for (int j = 0, k; j < tot; j++)
        {
            k = i * pri[j];
            if (k > n)
            {
                break;
            }
            
            vis[k] = 1;
            if (i % pri[j] == 0)
            {
                miu[k] = 0;
                phi[k] = phi[i] * pri[j];
                break;
            }
            
            miu[k] = -miu[i];
            phi[k] = phi[i] * (pri[j] - 1);
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        s[phi[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            f[i] += s[j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i] * f[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (miu[i] != 0)
        {
            for (int d = 1; i * d <= n; d++)
            {
                ans += miu[i] * phi[d] * f[i * d];
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d", &n);
        
        solve();
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
