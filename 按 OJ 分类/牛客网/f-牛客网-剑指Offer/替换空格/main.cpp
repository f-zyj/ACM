//
//  main.cpp
//  f-牛客网-剑指Offer
//
//  Created by ZYJ on 2018/7/14.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <iostream>

using namespace std;

char str[] = "Hello, World!\n";

class Solution
{
public:
    void replaceSpace(char *str,int length)
    {
        int blanksCnt = 0;
        for (int i = 0; i < length; i++)
        {
            if (str[i] == ' ')
            {
                blanksCnt++;
            }
        }
        
        int len = length + blanksCnt * 2;
        str[len] = '\0';
        for (int i = length - 1; i >= 0; i--)
        {
            if (str[i] != ' ')
            {
                str[--len] = str[i];
            }
            else
            {
                str[--len] = '0';
                str[--len] = '2';
                str[--len] = '%';
            }
        }
    }
};

int main(int argc, const char * argv[])
{
    Solution s = *new Solution();
    
    s.replaceSpace(str, 14);
    
    printf("%s", str);
    
    return 0;
}
