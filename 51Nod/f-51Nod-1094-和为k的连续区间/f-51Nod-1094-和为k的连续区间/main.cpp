//
//  main.cpp
//  f-51Nod-1094-和为k的连续区间
//
//  Created by ZYJ on 16/8/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 1e4 + 10;

int A[MAXN];
int sum[MAXN];

int main(int argc, const char * argv[])
{
    int N, K;
    cin >> N >> K;
    
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", A + i);
        sum[i] = sum[i - 1] + A[i];
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            if (sum[j] - sum[i] == K)
            {
                cout << i + 1 << ' ' << j << '\n';
                return 0;
            }
        }
    }
    
    cout << "No Solution\n";
    
    return 0;
}
