//
//  main.cpp
//  f-CF-Educational Codeforces Round 44 (Rated for Div. 2)-E-Pencils and Boxes
//
//  Created by ZYJ on 2018/5/22.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 5e5 + 10;

int n, k, d;
int a[MAXN];

int main()
{
    cin >> n >> k >> d;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    
    int m = n / k, pos = 0;
    
    while (m && pos < n)
    {
        m--;
        int mx = a[pos] + d;
        while (pos < n && (n - pos > m * k) && a[pos] <= mx)
        {
            pos++;
        }
    }
    
    if (m == 0 && pos == n)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    
    return 0;
}
