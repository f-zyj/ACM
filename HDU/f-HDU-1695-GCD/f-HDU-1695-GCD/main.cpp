//
//  main.cpp
//  f-HDU-1695-GCD
//
//  Created by ZYJ on 2017/9/26.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 7;

int a, b, c, d, k, cnt;
int pri[MAXN];
int miu[MAXN];
bool vis[MAXN];

void init()
{
    memset(pri, 0, sizeof(pri));
    memset(miu, 0, sizeof(miu));
    memset(vis, 0, sizeof(vis));
    miu[1] = 1;
    cnt = 0;
    for (int i = 2; i < MAXN; i++)
    {
        if (!vis[i])
        {
            pri[cnt++] = i;
            miu[i] = -1;
        }
        for (int j = 0; j < cnt && i * pri[j] < MAXN; j++)
        {
            vis[i * pri[j]] = 1;
            if (i % pri[j])
            {
                miu[i * pri[j]] = -miu[i];
            }
            else
            {
                miu[i * pri[j]] = 0;
                break;
            }
        }
    }
}

int main()
{
    init();
    
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        printf("Case %d: ", i);
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        
        if (k == 0)
        {
            puts("0");
            continue;
        }
        
        b /= k;
        d /= k;
        int t = min(b, d);
        long long ans1 = 0, ans2 = 0;
        for (int i = 1; i <= t; i++)
        {
            ans1 += (long long)miu[i] * (b / i) * (d / i);
        }
        for (int i = 1; i <= t; i++)
        {
            ans2 += (long long)miu[i] * (t / i) * (t / i);
        }
        
        printf("%lld\n", ans1 - (ans2 >> 1));
    }
    
    return 0;
}
