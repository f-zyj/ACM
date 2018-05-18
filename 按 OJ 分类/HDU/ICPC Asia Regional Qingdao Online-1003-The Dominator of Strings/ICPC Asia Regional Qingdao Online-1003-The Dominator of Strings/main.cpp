//
//  main.cpp
//  ICPC Asia Regional Qingdao Online-1003-The Dominator of Strings
//
//  Created by ZYJ on 2017/9/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int n;
char s[MAXN];
string ss[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d", &n);
        
        int tag = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", s);
            ss[i] = s;
            if (ss[i].length() > ss[tag].length())
            {
                tag = i;
            }
        }
        
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (i != tag)
            {
                if (ss[tag].find(ss[i], 0) == string::npos)
                {
                    flag = false;
                    break;
                }
            }
        }
        
        if (flag)
        {
            printf("%s\n", ss[tag].c_str());
        }
        else
        {
            printf("No\n");
        }
    }
    
    return 0;
}
