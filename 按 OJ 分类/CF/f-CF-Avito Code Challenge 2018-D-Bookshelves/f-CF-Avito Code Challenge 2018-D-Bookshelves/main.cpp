//
//  main.cpp
//  f-CF-Avito Code Challenge 2018-D-Bookshelves
//
//  Created by ZYJ on 2018/5/27.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 70;

int n, k;
ll a[MAXN];
ll s[MAXN];
ll dp[MAXN][MAXN];

int main(int argc, const char * argv[])
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    
    ll base_ = 0;
    for (int bit = 60; bit >= 0; bit--)
    {
        ll cnt = 1ll << bit;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        
        for (int i = 1; i <= k; i++)        //  i 堆
        {
            for (int j = 1; j <= n; j++)    //  前 j 个数
            {
                for (int k = 0; k < j; k++) //  前 k < j 个数
                {
                    if (dp[i - 1][k] && ((s[j] - s[k]) & cnt) && (((s[j] - s[k]) & base_) == base_))
                    {
                        dp[i][j] = 1;
                    }
                }
            }
        }
        
        if (dp[k][n])
        {
            base_ += cnt;
        }
    }
    
    cout << base_ << '\n';
    
    return 0;
}
