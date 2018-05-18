//
//  main.cpp
//  f-2016码农谷全国大学生程序设计邀请赛（第一轮资格赛）-试题二 奇怪的数字：6174
//
//  Created by ZYJ on 16/7/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

char num[5];
char numA[5];
char numB[5];

int main(int argc, const char * argv[])
{
    cin >> num;
    int res = 0;
    while ((num[0] - '0') * 1000 + (num[1] - '0') * 100 + (num[2] - '0') * 10 + (num[3] - '0') != 6174)
    {
        res++;
        for (int i = 0; i < 3; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                if (num[i] > num[j])
                {
                    swap(num[i], num[j]);
                }
            }
        }
        int MAX = (num[3] - '0') * 1000 + (num[2] - '0') * 100 + (num[1] - '0') * 10 + (num[0] - '0');
        int MIN = (num[0] - '0') * 1000 + (num[1] - '0') * 100 + (num[2] - '0') * 10 + (num[3] - '0');
        int dif = MAX - MIN;
        num[3] = dif % 10 + '0';
        dif /= 10;
        num[2] = dif % 10 + '0';
        dif /= 10;
        num[1] = dif % 10 + '0';
        dif /= 10;
        num[0] = dif + '0';
    }
    cout << res << '\n';
    return 0;
}
