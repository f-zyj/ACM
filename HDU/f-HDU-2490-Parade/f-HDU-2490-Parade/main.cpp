//
//  main.cpp
//  f-HDU-2490-Parade
//
//  Created by ZYJ on 2017/10/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>

using namespace std;

const int MAXN = 111;
const int MAXM = 1e4 + 10;

int n, m, k;
int sum[MAXM];
int dp[MAXN][MAXM];
int wel[MAXN][MAXM];
int len[MAXN][MAXM];

template <class T>
inline bool scan_d(T &ret)
{
    char c;
    int sgn;
    if (c = getchar(), c == EOF)
    {
        return 0;   //  EOF
    }
    while (c != '-' && (c < '0' || c > '9'))
    {
        c = getchar();
    }
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0');
    }
    ret *= sgn;
    return 1;
}

struct node
{
    int hap, dis;
    
    node() {}
    node(int h, int d) : hap(h), dis(d) {}
};

int main()
{
    while (~scanf("%d%d%d", &n, &m, &k) && n + m + k)
    {
        ++n;
        memset(dp, 0, sizeof(dp));
        memset(len, 0, sizeof(len));
        memset(wel, 0, sizeof(wel));
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scan_d(wel[i][j]);
            }
        }
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scan_d(len[i][j]);
            }
        }
        
        for (int i = 1; i <= n; i++)
        {
            deque<node> deq;
            int dis = 0;
            for (int j = 1; j <= m; j++)
            {
                sum[j] = sum[j - 1] + wel[i][j];
            }
            
            for (int j = 0; j <= m; j++)
            {
                dis += len[i][j];
                while (!deq.empty() && deq.front().hap <= dp[i - 1][j] - sum[j])
                {
                    deq.pop_front();
                }
                deq.push_front(node(dp[i - 1][j] - sum[j], dis));
                while (!deq.empty() && deq.front().dis - deq.back().dis > k)
                {
                    deq.pop_back();
                }
                dp[i][j] = deq.back().hap + sum[j];
            }
            
            deq.clear();
            dis = 0;
            len[i][m + 1] = 0;
            for (int j = m; j >= 0; j--)
            {
                dis += len[i][j + 1];
                while (!deq.empty() && deq.front().hap <= dp[i - 1][j] + sum[j])
                {
                    deq.pop_front();
                }
                deq.push_front(node(dp[i - 1][j] + sum[j], dis));
                while (!deq.empty() && deq.front().dis - deq.back().dis > k)
                {
                    deq.pop_back();
                }
                dp[i][j] = max(dp[i][j], deq.back().hap - sum[j]);
            }
        }
        
        int ans = 0;
        for (int j = 0; j <= m; j++)
        {
            ans = max(ans, dp[n][j]);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
