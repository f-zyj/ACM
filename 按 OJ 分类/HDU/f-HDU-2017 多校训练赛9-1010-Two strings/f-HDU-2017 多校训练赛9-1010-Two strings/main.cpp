////
////  main.cpp
////  f-HDU-2017 多校训练赛9-1010-Two strings
////
////  Created by ZYJ on 2017/8/22.
////  Copyright © 2017年 ZYJ. All rights reserved.
////
//
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <cstdio>
//
//#define clr(a, b) memset(a, b, sizeof(a))
//
//using namespace std;
//
//const int MAXN = 2555;
//
//char str1[MAXN];
//char str2[MAXN];
//int dp[MAXN][MAXN];
//
//int main()
//{
//    int T;
//    scanf("%d", &T);
//    
//    while (T--)
//    {
//        clr(dp, 0);
//        str1[0] = str2[0] = str1[1] = str2[1] = '#';
//        
//        scanf("%s%s", str1 + 2, str2 + 2);
//        int n = (int)strlen(str1 + 1);
//        int m = (int)strlen(str2 + 1);
//        
//        dp[0][0] = dp[1][1] = 1;
//        for (int i = 1; i <= n; i++)
//        {
//            for (int j = 1; j <= m; j++)
//            {
//                if (str2[j] == '.')
//                {
//                    dp[i][j] |= dp[i - 1][j - 1] | dp[i][j - 1];
//                }
//                else
//                {
//                    if (str2[j] == '*')
//                    {
//                        dp[i][j] |= dp[i][j - 1] | dp[i][j - 2];
//                        if (str1[i - 1] == str1[i])
//                        {
//                            dp[i][j] |= dp[i - 1][j];
//                        }
//                    }
//                    else
//                    {
//                        if (str1[i] == str2[j])
//                        {
//                            dp[i][j] |= dp[i - 1][j - 1];
//                        }
//                        else
//                        {
//                            dp[i][j] = 0;
//                        }
//                    }
//                }
//            }
//        }
//        
//        if (dp[n][m])
//        {
//            puts("yes");
//        }
//        else
//        {
//            puts("no");
//        }
//    }
//    
//    return 0;
//}

#include <iostream>
#include <cstring>
#include <regex>

using namespace std;

const int MAXN = 2555;

char str1[MAXN];
char str2[MAXN];
char pt[MAXN << 1];

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> str1 >> str2;
        int len2 = (int)strlen(str2);
        int strPos = 0, ptPos = 0;
        while (strPos < len2)
        {
            if (str2[strPos] == '.' && str2[strPos + 1] == '*')
            {
                strcpy(pt + ptPos, "(.)\\1*");
                ptPos += 6;
                strPos += 2;
            }
            else
            {
                pt[ptPos++] = str2[strPos++];
            }
        }
        pt[ptPos] = 0;
        regex re(pt);
        if (regex_match(str1, re))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    
    return 0;
}
