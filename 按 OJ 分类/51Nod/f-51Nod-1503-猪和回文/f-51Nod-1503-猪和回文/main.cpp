//
//  main.cpp
//  f-51Nod-1503-猪和回文
//
//  Created by ZYJ on 2016/9/29.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>

const int MAXN = 5e2 + 5;
const int MOD = 1e9 + 7;

int N, M;
int dp[2][MAXN][MAXN];  //  枚举两个点x坐标
char s[MAXN][MAXN];

void add(int &x, int y)
{
    x += y;
    if (x >= MOD)
    {
        x -= MOD;
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        scanf("%s", s[i] + 1);
    }
    
    int cur = 0;
    dp[0][1][N] = (s[1][1] == s[N][M]);
    for (int step = 1; step <= (M + N - 2) / 2; step++)
    {
        cur ^= 1;
        for (int i = 0; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                dp[cur][i][j] = 0;
            }
        }
        for (int x_1 = 1; x_1 <= N && x_1 - 1 <= step; x_1++)
        {
            for (int x_2 = N; x_2 >= 1 && N - x_2 <= step; x_2--)
            {
                int y_1 = 1 + step - (x_1 - 1);
                int y_2 = M - (step - (N - x_2));
                if (s[x_1][y_1] != s[x_2][y_2])
                {
                    continue;
                }
                //  ⬇️⬆️
                add(dp[cur][x_1][x_2], dp[cur ^ 1][x_1][x_2]);
                //  ⬇️⬅️
                add(dp[cur][x_1][x_2], dp[cur ^ 1][x_1][x_2 + 1]);
                //  ➡️⬆️
                add(dp[cur][x_1][x_2], dp[cur ^ 1][x_1 - 1][x_2]);
                //  ➡️⬅️
                add(dp[cur][x_1][x_2], dp[cur ^ 1][x_1 - 1][x_2 + 1]);
            }
        }
    }
    int ans = 0;
    //  累计两个点x坐标都到同一位置的情况
    for (int i = 1; i <= N; i++)
    {
        add(ans, dp[cur][i][i]);
    }
    if ((N + M) % 2)    //  如果步数为奇数
    {
        for (int i = 1; i < N; i++)
        {
            add(ans, dp[cur][i][i + 1]);
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
