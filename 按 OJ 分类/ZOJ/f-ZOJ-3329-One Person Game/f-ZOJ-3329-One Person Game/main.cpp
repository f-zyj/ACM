//
//  main.cpp
//  f-ZOJ-3329-One Person Game
//
//  Created by ZYJ on 2017/10/31.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 600;

int n, k1, k2, k3, a, b, c;
double A[MAXN], B[MAXN], P[MAXN];

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    while (T--)
    {
        memset(P, 0, sizeof(P));
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        
        scanf("%d%d%d%d%d%d%d", &n, &k1, &k2, &k3, &a, &b, &c);
        
        P[0] = 1.0 / k1 / k2 / k3; //  回到零的概率
        for (int i = 1; i <= k1; i++)
        {
            for (int j = 1; j <= k2; j++)
            {
                for (int k = 1; k <= k3; k++)
                {
                    if (i != a || j != b || k != c)
                    {
                        P[i + j + k] += P[0];   //  投掷出 i j k 的概率等于 P[0]
                    }
                }
            }
        }
        
        for (int i = n; i >= 0; i--)
        {
            A[i] = P[0];
            B[i] = 1;
            int t = k1 + k2 + k3;
            for (int j = 1; j <= t; j++)
            {
                A[i] += A[i + j] * P[j];
                B[i] += B[i + j] * P[j];
            }
        }
        
        printf("%.15lf\n", B[0] / (1 - A[0]));
    }
    
    return 0;
}
