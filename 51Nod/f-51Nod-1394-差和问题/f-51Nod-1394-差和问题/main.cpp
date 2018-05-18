//
//  main.cpp
//  f-51Nod-1394-差和问题
//
//  Created by ZYJ on 2017/6/20.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n, q;
int limit;
ll sum_a = 0, res = 0;

struct o
{
    int order;
    ll num;
} oper[MAXN];

map<ll, int> mli;
ll a[MAXN << 1], b[MAXN << 1];
ll fw_pos[MAXN << 1], ct[MAXN << 1];
ll fw_val[MAXN << 1];

int lowbit(int x)
{
    return x & (-x);
}

void add(int x, ll y, ll arr[])
{
    while (x <= limit)
    {
        arr[x] += y;
        x = x + lowbit(x);
    }
}

ll sum(int x, ll arr[])
{
    ll res = 0;
    while (x > 0)
    {
        res += arr[x];
        x = x - lowbit(x);
    }
    return res;
}

//  离散化
void discretize()
{
    sort(a + 1, a + n + 1);
    sort(b + 1, b + limit + 1);
    
    int cnt = 0;
    for (int i = 1; i <= limit; i++)
    {
        if (mli[b[i]])
        {
            continue;
        }
        mli[b[i]] = ++cnt;
    }
}

void build()
{
    ll temp;
    for (int i = 1; i <= n; i++)
    {
        int x = mli[a[i]];
        add(x, 1, fw_pos);
        add(x, a[i], fw_val);
        temp = sum(x - 1, fw_pos);
        res += temp * a[i] - (sum_a - (ct[x] * a[i]));
        ct[x]++;
        sum_a = sum_a + a[i];
    }
}

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
void Out(T a)
{
    if (a >= 10)
    {
        Out(a / 10);
    }
    putchar(a % 10 + '0');
}

int main()
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    scan_d(n);
    scan_d(q);
    
    for (int i = 1; i <= n; i++)
    {
        scan_d(a[i]);
        b[i] = a[i];
    }
    
    int cnt = n;
    for (int i = 1; i <= q; i++)
    {
        scan_d(oper[i].order);
        if (oper[i].order == 1 || oper[i].order == 2)
        {
            scan_d(oper[i].num);
            b[++cnt] = oper[i].num;
        }
    }
    
    limit = cnt;
    
    discretize();
    
    build();
    
    ll right_cnt, left_cnt, left_sum, right_sum;
    for (int i = 1; i <= q; i++)
    {
        if (oper[i].order == 3)
        {
            Out(res);
            putchar(10);
        }
        else if (oper[i].order == 2)
        {
            int x = mli[oper[i].num];
            if (ct[x] == 0)
            {
                puts("-1");
            }
            else
            {
                sum_a -= oper[i].num;
                add(x, -1, fw_pos);
                add(x, -oper[i].num, fw_val);
                left_cnt = sum(x - 1, fw_pos);
                right_cnt = n - left_cnt - ct[x];
                n--;
                ct[x]--;
                left_sum = sum(x - 1, fw_val);
                right_sum = sum_a - left_sum - ct[x] * oper[i].num;
                
                res += (left_sum - oper[i].num * left_cnt)
                     + (right_cnt * oper[i].num - right_sum);
            }
        }
        else
        {
            int x = mli[oper[i].num];
            
            sum_a += oper[i].num;
            add(x, 1, fw_pos);
            add(x, oper[i].num, fw_val);
            left_cnt = sum(x - 1, fw_pos);
            right_cnt = n - left_cnt - ct[x];
            n++;
            ct[x]++;
            left_sum = sum(x - 1, fw_val);
            right_sum = sum_a - left_sum - ct[x] * oper[i].num;
            
            res -= (left_sum - oper[i].num * left_cnt)
                 + (right_cnt * oper[i].num - right_sum);
        }
    }

    return 0;
}
