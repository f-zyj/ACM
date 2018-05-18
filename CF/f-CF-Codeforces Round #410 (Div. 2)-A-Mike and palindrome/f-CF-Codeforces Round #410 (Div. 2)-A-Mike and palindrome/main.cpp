//
//  main.cpp
//  f-CF-Codeforces Round #410 (Div. 2)-A-Mike and palindrome
//
//  Created by ZYJ on 2017/4/21.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
    string s;
    cin >> s;
    
    int cnt = 0;
    int mid = ((int)s.length() + 1) / 2;
    for (int i = 0; i < mid; i++)
    {
        if (s[i] != s[s.length() - 1 - i])
        {
            cnt++;
        }
    }
    
    if (cnt != 1)
    {
        if (cnt == 0 && s.length() % 2)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    else
    {
        cout << "YES\n";
    }
    
    return 0;
}
