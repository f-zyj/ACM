//
//  main.cpp
//  f-Manacher算法
//
//  Created by ZYJ on 16/6/20.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

//Manacher最长回文子串

/*
 * 求最长回文子串
 */

const int MAXN = 110010;
char A[MAXN * 2];
int B[MAXN * 2];

void Manacher(char s[], int len)
{
    int l = 0;
    A[l++] = '$';   //0下标存储为其他字符
    A[l++] = '#';
    for (int i = 0; i < len; i++)
    {
        A[l++] = s[i];
        A[l++] = '#';
    }
    A[l] = 0;       //空字符
    int mx = 0;
    int id = 0;
    for (int i = 0; i < l; i++)
    {
        B[i] = mx > i ? std::min(B[2 * id - i], mx - i) : 1;
        while (A[i + B[i]] == A[i - B[i]])
        {
            B[i]++;
        }
        if (i + B[i] > mx)
        {
            mx = i + B[i];
            id = i;
        }
    }
    return ;
}

/*
 * abaaba
 * i:   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14
 * A:   $  #  a  #  b  #  a  #  a  #  b  #  a  # '\0'
 * B:   1  1  2  1  4  1  2  7  2  1  4  1  2  1    //以第i个为中心的回文半径（包括第i个）
 */

char s[MAXN];

int main(int argc, const char * argv[])
{
    while (std::cin >> s)
    {
        int len = (int)strlen(s);
        Manacher(s, len);
        int ans = 0;
        for (int i = 0; i < 2 * len + 2; i++)   //两倍长度并且首位插有字符，所以i < 2 * len + 2
        {
            ans = std::max(ans, B[i] - 1);
        }
        std::cout << ans << std::endl;
    }

    return 0;
}
