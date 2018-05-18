//
//  main.cpp
//  f-51Nod-1671-货物运输
//
//  Created by ZYJ on 2017/9/23.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 5e5 + 10;
const int INF = 0x3f3f3f3f;

int n, m;
int l[MAXN], r[MAXN];

bool check(int m)
{
    int st_l = -INF, st_r = INF, ed_l = -INF, ed_r = INF;
    for (int i = 1; i <= n; i++)
    {
        if (r[i] - l[i] <= m)
        {
            continue;
        }
        
        st_l = max(st_l, l[i] + r[i] - m);
        st_r = min(st_r, l[i] + r[i] + m);
        ed_l = max(ed_l, l[i] - r[i] - m);
        ed_r = min(ed_r, l[i] - r[i] + m);
        if (st_l > st_r)
        {
            return 0;
        }
        if (ed_l > ed_r)
        {
            return 0;
        }
    }
    
    return 1;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", l + i, r + i);
    }
    for (int i = 1; i <= m; i++)
    {
        if (l[i] > r[i])
        {
            swap(l[i], r[i]);
        }
    }
    
    int l = 0, r = n, m, ans = -1;
    while (l <= r)
    {
        m = (l + r) >> 1;
        if (check(m))
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
