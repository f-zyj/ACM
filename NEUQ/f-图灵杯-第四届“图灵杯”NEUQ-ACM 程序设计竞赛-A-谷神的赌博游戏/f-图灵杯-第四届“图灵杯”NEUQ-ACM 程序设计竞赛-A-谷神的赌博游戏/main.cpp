//
//  main.cpp
//  f-图灵杯-第四届“图灵杯”NEUQ-ACM 程序设计竞赛-A-谷神的赌博游戏
//
//  Created by ZYJ on 2017/6/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//
//
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//const int MAXN = 22;
//
//int n;
//double dp[MAXN][MAXN][MAXN][3];
//
//int main()
//{
//    int T;
//    cin >> T;
//    
//    while (T--)
//    {
//        memset(dp, 0, sizeof(dp));
//        
//        cin >> n;
//        int m = 3 * n + 1;
//        for (int i = 0; i <= n + 1; i++)
//        {
//            for (int j = 0; j <= n; j++)
//            {
//                for (int k = 0; k <= n; k++)
//                {
//                    if (i + j + k == 1)
//                    {
//                        if (i)
//                        {
//                            dp[i][j][k][1] = (n + 1) * 1.0 / m;
//                        }
//                        else if (j)
//                        {
//                            dp[i][j][k][2] = n * 1.0 / m;
//                        }
//                        continue;
//                    }
//                    
//                    int now = m - i - j - k + 1;
//                    dp[i][j][k][1] = (j == 0 ? 0 : dp[i][j - 1][k][2] * (n - j + 1) / now)
//                                   + (k == 0 ? 0 : dp[i][j][k - 1][1] * (n - k + 1) / now);
//                    dp[i][j][k][2] = (i == 0 ? 0 : dp[i - 1][j][k][1] * (n - i + 2) / now)
//                                   + (k == 0 ? 0 : dp[i][j][k - 1][2] * (n - k + 1) / now);
//                }
//            }
//        }
//        
//        printf("%.9lf\n", dp[n + 1][n][n][1]);
//    }
//    
//    return 0;
//}

#include <cstdio>

int n;
double ans;

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d", &n);
        
        ans = (n + 1.0) / (3 * n + 1);
        for (int i = 1; i <= n; i++)
        {
            ans = ans * i / (i + n);
        }
        
        printf("%.9f\n", ans);
    }
    
    return 0;
}

