//
//  main.cpp
//  f-NYOJ-37-回文字符串
//
//  Created by ZYJ on 16/6/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include<iostream>
#include<cstring>

using namespace std;

/*
 *  逆置原字符串 和原字符串求最大公共子序列的长度 总长度减去该长度 即为所求
 */
const int MAXN = 1001;
int dp[MAXN][MAXN];
char sOne[MAXN];
char sTwo[MAXN];

int main()
{
    int N;
    cin >> N;
    while(N--)
    {
        int i, j;
        cin >> sOne;
        int len = (int)strlen(sOne);
        //  倒置
        for(i = len - 1, j = 0; i >= 0; i--, j++)
        {
            sTwo[j] = sOne[i];
        }
        for(i = 1; i <= len; i++)
        {
            for(j = 1;j <= len;j++)
            {
                if(sOne[i - 1] == sTwo[j - 1])
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