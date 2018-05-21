//
//  main.cpp
//  f-CF-Educational Codeforces Round 44 (Rated for Div. 2)-C-Liebig's Barrels
//
//  Created by ZYJ on 2018/5/21.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 10;

int n, k, l;
int a[MAXN];

int main(int argc, const char * argv[])
{
    cin >> n >> k >> l;
    
    int tmp = n * k;
    for (int i = 1; i <= tmp; i++)
    {
        scanf("%d", a + i);
    }
    sort(a + 1, a + tmp + 1);
    
    if (a[n] - a[1] > l)
    {
        cout << "0\n";
    }
    else
    {
        long long ans = 0;
        for (int i = 1, j = n - 1; i <= n; i++, j--)
        {
            if (a[i * k + j] - a[1] <= l)
            {
                ans += a[(i - 1) * k + 1];
            }
            else
            {
                int p = (int)(upper_bound(a + (i - 1) * k + 1, a + tmp + 1, a[1] + l) - a - 1);
                
                ans += a[(i - 1) * k + 1];
                while (j--)
                {
                    ans += a[p--];
                }
                break;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
