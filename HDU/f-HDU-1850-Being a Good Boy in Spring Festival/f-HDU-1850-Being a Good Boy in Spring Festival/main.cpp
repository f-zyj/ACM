//
//  main.cpp
//  f-HDU-1850-Being a Good Boy in Spring Festival
//
//  Created by ZYJ on 2017/9/21.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 111;

int n;
int ans, cot;
int a[MAXN];

int main(int argc, const char * argv[])
{
    while (cin >> n && n)
    {
        ans = 0;
        cot = 0;
        memset(a, 0, sizeof(a));
        
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            ans ^= a[i];
        }
        
        if (ans == 0)
        {
            puts("0");
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                int k = ans ^ a[i];
                if (k < a[i])
                {
                    cot++;
                }
            }
            cout << cot << '\n';
        }
    }
    
    return 0;
}
