//
//  main.cpp
//  f-CCF模拟-1-出现次数最多的数
//
//  Created by ZYJ on 2016/12/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 1010;

int S[MAXN];

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", S + i);
    }
    
    sort(S, S + n);
    
    int res = S[0], times = 1, res_ = S[0], times_ = 1;
    
    for (int i = 1; i < n; i++)
    {
        if (S[i] == S[i - 1])
        {
            times_++;
        }
        else
        {
            res_ = S[i];
            times_ = 1;
        }
        if (times_ > times)
        {
            res = res_;
            times = times_;
        }
    }
    
    cout << res << '\n';
    
    return 0;
}
