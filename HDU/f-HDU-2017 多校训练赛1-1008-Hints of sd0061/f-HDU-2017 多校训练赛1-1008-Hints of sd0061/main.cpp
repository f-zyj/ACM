//
//  main.cpp
//  f-HDU-2017 多校训练赛1-1008-Hints of sd0061
//
//  Created by ZYJ on 2017/7/27.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e7 + 10;
const int MAXM = 111;

int n, m;
unsigned a[MAXN];
unsigned c[MAXM];

struct xxx
{
    int val, pos;
    
    bool operator < (const xxx y) const
    {
        return val < y.val;
    }
} b[MAXM];

unsigned x, y, z;
inline unsigned rng61()
{
    unsigned t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;
    return z;
}

int main()
{
    int ce = 1;
    while (~scanf("%d%d%u%u%u", &n, &m, &x, &y, &z))
    {
        for (int i = 0; i < m; ++i)
        {
            scanf("%d", &b[i].val);
            b[i].pos = i;
        }
        sort(b, b + m);
        
        for (int i = 0; i < n; ++i)
        {
            a[i] = rng61();
        }

        b[m].val = n;
        for (int i = m - 1; ~i; --i)
        {
            nth_element(a, a + b[i].val, a + b[i + 1].val);
            c[b[i].pos] = a[b[i].val];
        }
        
        printf("Case #%d: ", ce++);
        for (int i = 0; i < m - 1; ++i)
        {
            printf("%u ", c[i]);
        }
        printf("%u\n", c[m - 1]);
    }
    
    return 0;
}
