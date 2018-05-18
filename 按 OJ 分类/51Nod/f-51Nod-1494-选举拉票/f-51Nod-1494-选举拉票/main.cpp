//
//  main.cpp
//  f-51Nod-1494-选举拉票
//
//  Created by ZYJ on 2017/7/15.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

#define lson rt << 1
#define rson rt << 1 | 1

using namespace std;

const int MAXA = 1e5 + 10;
const int MAXB = 1e4 + 10;

int n;
int tree[MAXB << 2];
int num[MAXB << 2];
vector<int> vi_b[MAXA];
vector<int> vi_t[MAXA];

void update(int rt, int l, int r, int x)
{
    if (l == r)
    {
        num[rt]++;
        tree[rt] += l;
        return ;
    }
    int m = (l + r) >> 1;
    if (x <= m)
    {
        update(lson, l, m, x);
    }
    else
    {
        update(rson, m + 1, r, x);
    }
    
    tree[rt] = tree[lson] + tree[rson];
    num[rt] = num[lson] + num[rson];
}

int query(int rt, int l, int r, int x)
{
    if (l == r)
    {
        return l * x;
    }
    
    int m = (l + r) >> 1;
    if (x == num[lson])
    {
        return tree[lson];
    }
    if (x > num[lson])
    {
        return tree[lson] + query(rson, m + 1, r, x - num[lson]);
    }
    else
    {
        return query(lson, l, m, x);
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

int main()
{
    scanf("%d", &n);
    
    int ans = 0, mx_a = 0, mx_b = 1, a, b;
    for (int i = 1; i <= n; i++)
    {
        scan_d(a), scan_d(b);
        if (b == 0)
        {
            continue;
        }
        
        ans += b;
        mx_a = max(mx_a, a);
        mx_b = max(mx_b, b);
        vi_b[a].push_back(b);
    }
    
    int mx_c = 0;
    for (int i = 1; i <= mx_a; i++)
    {
        if (vi_b[i].size())
        {
            sort(vi_b[i].begin(), vi_b[i].end(), greater<int>());
            
            mx_c = max(mx_c, (int)vi_b[i].size());
            for (int j = 0; j < vi_b[i].size(); j++)
            {
                vi_t[j].push_back(vi_b[i][j]);
            }
        }
    }
    
    int k = n, res = ans;
    for (int i = 0; i < mx_c; i++)
    {
        k -= vi_t[i].size();
        for (int j = 0; j < vi_t[i].size(); j++)
        {
            update(1, 1, mx_b, vi_t[i][j]);
            res -= vi_t[i][j];
        }
        
        int tmp = 0, mn;
        if (k <= i + 1)
        {
            mn = min(i + 2 - k, n);     //  还差 mn 票
            tmp = query(1, 1, mx_b, mn);//  取最小的 mn 票
        }
        
        ans = min(ans, res + tmp);
    }
    
    printf("%d\n", ans);
    
    return 0;
}
