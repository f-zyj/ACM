//
//  main.cpp
//  f-HDU-3461-Code Lock
//
//  Created by ZYJ on 2016/11/4.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>

const int MOD = 1e9 + 7;
const int MAXN = 1e7 + 10;

int pre[MAXN];
int count;

int find(int x)
{
    int r = x;
    while (r != pre[r])
    {
        r = pre[r];
    }
    
    int i = x;
    while (i != r)
    {
        int j = pre[i];
        pre[i] = r;
        i = j;
    }
    
    return r;
}

void join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    
    if (fx != fy)
    {
        pre[fx] = fy;
        count++;
    }
}

long long power(int n)
{
    long long sum = 1, tmp = 26;
    
    while (n)
    {
        if (n & 1)
        {
            sum = sum * tmp;
            sum %= MOD;
        }
        tmp = (tmp * tmp) % MOD;
        n >>= 1;
    }
    
    return sum;
}

int main()
{
    int n, m, l, r;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        count = 0;
        for (int i = 0; i <= n; i++)
        {
            pre[i] = i;
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &l, &r);
            join(l - 1, r);
        }
        
        printf("%lld\n", power(n - count) % MOD);
    }
    
    return 0;
}
