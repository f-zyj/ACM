//
//  main.cpp
//  f-百练-2456-Aggressive cows
//
//  Created by ZYJ on 2017/9/28.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100002;
const int INF = 0x3f3f3f3f;

int N, C;
int x[MAXN];

bool check(int m)
{
    int last = 0;
    for (int i = 1; i < C; i++)
    {
        int cur = last + 1;
        while (cur < N && x[cur] - x[last] < m)
        {
            cur++;
        }
        if (cur == N)
        {
            return false;
        }
        last = cur;
    }
    
    return true;
}

int main()
{
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", x + i);
    }
    sort(x, x + N);
    
    int l = 0, r = INF, ans = 0;
    while (l < r)
    {
        int m = (l + r) >> 1;
        if (check(m))
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
