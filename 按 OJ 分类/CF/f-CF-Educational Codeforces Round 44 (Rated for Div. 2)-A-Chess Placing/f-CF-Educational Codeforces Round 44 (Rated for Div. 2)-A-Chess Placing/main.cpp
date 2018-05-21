//
//  main.cpp
//  f-CF-Educational Codeforces Round 44 (Rated for Div. 2)-A-Chess Placing
//
//  Created by ZYJ on 2018/5/21.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 111;

int n;
int p[MAXN];

int main(int argc, const char * argv[])
{
    while (cin >> n)
    {
        int ans0 = 0, ans1 = 0, pos0 = 1, pos1 = 2;
        n /= 2;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
        }
        
        sort(p + 1, p + n + 1);
        
        for (int i = 1; i <= n; i++)
        {
            if (p[i] != pos0)
            {
                ans0 += abs(p[i] - pos0);
            }
            if (p[i] != pos1)
            {
                ans1 += abs(p[i] - pos1);
            }
            pos0 += 2;
            pos1 += 2;
        }
        
        cout << min(ans0, ans1) << '\n';
    }
    
    return 0;
}
