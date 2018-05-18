//
//  main.cpp
//  f-EOJ-大学生程序设计邀请赛（华东师范大学）-D-实验室传染病
//
//  Created by ZYJ on 2017/5/15.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdio>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1e5 + 10;

int n, flag;
int l[MAXN], r[MAXN];
pii a[MAXN], b[MAXN];

void update()
{
    stack<int> si;
    for (int i = 1; i <= n; i++)    //  维护单调递增栈，更新 l[]
    {
        while (!si.empty() && si.top() >= l[i])
        {
            if (l[si.top()] < l[i])
            {
                l[i] = l[si.top()];
                flag = 1;
            }
            si.pop();
        }
        si.push(i);
    }
    while (!si.empty())
    {
        si.pop();
    }
    for (int i = n; i >= 1; i--)    //  维护单调递减栈，更新 r[]
    {
        while (!si.empty() && si.top() <= r[i])
        {
            if (r[si.top()] > r[i])
            {
                r[i] = r[si.top()];
                flag = 1;
            }
            si.pop();
        }
        si.push(i);
    }
    while (!si.empty())
    {
        si.pop();
    }
}

void update_()
{
    stack<int> p;
    for (int i = 1; i <= n; i++)    //  维护单调递增栈，更新 r[]
    {
        while (!p.empty() && p.top() >= l[i])
        {
            if (r[p.top()] > r[i])
            {
                r[i] = r[p.top()];
                flag = 1;
            }
            p.pop();
        }
        p.push(i);
    }
    while (!p.empty())
    {
        p.pop();
    }
    for (int i = n; i >= 1; i--)    //  维护单调递减栈，更新 l[]
    {
        while (!p.empty() && p.top() <= r[i])
        {
            if (l[p.top()] < l[i])
            {
                l[i] = l[p.top()];
                flag = 1;
            }
            p.pop();
        }
        p.push(i);
    }
    while (!p.empty())
    {
        p.pop();
    }
}

int main()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &a[i].first, &a[i].second);
            b[i] = a[i];
        }
        sort(a + 1, a + n + 1);
        
        for (int i = 1; i <= n; i++)
        {
            l[i] = (int)(lower_bound(a + 1, a + n + 1,
                                     make_pair(a[i].first - a[i].second, 0)) - a);
            r[i] = (int)(lower_bound(a + 1, a + n + 1,
                                     make_pair(a[i].first + a[i].second, 0x3f3f3f3f)) - a - 1);
        }
        
        while (true)
        {
            flag = 0;
            update();
            update_();
            if (!flag)
            {
                break;
            }
        }
        
        for (int i = 1; i < n; i++)
        {
            int k = (int)(lower_bound(a + 1, a + n + 1, b[i]) - a);
            printf("%d ", r[k] - l[k] + 1);
        }
        int k = (int)(lower_bound(a + 1, a + n + 1, b[n]) - a);
        printf("%d\n", r[k] - l[k] + 1);
    }
    
    return 0;
}
