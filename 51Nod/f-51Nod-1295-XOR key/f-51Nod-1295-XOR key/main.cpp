//
//  main.cpp
//  f-51Nod-1295-XOR key
//
//  Created by ZYJ on 2017/8/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 5e4 + 5;
const int MAGIC = 30;
const int MAXM = MAXN * (MAGIC + 5);

int n, q, tot = 0;
int sum[MAXM];
int root[MAXN];
int son[MAXM][2];
bool bz[MAGIC + 5];

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

void insert(int v, int &x, int y)
{
    x = ++tot;
    memcpy(son[x], son[y], sizeof(son[x]));
    sum[x] = sum[y] + 1;
    if (!v)
    {
        return ;
    }
    insert(v - 1, son[x][bz[v - 1]], son[y][bz[v - 1]]);
}

int find(int v, int x, int y)
{
    if (!v)
    {
        return 0;
    }
    if (sum[son[x][bz[v - 1]]] > sum[son[y][bz[v - 1]]])
    {
        return find(v - 1, son[x][bz[v - 1]], son[y][bz[v - 1]]) + (1 << (v - 1));
    }
    return find(v - 1, son[x][1 - bz[v - 1]], son[y][1 - bz[v - 1]]);
}

int main()
{
    scan_d(n), scan_d(q);
    
    int x;
    for (int i = 1; i <= n; i++)
    {
        scan_d(x);
        for (int j = 0; j < MAGIC; x >>= 1)
        {
            bz[j++] = x & 1;
        }
        insert(MAGIC, root[i], root[i - 1]);
    }
    
    int l, r;
    while (q--)
    {
        scan_d(x), scan_d(l), scan_d(r);
        for (int j = 0; j < MAGIC; x >>= 1)
        {
            bz[j++] = 1 - (x & 1);
        }
        printf("%d\n", find(MAGIC, root[r + 1], root[l]));
    }
    
    return 0;
}
