//
//  main.cpp
//  f-蓝桥-ALGO-44-采油区域
//
//  Created by ZYJ on 2017/6/9.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAXN = 1555;

int N, M, K;
int map[MAXN][MAXN];
int sum[MAXN][MAXN];
int KK_sum[MAXN][MAXN];
int left_up[MAXN][MAXN];
int right_up[MAXN][MAXN];
int left_down[MAXN][MAXN];
int right_down[MAXN][MAXN];
int ans;

void get_sum()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + map[i][j];
        }
    }
}

void get_KK_sum()
{
    for (int i = K; i <= N; i++)
    {
        for (int j = K; j <= M; j++)
        {
            KK_sum[i][j] = sum[i][j] - sum[i - K][j] - sum[i][j - K] + sum[i - K][j - K];
        }
    }
}

void get_dir_dir()
{
    for (int i = K; i <= N; i++)
    {
        for (int j = K; j <= M; j++)
        {
            left_up[i][j] = KK_sum[i][j];
            left_up[i][j] = max(left_up[i][j], left_up[i - 1][j]);
            left_up[i][j] = max(left_up[i][j], left_up[i][j - 1]);
        }
    }
    
    for (int i = K; i <= N; i++)
    {
        for (int j = M - K + 1; j; j--)
        {
            right_up[i][j] = KK_sum[i][j + K - 1];
            right_up[i][j] = max(right_up[i][j], right_up[i - 1][j]);
            right_up[i][j] = max(right_up[i][j], right_up[i][j + 1]);
        }
    }
    
    for (int i = N - K + 1; i; i--)
    {
        for (int j = K; j <= M; j++)
        {
            left_down[i][j] = KK_sum[i + K - 1][j];
            left_down[i][j] = max(left_down[i][j], left_down[i + 1][j]);
            left_down[i][j] = max(left_down[i][j], left_down[i][j - 1]);
        }
    }
    
    for (int i = N - K + 1; i; i--)
    {
        for (int j = M - K + 1; j; j--)
        {
            right_down[i][j] = KK_sum[i + K - 1][j + K - 1];
            right_down[i][j] = max(right_down[i][j], right_down[i + 1][j]);
            right_down[i][j] = max(right_down[i][j], right_down[i][j + 1]);
        }
    }
}

void get_ans()
{
    //  左 中 右 结构
    for (int j = K; j + (K << 1) <= M; j++)
    {
        for (int i = K; i <= N; i++)
        {
            int t = left_up[N][j] + KK_sum[i][j + K] + right_up[N][j + K + 1];
            ans = max(ans, t);
        }
    }
    
    //  上 中 下 结构
    for (int i = K; i + (K << 1) <= N; i++)
    {
        for (int j = K; j <= M; j++)
        {
            int t = left_up[i][M] + KK_sum[i + K][j] + left_down[i + K + 1][M];
            ans = max(ans, t);
        }
    }
    
    //  左 右上 右下 结构
    for (int j = K; j + K <= M; j++)
    {
        for (int i = K; i + K <= N; i++)
        {
            int t = left_up[N][j] + right_up[i][j + 1] + right_down[i + 1][j + 1];
            ans = max(ans, t);
        }
    }
    
    //  左上 左下 右 结构
    for (int j = K; j + K <= M; j++)
    {
        for (int i = K; i + K <= N; i++)
        {
            int t = left_up[i][j] + left_down[i + 1][j] + right_down[1][j + 1];
            ans = max(ans, t);
        }
    }
    
    //  上 左下 右下 结构
    for (int i = K; i + K <= N; i++)
    {
        for (int j = K; j + K <= M; j++)
        {
            int t = left_up[i][M] + left_down[i + 1][j] + right_down[i + 1][j + 1];
            ans = max(ans, t);
        }
    }
    
    // 左上 右上 下 结构
    for (int i = K; i + K <= N; i++)
    {
        for (int j = K; j + K <= M; j++)
        {
            int t = left_up[i][j] + right_up[i][j + 1] + left_down[i + 1][M];
            ans = max(ans, t);
        }
    }
}

int main()
{
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            scanf("%d", map[i] + j);
        }
    }
    
    get_sum();
    get_KK_sum();
    get_dir_dir();
    
    ans = 0;
    get_ans();
    
    printf("%d\n", ans);
    
    return 0;
}
