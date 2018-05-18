//
//  main.cpp
//  f-蓝桥-ALGO-29-校门外的树
//
//  Created by ZYJ on 2017/6/5.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 111;
const int INF = 0x3f3f3f3f;

struct interval
{
    int l, r;
} Itv[MAXN];

int L, M;

bool cmp(interval a, interval b)
{
    if (a.l == b.l)
    {
        return a.r < b.r;
    }
    return a.l < b.l;
}

int main(int argc, const char * argv[])
{
    cin >> L >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> Itv[i].l >> Itv[i].r;
    }
    
    sort(Itv, Itv + M, cmp);
    for (int i = 1; i < M; i++)
    {
        if (Itv[i].l <= Itv[i - 1].r && Itv[i].r >= Itv[i - 1].r)
        {
            Itv[i].l = Itv[i - 1].l;
            Itv[i - 1].l = INF;
        }
        else if (Itv[i].r <= Itv[i - 1].r)
        {
            Itv[i].r = Itv[i - 1].r;
            Itv[i].l = Itv[i - 1].l;
            Itv[i - 1].l = INF;
        }
    }
    sort(Itv, Itv + M, cmp);
    
    int res = L + 1;
    for (int i = 0; i < M; i++)
    {
        if (Itv[i].l > L)
        {
            break;
        }
        res -= min(L - Itv[i].l + 1, Itv[i].r - Itv[i].l + 1);
    }
    
    cout << res << '\n';
    
    return 0;
}
