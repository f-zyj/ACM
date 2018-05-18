//
//  main.cpp
//  f-51Nod-1091-线段的重叠
//
//  Created by ZYJ on 16/7/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5e4 + 5;

struct line
{
    int x, y;
} L[MAXN];

bool cmp(line a, line b)
{
    return a.x < b.x;
}

int main(int argc, const char * argv[])
{
    freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &L[i].x, &L[i].y);
    }
    sort(L, L + N, cmp);
    int len = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int A = L[i].x > L[j].x ? L[i].x : L[j].x;
            int B = L[i].y > L[j].y ? L[j].y : L[i].y;
            len = len > B - A ? len : B - A;
            if (L[j].y > L[i].y)
            {
                break;
            }
        }
    }
    cout << len << '\n';
    
    return 0;
}
