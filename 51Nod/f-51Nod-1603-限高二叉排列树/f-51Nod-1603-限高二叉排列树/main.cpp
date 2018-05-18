//
//  main.cpp
//  f-51Nod-1603-限高二叉排列树
//
//  Created by ZYJ on 2017/3/7.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 40;

ll dp[MAXN][MAXN];  //  dp[i][j] i 个结点且高度小于等于 j 的树个数

int main()
{
    int n, h;
    scanf("%d%d", &n, &h);
    
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= i; k++)
            {
                dp[i][j] += dp[k - 1][j - 1] * dp[i - k][j - 1];    //  乘法原理合并树
            }
        }
    }
    
    cout << dp[n][n] - dp[n][h - 1] << endl;
    
    return 0;  
}
