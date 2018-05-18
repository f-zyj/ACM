//
//  main.cpp
//  f-CF-Codeforces Round #483 (Div. 2)-A-Game
//
//  Created by ZYJ on 2018/5/15.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1111;

int n;
int a[MAXN];

int main(int argc, const char * argv[])
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        
        cout << a[n - n / 2 - 1] << '\n';
    }
    
    return 0;
}
