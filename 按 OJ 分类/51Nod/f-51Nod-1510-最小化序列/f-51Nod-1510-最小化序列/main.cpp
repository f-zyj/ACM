//
//  main.cpp
//  f-51Nod-1510-最小化序列
//
//  Created by ZYJ on 2017/7/14.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 3e5 + 10;
const int MAXK = 5e3 + 10;

int n, k;
int A[MAXN];
int dp[MAXK][MAXK];

template <class T>
inline bool scan_d(T &ret)
{
    char c;
    int sgn;
    if (c = getchar(), c == EOF)
    {
        return 0; //EOF
    }
    while (c != '-' && (c < '0' || c > '9'))
    {
        c = getchar();
    }
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0');
    }
    ret *= sgn;
    return 1;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scan_d(A[i]);
    }
    sort(A, A + n);
    
    int t1 = n % k;
    int t2 = k - t1;
    k = n / k;
    
    dp[0][0] = 0;
    for (int i = 1; i <= t2; i++)
    {
        dp[i][0] = dp[i - 1][0] + A[i * k - 1] - A[(i - 1) * k];
    }
    for (int j = 1; j <= t1; j++)
    {
        dp[0][j] = dp[0][j - 1] + A[j * (k + 1) - 1] - A[(j - 1) * (k + 1)];
    }
    
    int k1, k2;
    for (int i = 1; i <= t2; i++)
    {
        for (int j = 1; j <= t1; j++)
        {
            k1 = (i - 1) * k + j * (k + 1);
            k2 = i * k + (j - 1) * (k + 1);
            dp[i][j] = min(dp[i - 1][j] + ((k1 + k) > n ? 0 : (A[k1 + k - 1] - A[k1])),
                           dp[i][j - 1] + ((k2 + k + 1) > n ? 0 : (A[k2 + k] - A[k2])));
        }
    }
    
    printf("%d\n", dp[t2][t1]);
    
    return 0;
}

