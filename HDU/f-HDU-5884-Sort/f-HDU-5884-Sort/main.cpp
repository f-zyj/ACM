//
//  main.cpp
//  f-HDU-5884-Sort
//
//  Created by ZYJ on 2017/6/27.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 1e5 + 10;

int N, T;
int a[MAXN];
queue<int> qi1, qi2;

bool charge(int k)
{
    while (!qi1.empty())
    {
        qi1.pop();
    }
    while (!qi2.empty())
    {
        qi2.pop();
    }
    for (int i = 1; i <= N; i++)
    {
        qi1.push(a[i]);
    }
    
    int num = 0, sum = 0, ans = 0;
    if ((N - 1) % (k - 1) != 0)
    {
        num = (N - 1) % (k - 1) + 1;
        for (int i = 1; i <= num; i++)
        {
            sum += qi1.front();
            qi1.pop();
        }
        qi2.push(sum);
        ans += sum;
    }
    
    while (!qi1.empty())
    {
        sum = 0;
        for (int i = 1; i <= k; i++)
        {
            if (!qi1.empty() && !qi2.empty())
            {
                if (qi1.front() <= qi2.front())
                {
                    sum += qi1.front();
                    qi1.pop();
                }
                else
                {
                    sum += qi2.front();
                    qi2.pop();
                }
            }
            else if (!qi1.empty())
            {
                sum += qi1.front();
                qi1.pop();
            }
            else if (!qi2.empty())
            {
                sum += qi2.front();
                qi2.pop();
            }
        }
        ans += sum;
        qi2.push(sum);
    }
    if (ans > T)
    {
        return false;
    }
    
    sum = 0;
    num = 0;
    while (!qi2.empty())
    {
        sum += qi2.front();
        qi2.pop();
        num++;
        if (num == k)
        {
            qi2.push(sum);
            ans += sum;
            sum = 0;
            num = 0;
            if (qi2.size() == 1)
            {
                break;
            }
        }
    }
    if (ans > T)
    {
        return false;
    }
    
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    
    while (t--)
    {
        scanf("%d%d", &N, &T);
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + N + 1);
        
        int l = 2, r = N, m, ans = 1;
        while (l <= r)
        {
            m = (l + r) >> 1;
            if (charge(m))
            {
                r = m - 1;
                ans = m;
            }
            else
            {
                l = m + 1;
            }
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
