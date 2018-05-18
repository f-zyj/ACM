//
//  main.cpp
//  f-51Nod-1002-数塔取数问题
//
//  Created by ZYJ on 16/7/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 125300;

int A[MAXN];


int main(int argc, const char * argv[])
{
//    freopen("input.txt", "r", stdin);
    int N;
    while (cin >> N)
    {
        int key = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                scanf("%d", &A[key++]);
            }
        }
        int line = N - 1;
        int E = key - N - 1;
        for (int i = line; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                A[E] += A[E + i] > A[E + i + 1] ? A[E + i] : A[E + i + 1];
                E--;
            }
        }
        cout << A[0] << '\n';
    }
    
    return 0;
}
