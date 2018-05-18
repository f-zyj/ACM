//
//  main.cpp
//  f-HDU-3047-Zjnu Stadium
//
//  Created by ZYJ on 2016/11/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 50005;

int n, m;
int pre[MAXN];
int rank_[MAXN];

void init()
{
    for (int i = 0; i <= n; ++i)
    {
        pre[i] = i;
        rank_[i] = 0;
    }
}

int find(int x)
{
    if (x == pre[x])
    {
        return pre[x];
    }
    
    int t = pre[x];
    pre[x] = find(pre[x]);
    rank_[x] += rank_[t];
    
    return pre[x];
}

bool join(int x, int y, int m)
{
    int fx = find(x);
    int fy = find(y);
    
    if (fx == fy)
    {
        if (rank_[x] + m != rank_[y])
        {
            return false;
        }
        return true;
    }
    pre[fy] = fx;
    rank_[fy] = rank_[x] + m - rank_[y];
    return true;
}

int main()
{
    int a, b, x;
    while (~scanf("%d%d", &n, &m))
    {
        init();
        
        int cnt = 0;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &a, &b, &x);
            if (!join(a, b, x))
            {
                ++cnt;
            }
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}
