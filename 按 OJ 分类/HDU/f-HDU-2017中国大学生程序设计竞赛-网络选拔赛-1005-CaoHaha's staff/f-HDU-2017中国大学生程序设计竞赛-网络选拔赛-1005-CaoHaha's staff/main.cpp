//
//  main.cpp
//  f-HDU-2017中国大学生程序设计竞赛-网络选拔赛-1005-CaoHaha's staff
//
//  Created by ZYJ on 2017/8/19.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

double n;
double ans[MAXN];

void init()
{
    for (int i = 4 ; i <= MAXN; i++)
    {
        if (i % 4 == 0)
        {
            ans[i] = (i / 4) * (i / 4) * 2;
        }
        else if ((i - 1) % 4 == 0)
        {
            ans[i] = ans[i - 1] + (i / 4 - 1) + 0.5;
        }
        else
        {
            ans[i] = ans[i - 1] + (i / 4 - 1) + 1.5;
        }
    }
}

int main()
{
    init();
    
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%lf", &n);
        int pos = (int)(lower_bound(ans + 4, ans + MAXN - 1, n) - ans);
        printf("%d\n", pos);
    }
    
    return 0;
}

