//
//  main.cpp
//  f-51Nod-1677-treecnt
//
//  Created by ZYJ on 2016/12/14.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 1e5 + 3;

ll fac[MAXN];       //  阶乘
ll inv[MAXN];       //  阶乘的逆元

ll QPow(ll x, ll n)
{
    ll ret = 1;
    ll tmp = x % MOD;
    
    while (n)
    {
        if (n & 1)
        {
            ret = (ret * tmp) % MOD;
        }
        tmp = tmp * tmp % MOD;
        n >>= 1;
    }
    
    return ret;
}

void init()
{
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv[MAXN - 1] = QPow(fac[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

ll C(ll a, ll b)
{
    if (b > a)
    {
        return 0;
    }
    if (b == 0)
    {
        return 1;
    }
    return fac[a] * inv[b] % MOD * inv[a - b] % MOD;
}

ll n, k;
ll ans;
ll total;               //  所有组合
int vis[MAXN];
ll nodeNum[MAXN];       //  i为根的树所拥有结点数
vector<ll> tree[MAXN];

ll dfs(ll s)
{
    if (tree[s].size() == 1 && s != 1)
    {
        return nodeNum[s] = 1;
    }
    if (nodeNum[s] && s != 1)
    {
        return nodeNum[s];
    }
    vis[s] = 1;
    ll cnt = 0;
    for (int i = 0; i < tree[s].size(); i++)
    {
        if (!vis[tree[s][i]])
        {
            ll tmp = dfs(tree[s][i]);
            cnt += tmp;
            ans = (ans + total - C(tmp, k) - C(n - tmp, k)) % MOD;
        }
    }
    return nodeNum[s] = cnt + 1;
}

int main()
{
    init();
    
    while (~scanf("%lld%lld", &n, &k))
    {
        ans = 0;
        memset(vis, 0, sizeof(vis));
        memset(nodeNum, 0, sizeof(nodeNum));
        nodeNum[1] = n;
        total = C(n, k);
        for (int i = 1; i <= n; i++)
        {
            tree[i].clear();
        }
        for (int i = 1; i < n; i++)
        {
            ll u, v;
            scanf("%lld%lld", &u, &v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        dfs(1);
        
        printf("%lld\n", (ans + MOD) % MOD);
    }
    
    return 0;
}
