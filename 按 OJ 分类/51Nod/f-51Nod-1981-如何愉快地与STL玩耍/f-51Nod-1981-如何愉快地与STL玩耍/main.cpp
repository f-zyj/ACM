//
//  main.cpp
//  f-51Nod-1981-如何愉快地与STL玩耍
//
//  Created by ZYJ on 2018/1/5.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>

using namespace std;

const int MAXN = 65540;
const int MAXS = 10001;

int N, Q;
int L, R, C_K;
int rt, cnt = 0;
bitset<MAXS> tmp;
bitset<MAXS> ans[MAXN];
bitset<MAXS> pre[MAXS];

struct node
{
    bitset<MAXS> bit, tag;
} tree[MAXN << 1];

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

template <class T>
void print_d(T x)
{
    if (x > 9)
    {
        print_d(x / 10);
    }
    putchar(x % 10 + '0');
}

void _insert(int l, int r)
{
    rt = (l + r) | (l != r);
    tree[rt].bit[C_K] = 1;
    if (L <= l && r <= R)
    {
        tree[rt].tag[C_K] = 1;
        return ;
    }
    
    int m = (l + r) >> 1;
    if (L <= m)
    {
        _insert(l,m);
    }
    if (R > m)
    {
        _insert(m + 1, r);
    }
}

void query(int l, int r)
{
    rt = (l + r) | (l != r);
    if (L <= l && r <= R)
    {
        ans[cnt] |= tree[rt].bit;
        return ;
    }
    
    ans[cnt] |= tree[rt].tag;
    int m = (l + r) >> 1;
    if (L <= m)
    {
        query(l, m);
    }
    if (R > m)
    {
        query(m + 1, r);
    }
}

inline size_t check(int m)
{
    tmp = ans[cnt] & pre[m];
    return tmp.count();
}

void solve()
{
    if (!C_K)
    {
        puts("-1");
        return ;
    }
    
    cnt++;
    query(1, N);
    if (ans[cnt].count() < C_K)
    {
        puts("-1");
        return ;
    }
    
    int l = 0, r = MAXS;
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (check(m) >= C_K)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    
    print_d(r + 1);
    putchar(10);
}

void init()
{
    pre[0][0] = 1;
    for (int i = 1; i < MAXS; i++)
    {
        pre[i] = pre[i - 1];
        pre[i][i] = 1;
    }
}

int main()
{
    init();
    
    scan_d(N);
    scan_d(Q);
    
    int op;
    while (Q--)
    {
        scan_d(op);
        scan_d(L);
        scan_d(R);
        scan_d(C_K);
        
        if (op == 1)
        {
            _insert(1, N);
        }
        else
        {
            solve();
        }
    }
    
    return 0;
}
