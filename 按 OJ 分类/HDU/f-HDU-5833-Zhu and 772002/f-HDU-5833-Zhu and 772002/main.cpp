//
//  main.cpp
//  f-HDU-5833-Zhu and 772002
//
//  Created by ZYJ on 2017/9/4.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 333;
const int MAXM = 2e3 + 10;
const int MOD = 1e9 + 7;

using namespace std;

//  高斯消元法求方程组的解

//  有equ个方程，var个变元。增广矩阵行数为equ，列数为var＋1，分别为0到var
int equ, var;
int a[MAXN][MAXN];  	//  增广矩阵
int x[MAXN];        	//  解集
int free_x[MAXN];   	//  用来存储自由变元（多解枚举自由变元可以使用）
int free_num;       	//  自由变元的个数


int Gauss()
{
    int max_r, col, k;
    free_num = 0;
    for (k = 0, col = 0; k < equ && col < var; k++, col++)
    {
        max_r = k;
        for (int i = k + 1; i < equ; i++)
        {
            if (abs(a[i][col]) > abs(a[max_r][col]))
            {
                max_r = i;
            }
        }
        if (a[max_r][col] == 0)
        {
            k--;
            free_x[free_num++] = col;   	//  这是自由变元
            continue;
        }
        
        if (max_r != k)
        {
            for (int j = col; j < var + 1; j++)
            {
                swap(a[k][j], a[max_r][j]);
            }
        }
        for (int i = k + 1; i < equ; i++)
        {
            if (a[i][col] != 0)
            {
                for (int j = col; j < var + 1; j++)
                {
                    a[i][j] ^= a[k][j];
                }
            }
        }
    }
    
    return k;
}

int mx_p;
ll p[MAXM];
bool prime[MAXM];

void isprime()
{
    mx_p = 0;
    memset(prime, false, sizeof(prime));
    
    for (ll i = 2; i < MAXM; i++)
    {
        if (!prime[i])
        {
            p[mx_p++] = i;
            for (ll j = i * i; j < MAXM; j += i)
            {
                prime[j] = true;
            }
        }
    }
}

ll quick_mod(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % MOD;
        }
        b >>= 1;
        a = (a * a) % MOD;
    }
    
    return ans;
}

int main()
{
    isprime();
    equ = mx_p;
    
    int T;
    scanf("%d", &T);
    
    for (int cs = 1; cs <= T; cs++)
    {
        memset(a, 0, sizeof(a));
        
        cin >> var;
        
        ll x, sum;
        for (int i = 0; i < var; i++)
        {
            scanf("%lld", &x);
            for (int j = 0; j < equ; j++)
            {
                sum = 0;
                if (x % p[j] == 0)
                {
                    ll tmp = x;
                    while (tmp % p[j] == 0)
                    {
                        sum++;
                        tmp /= p[j];
                    }
                }
                
                if (sum & 1)
                {
                    a[j][i] = 1;
                }
                else
                {
                    a[j][i] = 0;
                }
            }
        }
        
        ll ans = var - Gauss();
        ll ret = quick_mod(2ll, ans);
        ret--;
        ret = (ret % MOD + MOD) % MOD;
        
        printf("Case #%d:\n%lld\n", cs, ret);
    }
    
    return 0;
}
