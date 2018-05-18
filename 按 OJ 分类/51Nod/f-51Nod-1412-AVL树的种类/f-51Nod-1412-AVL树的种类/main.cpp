//
//  main.cpp
//  f-51Nod-1412-AVL树的种类
//
//  Created by ZYJ on 16/9/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
//
//#define LL long long
//#define P 1000000007
//#define MAXN 2000
//#define MAXL 15
//
//int min[MAXL + 1];
//int max[MAXL + 1];
//int dp[MAXN + 1][MAXL + 1];
//
//int solve(int n)
//{
//    min[0] = max[0] = 0;    //
//    min[1] = max[1] = 1;    //  第i层的最右端结点序号
//    for (int i = 2; i <= MAXL; ++i)
//    {
//        min[i] = min[i - 1] + min[i - 2] + 1;
//        max[i] = (1 << i) - 1;
//    }
//    
//    dp[0][0] = dp[1][1] = 1;
//    for (int i = 2; i <= n; ++i)
//    {
//        for (int lv = 2; lv <= MAXL && i >= min[lv]; ++lv)
//        {
//            if (i > max[lv])
//            {
//                continue;
//            }
//            for (int x = 0, y = i - 1; y >= 0; ++x, --y)
//            {
//                dp[i][lv] = (dp[i][lv] + (LL)dp[x][lv - 1] * dp[y][lv - 1]
//                          + (LL)dp[x][lv - 1] * dp[y][lv - 2]
//                          + (LL)dp[x][lv - 2] * dp[y][lv - 1]) % P;
//            }
//        }
//    }
//    
//    int ans = 0;
//    for (int lv = 0; lv <= MAXL; ++lv)
//    {
//        ans = (ans + dp[n][lv]) % P;
//    }
//    
//    return ans;
//}
//
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    printf("%d\n", solve(n));
//    
//    return 0;
//}


#include <iostream>
#include <cstdio>

#define MOD 1000000007

using namespace std;

const int MAXN = 2001;
const int tier = 11;

typedef long long ll;

ll dp[MAXN][tier];

void init()
{
    dp[0][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        for (int k = 2; k < tier; k++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i][k] += dp[i - j - 1][k - 1] * dp[j][k - 1];
                dp[i][k] %= MOD;
                dp[i][k] += 2 * dp[i - j - 1][k - 2] * dp[j][k - 1];
                dp[i][k] %= MOD;
            }
        }
    }
    return ;
}

int main()
{
    int n;
 
    init();
    
    while (scanf("%d", &n) == 1)
    {
        ll ans = 0;
        for (int i = 1; i < tier; i++)
        {
            ans += dp[n][i];
            ans %= MOD;
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}
