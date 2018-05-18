//
//  main.cpp
//  f-堆
//
//  Created by ZYJ on 2017/7/25.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>

using namespace std;

const int MAXN = 200000;

int A[MAXN];    //  20w空数组符合要求

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

priority_queue<int> qi;

int main(int argc, const char * argv[])
{
    clock_t start, finish;
    
    start = clock();
    
    freopen("/Users/zyj/Desktop/output.txt", "r", stdin);
    
    for (int i = 1; i <= MAXN; i++)
    {
        scan_d(A[i]);
        qi.push(A[i]);  //  堆排,符合要求
    }

    finish = clock();
    
    cout << finish - start << '\n';
    
    return 0;
}
