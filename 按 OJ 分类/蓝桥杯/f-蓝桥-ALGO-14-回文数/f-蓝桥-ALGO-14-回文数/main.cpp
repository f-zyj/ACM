//
//  main.cpp
//  f-蓝桥-ALGO-14-回文数
//
//  Created by ZYJ on 2017/6/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 100;
const int MAXSTEPS = 30;

int N, len;
char s[MAXN];
int num1[MAXN];
int num2[MAXN];
int num3[MAXN];

void add()
{
    num3[len] = 0;
    for (int i = len; i > 0; i--)
    {
        num3[i - 1] = (num1[i] + num2[i] + num3[i]) / N;
        num3[i] = (num1[i] + num2[i] + num3[i]) % N;
    }
    if (num3[0])
    {
        len++;
        for (int i = len; i > 0; i--)
        {
            num3[i] = num3[i - 1];
        }
        num3[0] = 0;
    }
}

bool charge()
{
    for (int i = 1, j = len; i < j; i++, j--)
    {
        if (num1[i] != num1[j])
        {
            return 0;
        }
    }
    return 1;
}

void getNum2()
{
    for (int i = 1; i <= len; i++)
    {
        num2[i] = num1[len - i + 1];
    }
}

int main(int argc, const char * argv[])
{
    scanf("%d%s", &N, s + 1);
    len = (int)strlen(s + 1);
    for (int i = 1; i <= len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            num1[i] = s[i] - '0';
        }
        else
        {
            num1[i] = s[i] - 'A' + 10;
        }
    }
    
    int steps = 0;
    while (!charge() && steps <= MAXSTEPS)
    {
        steps++;
        getNum2();
        add();
        memcpy(num1, num3, sizeof(num3));
    }
    
    if (steps <= MAXSTEPS)
    {
        cout << "STEP=" << steps << '\n';
    }
    else
    {
        cout << "Impossible!\n";
    }
    
    return 0;
}
