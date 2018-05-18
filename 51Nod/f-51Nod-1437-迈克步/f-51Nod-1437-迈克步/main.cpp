//
//  main.cpp
//  f-51Nod-1437-迈克步
//
//  Created by ZYJ on 2017/6/25.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stack>

using namespace std;

const int MAXN = 2e5 + 11;

struct num
{
    int value;
    int minLeft, minRight;
    
    num() : minLeft(1), minRight(1) {}
} A[MAXN];

int N;
int value, key;
stack<pair<int, int> > S;

void stackClear()
{
    while (!S.empty())
    {
        S.pop();
    }
}

void getMin()
{
    stackClear();
    
    S.push(make_pair(A[0].value, 0));
    for (int i = 1; i < N; i++)
    {
        while (!S.empty() && S.top().first >= A[i].value)
        {
            value = S.top().first;
            key = S.top().second;
            S.pop();
            
            A[i].minLeft += A[key].minLeft;
            if (!S.empty())
            {
                A[S.top().second].minRight += A[key].minRight;
            }
        }
        S.push(make_pair(A[i].value, i));
    }
    while (!S.empty())
    {
        key = S.top().second;
        S.pop();
        if (!S.empty())
        {
            A[S.top().second].minRight += A[key].minRight;
        }
    }
}

int ans[MAXN];

void solve()
{
    for (int i = 0; i < N; i++)
    {
        int t = A[i].minLeft + A[i].minRight - 1;
        ans[t] = max(ans[t], A[i].value);
    }
    for (int i = N - 1; i > 0; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
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

void Out(int a)
{    //  输出外挂
    if (a < 0)
    {
        putchar('-');
        a = -a;
    }
    if (a >= 10)
    {
        Out(a / 10);
    }
    putchar(a % 10 + '0');
}

int main(int argc, const char * argv[])
{
    scan_d(N);
    
    for (int i = 0; i < N; i++)
    {
        scan_d(A[i].value);
    }
    
    getMin();
    
    solve();
    
    for (int i = 1; i <= N; i++)
    {
        Out(ans[i]);
        putchar(' ');
    }
    putchar(10);
    
    return 0;
}
