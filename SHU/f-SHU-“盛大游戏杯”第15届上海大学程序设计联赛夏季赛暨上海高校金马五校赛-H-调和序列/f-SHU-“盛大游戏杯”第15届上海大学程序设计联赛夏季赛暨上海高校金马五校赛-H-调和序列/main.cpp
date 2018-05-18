//
//  main.cpp
//  f-SHU-“盛大游戏杯”第15届上海大学程序设计联赛夏季赛暨上海高校金马五校赛-H-调和序列
//
//  Created by ZYJ on 2017/7/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

const int MAXN = 2e4 + 10;

int A[MAXN];
vector<int> vi[MAXN];

int n, m;

bool cmp(int a, int b)
{
    return a > b;
}

void init()
{
    for (int i = 1; i < n; i++)
    {
        vi[i].clear();
        vi[i].push_back(A[0]);
        for (int j = i; j < n; j += i)
        {
            vi[i].push_back(A[j]);
        }
        sort(vi[i].begin(), vi[i].end(), cmp);
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

template <class T>
inline void print_d(T x)
{
    if (x > 9)
    {
        print_d(x / 10);
    }
    putchar(x % 10 + '0');
}

int main(int argc, const char * argv[])
{
    int T;
    scan_d(T);
    
    while (T--)
    {
        scan_d(n), scan_d(m);
        for (int i = 0; i < n; i++)
        {
            scan_d(A[i]);
        }
        
        init();
        
        int K, S;
        while (m--)
        {
            scan_d(K), scan_d(S);
            if (K >= n && S == 1)
            {
                print_d(A[0]);
                putchar(10);
            }
            else if (K >= n || vi[K].size() < S)
            {
                puts("-1");
            }
            else
            {
                print_d(vi[K][S - 1]);
                putchar(10);
            }
        }
    }
    
    return 0;
}
