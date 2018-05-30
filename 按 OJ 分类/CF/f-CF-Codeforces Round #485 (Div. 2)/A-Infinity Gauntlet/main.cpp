//
//  main.cpp
//  f-CF-Codeforces Round #485 (Div. 2)
//
//  Created by ZYJ on 2018/5/29.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int n;
map<string, string> mss;
map<string, int> msi;

static void init()
{
    mss["purple"] = "Power";
    mss["green"] = "Time";
    mss["blue"] = "Space";
    mss["orange"] = "Soul";
    mss["red"] = "Reality";
    mss["yellow"] = "Mind";
}

int main(int argc, const char * argv[])
{
#if DEBUG
    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    freopen("/Users/zyj/Desktop/output.txt", "w", stdout);
#endif
    
    init();
    
    cin >> n;
    
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        msi[s] = 1;
    }
    
    cout << 6 - n << '\n';
    for (auto it : mss)
    {
        if (!msi[it.first])
        {
            cout << it.second << '\n';
        }
    }
    
    return 0;
}
