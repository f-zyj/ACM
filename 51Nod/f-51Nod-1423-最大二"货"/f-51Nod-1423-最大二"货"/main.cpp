//
//  main.cpp
//  f-51Nod-1423-最大二"货"
//
//  Created by ZYJ on 2017/6/23.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

const int MAXN = 1e5 + 10;

int n;
int val[MAXN];
stack<int> si;

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

int main(int argc, const char * argv[])
{
    scan_d(n);
    for (int i = 0; i < n; i++)
    {
        scan_d(val[i]);
    }
    
    int res = 0;
    
    //  单调递减栈
    for (int i = 0; i < n; i++)
    {
        while (!si.empty() && val[i] > val[si.top()])
        {
            si.pop();
        }
        if (!si.empty())
        {
            res = max(res, val[i] ^ val[si.top()]);
        }
        si.push(i);
    }
    
    while (!si.empty())
    {
        si.pop();
    }
    
    //  反向单调递减栈
    for (int i = n - 1; i >= 0; i--)
    {
        while (!si.empty() && val[i] > val[si.top()])
        {
            si.pop();
        }
        if (!si.empty())
        {
            res = max(res, val[i] ^ val[si.top()]);
        }
        si.push(i);
    }
    
    cout << res << '\n';
    
    return 0;
}
