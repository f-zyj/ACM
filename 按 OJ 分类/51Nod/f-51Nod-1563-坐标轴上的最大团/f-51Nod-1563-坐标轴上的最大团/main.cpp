//
//  main.cpp
//  f-51Nod-1563-坐标轴上的最大团
//
//  Created by ZYJ on 2017/7/25.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 10;
const int INF = 0x3f3f3f3f;

struct node
{
    int l, r;
};

int n;
node a[MAXN];

bool cmp(node a, node b)
{
    if (a.r == b.r)
    {
        return a.l < b.l;
    }
    return a.r < b.r;
}

int main()
{
    cin >> n;
    
    int x, w;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &x, &w);
        a[i].l = x - w;
        a[i].r = x + w;
    }
    sort(a, a + n, cmp);
    
    int L = -INF;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].l >= L)
        {
            L = a[i].r;
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
