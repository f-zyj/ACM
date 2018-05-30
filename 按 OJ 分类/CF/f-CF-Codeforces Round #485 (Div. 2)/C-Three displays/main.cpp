//
//  main.cpp
//  f-CF-Codeforces Round #485 (Div. 2)
//
//  Created by ZYJ on 2018/5/30.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 3333;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int n;
int s[MAXN];
int c[MAXN];
long long dp[5][MAXN];

int main(int argc, const char * argv[])
{
#if DEBUG
    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    freopen("/Users/zyj/Desktop/output.txt", "w", stdout);
#endif
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", s + i);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", c + i);
    }
    
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        dp[1][i] = c[i];
    }
    
    for (int i = 2; i <= 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < j; k++)
            {
                if (s[j] > s[k])
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + c[j]);
                }
            }
        }
    }
    
    long long ans = INF;
    for (int i = 0; i < n; i++)
    {
        if (dp[3][i] < ans)
        {
            ans = dp[3][i];
        }
    }
    
    if (ans == INF)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans << '\n';
    }
    
    return 0;
}
