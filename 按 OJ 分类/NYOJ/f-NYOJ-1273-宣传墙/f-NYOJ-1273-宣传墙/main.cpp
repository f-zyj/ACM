//
//  main.cpp
//  f-NYOJ-1273-宣传墙
//
//  Created by ZYJ on 2017/2/20.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 997;
const int MAXN = 16;

struct mat
{
    int A[MAXN][MAXN];
    
    mat()
    {
        memset(A, 0, sizeof(A));
    }
    
    mat operator * (const mat &a) const
    {
        mat b;
        for (int i = 0; i < MAXN; i++)
        {
            for (int j = 0; j < MAXN; j++)
            {
                for (int k = 0; k < MAXN; k++)
                {
                    b.A[i][j] += A[i][k] * a.A[k][j];
                    b.A[i][j] %= MOD;
                }
            }
        }
        return b;
    }
};

mat map;

bool cmp(int i, int j)  //  状态 j 对状态 i 是否可行 j 是 col 列的状态 i 是 col - 1 列的状态
{
    for (int row = 0; row < 4; row++)
    {
        if ((i >> row) & 1)
        {
            if ((j >> row) & 1)
            {
//                if (row == 3)               //  这个特判有没有都行，因为 i >> 4 肯定为 0
//                {                           //  这样不过是思维更严谨些
//                    return false;
//                }
                if ((i >> (row + 1)) & 1)
                {
                    i -= (1 << (row + 1));  //  等价于 i ^= 1 << (rank + 1)，前边的写法不太直观
                }
                else
                {
                    return false;
                }
            }
            else
            {
                continue;
            }
        }
        else
        {
            if ((j >> row) & 1)
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

//  构造单元矩阵
void unit()
{
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            map.A[i][j] = cmp(i, j);
        }
    }
}

int slove(int n)
{
    mat a;
    mat b = map;
    for (int i = 0; i < MAXN; i++)
    {
        a.A[i][i] = 1;
    }
    while (n)
    {
        if (n & 1)
        {
            a = a * b;
        }
        b = b * b;
        n >>= 1;
    }
    return a.A[MAXN - 1][MAXN - 1];
}

int main ()
{
    int T;
    scanf("%d", &T);
    
    unit();
    
    while (T--)
    {
        int N, M, K;
        scanf("%d%d%d", &N, &M, &K);
        printf("%d %d\n", slove(M - 1), slove(N - M - K + 1));
    }
    return 0;
}
