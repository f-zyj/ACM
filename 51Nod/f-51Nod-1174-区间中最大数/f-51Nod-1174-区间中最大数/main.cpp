//
//  main.cpp
//  f-51Nod-1174-区间中最大数
//
//  Created by ZYJ on 16/7/26.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 *  求最大值,数组下标从1开始。
 *  求最小值,或者最大最小值下标,或者数组从0开始对应修改即可。
 */
const int MAXN = 10010;
int dp[MAXN][20];
int mm[MAXN];

//  初始化RMQ,b数组下标从1开始,从0开始简单修改
void initRMQ(int n, int b[])
{
    mm[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        mm[i] = ((i & (i - 1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
        dp[i][0] = b[i];
    }
    for (int j = 1; j <= mm[n]; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
}

//  查询最大值
int rmq(int x, int y)
{
    int k = mm[y - x + 1];
    return max(dp[x][k], dp[y - (1 << k) + 1][k]);
}

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    int b[MAXN];
    for (int i = 1; i <= N; i++)
    {
        cin >> b[i];
    }
    initRMQ(N, b);
    int Q;
    cin >> Q;
    int left, right;
    for (int i = 0; i < Q; i++)
    {
        cin >> left >> right;
        cout << rmq(left + 1, right + 1) << '\n';
    }
    return 0;
}
