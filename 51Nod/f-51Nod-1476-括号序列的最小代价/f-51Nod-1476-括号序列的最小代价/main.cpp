//
//  main.cpp
//  f-51Nod-1476-括号序列的最小代价
//
//  Created by ZYJ on 2017/7/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 5e4 + 5;

char s[MAXN];
int a[MAXN], b[MAXN];
priority_queue<int> pqi;

int main()
{
    scanf("%s", s);
    int n = (int)strlen(s);
    
    ll sum = 0;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {
            scanf("%d%d", &a[i], &b[i]);
            sum += b[i];
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            cnt++;
        }
        else if (s[i] == ')' || s[i] == '?')
        {
            cnt--;
        }
        if (s[i] == '?')
        {
            pqi.push(b[i] - a[i]);    //  替换时，a[i] - b[i]，考虑优先出来大的，故取反
        }
        if (cnt < 0)
        {
            if (pqi.empty())
            {
                flag = false;
                break;
            }
            sum -= pqi.top();
            pqi.pop();
            cnt += 2;
        }
    }
    if (cnt != 0)
    {
        flag = false;
    }
    
    printf("%lld\n", flag ? sum : -1);
    
    return 0;
}
