//
//  main.cpp
//  f-HDU-2017中国大学生程序设计竞赛-网络选拔赛-1006-Subsequence Count
//
//  Created by ZYJ on 2017/8/19.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

#define clr(a, b) memset(a, b, sizeof(a))

using namespace std;

typedef long long ll;

const int MAXN = 1e4 + 10;
const int MOD = 1e9 + 7;

int N, Q;
ll dp[MAXN];
int num[MAXN];
int vis[MAXN];
char S[MAXN];

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

template <class T>
inline void print_d(T x)
{
    if (x > 9)
    {
        print_d(x / 10);
    }
    putchar(x % 10 + '0');
}

void read_S()
{
    char ch = getchar();
    int pos = 0;
    while (ch != '\n')
    {
        S[++pos] = ch;
        ch = getchar();
    }
}

int main()
{
    int T;
    scan_d(T);
    
    while (T--)
    {
        scan_d(N), scan_d(Q);
        read_S();
        
        for (int i = 1; i <= N; i++)
        {
            num[i] = (S[i] - '0');
        }
        
        int type, l, r;
        while (Q--)
        {
            scan_d(type), scan_d(l), scan_d(r);
            if (type == 1)
            {
                for (int i = l; i <= r; i++)
                {
                    if (num[i])
                    {
                        num[i] = 0;
                    }
                    else
                    {
                        num[i] = 1;
                    }
                }
            }
            else
            {
                clr(dp, 0);
                clr(vis, 0);
                dp[l - 1] = 1;
                
                for (int i = l; i <= r; ++i)
                {
                    if (vis[num[i]] == 0)
                    {
                        dp[i] = (dp[i - 1] * 2) % MOD;
                    }
                    else
                    {
                        dp[i] = (2 * dp[i - 1] - dp[vis[num[i]] - 1] + MOD) % MOD;
                    }
                    vis[num[i]] = i;
                }
                
                print_d(dp[r] - 1);
                putchar(10);
            }
        }
    }
    
    return 0;
}
