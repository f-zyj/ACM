//
//  main.cpp
//  f-HDU-5575-Discover Water Tank
//
//  Created by ZYJ on 2017/11/21.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1e5 + 10;
const int MAXM = 2e5 + 5;

int n, m, x, y, z, ans;
int L[MAXN], R[MAXN], LH[MAXN], RH[MAXN], O[MAXN], X[MAXN];
vector<pii> vp;

//  左偏树相关
int tot, v[MAXM], l[MAXM], r[MAXM], d[MAXM], Heap[MAXN];

//  合并左偏树
int merge(int x, int y)
{
    if (x == 0)
    {
        return y;
    }
    if (y == 0)
    {
        return x;
    }
    if (v[x] > v[y])
    {
        swap(x, y);
    }
    r[x] = merge(r[x], y);
    if (d[l[x]] < d[r[x]])
    {
        swap(l[x], r[x]);
    }
    d[x] = d[r[x]] + 1;
    return x;
}

//  初始化可并堆结点
inline int init(int x)
{
    v[++tot] = x;
    l[tot] = r[tot] = d[tot] = 0;
    return tot;
}

//  左偏树的插入操作
inline int insert(int x, int y)
{
    return merge(x, init(y));
}

//  取得左偏树中的最小值
inline int top(int x)
{
    return v[x];
}

//  弹出左偏树
inline int pop(int x)
{
    return merge(l[x], r[x]);
}

//  判断左偏树是否非空
inline bool empty(int x)
{
    return x == 0;
}

//  初始化可并堆
void initHeap()
{
    memset(Heap, 0, sizeof(Heap));
    tot = 0;
}

//  并查集相关
int p[MAXN];

//  初始化并查集
void initSet()
{
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
}

//  查找集合的祖先
int find(int x)
{
    return x == p[x] ? x : p[x] = find(p[x]);
}

//  合并集合
inline void Union(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
    {
        return ;
    }
    p[y] = x;
    if (x < y)
    {
        RH[x] = RH[y];
        L[R[x]] = x;
        R[x] = R[y];
    }
    else
    {
        LH[x] = LH[y];
        R[L[x]] = x;
        L[x] = L[y];
    }
    //  合并可并堆
    Heap[x] = merge(Heap[x], Heap[y]);
    X[x] += X[y];
    O[x] += O[y];
}

int main()
{
    int T;
    scanf("%d", &T);
    
    for (int ce = 1; ce <= T; ce++)
    {
        scanf("%d%d", &n, &m);
        LH[1] = RH[n] = INT_MAX;
        L[n] = n - 1;
        for (int i = 1; i < n; i++)
        {
            scanf("%d", &RH[i]);
            //  用于快速查询水箱的左右挡板
            LH[i + 1] = RH[i];
            //  用于快速查询左右方水箱
            L[i] = i - 1;
            R[i] = i + 1;
        }
        
        initHeap();
        vp.clear();
        ans = 0;
        while (m--)
        {
            scanf("%d%d%d", &x, &y, &z);
            if (z == 1)
            {
                vp.push_back(pii(y + 1, x));
            }
            else
            {
                Heap[x] = Heap[x] ? insert(Heap[x], y) : init(y);
                ans++;
            }
        }
        
        initSet();
        sort(vp.begin(), vp.end());
        for (int i = 1; i <= n; i++)
        {
            O[i] = X[i] = 0;
        }
        for (int i = 0; i < vp.size(); i++)
        {
            x = find(vp[i].second);
            y = vp[i].first;
            //  向左溢出
            while (y > LH[x])
            {
                Union(x, L[x]);
                x = find(x);
            }
            //  向右溢出
            while (y > RH[x])
            {
                Union(x, R[x]);
                x = find(x);
            }
            //  删除水位以下的Ｘ
            while (!empty(Heap[x]) && top(Heap[x]) < y)
            {
                Heap[x] = pop(Heap[x]);
                X[x]++;
            }
            //  更新答案
            if (++O[x] >= X[x])
            {
                ans += (O[x] - X[x]);
                O[x] = X[x] = 0;
            }
        }
        
        printf("Case #%d: %d\n", ce, ans);
    }
    
    return 0;
}
