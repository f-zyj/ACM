//
//  main.cpp
//  f-51Nod-1197-字符串的数量 V2
//
//  Created by ZYJ on 2016/10/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 63;

void add(ll &x, ll y)
{
    x += y;
    if (x >= MOD)
    {
        x -= MOD;
    }
}

ll i, j;
ll p, k;
ll MAXP;
ll A[MAXN + 5][MAXN + 5];
ll E[MAXN + 5];
ll pr[20005];
ll MA[20005];

vector<ll> v[MAXN];
vector<ll> va[MAXN];
vector<ll> vb[MAXN];
vector<ll> vr[MAXN];

ll modAdd(ll a, ll b)
{
    a += b;
    return a >= MOD ? (a - MOD) : a;
}

ll modMul(ll a , ll b)
{
    a *= b;
    return a >= MOD ? (a % MOD) : a;
}

void multiply(const vector<ll> &Q, vector<ll> &Qr)
{
    
    int size = (int)Qr.size();
    
    for (int i = 0 ; i < size; i++)
    {
        Qr[i] = 0;
        for (int j = max(0 , 2 * i - size + 1); j < min(size, (2 * i + 1)); j++)
        {
            
            ll x = (j & 1) ? ((MOD - Q[j])) : (Q[j]);
            ll y = modMul(x, Q[2 * i - j]);
            
            Qr[i] = modAdd(Qr[i], y);
        }
    }
}

void cal(ll *A, ll n, ll k, ll *C)
{
    vector<ll> Q(k + 3);
    vector<ll> Qr(k + 3);
    
    n--;
    while (n >= k)
    {
        Q[0] = 1;
        for (ll i = 0; i < k; i++)
        {
            Q[i + 1] = -C[i];
            if (Q[i + 1] < 0)
            {
                Q[i + 1] += MOD;
            }
        }
        
        for (ll i = k; i < (2 * k); i++)
        {
            A[i] = 0;
            for (ll j = 0; j < k; j++)
            {
                ll add = modMul(A[i - 1 - j], C[j]);
                A[i] = modAdd(A[i], add);
            }
        }
        
        multiply(Q, Qr);
        
        for (ll i = 0; i < k; i++)
        {
            C[i] = (-Qr[i + 1]);
            
            if (C[i] < 0)
            {
                C[i] += MOD;
            }
        }
        
        int offset = n & 1;
        for (ll i = 0; i < k; i++)
        {
            A[i] = A[2 * i + offset];
        }
        
        n /= 2;
    }
    
    printf("%lld\n", A[n]);
}

int power(ll x, ll y)
{
    int sum = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
        {
            sum = 1ll * sum * x % MOD;
        }
        x = 1ll * x * x % MOD;
    }
    return sum;
}

void guass(ll n)
{
    for (int i = 1; i <= n; ++i)
    {
        int j;
        for (j = i; j <= n; ++j)
        {
            if (A[j][i])
            {
                break;
            }
        }
        for (int k = 1; k <= n + 1; ++k)
        {
            swap(A[i][k], A[j][k]);
        }
        int p = power(A[i][i], MOD - 2);
        for (int j = i + 1; j <= n; ++j)
        {
            if (A[j][i])
            {
                int now = 1ll * A[j][i] * p % MOD;
                for (int k = i; k <= n + 1; ++k)
                {
                    add(A[j][k], MOD - 1ll * A[i][k] * now % MOD);
                }
            }
        }
    }
    for (ll i = n; i; --i)
    {
        for (ll j = i + 1; j <= n; ++j)
        {
            add(A[i][n + 1], MOD - 1ll * A[i][j] * E[j] % MOD);
        }
        E[i] = 1ll * A[i][n + 1] * power(A[i][i], MOD - 2) % MOD;
    }
}

long long n, m, sA[MAXN], sB[MAXN];

long long Count(vector<ll> A, ll R)
{
    ll i, j, sum = 0;
    R %= MOD;
    for (i = 0; i < A.size(); ++i)
    {
        ll S = 0, now = 1;
        for (j = 0; j < vr[i].size(); ++j)
        {
            add(S, 1ll * vr[i][j] * now % MOD), now = 1ll * now * R % MOD;
        }
        add(sum, 1ll * S * A[i] % MOD);
    }
    return sum;
}

