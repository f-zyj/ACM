//
//  main.cpp
//  f-爱奇艺2018秋招-缺失的括号
//
//  Created by ZYJ on 2018/3/23.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;

int findIndex(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' && s[i + 1] == ')')
        {
            return i;
        }
    }
    return -1;
}

size_t solve(string s)
{
    int tmp;
    while (true)
    {
        tmp = findIndex(s);
        if (tmp == -1)
        {
            break;
        }
        while (tmp >= 0 && s[tmp] == '(' && s[tmp + 1] == ')')
        {
            s.erase(tmp, 2);
            tmp--;
        }
    }
    
    return s.length();
}

int main()
{
    cin >> s;
    cout << solve(s) << endl;
    
    return 0;
}
