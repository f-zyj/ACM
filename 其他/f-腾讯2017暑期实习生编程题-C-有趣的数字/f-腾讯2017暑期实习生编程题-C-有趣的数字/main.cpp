//
//  main.cpp
//  f-腾讯2017暑期实习生编程题-C-有趣的数字
//
//  Created by ZYJ on 2017/3/7.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 10;

int a[MAXN];

int main(int argc, const char * argv[])
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
        }
        sort(a, a + n);
        
        int tMin = a[0], numMin = 0;
        int tMax = a[n - 1], numMax = 0;
        if (tMin == tMax)
        {
            int ans = n * (n - 1) / 2;
            cout << ans << ' ' << ans << '\n';
            continue;
        }
        
        for (int i = 0; i < n; i++)
        {
            if (a[i] == tMin)
            {
                numMin++;
            }
            else
            {
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == tMax)
            {
                numMax++;
            }
            else
            {
                break;
            }
        }
        int resMax = numMin * numMax;
        
        tMin = a[1] - a[0];
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i + 1] - a[i] < tMin)
            {
                tMin = a[i + 1] - a[i];
            }
        }
        
        int resMin = 0;
        if (tMin != 0)
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (a[i + 1] - a[i] == tMin)
                {
                    resMin++;
                }
            }
        }
        else
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (a[i] == a[i + 1])
                {
                    int temp = 2;
                    for (int j = i + 2; j < n; j++)
                    {
                        if (a[j] == a[i])
                        {
                            temp++;
                        }
                        else
                        {
                            i = j;
                            break;
                        }
                    }
                    resMin += temp * (temp - 1) / 2;
                }
            }
        }
        
        cout << resMin << ' ' << resMax << '\n';
    }
    
    return 0;
}
