//
//  main.cpp
//  f-HDU-2017 多校训练赛6-1008-Kirinriki
//
//  Created by ZYJ on 2017/8/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 5555;
const int MAXM = MAXN >> 1;

int n, m;
int cnt, ans;
int tmp[MAXM];
char s[MAXN];

void check()
{
    int dis = 0, dis2 = 0, x1 = 0, x2 = 0;
    while (x2 < cnt)
    {
        dis2 += tmp[x2++];
        while (dis2 > m)
        {
            dis2 -= tmp[x1++];
        }
        dis = max(dis, x2 - x1);
    }
    ans = max(ans, dis);
}

void solve()
{
    n = (int)strlen(s + 1);
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt = 0;
        int x1 = i - 1;
        int x2 = i + 1;
        while (x1 > 0 && x2 <= n)
        {
            tmp[cnt++] = abs(s[x1--] - s[x2++]);
        }
        check();
    }
    for (int i = 1; i <= n; i++)
    {
        cnt = 0;
        int x1 = i;
        int x2 = i + 1;
        while (x1 > 0 && x2 <= n)
        {
            tmp[cnt++] = abs(s[x1--] - s[x2++]);
        }
        check();
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%s",&m, s + 1);
        
        solve();
        
        printf("%d\n", ans);
    }
    
    return  0;
}
