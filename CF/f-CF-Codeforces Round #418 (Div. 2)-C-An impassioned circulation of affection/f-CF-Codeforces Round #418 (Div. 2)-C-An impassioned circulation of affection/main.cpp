//
//  main.cpp
//  f-CF-Codeforces Round #418 (Div. 2)-C-An impassioned circulation of affection
//
//  Created by ZYJ on 2017/6/15.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1555;
const int MAXC = 26;

int n, q;
char str[MAXN];
int dp[MAXC][MAXN];

int main()
{
    while (cin >> n)
    {
        memset(dp, 0, sizeof(dp));
        
        scanf("%s", str);
        
        for (int i = 0; i < MAXC; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = j;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            int c = str[i] - 'a';
            int tmp = 1, k = i + 1;
            dp[c][0] = 1;
            for (int j = 0; j <= n; )
            {
                if (k >= n || str[i] != str[k])
                {
                    j++;
                }
                tmp++;
                if (tmp == n)
                {
                    while (j <= n)
                    {
                        dp[c][j++] = n;
                    }
                    break;
                }
                dp[c][j] = max(dp[c][j], tmp);
                k++;
            }
        }
        
        cin >> q;
        
        int m;
        char c[3];
        while (q--)
        {
            scanf("%d%s", &m, c);
            printf("%d\n", dp[c[0] - 'a'][m]);
        }
    }
    
    return 0;
}
