//
//  main.cpp
//  f-HDU-5883-The Best Path
//
//  Created by ZYJ on 2017/6/28.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 7;

int n, m;
int a[MAXN];
int degree[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        memset(degree, 0, sizeof(degree));
        
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        
        int u, v;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &u, &v);
            degree[u]++;
            degree[v]++;
        }
        
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (degree[i] & 1)
            {
                cnt++;
            }
        }
        if (cnt != 0 && cnt != 2)
        {
            printf("Impossible\n");
            continue;
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            degree[i] = (degree[i] + 1) >> 1;
            if (degree[i] & 1)
            {
                ans ^= a[i];
            }
        }
        int tmp = 0;
        if (cnt == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                tmp = max(tmp, ans ^ a[i]);
            }
            ans = tmp;
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
