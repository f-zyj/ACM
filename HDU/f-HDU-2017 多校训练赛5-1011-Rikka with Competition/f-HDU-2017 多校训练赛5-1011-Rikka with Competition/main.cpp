//
//  main.cpp
//  f-HDU-2017 多校训练赛5-1011-Rikka with Competition
//
//  Created by ZYJ on 2017/8/8.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int n,k;
int A[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", A + i);
        }
        sort(A + 1, A + 1 + n);
        
        int res = 1;
        for (int i = 2; i <= n; i++)
        {
            if (A[i] > A[i - 1] + k)
            {
                res = i;
            }
        }
        
        printf("%d\n", n - res + 1);
    }
    
    return 0;
}
