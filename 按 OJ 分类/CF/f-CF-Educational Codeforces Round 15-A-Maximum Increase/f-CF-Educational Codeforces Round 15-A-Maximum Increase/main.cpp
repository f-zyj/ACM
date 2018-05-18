//
//  main.cpp
//  f-CF-Educational Codeforces Round 15-A-Maximum Increase
//
//  Created by ZYJ on 16/7/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN];

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    a[0] = 0;
    int ans = 0;
    int start = 1;
    int i;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        if (a[i] <= a[i - 1])
        {
            ans = ans > i - start ? ans : i - start;
            start = i;
        }
    }
    ans = ans > i - start ? ans : i - start;
    
    cout << ans << '\n';
    
    return 0;
}
