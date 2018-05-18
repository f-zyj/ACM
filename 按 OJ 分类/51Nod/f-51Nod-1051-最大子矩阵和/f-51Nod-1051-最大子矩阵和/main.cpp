//
//  main.cpp
//  f-51Nod-1051-最大子矩阵和
//
//  Created by ZYJ on 16/8/1.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

typedef long long ll;

using namespace std;

const int MAXN = 505;

ll Matrix[MAXN][MAXN];

int main(int argc, const char * argv[])
{
//    freopen("input.txt", "r", stdin);
//    freopen("input.txt", "w", stdin);
    int M, N;
    cin >> M >> N;
    int A;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            scanf("%d", &A);
            Matrix[i][j] = Matrix[i - 1][j] + A;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j++)
        {
            int sum = 0;
            for (int k = 1; k <= M; k++)
            {
                sum += Matrix[j][k] - Matrix[i - 1][k];
                if (sum < 0)
                {
                    sum = 0;
                }
                else if (sum > ans)
                {
                    ans = sum;
                }
            }
        }
    }
    
    std::cout << ans << '\n';
    return 0;
}