//
//  main.cpp
//  f-HDU-2017 多校训练赛10-1010-Schedule
//
//  Created by ZYJ on 2017/8/28.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 5;

int n;

struct node
{
    int s, e;
} a[MAXN];

bool cmp(node a, node b)
{
    return a.s < b.s;
}

multiset<int> msi;

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d", &n);
    
        msi.clear();
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &a[i].s, &a[i].e);
        }
        sort(a, a + n, cmp);
        
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            auto it = msi.upper_bound(a[i].s);
            if (it == msi.begin())
            {
                ans += a[i].e - a[i].s;
                msi.insert(a[i].e);
            }
            else
            {
                it--;
                ans += a[i].e - *it;
                msi.erase(it);
                msi.insert(a[i].e);
            }
        }
        
        printf("%lu %lld\n", msi.size(), ans);
    }
    
    return 0;
}
