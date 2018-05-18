//
//  main.cpp
//  f-百度2016实习-编号转换
//
//  Created by ZYJ on 2018/3/23.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

bool isrc(string &s)
{
    if (s.size() < 2)
    {
        return false;
    }
    if (!(s[0] == 'R' && isdigit(s[1])))
    {
        return 0;
    }
    int i = 1;
    while (i < s.size() && s[i] != 'C')
    {
        i++;
    }
    if (i == s.size())
    {
        return 0;
    }
    return 1;
}

string int2str(int num)
{
    string s = "";
    while (num)
    {
        int i = num % 26;
        if (i == 0)
        {
            char c = 'Z';
            s = c + s;
            num = num / 26 - 1;
        }
        else
        {
            char c = 'A' + num % 26 - 1;
            num /= 26;
            s = c + s;
        }
    }
    return s;
}

string rc2(string &rc)
{
    string ans = " ";
    int i = 1;
    while (rc[i] != 'C')
    {
        i++;
    }
    int col = atoi(rc.substr(i + 1).c_str());
    string s = int2str(col);
    s += rc.substr(1, i - 1);
    
    return s;
}

string fun(int num)
{
    string s = "";
    while (num)
    {
        char c = '0' + num % 10;
        s = c + s;
        num /= 10;
    }
    
    return s;
}

string i2rc(string &s)
{
    int i = 0;
    int col = 0;
    while (!isdigit(s[i]))
    {
        col = col * 26 + (s[i] - 'A' + 1);
        i++;
    }
    string r = "R";
    r += s.substr(i);
    r += "C";
    r += fun(col);
    
    return r;
}

int n;
string rc, s;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> rc;
        if (isrc(rc))
        {
            s = rc2(rc);
        }
        else
        {
            s = i2rc(rc);
        }
        
        cout << s << endl;
    }
    
    return 0;
}
