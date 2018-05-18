//
//  main.cpp
//  f-51Nod-1689-逛街
//
//  Created by ZYJ on 2017/7/8.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <queue>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

const int MAXN = 1e5 + 10;

int n, k;
ll T;
int a[MAXN], b[MAXN], c[MAXN];
priority_queue<int> Q1, Q2, Q3;

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
    cin >> n >> T >> k;
    for (int i = 1; i <= n; i++)
    {
        scan_d(a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scan_d(b[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scan_d(c[i]);
    }
    
    ll sum1 = 0, sum2 = 0;
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        if (c[i])
        {
            Q1.push(b[i]);
            sum1 += b[i];
            if (Q1.size() > k)
            {
                Q2.push(Q1.top());
                sum2 += Q1.top();
                sum1 -= Q1.top();
                Q1.pop();
            }
        }
        else
        {
            Q2.push(b[i]);
            sum2 += b[i];
        }
        
        if (Q1.size() < k)
        {
            continue;
        }
        if (sum1 + a[i] > T)
        {
            continue;
        }
        
        ll temp = T - sum1 - a[i];
        //  如果 Q3 中最小花费小于 Q2 中最大花费，交换
        while (!Q3.empty() && !Q2.empty() && -Q3.top() < Q2.top())
        {
            int tag = Q2.top();
            sum2 -= Q2.top();   //  去掉 Q2 最大花费
            sum2 -= Q3.top();   //  加上 Q3 最小花费
            Q2.pop();
            Q2.push(-Q3.top());
            Q3.pop();
            Q3.push(-tag);
        }
        //  超限，去除
        while (!Q2.empty() && temp < sum2)
        {
            Q3.push(-Q2.top());
            sum2 -= Q2.top();
            Q2.pop();
        }
        //  加上 Q3 中最小依然合法，添加
        while (!Q3.empty() && temp >= sum2 - Q3.top())
        {
            Q2.push(-Q3.top());
            sum2 -= Q3.top();   //  加上 Q3 最小花费
            Q3.pop();
        }
        
        if (temp >= sum2 && k + (int)Q2.size() > ans)
        {
            ans = k + (int)Q2.size();
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
