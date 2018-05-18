//
//  main.cpp
//  f-UVA-12260-Free Goodies
//
//  Created by ZYJ on 2017/10/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_LEN_NAME = 11;
const int MAXN = 1010;

struct Node
{
    int x, y;
    bool operator < (const Node &rhs) const
    {
        if (x != rhs.x)
        {
            return x > rhs.x;
        }
        return y < rhs.y;
    }
} arr[MAXN];

int n;
int dp[MAXN][MAXN >> 1];
int cost[MAXN][MAXN >> 1];
char name[MAX_LEN_NAME];

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d%s", &n, name);
        
        int sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d", &arr[i].x, &arr[i].y);
            sum += arr[i].x;
        }
        
        sort(arr + 1, arr + 1 + n);
        
        memset(dp, 0, sizeof(dp));
        memset(cost, 0, sizeof(cost));
        
        int cur = 0;
        int i = name[0] == 'P' ? 2 : 1;
        for (; i <= n; ++i)
        {
            ++cur;
            int t = (cur + 1) >> 1;
            for (int j = 1; j <= t; ++j)
            {
                int &ans = dp[i][j] = dp[i - 1][j];
                cost[i][j] = cost[i - 1][j];
                
                if (j == 1 || dp[i - 1][j - 1])
                {
                    int tmp = dp[i - 1][j - 1] + arr[i].y;
                    if (tmp > ans)
                    {
                        ans = tmp;
                        cost[i][j] = cost[i - 1][j - 1] + arr[i].x;
                    }
                    else if (tmp == ans)
                    {
                        cost[i][j] = min(cost[i][j], cost[i - 1][j - 1] + arr[i].x);
                    }
                }
            }
        }
        
        printf("%d %d\n", sum - cost[n][(cur + 1) >> 1], dp[n][(cur + 1) >> 1]);
    }
    
    return 0;
}
