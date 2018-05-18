//
//  main.cpp
//  f-51Nod-1773-A国的贸易
//
//  Created by ZYJ on 2017/7/3.
//  Copyright ? 2017年 ZYJ. All rights reserved.
//

#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 2330010;
const int MOD = 1e9 + 7;
const int INV_2 = 5e8 + 4;  //  2的逆元

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

template <class T>
inline void print_d(T x)
{
    if (x > 9)
    {
        print_d(x / 10);
    }
    putchar(x % 10 + '0');
}

int N;
int a[MAXN], b[MAXN];

inline void FWT(int c[], int tf_utf)    //  tf_utf 1:tf; 0:utf
{
    for (int i = 1; i < N; i <<= 1)
    {
        int tmp = i << 1;
        for (int j = 0; j < N; j += tmp)
        {
            for (int k = 0; k < i; k++)
            {
                int x = c[j + k], y = c[j + k + i];
                if (tf_utf)
                {
                    c[j + k] = x + y;
                    if (c[j + k] >= MOD)
                    {
                        c[j + k] -= MOD;
                    }
                    c[j + k + i] = x - y;
                    if (c[j + k + i] < 0)
                    {
                        c[j + k + i] += MOD;
                    }
                }
                else
                {
                    c[j + k] = (ll)(x + y) * INV_2 % MOD;
                    c[j + k + i] = (ll)(x - y + MOD) * INV_2 % MOD;
                }
            }
        }
    }
}

int QPow(int a, int k)
{
    int ret = 1;
    while (k)
    {
        if (k & 1)
        {
            ret = (ll)ret * a % MOD;
        }
        a = (ll)a * a % MOD;
        k >>= 1;
    }
    
    return ret;
}

int n, t;

int main()
{
    scan_d(n), scan_d(t);
    
    N = 1 << n;
    for (int i = 0; i < N; i++)
    {
        scan_d(a[i]);
    }
    
    b[0] = 1;
    for (int i = 0; i < n; i++)
    {
        b[1 << i] = 1;
    }
    
    FWT(a, 1);
    FWT(b, 1);
    
    for (int i = 0; i < N; i++)
    {
        a[i] = (ll)a[i] * QPow(b[i], t) % MOD;
    }
    
    FWT(a, 0);
    
    for (int i = 0; i < N; i++)
    {
        print_d((a[i] + MOD) % MOD);
        putchar(' ');
    }
    putchar(10);
    
    return 0;
}
