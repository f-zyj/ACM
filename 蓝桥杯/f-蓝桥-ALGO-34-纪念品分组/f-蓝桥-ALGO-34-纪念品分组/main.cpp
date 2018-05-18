//
//  main.cpp
//  f-蓝桥-ALGO-34-纪念品分组
//
//  Created by ZYJ on 2017/6/6.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 3e4 + 10;

int w, n;
int p[MAXN];

int main(int argc, const char * argv[])
{
    cin >> w >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", p + i);
    }
    sort(p, p + n);
    
    int left = 0, right = n - 1, res = 0;
    while (left < right)
    {
        res++;
        if (p[right] + p[left] <= w)
        {
            right--;
            left++;
        }
        else
        {
            right--;
        }
    }
    if (left == right)
    {
        res++;
    }
    cout << res << '\n';
    
    return 0;
}
