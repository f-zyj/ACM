//
//  main.cpp
//  f-HDU-6004-Periodical Cicadas
//
//  Created by ZYJ on 2017/11/18.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef __int128 lll;

const int MAXN = 202;
const int MAXM = MAXN * MAXN / 2 + MAXN;

struct node
{
    ll a, b;
} dp[MAXN][MAXM];

int n, m, q;

inline int _hash(int x, int y)
{
    return (2 * m - x + 1) * x / 2 + y - x + 1;
}

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    
    ll ans = exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - a / b * y;
    
    return ans;
}

node merge(node x, node y)
{
    if (x.a == -1 || y.a == -1)
    {
        return {-1, -1};
    }
    
    ll _x, _y;
    ll g = exgcd(x.b, y.b, _x, _y);
    if ((y.a - x.a) % g)
    {
        return {-1, -1};
    }
    
    ll t = (y.a - x.a) / g;
    lll p = x.a + (lll)x.b * _x * t;
    lll q = x.b / g * y.b;
    p = (p % q + q) % q;
    return {(ll)p, (ll)q};
}

void init()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = j + 1; k < m; k++)
            {
                dp[i][_hash(j, k)] = merge(dp[i][_hash(k, k)], dp[i][_hash(j, k - 1)]);
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    for (int ce = 1; ce <= T; ce++)
    {
        printf("Case #%d:\n", ce);
        
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%lld", &dp[i][_hash(j, j)].a);
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%lld", &dp[i][_hash(j, j)].b);
            }
        }
        
        init();
        
        scanf("%d", &q);
        
        int x1, y1, x2, y2;
        while (q--)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            x1--; y1--; x2--; y2--;
            node ans = dp[x1][_hash(y1, y2)];
            for (int i = x1 + 1; i <= x2; i++)
            {
                if (ans.a == -1)
                {
                    break;
                }
                ans = merge(ans, dp[i][_hash(y1, y2)]);
            }
            
            printf("%lld\n", ans.a);
        }
    }

    return 0;
}
