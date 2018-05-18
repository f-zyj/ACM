//
//  main.cpp
//  f-51Nod-1420-数袋鼠好有趣
//
//  Created by ZYJ on 16/9/18.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 5e5;

int si[MAXN];

int bs(int l, int h, int v)
{
    int m;
    while (l < h)
    {
        m = (l + h) >> 1;
        if (si[m] < v)
        {
            l = m + 1;
        }
        else
        {
            h = m;
        }
    }
    return l;
}

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", si + i);
    }
    sort(si, si + n);
    int big = bs(0, n, 2 * si[0]);
    int res = 0;
    
    for (int i = 0; i < n / 2; i++)
    {
        while (si[big] < 2 * si[i] && big < n)
        {
            big++;
        }
        if (big < n)
        {
            big++;
            res++;
        }
    }
    
    cout << n - res << '\n';
    return 0;
}
