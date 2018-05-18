//
//  main.cpp
//  f-图灵杯-第四届“图灵杯”NEUQ-ACM 程序设计竞赛-C-来简单地数个数
//
//  Created by ZYJ on 2017/6/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAXN = 550;
const int MAXL = 105;

int Fib[MAXN][MAXL];
int limit = -1;

void init()
{
    Fib[0][0] =  Fib[1][0] = 104;
    Fib[0][104] = Fib[1][104] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        int c = 0;
        for (int j = 104; j > 0; j--)
        {
            Fib[i][j] = Fib[i - 1][j] + Fib[i - 2][j] + c;
            c = Fib[i][j] / 10;
            Fib[i][j] %= 10;
        }
        for (int j = 1; j < MAXL; j++)
        {
            if (Fib[i][j] != 0)
            {
                Fib[i][0] = j;
                break;
            }
        }
        if (c > 0)
        {
            limit = i;
            break;
        }
    }
}

string a, b;
int A[MAXL], B[MAXL];

int main(int argc, const char * argv[])
{
    init();
    
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    while (cin >> a >> b, a[0] != '0' || b[0] != '0')
    {
        int j = 104;
        for (int i = (int)a.length() - 1; i >= 0; i--, j--)
        {
            A[j] = a[i] - '0';
        }
        A[0] = j + 1;
        j = 104;
        for (int i = (int)b.length() - 1; i >= 0; i--, j--)
        {
            B[j] = b[i] - '0';
        }
        B[0] = j + 1;
        
        int cnt = 0;
        for (int i = 1; i < limit; i++)
        {
            if (Fib[i][0] > A[0])
            {
                continue;
            }
            if (Fib[i][0] < B[0])
            {
                break;
            }
            if (Fib[i][0] < A[0] && Fib[i][0] > B[0])
            {
                cnt++;
                continue;
            }
            int flag = 1;
            if (Fib[i][0] == A[0])
            {
                for (int j = A[0]; j < MAXL; j++)
                {
                    if (A[j] < Fib[i][j])
                    {
                        break;
                    }
                    else if (A[j] > Fib[i][j])
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if (Fib[i][0] == B[0])
            {
                for (int j = B[0]; j < MAXL; j++)
                {
                    if (B[j] > Fib[i][j])
                    {
                        break;
                    }
                    else if (B[j] < Fib[i][j])
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag)
            {
                cnt++;
            }
        }
        
        cout << cnt << '\n';
    }
    
    return 0;
}
