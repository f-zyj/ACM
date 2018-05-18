//
//  main.cpp
//  f-HDU-2017"百度之星"程序设计大赛-初赛(B)-1006-小小粉丝度度熊
//
//  Created by ZYJ on 2017/8/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int n, m;
ll C[MAXN];

struct node
{
    ll l, r;
} A[MAXN], B[MAXN];

int cmp(node a, node b)
{
    if (a.l != b.l)
    {
        return a.l < b.l;
    }
    return a.r < b.r;
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lld%lld", &A[i].l, &A[i].r);
        }
        sort(A, A + n, cmp);
        
        int cnt = 1;
        B[cnt++] = A[0];
        for (int i = 1; i < n; i++)
        {
            if (A[i].l <= B[cnt - 1].r)
            {
                B[cnt - 1].r = max(B[cnt - 1].r, A[i].r);
            }
            else
            {
                B[cnt++] = A[i];
            }
        }
        
        C[0] = 0;
        C[1] = B[1].r - B[1].l + 1;
        for (int i = 2; i < cnt; i++)
        {
            C[i] = C[i - 1] + (B[i].r - B[i].l) + 1;
        }
        
        ll ans = 0;
        for (int i = 1, j = 1; i < cnt; i++)
        {
            while (j < cnt && (B[j].r - B[i].l + 1 - (C[j] - C[i - 1]) <= m))
            {
                ans = max(ans, B[j].r - B[i].l + 1);
                j++;
            }
            ll tmp = B[j - 1].r - B[i].l + 1;
            ll tep = tmp - (C[j - 1] - C[i - 1]);
            if (m >= tep)
            {
                tep = m - tep;
            }
            else
            {
                tep = 0;
            }
            ans = max(ans, tmp + tep);
        }
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
