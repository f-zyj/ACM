//
//  main.cpp
//  f-51Nod-1436-方程的解数
//
//  Created by ZYJ on 2017/6/25.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

#define mod(a, m) ((a) % (m) + (m)) % (m)

using namespace std;

typedef long long ll;

const int MAGIC = 64;

ll n, k, l, m;

struct matrix
{
    ll c[2][2];
} a;

ll f[2];

void ans_cf(matrix a)
{
    f[0] = mod(a.c[0][0] + a.c[1][0], m);
    f[1] = mod(a.c[0][1] + a.c[1][1], m);
}

matrix matrix_cf(matrix a, matrix b)
{
    matrix ans;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ans.c[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                ans.c[i][j] += a.c[k][i] * b.c[j][k];
                ans.c[i][j] = mod(ans.c[i][j], m);
            }
        }
    }
    
    return ans;
}

matrix matrix_pow(matrix a, ll n)
{
    matrix ans;
    ans.c[0][0] = ans.c[1][1] = 1;
    ans.c[0][1] = ans.c[1][0] = 0;
    while (n)
    {
        if (n & 1)
        {
            ans = matrix_cf(ans, a);
        }
        n = n >> 1;
        a = matrix_cf(a, a);
    }
    
    return ans;
}

ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = mod(ans * a, m);
        }
        b = b >> 1;
        a = mod(a * a, m);
    }
    
    return ans;
}

void init()
{
    a.c[0][0] = a.c[0][1] = a.c[1][0] = 1;
    a.c[1][1] = 0;
}

int main(int argc, const char * argv[])
{
    cin >> n >> k >> l >> m;
    
    unsigned long long t = 1ULL << l;
    if (m == 1 || (k >= t && l != MAGIC))
    {
        cout << 0 << '\n';
        return 0;
    }

    init();
    a = matrix_pow(a, n);
    ans_cf(a);
    ll x = f[0], y = mod(qpow(2, n) - x, m);
    
    int cnt_0 = 0, cnt_1 = 0;
    while (k)
    {
        if (k % 2)
        {
            cnt_1++;
        }
        else
        {
            cnt_0++;
        }
        k >>= 1;
    }
    cnt_0 += l - cnt_0 - cnt_1;
    
    ll ans = mod(mod(qpow(x, cnt_0), m) * mod(qpow(y, cnt_1), m), m);
    cout << ans << '\n';
    
    return 0;
}
