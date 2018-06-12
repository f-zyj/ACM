//
//  main.cpp
//  f-CF-Codeforces Round #487 (Div. 2)
//
//  Created by ZYJ on 2018/6/12.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int n, l, w;
int a[MAXN], b[MAXN];

int main()
{
    while (cin >> n >> l >> w)
    {
        long long ans = 0;
        
        int x, v, cnt_a = 0, cnt_b = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &x, &v);
            
            if (v == 1)
            {
                a[++cnt_a] = x;
            }
            if (v == -1)
            {
                b[++cnt_b] = x;
            }
        }
        sort(a + 1, a + 1 + cnt_a);
        sort(b + 1, b + 1 + cnt_b);
        
        for (int i = 1, j = 1; i <= cnt_a; i++)
        {
            for (; j <= cnt_b; j++)
            {
                if (b[j] < a[i])
                {
                    continue;
                }
                
                double tmp = b[j] - a[i] + l;
                double x = tmp / 2 + a[i];
                if (x < 0)
                {
                    x = -x;
                }
                
                if ((tmp / 2) * w > x)
                {
                    break;
                }
            }
            
            if (j > cnt_b)
            {
                break;
            }
            
            ans += cnt_b - j + 1;
        }
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
