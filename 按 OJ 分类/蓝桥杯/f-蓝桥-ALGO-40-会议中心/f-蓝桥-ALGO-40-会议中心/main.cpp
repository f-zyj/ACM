//
//  main.cpp
//  f-蓝桥-ALGO-40-会议中心
//
//  Created by ZYJ on 2017/6/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

const int MAXN = 2e5 + 10;
const int INF = 0x3f3f3f3f;

struct node
{
    int l, r;
    
    node() {}
    node(int l_, int r_) : l(l_), r(r_) {}
    bool operator < (const node &s) const
    {
        return l < s.l || (l == s.l && r < s.r);
    }
};

int n;
int tag[MAXN << 1];
int net[20][MAXN << 1]; //  存储下一个区间的起点
int cnt = 0, limit = 1, limit_;
node A[MAXN];
node B[MAXN];
node tmp[MAXN];
set<node> ss;
set<node>::iterator it;

int bs(int x)
{
    for (int l = 0, r = limit - 1; l < r + 1;)
    {
        int m = (l + r) >> 1;
        if (x == tag[m])
        {
            return m;
        }
        if (x < tag[m])
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return 0;
}

bool cmp(const node &a,const node &b)
{
    return a.r < b.r || (a.r == b.r && a.l > b.l);
}

//  离散化
void discrete()
{
    sort(tag, tag + (n << 1));
    limit = (int)(unique(tag, tag + (n << 1)) - tag);
    
    for (int i = 0; i < n; i++)
    {
        tmp[i] = A[i] = node(bs(A[i].l), bs(A[i].r));
    }
    sort(tmp, tmp + n, cmp);

    int p = 0;
    B[cnt++] = tmp[0];
    for (int i = 1; i < n; ++i)
    {
        if (tmp[i].l > tmp[p].l)
        {
            B[cnt++] = tmp[p = i];
        }
    }
}

void next_set()
{
    int p = cnt - 1;
    net[0][limit] = INF;
    for (int j = limit - 1; j >= 0; j--)
    {
        if (p > -1 && j == B[p].l)
        {
            net[0][j] = B[p--].r + 1;
        }
        else
        {
            net[0][j] = net[0][j + 1];
        }
    }
    for (int i = 0; 1; i++)
    {
        bool flag = 0;
        net[i + 1][limit] = INF;
        for (int k = 0; k < limit; k++)
        {
            if (net[i][k] == INF)
            {
                net[i + 1][k] = INF;
            }
            else
            {
                net[i + 1][k] = net[i][net[i][k]];
            }
            if (net[i + 1][k] < INF)
            {
                flag = 1;
            }
        }
        if (!flag)
        {
            limit_ = i;
            break;
        }
    }
}

int max_cnt(int l, int r)
{
    if (l > r)
    {
        return 0;
    }
    
    r++;
    int ans = 0, p = l;
    for (int i = limit_; i > -1 && p < r; i--)
    {
        if (net[i][p] <= r)
        {
            p = net[i][p];
            ans += 1 << i;
        }
    }
    
    return ans;
}

bool query(int x)
{
    int l = A[x].l, r = A[x].r;
    it = ss.lower_bound(node(l, INF));
    
    if (it-- == ss.begin())
    {
        return 0;
    }
    
    int l_ = it->l, r_ = it->r;
    if (l_ > l || r_ < r)
    {
        return 0;
    }
    
    if (max_cnt(l_, l - 1) + max_cnt(r + 1, r_) + 1 < max_cnt(l_, r_))
    {
        return 0;
    }
    
    ss.erase(it);
    if (l_ < l)
    {
        ss.insert(node(l_, l - 1));
    }
    if (r < r_)
    {
        ss.insert(node(r + 1, r_));
    }
    return 1;
}

int main()
{
    cin >> n;
    int l, r;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &l, &r);
        A[i] = node(l, r);
        //  用于离散化
        tag[i << 1] = l;
        tag[(i << 1) + 1] = r;
    }
    
    discrete();
    next_set();
    
    printf("%d\n", max_cnt(0, limit - 1));
    ss.insert(node(0, limit - 1));
    for (int i = 0; i < n; i++)
    {
        if (query(i))
        {
            printf("%d ", i + 1);
        }
    }
    putchar(10);
    
    return 0;
}
