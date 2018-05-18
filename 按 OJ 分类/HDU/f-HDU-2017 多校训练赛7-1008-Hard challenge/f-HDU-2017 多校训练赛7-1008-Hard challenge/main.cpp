//
//  main.cpp
//  f-HDU-2017 多校训练赛7-1008-Hard challenge
//
//  Created by ZYJ on 2017/8/15.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 5e4 + 7;

struct node
{
    long long x;
    long long y;
    long long val;
    double deg;
    int flag;
    
    bool operator < (const node &p) const
    {
        return deg < p.deg;
    }
} edge[MAXN];

bool cmp(node a, node b)
{
    return a.deg > b.deg;
}

int n;

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d", &n);
        
        long long tmp1 = 0, tmp2 = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld%lld%lld", &edge[i].x, &edge[i].y, &edge[i].val);
            
            edge[i].deg = abs(edge[i].y) /
                sqrt((double)((edge[i].x * edge[i].x) + (edge[i].y * edge[i].y)));
            if ((edge[i].x < 0 && edge[i].y > 0) || (edge[i].x > 0 && edge[i].y < 0))
            {
                edge[i].deg += 1;
            }
            if (edge[i].y < 0)
            {
                edge[i].flag = -1;
                tmp2 += edge[i].val;
            }
            else if (edge[i].y == 0)
            {
                if (edge[i].x < 0)
                {
                    edge[i].flag = -1;
                    tmp2 += edge[i].val;
                }
                else
                {
                    edge[i].flag = 1;
                    tmp1 += edge[i].val;
                }
            }
            else
            {
                edge[i].flag = 1;
                tmp1 += edge[i].val;
            }
        }
        
        int flag = 0;
        long long ans = 0;
        sort(edge + 1, edge + 1 + n);
        for (int i = 1; i <= n; i++)
        {
            if (edge[i].deg > 1 && !flag)
            {
                flag = 1;
                sort(edge + i, edge + 1 + n, cmp);
                i--;
                continue;
            }
            if (edge[i].flag == 1)
            {
                ans = max(ans, tmp1 * tmp2);
                tmp1 -= edge[i].val;
                tmp2 += edge[i].val;
            }
            else
            {
                ans = max(ans, tmp1 * tmp2);
                tmp1 += edge[i].val;
                tmp2 -= edge[i].val;
            }
            ans = max(ans, tmp1 * tmp2);
        }
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
