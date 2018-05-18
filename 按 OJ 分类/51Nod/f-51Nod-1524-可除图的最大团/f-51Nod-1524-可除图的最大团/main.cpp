//
//  main.cpp
//  f-51Nod-1524-可除图的最大团
//
//  Created by ZYJ on 2016/12/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e6 + 10;

int num[MAXN];
int dp[MAXN];   //  dp[i]:以i为最小值的最大团点数

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9') ;
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scan_d(num[i]);
    }
    sort(num, num + n);
    
    int ans = 1;
    dp[num[n - 1]] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        int maxDP = 0;
        for (int j = 2 * num[i]; j <= num[n - 1]; j += num[i])
        {
            maxDP = max(maxDP, dp[j]);
        }
        dp[num[i]] = maxDP + 1;
        ans = max(ans, dp[num[i]]);
    }
    
    printf("%d\n", ans);
    
    return 0;
}
