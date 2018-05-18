//
//  main.cpp
//  f-HDU-2017中国大学生程序设计竞赛-网络选拔赛-1001-Vertex Cover
//
//  Created by ZYJ on 2017/8/19.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1e4 + 5;

pair<int, int> pii[MAXN];

int a = 99, b = 111, c = 0;

void solve()
{
    for (int i = a; i >= 2; i--)
    {
        int x = a / i;
        for (int j = 0; j < x; j++)
        {
            int tmp = b++;
            for (int k = 1; k <= i; k++)
            {
                pii[c].first = tmp;
                pii[c].second = k + i * j;
                c++;
            }
        }
    }
}

void output()
{
    printf("%d %d\n", b - 1, c);
    for (int i = 0; i <= c - 1; i++)
    {
        printf("%d %d\n", pii[i].first, pii[i].second);
    }
    printf("%d\n", a);
    for (int i = 1; i <= a; i++)
    {
        printf("%d\n", i);
    }
}

int main(int argc, const char * argv[])
{
    solve();
    
    output();
    
    return 0;
}
