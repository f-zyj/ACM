//
//  main.cpp
//  f-51Nod-1448-二染色问题
//
//  Created by ZYJ on 16/9/21.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 22;

char s[MAXN][MAXN];

int N, K;
int vis[MAXN][MAXN];

int main()
{
    int T;
    cin >> T;
    
    int sumA, sumB;
    while (T--)
    {
        memset(vis, 0, sizeof(vis));
        scanf("%d%d", &N, &K);
        
        int flag = 1;
        for (int i = 1; i <= N; i++)
        {
            scanf("%s", s[i] + 1);
        }
        while (flag)
        {
            flag = 0;
            for (int i = 1; i <= N - K + 1; i++)
            {
                for (int j = 1; j <= N - K + 1; j++)
                {
                    sumA = 0;
                    sumB = 0;
                    int tag = 0;
                    for (int l = i; l < i + K; l++)
                    {
                        for (int m = 0; m < K; m++)
                        {
                            if (vis[l][j + m])
                            {
                                continue;
                            }
                            tag = 1;
                            if (s[l][j + m] == 'B')
                            {
                                sumA++;
                            }
                            else
                            {
                                sumB++;
                            }
                        }
                    }
                    if ((sumA == 0 || sumB == 0) && tag)
                    {
                        flag = 1;
                        for (int l = i; l < i + K; l++)
                        {
                            for (int m = 0; m < K; m++)
                            {
                                vis[l][j + m] = 1;
                            }
                        }
                    }
                }
            }
        }
        
        flag = 1;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (vis[i][j] == 0 && s[i][j] == 'B')
                {
                    flag = 0;
                }
            }
        }
        
        if (flag)
        {
            puts("Possible");
        }
        else
        {
            puts("Impossible");
        }
    }
    
    return 0;
}