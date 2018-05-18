//
//  main.cpp
//  f-NYOJ-1255-Rectangles
//
//  Created by ZYJ on 2017/5/8.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 110;

int dp[MAXN];

struct Rct
{
    int r, c;
} R[MAXN];

bool cmp(Rct a, Rct b)
{
    if (a.r != b.r)
    {
        return a.r < b.r;
    }
    return a.c < b.c;
}

int main()
{
    int T;
    cin >> T;
    
    int n;
    while (T--)
    {
        cin >> n;
        int r, c;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &r, &c);
            if (r < c)
            {
                swap(r, c);
            }
            dp[i] = 1;
            R[i].r = r;
            R[i].c = c;
        }
        sort(R, R + n, cmp);
        
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[i] < dp[j] + 1 && R[i].r >= R[j].r && R[i].c >= R[j].c)
                {
                    dp[i] = dp[j] + 1;
                    res = max(res, dp[i]);
                }
            }
        }
        
        cout << res << '\n';
    }
    
    return 0;
}
