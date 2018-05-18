//
//  main.cpp
//  f-2016码农谷全国大学生程序设计邀请赛（测试赛）-试题三-将数分成两组，使得两组中各元素的和相等
//
//  Created by ZYJ on 16/7/17.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int num[1000];

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    int n;
    int key = 0;
    int sum_5 = 0;
    int sum_3 = 0;
    
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        if (n % 5 == 0)
        {
            sum_5 += n;
        }
        else if (n % 3 == 0)
        {
            sum_3 += n;
        }
        else
        {
            num[key++] = n;
        }
    }
    
    for (int i = 0; i < key - 1; i++)
    {
        for (int j = i + 1; j < key; j++)
        {
            if (fabs(num[i]) > fabs(num[j]))
            {
                swap(num[i], num[j]);
            }
        }
    }
    
    int dif = sum_5 - sum_3;
    int res = 0;
    while (key)
    {
        if (res > -dif)
        {
            if (num[key - 1] > 0)
            {
                res -= num[key - 1];
            }
            else
            {
                res += num[key - 1];
            }
        }
        else
        {
            if (num[key - 1] > 0)
            {
                res += num[key - 1];
            }
            else
            {
                res -= num[key - 1];
            }
        }
        key--;
    }
    
    if (res == -dif)
    {
        cout << "1" << '\n';
    }
    else
    {
        cout << "0" << '\n';
    }
    return 0;
}
