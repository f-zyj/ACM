//
//  main.cpp
//  f-2016码农谷全国大学生程序设计邀请赛（测试赛）-试题四-求二进制数字符串的和
//
//  Created by ZYJ on 16/7/13.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

char strA[101];
char A[101];
char strB[101];
char B[101];
char C[101];

void carry(int i)
{
    C[i] += 1;
    if (C[i] == '2')
    {
        C[i] = '0';
        carry(i + 1);
    }
    return ;
}

int main(int argc, const char * argv[])
{
    cin >> strA >> strB;
    int keyA = 0;
    int keyB = 0;
    int lenA = (int)strlen(strA);
    int lenB = (int)strlen(strB);
    for (int i = lenA - 1; i >= 0; i--)
    {
        A[keyA++] = strA[i];
//        cout << A[keyA - 1];
    }
//    cout << endl;
    
    for (int i = lenB - 1; i >= 0; i--)
    {
        B[keyB++] = strB[i];
//        cout << B[keyB - 1];
    }
//    cout << endl;
    
    for (int i = 0; i < keyA + keyB; i++)
    {
        C[i] = '0';
//        cout << C[i];
    }
//    cout << endl;
    int MAX = keyA > keyB ? keyA : keyB;
    int MIN = keyA < keyB ? keyA : keyB;
    for (int i = 0; i < MAX; i++)
    {
        if (i < MIN)
        {
            if (A[i] + B[i] - '0' - '0' == 1)
            {
                C[i] += 1;
            }
            else if (A[i] + B[i] - '0' - '0' == 2)
            {
                carry(i + 1);
            }
            if (C[i] > '1')
            {
                C[i] = '0';
                carry(i + 1);
            }
        }
        else
        {
            if (keyA > keyB)
            {
                if (A[i] - '0' == 1)
                {
                    C[i] += 1;
                }
                if (C[i] > '1')
                {
                    C[i] = '0';
                    carry(i + 1);
                }
            }
            else
            {
                if (B[i] - '0' == 1)
                {
                    C[i] += 1;
                }
                if (C[i] > '1')
                {
                    C[i] = '0';
                    carry(i + 1);
                }
            }
        }
    }
    int lenC = (int)strlen(C);
    
    bool f = false;
    
    for (int i = lenC - 1; i >= 0; i--)
    {
        if (C[i] != '0')
        {
            f = true;
        }
        if (f)
        {
           cout << C[i];
        }
    }
    std::cout << '\n';
    return 0;
}
