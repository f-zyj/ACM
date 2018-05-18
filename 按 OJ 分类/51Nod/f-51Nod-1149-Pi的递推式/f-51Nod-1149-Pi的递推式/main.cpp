//
//  main.cpp
//  f-51Nod-1149-Pi的递推式
//
//  Created by ZYJ on 2017/9/23.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef double db;

const db PI = M_PI;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;

int n, m, ans;
int fac[MAXN];
int inv[MAXN];

int QPow(int x, int y)
{
    if (!y)
    {
        return 1;
    }
    
    int ret = QPow(x, y >> 1);
    ret = (ll)ret * ret % MOD;
    if (y & 1)
    {
        ret = (ll)ret * x % MOD;
    }
    
    return ret;
}

int C(int n, int m)
{
    return (ll)fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

//  预处理阶乘逆元
void init()
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = (ll)fac[i - 1] * i % MOD;
    }
    inv[n] = QPow(fac[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--)
    {
        inv[i] = (ll)inv[i + 1] * (i + 1) % MOD;
    }
}

int main()
{
    scanf("%d", &n);
    if (n < 4)
    {
        printf("1\n");
        return 0;
    }
    
    init();
    
    n -= 4;
    int tmp = (int)(n / PI);
    //  最后一个超越的是 1，枚举 PI
    for (int i = 0, t; i <= tmp; i++)
    {
        t = (n - i * PI);
        ans += C(t + i, i);
        ans %= MOD;
    }
    //  最后一个超越的是 PI，枚举 1
    for (int i = 0, t; i <= n; i++)
    {
        t = (n - i) / PI;
        ans += C(t + i, i);
        ans %= MOD;
    }
    
    printf("%d\n", ans);
    
    return 0;
}
