//
//  main.cpp
//  f-计蒜客-2017 计蒜之道 复赛-F-腾讯消消乐
//
//  Created by ZYJ on 2017/6/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

const ll MAXN = 18;
const ll MOD = 1e9 + 7;

ll A[MAXN + 10];
ll dp[2][(1 << MAXN) + 10];

inline void mod(ll &x)
{
    x -= x / MOD * MOD;
}

inline ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

vector<ll> vl;

int main()
{
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    
    int cnt = 0, w;
    ll a;
    for (int i = 1; i <= n; i++)
    {
        a = A[i];
        w = 0;
        for (int j = i; j <= n; j++)
        {
            if ((a = gcd(a, A[j])) >= k)
            {
                w ^= 1 << (n - j);
                dp[cnt][w] = 1;
            }
            else
            {
                break;
            }
        }
    }
    cnt++;
    
    ll t, j_, sz, ans = 0;
    for (int i = 2; i <= n; i++, cnt ^= 1)
    {
        memset(dp[cnt], 0, sizeof(dp[cnt]));
        
        ans += (i - 1) * dp[cnt ^ 1][(1 << n) - 1];
        ans %= MOD;
        
        for (int j = 0; j < (1 << n); j++)
        {
//            cout << dp[cnt^1][j] << ' ';
            if (dp[cnt ^ 1][j] == 0)
            {
                continue;
            }
            
            t = n;
            j_ = j;
            vl.clear();
            while (t)
            {
                if (!(j_ & 1))
                {
                    vl.push_back(t);
                }
                j_ >>= 1;
                t--;
            }
            
            sz = vl.size();
            for (int i_ = 0; i_ < sz; i_++)
            {
                a = A[vl[i_]];
                w = 0;
                for (int j_ = i_; j_ < sz; j_++)
                {
                    if ((a = gcd(a, A[vl[j_]])) >= k)
                    {
                        w ^= 1 << (n - vl[j_]);
                        dp[cnt][j ^ w] += dp[cnt ^ 1][j];
                        dp[cnt][j ^ w] %= MOD;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
//        putchar(10);
    }
    
    ans += n * dp[cnt ^ 1][(1 << n) - 1];
    ans %= MOD;
    
    cout << ans << endl;  

    return 0;  
}