int main()
{
    for (i = 0; i < MAXN; ++i)
    {
        memset(A, 0, sizeof(A));
        for (j = 1; j <= i + 2; ++j)
        {
            for (k = 1; k <= i + 2; ++k)
            {
                A[j][k] = power(j, k - 1);
            }
            A[j][i + 3] = power(2 * j - 1, i);
            add(A[j][i + 3], A[j - 1][i + 3]);
            if (j > 1)
            {
                add(A[j][i + 3], power(2 * j - 2, i));
            }
        }
        guass(i + 2);
        for (j = 1; j <= i + 2; ++j)
        {
            v[i].push_back(E[j]);
        }
    }
    
    for (i = 0; i < MAXN; ++i)
    {
        memset(A, 0, sizeof(A));
        for (j = 1; j <= i + 2; ++j)
        {
            for (k = 1; k <= i + 2; ++k)
            {
                A[j][k] = power(j, k - 1);
            }
            A[j][i + 3] = power(j, i);
            (A[j][i + 3] += A[j - 1][i + 3]) %= MOD;
        }
        guass(i + 2);
        for (j = 1; j <= i + 2; ++j)
        {
            vr[i].push_back(E[j]);
        }
    }
    //    int T;
    //    scanf("%d", &T);
    //    for (; T--; )
    //    {
    scanf("%lld%lld", &n, &m);
    MAXP = (int)(log2(n) + 1);
    memset(sA, 0, sizeof(sA));
    memset(sB, 0, sizeof(sB));
    for (i = 1; i <= MAXP; ++i)
    {
        va[i].clear(), vb[i].clear();
    }
    sA[1] = n / 2;
    sB[1] = n;
    vb[1].push_back(1);
    for (i = 2; i <= MAXP; ++i)
    {
        sA[i] = sA[i - 1] / 2;
        sB[i] = sB[i - 1] / 2;
        long long str = Count(vb[i - 1], sB[i - 1]);
        for (j = 0; j < i; ++j)
        {
            vb[i].push_back(0), va[i].push_back(0);
        }
        vb[i][0] = str;
        for (j = 0; j < vb[i - 1].size(); ++j)
        {
            ll wei = (MOD - vb[i - 1][j]);
            for (k = 0; k < (int)v[j].size(); ++k)
            {
                add(vb[i][k], 1ll * wei * v[j][k] % MOD);
            }
        }
        ll End = Count(vb[i - 1], sA[i - 1]);
        va[i][0] = (str - End + MOD) % MOD;
        add(va[i][0], Count(va[i - 1], sA[i - 1]));
        for (j = 0; j < va[i - 1].size(); ++j)
        {
            ll wei = (MOD - va[i - 1][j]);
            for (k = 0; k < v[j].size(); ++k)
            {
                add(va[i][k], 1ll * wei * v[j][k] % MOD);
            }
        }
    }
    for (i = 1; i <= MAXP; ++i)
    {
        pr[i] = Count(va[i], sA[i]);
        add(pr[i], Count(vb[i], sB[i]));
        add(pr[i], MOD - Count(vb[i], sA[i]));
    }
    memset(MA, 0, sizeof(MA));
    MA[0] = 1;
    for (i = 1; i < MAXP; ++i)
    {
        for (j = 1; j <= i; ++j)
        {
            add(MA[i], 1ll * MA[i - j] * pr[j] % MOD);
        }
    }
    for (i = 0; i < MAXP; ++i)
    {
        swap(pr[i], pr[i + 1]);
    }
    if (m < MAXP)
    {
        printf("%lld\n", MA[m]);
    }
    else
    {
        cal(MA, m + 1, MAXP, pr);
    }
    //    }
    
    return 0;
}

