//
//  main.cpp
//  f-CF-Codeforces Round #210 (Div. 1)-A-Levko and Array Recovery
//
//  Created by ZYJ on 2017/3/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 5e4 + 10;
const int INF = 0x3f3f3f3f;

int n, m;
int a[MAXN], cnt[MAXN];
int op[MAXN], l[MAXN], r[MAXN], d[MAXN];

int main()
{
    memset(a, 0x3f, sizeof(a));
    memset(cnt, 0, sizeof(cnt));
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d%d", op + i, l + i, r + i, d + i);
        
        if (op[i] == 1)
        {
            for (int j = l[i]; j <= r[i]; j++)
            {
                cnt[j] += d[i];
            }
        }
        else
        {
            for (int j = l[i]; j <= r[i]; j++)
            {
                a[j] = min(a[j], d[i] - cnt[j]);
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == INF)
        {
            cnt[i] = a[i] = 0;
        }
        else
        {
            cnt[i] = a[i];
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (op[i] == 1)
        {
            for (int j = l[i]; j <= r[i]; j++)
            {
                cnt[j] += d[i];
            }
        }
        else
        {
            int MAX_ = -INF;
            for (int j = l[i]; j <= r[i]; j++)
            {
                MAX_ = max(MAX_, cnt[j]);
            }
            if (MAX_ != d[i])
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    
    printf("YES\n");
    for (int i = 1; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n]);
    
    return 0;
}
