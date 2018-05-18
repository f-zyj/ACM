//
//  main.cpp
//  f-51Nod-1220-约数之和
//
//  Created by ZYJ on 2017/9/7.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <map>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INV_2 = 5e8 + 4;

int n, sqn, tot, ans;
int prime[MAXN];
int f[MAXN];
bool vis[MAXN];
map<ll, int> _hash;

inline void inc(int &x, int y)
{
    x += y;
    if (x >= MOD)
    {
        x -= MOD;
    }
}

inline void dec(int &x, int y)
{
    x -= y;
    if (x < 0)
    {
        x += MOD;
    }
}

inline int num1(int x)
{
    return x * (x + 1LL) % MOD * INV_2 % MOD;
}

inline int num1(int L, int R)
{
    int ret = num1(R);
    dec(ret, num1(L - 1));
    return ret;
}

int calc_imu(int x)
{
    if (x <= sqn)
    {
        return f[x];
    }
    if (_hash.count(x))
    {
        return _hash[x];
    }
    
    int ret = 1;
    for (int i = 2, j; i <= x; i = j + 1)
    {
        j = x / (x / i);
        dec(ret, (ll)num1(i, j) * calc_imu(x / i) % MOD);
    }
    
    return _hash[x] = ret;
}

inline int calc_imu(int L, int R)
{
    int ret = calc_imu(R);
    dec(ret, calc_imu(L - 1));
    return ret;
}

int calc_g(int n)
{
    int ret = 0;
    for (int i = 1, j; i <= n; i = j + 1)
    {
        j = n / (n / i);
        inc(ret, (j - i + 1LL) * num1(n / i) % MOD);
    }
    return ret;
}

int calc_h(int n)
{
    int ret = 0;
    for (int i = 1, j; i <= n; i = j + 1)
    {
        j = n / (n / i);
        inc(ret, (ll)(n / i) * num1(i, j) % MOD);
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    
    f[1] = 1;
    sqn = (int)ceil(pow(n, 2.0 / 3));
    for (int i = 2; i <= sqn; ++i)
    {
        if (!vis[i])
        {
            prime[tot++] = i;
            dec(f[i], 1);
        }
        for (int j = 0, k = sqn / i, o; j < tot && prime[j] <= k; ++j)
        {
            vis[o = i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                f[o] = 0;
                break;
            }
            else
            {
                dec(f[o], f[i]);
            }
        }
        f[i] = (f[i - 1] + (ll)i * f[i]) % MOD;
    }
    
    for (int i = 1, j; i <= n; i = j + 1)
    {
        j = n / (n / i);
        inc(ans, (ll)calc_imu(i, j) * calc_g(n / i) % MOD * calc_g(n / i) % MOD);
    }
    
    printf("%d\n", ans);
    
    return 0;
}
