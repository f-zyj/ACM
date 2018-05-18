//
//  main.cpp
//  f-51Nod-1564-区间的价值
//
//  Created by ZYJ on 2017/6/14.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int n;
int A[MAXN];
ll ans[MAXN];

void solve(int l, int r)
{
    if (l > r)
    {
        return ;
    }
    
    int max_ = 0, min_ = INF;
    int maxp = 0, minp = 0;
    for (int i = l; i <= r; i++)
    {
        if (A[i] > max_)
        {
            max_ = A[i];
            maxp = i;
        }
        if (A[i] < min_)
        {
            min_ = A[i];
            minp = i;
        }
    }
    
    int len = abs(maxp - minp) + 1;
    for (int i = r - l + 1; i >= len; i--)
    {
        ans[i] = max(ans[i], (ll)min_ * max_);
    }
    solve(l, minp - 1);
    solve(minp + 1, r);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
    }
    
    solve(1, n);
    for (int i = 1; i <= n; i++)
    {
        printf("%lld\n", ans[i]);
    }
    
    return 0;
}
