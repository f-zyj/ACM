//
//  main.cpp
//  f-HDU-3183-A Magic Lamp
//
//  Created by ZYJ on 2016/11/8.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    string s;
    int m;
    while (cin >> s >> m)
    {
        int len = (int)s.length();
        int p = 0;
        int tmp_pos = m;
        int flag = 0;
        
        for (int i = 0; i < len - m; i++)
        {
            char mmin = s[p];
            for (int j = p + 1; j <= tmp_pos; j++)
            {
                if (s[j] < mmin)
                {
                    mmin = s[j];
                    p = j;
                }
            }
            tmp_pos++;
            p++;
            if (!flag)
            {
                if (mmin == '0')
                {
                    continue;
                }
                else
                {
                    cout << mmin;
                    flag = 1;
                }
            }
            else
            {
                cout << mmin;
            }
        }
        if (!flag)
        {
            cout << "0";
        }
        cout << endl;
    }
    
    return 0;
}
