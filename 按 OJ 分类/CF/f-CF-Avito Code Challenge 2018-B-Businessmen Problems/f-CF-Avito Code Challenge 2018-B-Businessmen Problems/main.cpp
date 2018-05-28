//
//  main.cpp
//  f-CF-Avito Code Challenge 2018-B-Businessmen Problems
//
//  Created by ZYJ on 2018/5/27.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

int n, m, x, y;
map<int, int> mii;

int main(int argc, const char * argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (mii[x] < y)
        {
            mii[x] = y;
        }
    }
    
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        if (mii[x] < y)
        {
            mii[x] = y;
        }
    }
    
    long long sum = 0;
    for (auto it : mii)
    {
        sum += it.second;
    }
    
    cout << sum << '\n';
    
    return 0;
}
