//
//  main.cpp
//  f-爱奇艺2018秋招-XML文档
//
//  Created by ZYJ on 2018/3/23.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

const int MAXN = 1e4 + 10;
const int MAXM = 1e3 + 10;

char strs[MAXN];
char str[MAXM];
stack<string> ss;

int main()
{
    while (gets(str) != NULL)
    {
        strcat(strs, str);
    }
    
    string _str(strs, strlen(strs));
    
    int len = (int)_str.size();
    
    for (int i = 0; i < len; )
    {
        if (_str[i] == '<' && _str[i + 1] != '!' && _str[i + 1] != '/')
        {
            int j = i + 1;
            for (; j < len; j++)
            {
                if (_str[j] == '>')
                {
                    break;
                }
            }
            
            string tmp = _str.substr(i + 1, j - 1 - i);
            ss.push(tmp);
            i = j + 1;
        }
        else if (_str[i] == '<' && _str[i + 1] == '/')
        {
            int j = i + 2;
            for (; j < len; j++)
            {
                if (_str[j] == '>')
                {
                    break;
                }
            }
            
            string tmp = _str.substr(i + 2, j - 2 - i);
            if (0 != strcmp(tmp.c_str(), ss.top().c_str()))
            {
                cout << "Invalid";
                return 0;
            }
            else
            {
                ss.pop();
                i = j + 1;
            }
        }
        else
        {
            i++;
        }
    }
    
    if (ss.empty())
    {
        cout << "Valid";
    }
    else
    {
        cout << "Invalid";
    }
    
    return 0;
}
