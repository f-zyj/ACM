//
//  main.cpp
//  f-2016年多大学培训大赛4-1012-Bubble Sort
//
//  Created by ZYJ on 16/7/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

//  WA

const int MAXN = 1e5 + 5;

int num[MAXN];
int flag[MAXN];

void QuickSort(int h, int t, int a[])
{
    if (h >= t)
    {
        return;
    }
    int mid = (h + t) / 2, i = h, j = t, x;
    x = a[mid];
    while (1)
    {
        while (a[i] < x)
        {
            i++;
        }
        while (a[j] > x)
        {
            j--;
        }
        if (i >= j)
        {
            break;
        }
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        flag[i] += j - i;
        flag[j] -= j - i;
    }
    a[mid] = a[j];
    a[j] = x;
    QuickSort(h, j - 1, a);
    QuickSort(j + 1, t, a);
    return ;
}


int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        memset(flag, 0, sizeof(flag));
        
        for (int i = 0; i < N; i++)
        {
            cin >> num[i];
        }
        
        QuickSort(0, N, num);
        
        for (int i = 0; i < N; i++)
        {
            cout << fabs(flag[i]) << '\n';
        }
    }

    return 0;
}
