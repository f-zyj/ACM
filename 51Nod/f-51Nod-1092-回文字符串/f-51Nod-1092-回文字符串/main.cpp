//
//  main.cpp
//  f-51Nod-1092-回文字符串
//
//  Created by ZYJ on 16/8/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1001;
int dp[MAXN][MAXN];
char sOne[MAXN];
char sTwo[MAXN];

int main()
{
    while(cin >> sOne)
    {
        int i, j;
        int len = (int)strlen(sOne);
        //  倒置
        for (i = len - 1, j = 0; i >= 0; i--, j++)
        {
            sTwo[j] = sOne[i];
        }
        for (i = 1; i <= len; i++)
        {
            for (j = 1;j <= len;j++)
            {
                if (sOne[i - 1] == sTwo[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        cout << len - dp[len][len] << endl;
    }
    return 0;
}
