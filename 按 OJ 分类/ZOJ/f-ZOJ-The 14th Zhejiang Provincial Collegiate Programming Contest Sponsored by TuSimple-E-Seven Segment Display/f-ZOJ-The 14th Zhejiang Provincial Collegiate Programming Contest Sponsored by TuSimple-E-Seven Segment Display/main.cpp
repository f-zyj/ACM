//
//  main.cpp
//  f-ZOJ-The 14th Zhejiang Provincial Collegiate Programming Contest Sponsored by TuSimple-E-Seven Segment Display
//
//  Created by ZYJ on 2017/4/23.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

const int LEN = 8;
const int MAXN = LEN + 5;
const int EC[] = {6, 2, 5, 5,
                  4, 5, 6, 3,
                  7, 6, 6, 5,
                  4, 5, 5, 4};
const ll INF = 0xFFFFFFFF;
const ll POW[] = {1, 16, 256, 4096,
    65536, 1048576, 16777216, 268435456};

char s[MAXN];
ll d[MAXN];
ll dp[MAXN];    //  前x位中1出现次数（0~9均是如此）

void init()
{
    for (int i = 1; i < MAXN; i++)
    {
        dp[i] = dp[i - 1] * 16 + POW[i - 1];
    }
}

int HtoD(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }
    else
    {
        return ch - 'A' + 10;
    }
}

ll count(int place) //  数是x，查询的数位是place
{
    ll result = 0;
    ll tail = 0;
    for (int i = 0; i < LEN; i++)
    {
        if (d[i] > place)
        {
            result += POW[i] + d[i] * dp[i];
        }
        else if (d[i] == place)
        {
            result += tail + 1 + d[i] * dp[i];
        }
        else if (d[i] < place)
        {
            result += d[i] * dp[i];
        }
        tail = tail + d[i] * POW[i];    //  头为place个数
    }
    return result;
}

ll solve(ll x)
{
    if (x < 0)
    {
        return 0;
    }
    ll res = 0;
    for (int i = 0; i < LEN; i++)
    {
        d[i] = x % 16;
        x /= 16;
    }
    for (int i = 0; i < 16; i++)
    {
        res += count(i) * EC[i];
    }
    
    return res;
}

int main()
{
    init();
    
    int T;
    scanf("%d", &T);

    int n;
    while (T--)
    {
        scanf("%d%s", &n, s);
        
        ll num = 0;
        for (int i = LEN - 1; i >= 0; i--)
        {
            num += HtoD(s[i]) * POW[LEN - i - 1];
        }
        ll num_ = num + n - 1, temp = 0;
        if (num_ > INF)
        {
            temp = solve(INF) - solve(num - 1);
            num = 0;
            num_ -= INF + 1;
        }
        printf("%lld\n", temp + solve(num_) - solve(num - 1));
    }
    
    return 0;
}
