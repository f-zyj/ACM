//
//  main.cpp
//  f-蓝桥-ALGO-32-JAM计数法
//
//  Created by ZYJ on 2017/6/5.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int s, t, w;
string st;
string ed;

int main(int argc, const char * argv[])
{
    cin >> s >> t >> w >> st;
    for (int i = 0; i < w; i++)
    {
        ed.push_back('a' + t - w + i);
    }
    
    int cnt = 5;
    while (st != ed && cnt--)
    {
        for (int i = (int)st.length() - 1, j = 1; i >= 0; i--, j++)
        {
//            cout << char('a' + t - j) << '\n';
            if (st[i] < 'a' + t - j)
            {
                st[i]++;
                for (int k = i + 1; k < st.length(); k++)
                {
                    st[k] = st[k - 1] + 1;
                }
                break;
            }
        }
        cout << st << '\n';
    }
    
    return 0;
}
