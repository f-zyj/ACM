//
//  main.cpp
//  f-2016码农谷全国大学生程序设计邀请赛（第一轮资格赛）-试题三 将一个英文语句以单词为单位逆序排序
//
//  Created by ZYJ on 16/7/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

char word[22][16];

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> word[i];
    }
    for (int i = N - 1; i > 0; i--)
    {
        int len = (int)strlen(word[i]);
        for (int j = len - 1; j >= 0; j--)
        {
            cout << word[i][j];
        }
        cout << ' ';
    }
    int len = (int)strlen(word[0]);
    for (int j = len - 1; j >= 0; j--)
    {
        cout << word[0][j];
    }
    cout << '\n';
    return 0;
}
