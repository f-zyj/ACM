//
//  main.cpp
//  f-51Nod-1573-美丽的集合
//
//  Created by ZYJ on 2017/10/8.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <bitset>
#include <iostream>

using namespace std;

const int MAXN = 1005;
const int MAXM = 1e5 + 10;

int n, Q;
int cnt[MAXN];
int pre[MAXN];
int d[MAXN][MAXN];
bitset<MAXM> a[MAXN];
bitset<MAXM> b;

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

int find(int x)
{
    return pre[x] == x ? x : pre[x] = find(pre[x]);
}

int main()
{
    scan_d(n);
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = 1;
        pre[i] = i;
        scan_d(d[i][cnt[i]]);
        a[i][0] = a[i][d[i][cnt[i]]] = 1;
    }
    
    scan_d(Q);
    int A, i, j;
    while (Q--)
    {
        scan_d(A);
        if (A == 2)
        {
            scan_d(i);
            printf("%zu\n", a[find(i)].count());    //  输出 a 中 1 的个数
            continue;
        }
        
        scan_d(i);
        scan_d(j);
        //  合并 i 和 j 所在集合
        int x = find(i), y = find(j);
        if (cnt[y] > cnt[x])
        {
            swap(x, y);
        }
        pre[y] = x;
        
        for (i = cnt[y]; i; i--)
        {
            d[x][++cnt[x]] = d[y][i];
            a[x] |= a[x] << (d[x][cnt[x]]);         //  添加一个元素后与原来的元素组成的新和
        }
    }
    
    return 0;
}
