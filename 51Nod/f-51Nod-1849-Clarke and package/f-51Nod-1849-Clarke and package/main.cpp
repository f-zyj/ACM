//
//  main.cpp
//  f-51Nod-1849-Clarke and package
//
//  Created by ZYJ on 2017/12/9.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 3000;
const int MAGIC_I = 10000;
const double MAGIC_D = 0.0001;

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

struct package
{
    int c, p, id;
} pac[MAXN];

bool cmp(const package &x, const package &y)
{
    return x.c < y.c;
}

int n, m;
int tmp[MAXN];
double dp[MAXN];

int main()
{
    scan_d(n);
    scan_d(m);
    
    int k, tot = 0;
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        scan_d(k);
        while (k--)
        {
            tot++;
            scan_d(pac[tot].c);
            scan_d(pac[tot].p);
            pac[tot].id = i;
        }
    }
    
    sort(pac + 1, pac + 1 + tot, cmp);
    
    for (int i = tot; i; i--)
    {
        for (int j = 0; j < n; j++)
        {
            dp[j] = 0;
        }
        dp[0] = 1;
        
        for (int j = 1; j <= n; j++)
        {
            if (j != pac[i].id)
            {
                for (int k = n - 1; k; k--)
                {
                    dp[k] = dp[k] * (MAGIC_I - tmp[j]) * MAGIC_D + dp[k - 1] * tmp[j] * MAGIC_D;
                }
                dp[0] *= (MAGIC_I - tmp[j]) * MAGIC_D;
            }
        }
        
        for (int j = 0; j < m; j++)
        {
            ans += dp[j] * pac[i].c * pac[i].p * MAGIC_D;
        }
        tmp[pac[i].id] += pac[i].p;
    }
    
    printf("%.8lf\n", ans);
    
    return 0;
}
