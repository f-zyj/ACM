//
//  main.cpp
//  f-51Nod-1140-矩阵相乘结果的判断
//
//  Created by ZYJ on 2017/3/18.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef long long ll;

ll A[2][520];
ll B[2][520];
ll C[2][520];
ll X[2][520];

int main()
{
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++)
    {   //  随机生成两个 1 * n 矩阵
        X[0][i] = rand() % 10000 + 2;
        X[1][i] = rand() % 10000 + 2;
    }
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));
    
    ll key;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%lld", &key);
            A[0][j] += X[0][i] * key;
            A[1][j] += X[1][i] * key;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%lld", &key);
            B[0][j] += A[0][i] * key;
            B[1][j] += A[1][i] * key;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%lld", &key);
            C[0][j] += X[0][i] * key;
            C[1][j] += X[1][i] * key;
        }
    }
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (B[0][i] != C[0][i] || B[1][i] != C[1][i])
        {
            flag = false;
            break;
        }
    }
    
    printf("%s\n", flag ? "Yes" : "No");
    
    return 0;
}

