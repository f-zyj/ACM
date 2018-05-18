//
//  main.cpp
//  f-腾讯2017暑期实习生编程题-A-构造回文
//
//  Created by ZYJ on 2017/3/7.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1010;

int a[MAXN][MAXN];

int LCS(const char *s1, const char *s2)
{   //  s1:0...m, s2:0...n
    int m = (int)strlen(s1), n = (int)strlen(s2);
    int i, j;
    a[0][0] = 0;
    for (i = 1; i <= m; ++i)
    {
        a[i][0] = 0;
    }
    for (i = 1; i <= n; ++i)
    {
        a[0][i] = 0;
    }
    for (i = 1; i <= m; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                a[i][j] = a[i - 1][j - 1] + 1;
            }
            else if (a[i - 1][j] > a[i][j - 1])
            {
                a[i][j]= a[i - 1][j];
            }
            else
            {
                a[i][j] = a[i][j - 1];
            }
        }
    }
    return a[m][n];
}

int main()
{
    char s[MAXN], s_[MAXN];
    
    while (~scanf("%s", s))
    {
        int len = (int)strlen(s);
        for (int i = 0; i < len; i++)
        {
            s_[len - i - 1] = s[i];
        }
        cout << len - LCS(s, s_) << '\n';
    }
    
    return 0;
}
