//
//  main.cpp
//  f-BZOJ-2301-[HAOI2011]Problem b
//
//  Created by ZYJ on 16/7/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

//  莫比乌斯反演

/*
 *  对于给出的n个询问，每次球有多少个数对儿(x, y)，满足a ≤ x ≤ b，c ≤ y ≤ d，且gcd(x, y) = k
 *  gcd(x, y)函数为x和y的最大公约数
 *  1 ≤ n ≤ 50000, 1 ≤ a ≤ b ≤ 50000, 1 ≤ c ≤ d ≤ 50000, 1 ≤ k ≤ 50000
 */

const int MAXN = 100000;
bool check[MAXN + 10];
int prime[MAXN + 10];
int mu[MAXN + 10];

void Moblus()
{
    memset(check, false, sizeof(check));
    mu[1] = 1;
    int tot = 0;
    for (int i = 2; i <= MAXN; i++)
    {
        if (!check[i])
        {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > MAXN)
            {
                break;
            }
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            else
            {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
    return ;
}

int sum[MAXN + 10];

//  找[1, n], [1, m]内互质的数的对数
long long solve(int n, int m)
{
    long long ans = 0;
    if (n > m)
    {
        swap(n, m);
    }
    for (int i = 1, la = 0; i <= n; i = la + 1)
    {
        la = min(n / (n / i), m / (m / i));
        ans += (long long)(sum[la] - sum[i - 1]) * (n / i) * (m / i);
    }
    return ans;
}

int main(int argc, const char * argv[])
{
    Moblus();
    sum[0] = 0;
    for (int i = 1; i <= MAXN; i++)
    {
        sum[i] = sum[i - 1] + mu[i];
    }
    int a, b, c, d, k;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        long long ans = solve(b / k, d / k) - solve((a - 1) / k, d / k) - solve(b / k, (c - 1) / k) + solve((a - 1) / k, (c - 1) / k);
        printf("%lld\n", ans);
    }
    return 0;
}