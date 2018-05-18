//
//  main.cpp
//  f-51Nod-1328-比赛往事
//
//  Created by ZYJ on 2017/4/28.
//  Copyright ? 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1010;

int N;
int p[MAXN], c[MAXN], cnt = 0;
int p_[MAXN], c_[MAXN], cnt_ = 0;

void ins(int *a, int k, int x)
{
    while (k && a[k - 1] > x)
    {
        a[k] = a[k - 1];
        k--;
    }
    a[k] = x;
}

int main()
{
    cin >> N;
    
    int a, b;
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d", &a, &b);
        if (a <= b)
        {
            p[cnt] = a;
            c[cnt++] = b;
        }
        else
        {
            p_[cnt_] = a;
            c_[cnt_++] = b;
        }
    }
    
    sort(p_, p_ + cnt_);
    sort(c_, c_ + cnt_);
    
    while (true)
    {
        int tmp = cnt_ - 1;
        while (tmp >= 0 && p_[tmp] <= c_[tmp])
        {
            tmp--;
        }
        if (tmp < 0)
        {
            break;
        }
        int tag = -1;
        for (int i = 0; i < cnt; i++)
        {
            if (p[i] <= c_[tmp] && c[i] >= p_[tmp] && (tag == -1 || p[i] < p[tag]))
            {
                tag = i;
            }
        }
        if (tag < 0)
        {
            for (int i = 0; i < cnt; i++)
            {
                if (c[i] >= p_[tmp] && (tag == -1 || p[i] < p[tag]))
                {
                    tag = i;
                }
            }
        }
        if (tag < 0)
        {
            puts("-1");
            return 0;
        }
        ins(p_, cnt_, p[tag]);
        ins(c_, cnt_, c[tag]);
        cnt_++;
        cnt--;
        p[tag] = p[cnt];
        c[tag] = c[cnt];
    }
    
    printf("%d", cnt_);

    return 0;
}
