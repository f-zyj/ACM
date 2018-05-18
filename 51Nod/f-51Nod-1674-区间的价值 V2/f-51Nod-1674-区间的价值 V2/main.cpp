//
//  main.cpp
//  f-51Nod-1674-区间的价值 V2
//
//  Created by ZYJ on 2016/12/26.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int cinDiy()
{
    int k = 0;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar()) ;
    for (; c >= '0' && c <= '9'; c = getchar())
    {
        k = k * 10 + c - 48;
    }
    return k;
}

const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int a[MAXN];
int AND[MAXN];
int OR[MAXN];
int sum[MAXN], resA, resO;
ll ans = 0;

void solve(int l, int r)
{
    if (l == r)
    {
        return ;
    }
    int mid = (l + r + 1) >> 1;
    
    ll pos = mid;
    AND[pos] = OR[pos] = a[mid];
    sum[pos] = 1;
    for (int i = mid + 1; i <= r; ++i)
    {
        if (((AND[pos] & a[i]) != AND[pos]) || ((OR[pos] | a[i]) != OR[pos]))
        {
            ++pos;
            AND[pos] = AND[pos - 1] & a[i];
            OR[pos] = OR[pos - 1] | a[i];
            sum[pos] = 1;
        }
        else
        {
            ++sum[pos];
        }
    }
    
    resA = resO = a[mid - 1];
    for (int i = mid - 1; i >= l; --i)
    {
        resA &= a[i];
        resO |= a[i];
        for (int j = mid; j <= pos; ++j)
        {
            ans = (ans + (ll)(resA & AND[j]) * (ll)(resO | OR[j]) % MOD * (ll)(sum[j]) % MOD) % MOD;
        }
    }
    
    solve(l, mid - 1);
    solve(mid, r);
}

int main()
{
    int n;
    n = cinDiy();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = cinDiy();
        ans = (ans + 1ll * a[i] * a[i]) % MOD;  //  序列[i, i]
    }
    
    solve(1, n);
    printf("%d\n", (int)ans);
    
    return 0;
}
