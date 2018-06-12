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

const string str[] = {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"};

string s;

int main(int argc, const char * argv[])
{
    cin >> s;
    
    bool flag = false;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int cnt = 0;
            for (int k = 0; k < 3; k++)
            {
                if (s[i + k] == str[j][k])
                {
                    cnt++;
                }
            }
            
            if (cnt == 3)
            {
                flag = true;
                break;
            }
        }
    }
    
    if (flag)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    
    return 0;
}
