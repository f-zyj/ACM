//
//  main.cpp
//  f-2017"百度之星"程序设计大赛-资格赛-1002-度度熊的王国战略
//
//  Created by ZYJ on 2017/8/6.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

#define clr(a, b) memset(a, b, sizeof(a))

using namespace std;

const int MAXN = 3333;

int n, m;
int val[MAXN];
int pre[MAXN];

int find(int x)
{
    if (pre[x] == 0)
    {
        return x;
    }
    return pre[x] = find(pre[x]);
}

int main(void)
{
    while (~scanf("%d%d", &n, &m))
    {
        clr(pre, 0);
        clr(val, 0);
     
        int cnt = n - 1;
        int u, v, w, u_, v_;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            if (u == v)
            {
                continue;
            }
            
            val[u] += w;
            val[v] += w;
            u_ = find(u);
            v_ = find(v);
            if (u_ != v_)
            {
                pre[u_] = v_;
                cnt--;
            }
        }
        
        if (cnt == 0)
        {
            sort(val + 1, val + n + 1);
            printf("%d\n", val[1]);
        }
        else
        {
            printf("0\n");
        }
    }
    
    return 0;
}
