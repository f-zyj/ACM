//
//  main.cpp
//  f-HDU-5985-Lucky Coins
//
//  Created by ZYJ on 2017/10/16.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_STAPES = 75;
const int MAXN = 15;

int n;
int num[MAXN];
double p[MAXN];
double die[MAXN][MAX_STAPES + 5];
double alive[MAXN][MAX_STAPES + 5];
double luck[MAXN];

void solve()
{
    for (int i = 0; i < MAXN; i++)
    {
        luck[i] = 0.0;
    }
    
    for (int i = 0; i < n; i++)
    {
        double tmp = p[i];
        for (int j = 1; j <= MAX_STAPES; j++)
        {
            die[i][j] = pow(1 - tmp, num[i]);
            alive[i][j] = 1 - die[i][j];
            tmp *= p[i];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < MAX_STAPES; j++)
        {
            double tmp = 1.0;
            for (int k = 0; k < n; k++)
            {
                if (k != i)
                {
                    tmp *= die[k][j];
                }
            }
            luck[i] += (alive[i][j] - alive[i][j + 1]) * tmp;
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d", &n);
        
        for (int i = 0; i < n; i++)
        {
            scanf("%d%lf", &num[i], &p[i]);
        }
        
        if (n == 1)
        {
            puts("1.000000");
            continue;
        }
        
        solve();
        
        for (int i = 0; i < n; i++)
        {
            printf("%.6f%c", luck[i], (i == n - 1) ? '\n' : ' ');
        }
    }
    
    return 0;
}
