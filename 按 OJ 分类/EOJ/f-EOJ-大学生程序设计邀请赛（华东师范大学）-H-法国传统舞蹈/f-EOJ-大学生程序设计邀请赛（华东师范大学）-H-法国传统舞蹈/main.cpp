//
//  main.cpp
//  f-EOJ-大学生程序设计邀请赛（华东师范大学）-H-法国传统舞蹈
//
//  Created by ZYJ on 2017/5/16.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 30;
const int INF = 0x3f3f3f3f;

char s[MAXN];
int vis[MAXN];
int A[MAXN], B[MAXN], C[MAXN], D[MAXN];

int main()
{
    int N, M, K;
    while (cin >> N >> M >> K)
    {
        while (K--)
        {
            for (int i = N + 1; i <= N + M; i++)    //  建立 r 的不重复映射
            {
                B[i] = i;
            }
            
            int cnt = N + 1;
            for (int i = 1; i <= N + M; i++)
            {
                scanf("%s", s);
                if (s[0] == 'r')
                {
                    A[i] = cnt++;
                }
                else
                {
                    sscanf(s, "%d", &A[i]);
                }
            }
            
            int ans = INF;
            do
            {
                for (int i = 1; i <= N + M; i++)    //  更替 r 映射顺序
                {
                    C[i] = A[i] <= N ? A[i] : B[A[i]];
                }
                for (int i = 1; i <= N + M; i++)    //  建立后继数组
                {
                    D[C[i]] = C[i % (N + M) + 1];
                    vis[i] = 0;
                }
                for (int i = 1; i <= N + M; i++)    //  将后继数组更替为循环节数组
                {
                    D[i] = (D[i] + N + M - 2) % (N + M) + 1;
                }
                
                int cnt = N + M;
                for (int i = 1; i <= N + M; i++)    //  查找循环节
                {
                    if (vis[i])
                    {
                        continue;
                    }
                    vis[i] = 1;
                    cnt--;
                    for (int j = D[i]; j != i; j = D[j])
                    {
                        vis[j] = 1;
                    }
                }
                if (cnt & 1)    //  必须为偶数方可
                {
                    continue;
                }
                ans = min(ans, cnt);
            } while (next_permutation(B + N + 1, B + N + M + 1));   //  下一个排列
            
            printf("%d\n", ans);
        }
    }
    
    return 0;
}
