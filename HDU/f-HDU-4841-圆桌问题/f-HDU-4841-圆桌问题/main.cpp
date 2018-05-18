//
//  main.cpp
//  f-HDU-4841-圆桌问题
//
//  Created by ZYJ on 2017/9/6.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 4e4;
const int MOD = 50;

int n, m;
int flag[MAXN];
vector<int> vi;

int main()
{
    int tot, now;
    while (~scanf("%d%d", &n, &m))
    {
        vi.clear();
        tot = n << 1;
        for (int i = 1; i <= tot; i++)
        {
            vi.push_back(i);
            flag[i] = 0;
        }
        
        now = 1;
        while (tot > n)
        {
            now += (m - 1);
            if (now <= tot)
            {
                flag[vi[now - 1]] = 1;
                vi.erase(vi.begin() + now - 1);
                now = now == tot ? 1 : now;
            }
            else
            {
                now %= tot;
                now = now == 0 ? tot : now; //  nwo 太大时，%tot 存在为 0 的情况
                flag[vi[now - 1]] = 1;
                vi.erase(vi.begin() + now - 1);
                now = now == tot ? 1 : now;
            }
            tot--;
        }
        
        int tmp = n << 1;
        for (int i = 1; i <= tmp; i++)
        {
            if (flag[i])
            {
                printf("B");
            }
            else
            {
                printf("G");
            }
            if (i % MOD == 0)
            {
                putchar(10);
            }
        }
        
        
        if ((n << 1) % MOD != 0)
        {
            putchar(10);
        }
        
        putchar(10);
    }
    
    return 0;
}
