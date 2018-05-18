//
//  main.cpp
//  f-51Nod-1425-减减数
//
//  Created by ZYJ on 2017/6/24.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll n;
map<pll, pll> mpp;

pll dfs(ll mx, ll n)
{
    if (mpp[pll(mx, n)].first)
    {
        return mpp[pll(mx, n)];
    }
    if (n < 10)
    {
        return pll(mx > 0 || n > 0, max(mx, n) - n);
    }
    
    ll m = 1;
    while (m <= n / 10)
    {
        m *= 10;
    }
    ll p = n / m;
    m = p * m;
    pll a = dfs(max(mx, p), n - m);
    pll b = dfs(mx, m - a.second);
    return mpp[pll(mx, n)] = pll(a.first + b.first, b.second);
}

int main()
{
    scanf("%lld", &n);
    printf("%lld\n", dfs(0, n).first);
    
    return 0;
}
