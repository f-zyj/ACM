//
//  main.cpp
//  f-51Nod-1491-黄金系统
//
//  Created by ZYJ on 2016/9/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 5;

char A[MAXN];
char B[MAXN];

//  判断相连的1的奇偶性
bool judge(char C[], int i)
{
    int res = 0;
    while (C[i] == '1' && i > 0)
    {
        res++;
        i--;
    }
    return res % 2;
}

int main(int argc, const char * argv[])
{
    scanf("%s %s", A + 2, B + 2);
    A[0] = A[1] = B[0] = B[1] = '0';
    int lenA = (int)strlen(A);
    int lenB = (int)strlen(B);
    int len = lenA > lenB ? lenA : lenB;
    
    if (lenA < lenB)
    {
        int k = lenB - lenA;
        int pos = k;
        k += 2;
        for (int i = lenB - 1; i >= k; i--)
        {
            A[i] = A[i - pos];
        }
        for (int i = 2; i < k; i++)
        {
            A[i] = '0';
        }
    }
    else if (lenA > lenB)
    {
        int k = lenA - lenB;
        int pos = k;
        k += 2;
        for (int i = lenA - 1; i >= k; i--)
        {
            B[i] = B[i - pos];
        }
        for (int i = 2; i < k; i++)
        {
            B[i] = '0';
        }
    }
//    cout << A << '\n' << B << "\n\n";
    
    bool flag = true;
    for (int i = len - 1; i >= 2; i--)
    {
        if (A[i] == '0')
        {
            flag = true;
        }
        else if (A[i] == '1' && flag)
        {
            flag = false;
            if (judge(A, i))
            {
                continue;
            }
        }
        if (A[i] > '0' && A[i - 1] > '0')
        {
            A[i]--;
            A[i - 1]--;
            A[i - 2]++;
        }
    }
    
    flag = true;
    for (int i = len - 1; i >= 2; i--)
    {
        if (B[i] == '0')
        {
            flag = true;
        }
        else if (B[i] == '1' && flag)
        {
            flag = false;
            if (judge(B, i))
            {
                continue;
            }
        }
        if (B[i] > '0' && B[i - 1] > '0')
        {
            B[i]--;
            B[i - 1]--;
            B[i - 2]++;
        }
    }
    
//    cout << A << '\n' << B << "\n\n";
    
    for (int i = 0; i < len; i++)
    {
        if (A[i] != B[i])
        {
            if (A[i] > B[i])
            {
                cout << ">\n";
                return 0;
            }
            else
            {
                cout << "<\n";
                return 0;
            }
        }
    }
    cout << "=\n";
    
    return 0;
}
