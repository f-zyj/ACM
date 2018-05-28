//
//  main.cpp
//  f-CF-Avito Code Challenge 2018-E-Addition on Segments
//
//  Created by ZYJ on 2018/5/28.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e4 + 5;

struct Q
{
    int l, r, x;
    bool operator < (const Q &rhs) const
    {
        return r < rhs.r;
    }
} qs[MAXN];

int n, q;
int dp[MAXN];

int main()
{
    scanf("%d%d", &n, &q);
    
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d%d", &qs[i].l, &qs[i].r, &qs[i].x);
    }
    sort(qs, qs + q);
    
    for (int i = 0; i < q; i++)
    {
        int l = qs[i].l, r = qs[i].r, x = qs[i].x;
        for (int j = n - x; j >= 1; j--)
        {
            if (dp[j] >= l)
            {
                dp[j + x] = max(dp[j + x], dp[j]);
            }
        }
        dp[x] = r;
    }
    
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += (dp[i] > 0);
    }
    
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] > 0)
        {
            printf("%d ", i);
        }
    }
    puts("");
    
    return 0;
}
