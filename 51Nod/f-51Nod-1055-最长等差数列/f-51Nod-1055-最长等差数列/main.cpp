//
//  main.cpp
//  f-51Nod-1055-最长等差数列
//
//  Created by ZYJ on 2016/10/13.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>

using namespace std;

int const MAXN = 10005;
int a[MAXN];
short int dp[MAXN][MAXN]; //  dp[i][j]表示的是以i和j为前两个元素的序列

int main()
{
    int n, ans;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        for (int i = 0 ; i < n ; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                dp[i][j] = 2;  //  最小值为2
            }
        }
        ans = 2;
        for (int j = n - 2; j >= 1; j--)
        {
            int i = j - 1, k = j + 1;
            while (i >= 0 && k <= n - 1)
            {
                if (a[i] + a[k] < 2 * a[j])
                {
                    k++;
                }
                else if (a[i] + a[k] > 2 * a[j])
                {
                    i--;
                }
                else
                {
                    dp[i][j] = dp[j][k] + 1;
                    if (dp[i][j] > ans)
                    {
                        ans = dp[i][j];
                    }
                    i--;
                    k++;
                }
            }
        }
        printf("%d\n", ans);
    }
    
    return 0 ;
}
