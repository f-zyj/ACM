//
//  main.cpp
//  f-HDU-2017 多校训练赛6-1003-Inversion
//
//  Created by ZYJ on 2017/8/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

struct node
{
    int num, pos;
} A[MAXN];

bool cmp(node x, node y)
{
    return x.num > y.num;
}

int n;

int solve(int x)
{
    int tmp = 1;
    while (A[tmp].pos % x == 0)
    {
        tmp++;
    }
    return A[tmp].num;
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
        scan_d(n);
        for (int i = 1; i <= n; i++)
        {
            scan_d(A[i].num);
            A[i].pos = i;
        }
        
        sort(A + 1, A + 1 + n, cmp);
        
        for (int i = 2; i <= n; i++)
        {
            printf("%d%c", solve(i), i == n ? '\n' : ' ');
        }
    }
    
    return  0;
}
