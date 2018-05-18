//
//  main.cpp
//  f-2016CCPC-A-A water problem
//
//  Created by ZYJ on 16/8/14.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1e7 + 9;

const int XIXI = 73;
const int HAHA = 137;

char N[MAXN];

int mod(char str[],int num)
{
    int len = (int)strlen(str);
    int ans = 0;
    for(int i = 0; i < len; ++i)
    {
        ans = ans * 10 + (str[i]-'0');
        ans %= num;
    }
    return ans;
}

int main(int argc, const char * argv[])
{
    int key = 1;
    while (cin >> N)
    {
        if (!(mod(N, XIXI)) && !(mod(N, HAHA)))
        {
            cout << "Case #" << key++ << ": YES\n";
        }
        else
        {
            cout << "Case #" << key++ << ": No\n";
        }
    }
    
    return 0;
}
