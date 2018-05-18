//
//  main.cpp
//  f-51Nod-1595-回文度
//
//  Created by ZYJ on 2017/7/31.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e7 + 10;

char A[MAXN];
int B[MAXN];

void Manacher(int len)
{
    int mx = 0, id = 0;
    for (int i = 1; i < len; i++)
    {
        if (i <= mx)
        {
            B[i] = min(B[2 * id - i] , mx - i + 1);
        }
        else
        {
            B[i] = 1;
        }
        while (A[i - B[i]] == A[i + B[i]])
        {
            B[i]++;
        }
        if (i + B[i] - 1 > mx)
        {
            id = i;
            mx = i + B[i] - 1;
        }
    }
}

int main()
{
    char ch;
    int len = 0;
    A[len++] = '$';
    A[len++] = '#';
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        A[len++] = ch;
        A[len++] = '#';
    }
    A[len] = '\0';
    
    Manacher(len);
    
    int pos = 1;
    len /= 2;
    for (int i = 2; i <= len; i++)
    {
        A[pos++] = B[i] == i;
    }
    
    memset(B, 0, sizeof(B));
    for (int i = 1; i < pos; i++)
    {
        if (A[i])
        {
            B[i] = B[i / 2] + 1;
        }
    }
    
    int ans = 0;
    for (int i = 1; i < pos; i++)
    {
        ans += B[i];
    }
    
    cout << ans << endl;
    
    return 0;
}
