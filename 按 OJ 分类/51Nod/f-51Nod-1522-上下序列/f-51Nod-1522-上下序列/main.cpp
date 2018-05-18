//
//  main.cpp
//  f-51Nod-1522-上下序列
//
//  Created by ZYJ on 2017/7/25.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 72;
const int MAXK = 111;

int n, k;
char s[5];
int limit[MAXK][3];
ll dp[MAXN][MAXN];

// 0 < 1 <= 2 = 3 >= 4 >    这个部分最后画一下图，不然容易迷
bool charge(int t1, int t2, int l, int r)
{
    for (int i = 0; i < k; i++)
    {
        if ((limit[i][0] == t1 && limit[i][1] == t2) || (limit[i][0] == t2 && limit[i][1] == t1))
        {
            if (limit[i][2] == 0 || limit[i][2] == 4)
            {
                return false;
            }
        }
        else if (limit[i][0] == t1 || limit[i][0] == t2)
        {
            if (limit[i][1] >= l && limit[i][1] <= r)
            {
                if (limit[i][2] >= 2)
                {
                    return false;
                }
            }
        }
        else if (limit[i][1] == t1 || limit[i][1] == t2)
        {
            if (limit[i][0] >= l && limit[i][0] <= r)
            {
                if (limit[i][2] <= 2)
                {
                    return false;
                }
            }
        }
    }
    
    return true;
}

int main()
{
    scanf("%d%d", &n, &k);

    for (int i = 0; i < k;i++)
    {
        scanf("%d%s%d", &limit[i][0], s, &limit[i][1]);
        //  < <= = >= >
        if (s[0] == '<' && s[1] != '=')
        {
            limit[i][2] = 0;
        }
        else if (s[0] == '<')
        {
            limit[i][2] = 1;
        }
        else if (s[0] == '=')
        {
            limit[i][2] = 2;
        }
        else if (s[0] == '>' && s[1] == '=')
        {
            limit[i][2] = 3;
        }
        else
        {
            limit[i][2] = 4;
        }
    }
    for (int i = 2; i <= 2 * n; i += 2)             //  区间长度
    {
        for (int j = 1; j <= 2 * n - i + 1; j++)    //  左端点
        {
            int k = j + i - 1;                      //  右端点
            dp[j][k] = 0;
            if (i == 2)
            {
                if (charge(j, k, j + 1, k - 1))
                {
                    dp[j][k] = 1;
                }
            }
            else
            {
                if (charge(j, j + 1, j + 2, k))
                {
                    dp[j][k] += dp[j + 2][k];
                }
                if (charge(k - 1, k, j, k - 2))
                {
                    dp[j][k] += dp[j][k - 2];
                }
                if (charge(j, k, j + 1, k - 1))
                {
                    dp[j][k] += dp[j + 1][k - 1];
                }
            }
        }
    }

    printf("%lld\n", dp[1][2 * n]);
    
    return 0;
}
