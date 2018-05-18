//
//  main.cpp
//  f-图灵杯-第四届“图灵杯”NEUQ-ACM 程序设计竞赛-I-一道不简单的题目
//
//  Created by ZYJ on 2017/6/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string Q[2] = {"Is this NEUQ?", "I have some question!"};
string R[2] = {"Yes, welcome to NEUQ.", "What can I do for you?"};

string a;

int main(int argc, const char * argv[])
{
    cin >> a;
    if (a[1] == Q[0][1])
    {
        cout << R[0] << '\n';
    }
    else
    {
        cout << R[1] << '\n';
    }
    
    return 0;
}
