//
//  main.cpp
//  f-2016码农谷全国大学生程序设计邀请赛（测试赛）-试题一-将字符串中的字符按规则重新排列
//
//  Created by ZYJ on 16/7/13.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

string strA;
string strB;

int main(int argc, const char * argv[])
{
    int key = 0;
    char taga = 'a';
    char tagA = 'A';
    int count = 0;
    
    getline(cin, strA);
    
    for (int i = 0; i < strA.length(); i++)
    {
        if ((strA[i] >= 'a' && strA[i] <= 'z') || (strA[i] >= 'A' && strA[i] <= 'Z'))
        {
            strB[key++] = strA[i];
        }
    }
    
    for (int i = 0; i < strA.length(); i++)
    {
        if ((strA[i] >= 'a' && strA[i] <= 'z') || (strA[i] >= 'A' && strA[i] <= 'Z'))
        {
            bool flag = true;
        l:
            while (flag)
            {
                for (int j = 0; j < key; j++)
                {
                    if (strB[j] == taga + count || strB[j] == tagA + count)
                    {
                        strA[i] = strB[j];
                        strB[j] = '*';
                        flag = false;
                        goto l;
                    }
                }
                count++;
            }
        }
    }
    
    cout << strA << '\n';
    
    return 0;
}
