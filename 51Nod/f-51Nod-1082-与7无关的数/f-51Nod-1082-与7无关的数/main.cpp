//
//  main.cpp
//  f-51Nod-1082-与7无关的数
//
//  Created by ZYJ on 16/7/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 1e6 + 7;

bool A[MAXN];
long long sum[MAXN];

void debug()
{
    for (int i = 0; i < MAXN; i++)
    {
        printf("%4d %4d\n", i, A[i]);
    }
    return ;
}

void init()
{
    memset(A, true, sizeof(A));
    //  筛除7的倍数
    for (int i = 7; i < MAXN; i += 7)
    {
        A[i] = false;
    }
    //  筛选数位含7
    int radix;
    for (int i = 1; i < MAXN; i *= 10)
    {
        radix = i * 10;
        for (int j = i * 7; j < MAXN; j += radix)
        {
            for (int k = 0; k < i; k++)
            {
                A[k + j] = false;
            }
        }
    }
    //  调试
//    debug();
    return ;
}

void solve()
{
    sum[0] = 0;
    sum[1] = 1;
    for (long long i = 2; i < MAXN; i++)    //  这里的必须是long long
    {
        if (A[i])
        {
            sum[i] = sum[i - 1] + i * i;    //  因为这里i * i，所以要考虑到溢出
        }
        else
        {
            sum[i] = sum[i - 1];
        }
    }
    return ;
}

int main(int argc, const char * argv[])
{
    init();
    solve();
    
//    freopen("input.txt", "r", stdin);
    
    int T, N;
    cin >> T;
    
    while (T--)
    {
        scanf("%d", &N);
        printf("%lld\n", sum[N]);
    }
    
    return 0;
}
