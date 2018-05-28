//
//  main.cpp
//  f-CF-Avito Code Challenge 2018-A-Antipalindrome
//
//  Created by ZYJ on 2018/5/27.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string s;

int main(int argc, const char * argv[])
{
    while (cin >> s)
    {
        int flag = 1;
        for (int i = 0, j = (int)s.length() - 1; i <= j; i++, j--)
        {
            if (s[i] != s[j])
            {
                flag = 0;
                break;
            }
        }
        
        if (!flag)
        {
            cout << s.length() << '\n';
        }
        else
        {
            flag = 1;
            for (int i = 1; i < s.length(); i++)
            {
                if (s[i] != s[0])
                {
                    flag = 0;
                    break;
                }
            }
            
            if (flag)
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << s.length() - 1 << '\n';
            }
        }
    }
    
    return 0;
}
