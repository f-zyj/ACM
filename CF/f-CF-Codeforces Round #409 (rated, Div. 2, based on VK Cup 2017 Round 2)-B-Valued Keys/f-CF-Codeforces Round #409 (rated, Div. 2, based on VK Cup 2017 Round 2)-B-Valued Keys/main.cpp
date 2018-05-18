//
//  main.cpp
//  f-CF-Codeforces Round #409 (rated, Div. 2, based on VK Cup 2017 Round 2)-B-Valued Keys
//
//  Created by ZYJ on 2017/4/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
    string s1, s2;
    
    while (cin >> s1 >> s2)
    {
        string res = s2;
        int flag = 0;
        for (int i = 0; i < s1.length(); i++)
        {
            if (res[i] > s1[i])
            {
                flag = 1;
                break;
            }
        }
        
        if (flag)
        {
            cout << "-1\n";
            continue;
        }
        cout << res << '\n';
    }
    
    return 0;
}
