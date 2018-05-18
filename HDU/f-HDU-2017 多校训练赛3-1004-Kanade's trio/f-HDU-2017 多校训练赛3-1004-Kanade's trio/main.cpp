//
//  main.cpp
//  f-HDU-2017 多校训练赛3-1004-Kanade's trio
//
//  Created by ZYJ on 2017/8/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 10;
const int MAGIC = 30;

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

int n, tot;
int a[MAXN];
int go[MAXN << 5][2];
int num[MAXN << 5];
int tree[MAXN][MAGIC][2];
ll ss[MAXN << 5];

int main()
{
    int T;
    scan_d(T);
    while (T--)
    {
        for (int i = 1; i <= tot; i++)
        {
            go[i][0] = go[i][1] = 0;
            ss[i] = num[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < MAGIC; j++)
            {
                tree[i][j][0] = tree[i][j][1] = 0;
            }
        }
        
        tot = 1;
        scan_d(n);
        for (int i = 1; i <= n; i++)
        {
            scan_d(a[i]);
        }
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < MAGIC; j++)
            {
                tree[i][j][0] = tree[i - 1][j][0];
                tree[i][j][1] = tree[i - 1][j][1];
            }
            for (int j = 0; j < MAGIC; j++)
            {
                int k = (a[i] & (1 << j)) > 0;
                tree[i][j][k]++;
            }
        }
        
        ll ans = 0;
        for (int i = n; i >= 1; i--)
        {
            int now = 1;
            for (int j = MAGIC - 1; j >= 0; j--)
            {
                int k = (a[i] & (1 << j)) > 0;
                if (go[now][k ^ 1])
                {
                    ans += ss[go[now][k ^ 1]] - num[go[now][k ^ 1]] * 1ll * tree[i][j][k];
                }
                if (!go[now][k])
                {
                    break;
                }
                now = go[now][k];
            }
            now = 1;
            for (int j = MAGIC - 1; j >= 0; j--)
            {
                int k = (a[i] & (1 << j)) > 0;
                if (!go[now][k])
                {
                    go[now][k] = ++tot;
                }
                now = go[now][k];
                ss[now] += tree[i - 1][j][k ^ 1];
                num[now]++;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}

