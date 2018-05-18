//
//  main.cpp
//  f-今日头条2018校招-字母交换
//
//  Created by ZYJ on 2018/3/23.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 26;
const int MAX_LEN = 1e3 + 10;

string str;
int num;
int b[MAXN];
int m[MAX_LEN];
int a[MAX_LEN][MAXN];

int dp(int i, int j, int a[])
{
    if (i == j)
    {
        return 0;
    }
    else if (i + 1 == j)
    {
        return a[j] - a[i] - 1;
    }
    else
    {
        return dp(i + 1, j - 1, a) + a[j] - a[i] - (j - i);
    }
}

int main()
{
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(m, 0, sizeof(m));
    
    cin >> str >> num;
    int length = (int)str.length();
    
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            a[i][str[i] - 'a'] = 1;
        }
    }
    
    for (int j = 0; j < MAXN; j++)
    {
        int k = 0;
        for (int i = 0; i < length; i++)
        {
            if (a[i][j] == 1)
            {
                m[k++] = i;
            }
        }
        
        if (k == 1)
        {
            b[j] = 1;
        }
        else
        {
            int temp = -1;
            for (int i = 0; i < k; i++)
            {
                for (int _i = i + 1; _i < k; _i++)
                {
                    if (dp(i, _i, m) <= num)
                    {
                        if ((_i - i) + 1 > temp)
                        {
                            temp = (_i - i) + 1;
                        }
                    }
                }
            }
            b[j] = temp;
        }
        
    }
    
    sort(b, b + MAXN);
    
    cout << b[MAXN - 1] << endl;
    
    return 0;
}

