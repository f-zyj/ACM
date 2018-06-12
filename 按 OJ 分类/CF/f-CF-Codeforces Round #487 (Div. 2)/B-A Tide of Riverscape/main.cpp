//
//  main.cpp
//  f-CF-Codeforces Round #487 (Div. 2)
//
//  Created by ZYJ on 2018/6/11.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <iostream>
#include <string>

using namespace std;

int n, p;
string s;

int main(int argc, const char * argv[])
{
    while (cin >> n >> p >> s)
    {
        int flag = 0, t = n - p;
        for (int i = 0; i < t; i++)
        {
            if (s[i] == s[i + p] && s[i] == '.')
            {
                s[i] = '0';
                s[i + p] = '1';
                flag = 1;
                break;
            }
            
            if (s[i] != s[i + p])
            {
                if (s[i] == '.')
                {
                    if (s[i + p] == '0')
                    {
                        s[i] = '1';
                    }
                    else
                    {
                        s[i] = '0';
                    }
                }
                else if (s[i + p] == '.')
                {
                    if (s[i] == '0')
                    {
                        s[i + p] = '1';
                    }
                    else
                    {
                        s[i + p] = '0';
                    }
                }
                
                flag = 1;
                break;
            }
            
            if (s[i] == '1')
            {
                if (s[i + p] == '.')
                {
                    flag = 1;
                    s[i + p] = '0';
                    break;
                }
            }
            
            else if (s[i] == '0')
            {
                if (s[i + p] == '.')
                {
                    flag = 1;
                    s[i + p] = '1';
                    break;
                }
            }
        }
        
        if (flag)
        {
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '.')
                {
                    cout << '0';
                }
                else
                {
                    cout << s[i];
                }
            }
            putchar(10);
        }
        else
        {
            cout << "No\n";
        }
    }
    
    return 0;
}
