//
//  main.cpp
//  f-快排
//
//  Created by ZYJ on 16/7/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

void ksort(int l, int h, int a[])
{
    if (h < l + 2)
    {
        return ;
    }
    int e = h, p = l;
    while (l < h)
    {
        while (++l < e && a[l] <= a[p]);
        while (--h > p && a[h] >= a[p]);
        if (l < h)
        {
            swap(a[l], a[h]);
        }
    }
    swap(a[h], a[p]);
    ksort(p, h, a);
    ksort(l, e, a);
    return ;
}