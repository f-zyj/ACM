//
//  main.cpp
//  f-CF-Codeforces Round #409 (rated, Div. 2, based on VK Cup 2017 Round 2)-A-Vicious Keyboard
//
//  Created by ZYJ on 2017/4/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
    string s;
    
    while (cin >> s)
    {
        if (s.length() == 1)
        {
            cout << 0 << '\n';
            continue;
        }
        
        int res = 0, flag = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'V' && s[i + 1] == 'K')
            {
                res++;
                i++;
            }
            else if ((s[i] == 'V' && s[i + 1] == 'V' && s[i + 2] != 'K')
                     || (s[i] == 'K' && s[i + 1] == 'K'))
            {
                flag = 1;
                i++;
            }
        }
        if (flag)
        {
            res++;
        }
        cout << res << '\n';
    }
    
    return 0;
}
