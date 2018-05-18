//
//  main.cpp
//  f-51Nod-1137-矩阵乘法
//
//  Created by ZYJ on 16/7/26.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int M_1[105][105];
int M_2[105][105];
long long M_3[105][105];

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    memset(M_3, 0, sizeof(M_3));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> M_1[i][j];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> M_2[i][j];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                M_3[i][j] += M_1[i][k] * M_2[k][j];
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            cout << M_3[i][j] << ' ';
        }
        cout << M_3[i][N] << '\n';
    }
    
    return 0;
}
