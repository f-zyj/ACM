//
//  main.cpp
//  f-HDU-2017 多校训练赛7-1010-Just do it
//
//  Created by ZYJ on 2017/8/15.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>

const int MAXN = 2e5 + 10;

int n, m;
int a[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        
        m--;
        int k = 1;
        while (k < n)
        {
            for (int i = n; i > k; i--)
            {
                a[i] ^= m & 1 ? 0 : a[i - k];
            }
            m >>= 1;
            k <<= 1;
        }
        
        for (int i = 1; i <= n; i++)
        {
            printf("%d%c", a[i], i == n ? '\n' : ' ');
        }
    }
    
    return 0;
}

