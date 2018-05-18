//
//  main.cpp
//  f-最长公共子序列
//
//  Created by ZYJ on 16/7/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

const int N = 1010;

int a[N][N];

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

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
