//
//  main.cpp
//  f-HPU-1008-Mod
//
//  Created by ZYJ on 2016/11/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

#define ll long long

using namespace std;

const int MAXN = 2000;
const int MAXA = 100000;

ll mlop;
ll a[MAXN];
ll a_[MAXN];
ll f[MAXA];
ll sum[MAXA];
bool vis[MAXA];
int cnt;
int N, Q;

void init()
{
    memset(sum, 0, sizeof(sum));
    memset(vis, 0, sizeof(vis));
    
    cnt = 1;
    mlop = MAXA + 1;
    a_[0] = mlop;
    
    //  获取产生贡献的a[i]存入a_[j]
    for (int i = 0; i < N; i++)
    {
        if (mlop > a[i])
        {
            a_[cnt++] = a[i];
            mlop = a[i];
        }
    }
    
    mlop = a_[cnt - 1];
    for (int i = cnt - 2; i >= 0; i--)
    {
        ll j;
        vis[mlop] = true;
        
        //  周期性，ture表示返回周期开始，false表示渐变（上一个+1）
        //  周期始终从vis[1]开始
        for (j = mlop + 1; j + mlop - 1 <= a_[i]; j += mlop)
        {
            memcpy(&vis[j], &vis[1], sizeof(bool) * mlop);
        }
        if (j < a_[i])
        {
            memcpy(&vis[j], &vis[1], sizeof(bool) * (a_[i] - j + 1));
        }
        mlop = a_[i];
    }
    
    ll val = 1;
    
    //  获取周期起点值
    for (int i = 1; i < cnt; i++)
    {
        val %= a_[i];
    }
    
    f[1] = val;
    sum[1] = f[1];
    for (int i = 2; i <= MAXA; i++)
    {
        f[i] = f[i - 1] + 1;
        if (vis[i])
        {
            f[i] = 0;
        }
        
        sum[i] = sum[i - 1] + f[i];
    }
}


int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d", &N);
        
        for (int i = 0; i < N; i++)
        {
            scanf("%lld", &a[i]);
        }
        
        init();
        scanf("%d", &Q);
        
        while (Q--)
        {
            ll l, r;
            scanf("%lld%lld", &l, &r);
            printf("%lld\n", sum[r] - sum[l - 1]);
        }
    }
    
    return 0;
}
