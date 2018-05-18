//
//  main.cpp
//  f-51Nod-1043-幸运号码
//
//  Created by ZYJ on 16/8/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

#define maxn 1005

using namespace std;

const int mod = 1e9 + 7;

long long dp[2][9 * maxn];  //  滚动数组

int n;

int main()
{
    //freopen("i.txt","r",stdin);
    //freopen("o.txt","w",stdout);
    
    int i, j, k;
    long long ans;
    cin >> n;
    
    //  初始化
    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1;               //  两位和为1的只有一种
    for (i = 0; i <= 9; ++i)
    {
        dp[1][i] = 1;           //  1位和为i的只有一种
    }
    
    for (i = 2; i <= n; i++)
    {
        for (k = 0; k <= n * 9; k++)    //  dp[i][k]可以由dp[i-1][k-j]提供，j为0~9
        {
            long long sum = 0;
            for (j = 0; j <= 9; j++)
            {
                if (k >= j)
                {
                    sum = (sum + dp[(i - 1) & 1][k - j]) % mod;
                }
                else
                {
                    break;              //  无法通过减去一位j的状态提供
                }
            }
            dp[i & 1][k] = sum;         //  更新
        }
    }
    
    ans = 0;
    for (i = 0; i <= n * 9; i++)
    {
        ans = (ans + dp[n & 1][i] * (dp[n & 1][i] - dp[(n - 1) & 1][i])) % mod; //  把0去掉的方法就是dp[n][i]-dp[n-1][i]
    }
    
    cout << ans << endl;
    
    return 0;
}
