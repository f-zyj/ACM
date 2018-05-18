//
//  main.cpp
//  ICPC Asia Regional Qingdao Online-1008-Chinese Zodiac
//
//  Created by ZYJ on 2017/9/19.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

string s1, s2;
map<string, int> msi;

int main()
{
    msi["rat"] = 1;
    msi["ox"] = 2;
    msi["tiger"] = 3;
    msi["rabbit"] = 4;
    msi["dragon"] = 5;
    msi["snake"] = 6;
    msi["horse"] = 7;
    msi["sheep"] = 8;
    msi["monkey"] = 9;
    msi["rooster"] = 10;
    msi["dog"] = 11;
    msi["pig"] = 12;
    
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        cin >> s1 >> s2;
        if (s1 == s2)
        {
            puts("12");
        }
        else if (msi[s1] < msi[s2])
        {
            printf("%d\n", abs(msi[s1] - msi[s2]));
        }
        else
        {
            printf("%d\n", msi[s2] - msi[s1] + 12);
        }
    }
    
    return 0;
}
