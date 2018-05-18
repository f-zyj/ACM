//
//  main.cpp
//  f-2016码农谷全国大学生程序设计邀请赛（测试赛）-试题二-统计出以某个字符串为前缀的单词数量
//
//  Created by ZYJ on 16/7/13.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string str[10000];
string flag;

int main(int argc, const char * argv[])
{
    int i = 0;
    while (cin >> str[i])
    {
        if (str[i] == "88888888")
        {
            break;
        }
        i++;
    }
    while (cin >> flag)
    {
        int ans = 0;
        for (int j = 0; j < i; j++)
        {
            bool tag = true;
            for (int k = 0; k < flag.length(); k++)
            {
                if (flag[k] != str[j][k])
                {
                    tag = false;
                    break;
                }
            }
            if (tag)
            {
                ans++;
            }
            tag = true;
        }
        cout << ans << '\n';
    }
    return 0;
}
