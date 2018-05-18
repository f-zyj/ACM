//
//  main.cpp
//  f-CCF模拟-3-最大的矩阵
//
//  Created by ZYJ on 2016/12/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1010;

int h[MAXN];

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", h + i);
    }
    
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int j, k;
        for (j = i - 1; j >= 0; j--)
        {
            if (h[j] < h[i])
            {
                j++;
                break;
            }
        }
        if (j == -1)
        {
            j++;
        }
        for (k = i + 1; k < n; k++)
        {
            if (h[k] < h[i])
            {
                k--;
                break;
            }
        }
        if (k == n)
        {
            k--;
        }
        int temp = (k - j + 1) * h[i];
        if (temp > res)
        {
            res = temp;
        }
    }
    
    cout << res << '\n';
    
    return 0;
}
