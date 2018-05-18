//
//  main.cpp
//  f-51Nod-1661-黑板上的游戏
//
//  Created by ZYJ on 2017/9/20.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MAGIC = 64;

int n;
ll k;
ll sl[MAXN];
ll sr[MAXN];
ll a[MAXN];
ll vt[MAXN];

ll SG(ll x)
{
    if (x == 1)
    {
        return 0;
    }
    
    return x % k == 1 ? SG(x / k) : x - x / k - (x % k != 0);
}

int main()
{
    sl[0] = sr[n + 1] = 0;
    
    cin >> n >> k;
    ll p = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", a + i);
        vt[i] = SG(a[i]);
        sl[i] = sl[i - 1] ^ vt[i];
    }
    
    for (int i = n; i >= 1; i--)
    {
        sr[i] = sr[i + 1] ^ vt[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ll tt = sl[i - 1] ^ sr[i + 1];
        ll tx = ceil(1.0 * a[i] / k);
        if (a[i] == 1 || vt[i] <= tt)
        {
            continue;
        }
        
        ll tmp = (ll)(1.0 * tt * k / (k - 1) + 1);
        if (tmp % k == 1)
        {
            tmp--;
        }
        for (int j = 0; j < MAGIC; j++)
        {
            if (tmp >= tx)
            {
                break;
            }
            
            tmp = tmp * k + 1;
        }
        if (tmp < a[i] && SG(tmp) == tt)
        {
            p = i;
            ans = tmp;
            break;
        }
    }
    
    if (sl[n])
    {
        cout << "Alice " << p << " " << ans << endl;
    }
    else
    {
        puts("Bob");
    }
    
    return 0;
}
