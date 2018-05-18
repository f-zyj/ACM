//
//  main.cpp
//  f-51Nod-1204-Parity
//
//  Created by ZYJ on 2017/4/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

const int MAXN = 1e5 + 10;

int pre[MAXN * 2];

int find(int x)
{
    if (pre[x] != x)
    {
        pre[x] = find(pre[x]);
    }
    return pre[x];
}

void join(int x, int y)
{
    x = find(x);
    y = find(y);
    
    pre[y] = x;
}

void init()
{
    for (int i = 0; i <= MAXN * 2; i++)
    {
        pre[i] = i;
    }
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    init();
    
    int N, Q;
    std::cin >> N >> Q;
    
    int left, right;
    int cnt = 0, flag = -1;
    char s[5];
    while (++cnt)
    {
        if (cnt > Q)
        {
            break;
        }
        scanf("%d%d%s", &left, &right, s);
        if (s[0] == 'e')
        {
            if (find(left - 1 + N) == find(right) && find(left - 1) == find(right + N))
            {
                flag = cnt;
                break;
            }
            else
            {
                join(left - 1, right);
                join(left - 1 + N, right + N);
            }
        }
        else
        {
            if (find(left - 1) == find(right) && find(left - 1 + N) == find(right + N))
            {
                flag = cnt;
                break;
            }
            else
            {
                join(left - 1, right + N);
                join(left - 1 + N, right);
            }
        }
    }
    
    std::cout << flag << '\n';
    
    return 0;
}
