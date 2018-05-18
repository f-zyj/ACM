//
//  main.cpp
//  f-51Nod-1455-宝石猎人
//
//  Created by ZYJ on 16/9/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cstdio>
//#include <cstring>
//
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 3e4 + 5;
//const int MAXM = 500;
//
//int res;
//int n, d, pos;
//int land[MAXN];
//int dp[MAXN][MAXM];     //  dp[i][j]表示走到第i个岛，上一步是j所捡的宝石数量
//
//void input()
//{
//    int stone;
//    pos = 0;
//    scanf("%d%d", &n, &d);
//    for (int i = 1; i < n; i++)
//    {
//        scanf("%d", &stone);
//        land[stone]++;
//    }
//    scanf("%d", &pos);
//    land[pos]++;
//    return ;
//}
//
//void solve()
//{
//    memset(dp, -1, sizeof(dp));
//    
//    int mid = MAXM / 2;   //  空间优化，mid是偏移值
//    dp[d][mid] = land[d];
//    for (int i = d; i <= pos; i++)
//    {
//        for (int j = 0; j < MAXM; j++)
//        {
//            if (dp[i][j] >= 0)
//            {
//                int next = d + j - mid;
//                for (int k = -1; k <= 1; k++)
//                {
//                    if (next + k >= 1 && i + next + k <= pos)
//                    {
//                        dp[i + next + k][j + k] = max(dp[i + next + k][j + k], dp[i][j] + land[i + next + k]);
//                    }
//                }
//            }
//        }
//    }
//    res = 0;
//    for (int i = d; i <= pos; i++)
//    {
//        for (int j = 0; j <= MAXM; j++)
//        {
//            res = max(res, dp[i][j]);
//        }
//    }
//    printf("%d", res);
//}
//
//int main()
//{
//    input();
//    solve();
//    
//    return 0;
//}


#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 3e4 + 1;

int val[MAXN];

void solve()
{
    int n, d;
    scanf("%d%d", &n, &d);
    
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        val[x]++;
    }
    
    int min_d, max_d, sum;
    sum = min_d = d;
    while (sum < MAXN && min_d > 1)
    {
        sum += --min_d;
    }
    sum = max_d = d;
    while (sum < MAXN)
    {
        sum += ++max_d;
    }
    
    vector<vector<int> > dp(MAXN, vector<int> (max_d - min_d + 1));
    
    //  从尾向前推
    for (int i = MAXN - 1; i >= d; i--)
    {
        for (int j = min_d; j <= max_d; j++)
        {
            int tmp = 0;
            if (i + j - 1 < MAXN && j != min_d)
            {
                tmp = max(tmp, dp[i + j - 1][j - 1 - min_d]);
            }
            if (i + j < MAXN)
            {
                tmp = max(tmp, dp[i + j][j - min_d]);
            }
            if (i + j + 1 < MAXN && j != max_d)
            {
                tmp = max(tmp, dp[i + j + 1][j + 1 - min_d]);
            }
            dp[i][j - min_d] = tmp + val[i];
        }
    }
    
    printf("%d\n", dp[d][d - min_d]);		
}

int main()
{
    solve();
    
    return 0;
}
