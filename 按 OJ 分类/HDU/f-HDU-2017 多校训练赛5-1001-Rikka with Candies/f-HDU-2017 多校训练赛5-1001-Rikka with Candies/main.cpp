//
//  main.cpp
//  f-HDU-2017 多校训练赛5-1001-Rikka with Candies
//
//  Created by ZYJ on 2017/8/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <bitset>

using namespace std;

const int MAXN = 5e4 + 10;

int n, m, q;
bitset<MAXN> a, b, ans;
bitset<MAXN> bb;    //  b的倍数，bb[i] ＝ 1: 有奇数个 y 满足 i ％ b[y] == 0

void solve(int mk)
{
    bb.reset();
    ans.reset();
    for (int i = mk; i >= 0; --i)
    {
        ans[i] = (bb & (a >> i)).count() & 1;
        if (b[i])
        {
            //  枚举 b[i] 的倍数
            for (int j = 0; j < MAXN; j += i)
            {
                bb.flip(j);
            }
        }
    }
}

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

int main()
{
    int T;
    scan_d(T);
    
    while (T--)
    {
        scan_d(n), scan_d(m), scan_d(q);
        
        a.reset();
        b.reset();
        int mk = 0, x;
        for (int i = 0; i < n; i++)
        {
            scan_d(x);
            a.set(x);
        }
        for (int i = 0; i < m; i++)
        {
            scan_d(x);
            b.set(x);
            mk = max(mk, x);
        }
        
        solve(mk);
        
        while (q--)
        {
            scanf("%d", &x);
            if (ans[x])
            {
                puts("1");
            }
            else
            {
                puts("0");
            }
        }
    }
    
    return 0;
}
