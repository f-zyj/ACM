//
//  main.cpp
//  ICPC Asia Regional Shenyang Online-1004-array array array
//
//  Created by ZYJ on 2017/9/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 7;
const int INF = 1e6 + 7;

int n, k;
int A[MAXN];
int B[MAXN];
int G[MAXN];

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
            B[n - i + 1] = A[i];
        }
        for (int i = 1; i <= n; i++)
        {
            G[i] = INF;
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int k = (int)(upper_bound(G + 1, G + 1 + n, A[i]) - G);
            if (G[k] == A[i])
            {
                k++;
            }
            G[k] = A[i];
            ans = max(k, ans);
        }
        for (int i = 1; i <= n; i++)
        {
            G[i] = INF;
        }
        
        for (int i = 1; i <= n; i++)
        {
            int k = (int)(upper_bound(G + 1, G + 1 + n, B[i]) - G);
            if (G[k] == B[i])
            {
                k++;
            }
            G[k] = B[i];
            ans = max(k, ans);
        }
        if (n - ans <= k)
        {
            puts("A is a magic array.");
        }
        else
        {
            puts("A is not a magic array.");
        }
    }
    
    return 0;
}
