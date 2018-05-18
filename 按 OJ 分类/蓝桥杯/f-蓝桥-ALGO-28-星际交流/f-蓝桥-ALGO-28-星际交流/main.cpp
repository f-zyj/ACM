//
//  main.cpp
//  f-蓝桥-ALGO-28-星际交流
//
//  Created by ZYJ on 2017/6/5.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 11111;

int N, M;
int A[MAXN];

int main(int argc, const char * argv[])
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", A + i);
    }
    
    while (M--)
    {
        next_permutation(A, A + N);
    }
    
    printf("%d", A[0]);
    for (int i = 1; i < N; i++)
    {
        printf(" %d", A[i]);
    }
    putchar(10);
    
    return 0;
}
