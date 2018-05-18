//
//  main.cpp
//  f-蓝桥-ALGO-37-Hankson的趣味题
//
//  Created by ZYJ on 2017/6/6.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 55555;

int cnt;
int prime[MAXN];
bool vis[MAXN];

void init()
{
    for (int i = 2; i <= MAXN; i++)
    {
        if (!vis[i])
        {
            prime[++cnt] = i;
            for (long long j = 1ll * i * i; j <= MAXN; j += i)
            {
                vis[j] = 1;
            }
        }
    }
}

int cal(int &x, int p)
{
    int res = 0;
    while (x % p == 0)
    {
        res++;
        x /= p;
    }
    return res;
}

int n;
int a0, a1, b0, b1;

int main()
{
    init();
    
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
//    freopen("/Users/zyj/Desktop/output.txt", "w", stdout);
    
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        int ans = 1;
        scanf("%d%d%d%d", &a0, &a1, &b0, &b1);
        if (b1 % a1)
        {
            cout << 0 << '\n';
            continue;
        }
        
        for (int i = 1; i <= cnt; i++)
        {
            if (b1 % prime[i] == 0)
            {
                int a0_ = cal(a0, prime[i]);
                int a1_ = cal(a1, prime[i]);
                int b0_ = cal(b0, prime[i]);
                int b1_ = cal(b1, prime[i]);

                if (a0_ == a1_ && b0_ == b1_)
                {
                    ans *= (b1_ - a1_ + 1);
                }
                else if (a0_ == a1_ && b0_ < b1_)
                {
                    if (a1_ > b1_)
                    {
                        ans = 0;
                    }
                }
                else if (a0_ > a1_ && b0_ == b1_)
                {
                    if (a1_ > b1_)
                    {
                        ans = 0;
                    }
                }
                else if (a1_ != b1_)
                {
                    ans = 0;
                }
            }
            if (i == cnt && b1 > 1)
            {
                prime[++cnt] = b1;
            }
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
