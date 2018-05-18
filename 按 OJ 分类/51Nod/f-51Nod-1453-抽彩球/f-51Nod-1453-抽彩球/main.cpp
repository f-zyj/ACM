//
//  main.cpp
//  f-51Nod-1453-抽彩球
//
//  Created by ZYJ on 16/9/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//
//using namespace std;
//
//typedef long long ll;
//
//const int MOD = 1e9 + 7;
//const int MAXN = 1e3 + 5;
//
//int k;
//ll res, sum;
//int c[MAXN];
//long long C[MAXN][MAXN];
//
//void init()
//{
//    for (int i = 0; i < MAXN; i++)
//    {
//        for (int j = 0; j <= i; j++)
//        {
//            if (j == 0 || j == i)
//            {
//                C[i][j] = 1;
//            }
//            else
//            {
//                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
//            }
//        }
//    }
//    return ;
//}
//
//void input()
//{
//    scanf("%d", &k);
//    sum = 0;
//    for (int i = 1; i <= k; i++)
//    {
//        scanf("%d", &c[i]);
//        c[i]--;
//    }
//    return ;
//}
//
//void solve()
//{
//    ll empty = 1;   //  当前有多少空位
//    res = 1;
//    
//    for (int i = 1; i <= k; i++)
//    {
//        res = (res * C[empty + c[i] - 1][c[i]]) % MOD;
//        empty = empty + c[i] + 1;
//    }
//    cout << res << endl;
//    return ;
//}
//
//int main()
//{
//    init();
//    input();
//    solve();
//    
//    return 0;
//}

#include <stdio.h>

#define LL long long

const LL MOD = 1e9 + 7;
const int MAXN = 1e3 + 5;
const int MAXM = 1e6 + 5;

int n;
int a[MAXN];
LL fac[MAXM];

LL ppow(LL x, LL y)
{
    LL c = 1;
    while (y)
    {
        if (y & 1)
        {
            c = c * x % MOD;
        }
        y >>= 1;
        x = x * x % MOD;
    }
    return c;
}

LL work(LL m, LL i)
{
    return ((fac[m] % MOD) * (ppow((fac[i] * fac[m-i]) % MOD, MOD - 2) % MOD)) % MOD;
}

int main()
{
    fac[0] = 1;
    for(int i = 1; i < MAXM; i++)
    {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    LL ans = 1,sum = 0;
    scanf("%d", &n);
    for(int i = 1; i<= n; i++)
    {
        scanf("%d", a + i);
        sum += a[i];
    }
    for(int i = n; i >= 1; i--)
    {
        ans *= work(sum - 1, a[i] - 1);
        ans %= MOD;
        sum -= a[i];
    }
    printf("%lld\n", ans);
    
    return 0;
}
