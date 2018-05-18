//
//  main.cpp
//  f-51Nod-1202-子序列个数
//
//  Created by ZYJ on 16/8/26.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

int n;
int pos[MAXN];  //  pos[i]i元素上次出现的位置
int val[MAXN];  //  元素
long long dp[MAXN];

int main()
{
    int i;
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++)
    {
        scanf("%d", val + i);
    }
    for (i = 1; i <= n; i++)
    {
        if (pos[val[i]] == 0)   //  如果该元素没有出现过
        {   //  前i个组成的序列加上与第i个组合的序列再加上第i个单独作为序列
            dp[i] = (dp[i - 1] * 2 + 1) % MOD;
        }
        else
        {   //  前i个组成的序列加上与第i个组合的序列减去以这个元素为结尾的次数
            dp[i] = (dp[i - 1] * 2 - dp[pos[val[i]] - 1] + MOD) % MOD;
        }
        pos[val[i]] = i;
    }
    
    printf("%lld\n", dp[n]);
    
    return 0;
}
