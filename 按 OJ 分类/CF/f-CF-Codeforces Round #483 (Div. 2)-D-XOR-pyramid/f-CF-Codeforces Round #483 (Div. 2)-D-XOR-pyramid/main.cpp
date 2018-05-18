//
//  main.cpp
//  f-CF-Codeforces Round #483 (Div. 2)-D-XOR-pyramid
//
//  Created by ZYJ on 2018/5/15.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 5555;

int n, q;
int a[MAXN];
int dp[MAXN][MAXN];
int dp_1[MAXN][MAXN];

int fun_dp(int l, int r)
{
    if (~dp[l][r])
    {
        return dp[l][r];
    }
    if (l == r)
    {
        return dp[l][r] = a[l];
    }
    return dp[l][r] = fun_dp(l + 1, r) ^ fun_dp(l, r - 1);
}

int fun_dp_1(int l, int r)
{
    if (~dp_1[l][r])
    {
        return dp_1[l][r];
    }
    if (l == r)
    {
        return dp_1[l][r] = dp[l][r];
    }
    return dp_1[l][r] = max(dp[l][r], max(fun_dp_1(l + 1, r), fun_dp_1(l, r - 1)));
}

int main(int argc, const char * argv[])
{
    memset(dp, -1, sizeof(dp));
    memset(dp_1, -1, sizeof(dp_1));
    
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
    }
    
    cin >> q;
    int l, r;
    while (q--)
    {
        scanf("%d%d", &l, &r);
        fun_dp(l, r);
        fun_dp_1(l, r);
        printf("%d\n", dp_1[l][r]);
    }
    
    return 0;
}