//#include <stdio.h>
//
//typedef long long ll;
//
//const int MAXN = 61;
//const int MOD = 1e9 + 7;
//
//int deg;
//int iact[MAXN + 1];
//int val[MAXN + 1];
//int nxt[MAXN + 1];
//int seq[MAXN + 1];
//
//ll n, m;
//
//inline int mod_add(int x, int y)
//{
//    return x + y < MOD ? x + y : x + y - MOD;
//}
//
//inline int mod_dec(int x, int y)
//{
//    return x - y >= 0 ? x - y : x - y + MOD;
//}
//
//int value(int a)
//{
//    if (a < deg)
//    {
//        return val[a];
//    }
//    static int pre[MAXN], suf[MAXN];
//    pre[0] = a;
//    for (int i = 1; i < deg; ++i)
//    {
//        pre[i] = (ll)(a - i) * pre[i - 1] % MOD;
//    }
//    suf[deg - 1] = a - deg + 1;
//    for (int i = deg - 2; i >= 0; --i)
//    {
//        suf[i] = (ll)(a - i) * suf[i + 1] % MOD;
//    }
//    int ret = 0;
//    for (int i = 0; i < deg; ++i)
//    {
//        int tmp = (ll)val[i] * iact[i] % MOD * iact[deg - 1 - i] % MOD;
//        if (i > 0)
//        {
//            tmp = (ll)tmp * pre[i - 1] % MOD;
//        }
//        if (i < deg - 1)
//        {
//            tmp = (ll)tmp * suf[i + 1] % MOD;
//        }
//        if (((deg - 1 - i) & 1) && tmp > 0)
//        {
//            tmp = MOD - tmp;
//        }
//        ret += tmp;
//        if (ret >= MOD)
//        {
//            ret -= MOD;
//        }
//    }
//    return ret;
//}
//
//struct Matrix
//{
//    int r, c, num[MAXN][MAXN];
//    Matrix operator * (const Matrix &t) const
//    {
//        Matrix ret = {r, t.c};
//        for (int i = 0; i < r; ++i)
//        {
//            for (int j = 0; j < c; ++j)
//            {
//                for (int k = 0; k < t.c; ++k)
//                {
//                    ret.num[i][k] = (ret.num[i][k] + (ll)num[i][j] * t.num[j][k]) % MOD;
//                }
//            }
//        }
//        return ret;
//    }
//    Matrix pow(ll k)
//    {
//        Matrix ret = {r, r}, tmp = *this;
//        for (int i = 0; i < r; ++i)
//        {
//            ret.num[i][i] = 1;
//        }
//        for (; k > 0; k >>= 1, tmp = tmp * tmp)
//        {
//            if (k & 1)
//            {
//                ret = ret * tmp;
//            }
//        }
//        return ret;
//    }
//} A;
//
//int main()
//{
////    int T;
////    scanf("%d", &T);
//
////    while (T--)
////    {
//        iact[0] = 0;
//        iact[1] = 1;
//        for (int i = 2; i <= MAXN; ++i)
//        {
//            iact[i] = MOD - MOD / i * (ll)iact[MOD % i] % MOD;
//        }
//        iact[0] = 1;
//        for (int i = 1; i <= MAXN; ++i)
//        {
//            iact[i] = iact[i - 1] * (ll)iact[i] % MOD;
//        }
//
//        int len;
//        scanf("%lld%lld", &n, &m);
//
//        ll tmp = (n << 1) - 1;
//        deg = val[0] = 1;
//        for (len = 1; --tmp >= 0; ++len)
//        {
//            for (int i = 0, pos = tmp & 1; i <= deg; ++i, pos = mod_add(pos, 2))
//            {
//                nxt[i] = mod_add(i > 0 ? nxt[i - 1] : 0, value(pos));
//            }
//            ++deg;
//            for (int i = 0; i < deg; ++i)
//            {
//                val[i] = nxt[i];
//            }
//            tmp >>= 1;
//            seq[len] = value(tmp % MOD);
//        }
//        --len;
//
//        ll tmp_ = n - 1;
//        deg = val[0] = 1;
//        for (int j = 1; --tmp_ >= 0; ++j)
//        {
//            for (int i = 0, pos = tmp_ & 1; i <= deg; ++i, pos = mod_add(pos, 2))
//            {
//                nxt[i] = mod_add(i > 0 ? nxt[i - 1] : 0, value(pos));
//            }
//            ++deg;
//            for (int i = 0; i < deg; ++i)
//            {
//                val[i] = nxt[i];
//            }
//            tmp_ >>= 1;
//            seq[j] = mod_dec(seq[j], value(tmp_ % MOD));
//        }
//
//        A = (Matrix){len, len};
//        for (int i = 1; i < len; ++i)
//        {
//            A.num[i][i - 1] = 1;
//        }
//        for (int i = 0; i < len; ++i)
//        {
//            A.num[i][len - 1] = seq[len - i];
//        }
//        A = A.pow(m);
//        printf("%d\n", A.num[len - 1][len - 1]);
////    }
//
//    return 0;
//}


