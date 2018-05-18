//
//  main.cpp
//  f-51Nod-1396-还是01串
//
//  Created by ZYJ on 16/8/12.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e6 + 10;

char S[MAXN];
int S_0[MAXN];
int S_1[MAXN];

int main(int argc, const char * argv[])
{
    scanf("%s", S + 1);
    int len = (int)strlen(S + 1);
    for (int i = 1; i <= len; i++)
    {
        if (S[i] == '0')
        {
            S_0[i] = S_0[i - 1] + 1;
            S_1[i] = S_1[i - 1];
        }
        else
        {
            S_0[i] = S_0[i - 1];
            S_1[i] = S_1[i - 1] + 1;
        }
    }
    
    int k = -1;
    if (S_1[len] == 0)
    {
        k = 0;
    }
    else if (S_0[len] == 0)
    {
        k = len;
    }
    else
    {
        for (int i = 1; i < len; i++)
        {
            if (S_0[i] - S_0[0] == S_1[len] - S_1[i])
            {
                k = i;
                break;
            }
        }
    }
    
    cout << k << '\n';
    return 0;
}
