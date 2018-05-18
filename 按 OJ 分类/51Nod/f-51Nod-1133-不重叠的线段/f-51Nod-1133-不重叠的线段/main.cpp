//
//  main.cpp
//  f-51Nod-1133-不重叠的线段
//
//  Created by ZYJ on 16/8/3.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e4 + 5;

struct line
{
    int x, y;
} L[MAXN];

bool cmp(line a, line b)
{
    return a.y < b.y;
}

int main(int argc, const char * argv[])
{
    // freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d", &L[i].x, &L[i].y);
    }
    sort(L + 1, L + N, cmp);
    
    int res = 1;
    int flagY = L[1].y;
    for (int i = 2; i <= N; i++)
    {
        if (L[i].x >= flagY)
        {
            flagY = L[i].y;
            res++;
        }
    }
    cout << res << '\n';
    
    return 0;
}