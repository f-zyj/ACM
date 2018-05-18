//
//  main.cpp
//  f-51Nod-1154-回文串划分
//
//  Created by ZYJ on 16/8/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 5e3 + 5;

char S[MAXN];
char SS[MAXN * 2];
int dp[MAXN];
int len;

//  查找以pos为轴心的回文串，返回轴心左边部分长度加1
int search(int pos)
{
    int flag = pos + 1 > len - pos ? len - pos : pos + 1;
    bool tag = true;
    for (int i = 1; i < flag; i++)
    {
        if (S[pos - i] != S[pos + i])
        {
            return i;
        }
    }
    if (tag)
    {
        return flag;
    }
    return 0;
}

//  查找以pos与pos+1为轴心的回文串，返回回文串长度的一半
int search_(int pos)
{
    if (S[pos] != S[pos + 1])
    {
        return 0;
    }
    int flag = pos > len - pos - 1 ? len - pos - 1 : pos;
    bool tag = true;
    for (int i = 1; i < flag; i++)
    {
        if (S[pos - i] != S[pos + 1 + i])
        {
            return i;
        }
    }
    if (tag)
    {
        return flag;
    }
    return 0;
}

int main(int argc, const char * argv[])
{
    scanf("%s", S + 1);
    S[0] = '#';
    len = (int)strlen(S);
    
    int flag = 0;
    
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 1; i < len; i++)
    {
        dp[i] = min(dp[i], dp[i - 1] + 1);
        flag = search(i);
        for (int j = 1; j <= flag; j++)
        {
            dp[i + j - 1] = min(dp[i + j - 1], dp[i - j] + 1);
        }
        
        flag = search_(i);
        if (flag)
        {
            for (int j = 1; j <= flag; j++)
            {
                dp[i + j] = min(dp[i + j], dp[i - j] + 1);
            }
        }
    }
    
//    for (int i = 0; i < len; i++)
//    {
//        cout << i << ':' <<  dp[i] << '\n';
//    }
    cout << dp[len - 1] << '\n';
    
    return 0;
}
