//
//  main.cpp
//  f-HDU-1003-Max Sum
//
//  Created by ZYJ on 2016/10/9.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include<iostream>

#define MAXN 100010

using namespace std;

int a[MAXN], d[MAXN];

int main()
{
    int T;
    int n;
    int max, key = 1;
    cin >> T;
    
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        d[1] = a[1];
        for (int i = 2; i <= n; i++)
        {
            if (d[i - 1] < 0)
            {
                d[i] = a[i];
            }
            else
            {
                d[i] = d[i - 1] + a[i];
            }
        }
        max = d[1];
        int end = 1;
        for (int i = 2; i <= n; i++)
        {
            if (max < d[i])
            {
                max = d[i];
                end = i;
            }
        }
        int sum = 0;
        int start = end;
        for (int i = end; i > 0; i--)
        {
            sum = sum + a[i];
            if (sum == max)
            {
                start = i;
            }
        }
        cout << "Case " << key++ << ":" << endl << max << " " << start << " " << end << endl;
        if (T)
        {
            cout << endl;
        }
    }
    
    return 0;
}
