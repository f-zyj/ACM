//
//  main.cpp
//  f-51Nod-1098-最小方差
//
//  Created by ZYJ on 16/8/6.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 1e4 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int num[MAXN];
long long sum[MAXN] = {0};

int main(int argc, const char * argv[])
{
    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int M, N;
    cin >> M >> N;
    
    for (int i = 1; i <= M; i++)
    {
        scanf("%d", num + i);
    }
    sort(num + 1, num + M + 1);
    for (int i = 1; i <= M; i++)
    {
        sum[i] = sum[i - 1] + num[i];
    }
    
    double SSN = INF;
    for (int i = 1; i <= M - N + 1; i++)
    {
        double k = (sum[i + N - 1] - sum[i - 1]) * 1.0 / N;
        long double S = 0;
        for (int j = 0; j < N; j++)
        {
            S += (num[i + j] - k) * (num[i + j] - k);
        }
        SSN = SSN > S ? S : SSN;
    }
    
    std::cout << (long long)SSN << '\n';
    return 0;
}
