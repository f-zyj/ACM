//
//  main.cpp
//  f-51Nod-1589-移数博弈
//
//  Created by ZYJ on 2017/7/20.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 1e7 + 7;
const int MOD = 1e9 + 7;

int n, A, B, p;
int a[MAXN];
int b[MAXN];
int cnt[MAXN];
int net[MAXN];
int pre[MAXN];
int l1, r1, l2, r2;

void del(int now)
{
    net[pre[now]] = net[now];
    pre[net[now]] = pre[now];
}

int main()
{
    cin >> n >> a[0] >> A >> B >> p;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = (1LL * A * a[i - 1] + B) % p;
        cnt[a[i]]++;
    }
    for (int i = 1; i < p; ++i)
    {
        cnt[i] += cnt[i - 1];
    }
    //  桶排后，b 指向元素在 a 中的位置，b 是排好序的
    for (int i = n; i >= 1; --i)
    {
        b[cnt[a[i]]--] = i;
    }
    //  仿真链表
    for (int i = 1; i <= n; ++i)
    {
        net[i] = i + 1;
        pre[i] = i - 1;
    }
    
    int now;
    ll ans = 0;
    pre[0] = 0;
    net[n + 1] = n + 1;
    for (int i = 1; i <= n; ++i)
    {
        now = b[i];
        l1 = pre[now];
        r1 = net[now];
        l2 = pre[l1];
        r2 = net[r1];
        //  乘法原理求每个数的贡献
        ans = ans + 1LL * a[l1] * a[now] % MOD * (l1 - l2) % MOD * (r1 - now) % MOD;
        if (ans >= MOD)
        {
            ans -= MOD;
        }
        ans = ans + 1LL * a[r1] * a[now] % MOD * (r2 - r1) % MOD * (now - l1) % MOD;
        if (ans >= MOD)
        {
            ans -= MOD;
        }
        del(now);
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
