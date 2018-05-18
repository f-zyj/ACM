//
//  main.cpp
//  f-最短公共祖先
//
//  Created by ZYJ on 16/7/12.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

//  最短公共祖先（两个长字符串）

/*
 *  The shortest common superstring of 2 strings S1 and S2 is 
 *  a string S with|the minimum number of characters which 
 *  contains both S1 and S2 as a sequence of consecutive characters.
 */
const int N = 1000010;
char a[2][N];
int fail[N];

inline int max(int a, int b)
{
    return (a > b) ? a : b;
}

int kmp(int &i, int &j, char* str, char* pat)
{
    int k;
    memset(fail, -1, sizeof(fail));
    for (i = 1; pat[i]; ++i)
    {
        for (k = fail[i - 1]; k >= 0 && pat[i] != pat[k + 1]; k = fail[k]);
        if (pat[k + 1] == pat[i])
        {
            fail[i] = k + 1;
        }
    }
    i = j = 0;
    while (str[i] && pat[j])
    {
        if (pat[j] == str[i])
        {
            i++;
            j++;
        }
        else if (j == 0)
        {
            i++;    //  第一个字符匹配失败，从str下一个字符开始
        }
        else
        {
            j = fail[j - 1] + 1;
        }
    }
    if (pat[j])
    {
        return -1;
    }
    else
    {
        return i - j;
    }
}

int main(int argc, const char * argv[])
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int i, j, l1 = 0, l2 = 0;
        cin >> a[0] >> a[1];
        int len1 = (int)strlen(a[0]), len2 = (int)strlen(a[1]), val;
        val = kmp(i, j, a[1], a[0]);            //  a[1]在前
        if (val != -1)
        {
            l1 = len1;
        }
        else
        {
//            printf("i:%d, j:%d\n", i, j);
            if (i == len2 && j - 1 >= 0 && a[1][len2 - 1] == a[0][j - 1])
            {
                l1 = j;
            }
        }
        val = kmp(i, j, a[0], a[1]);            //  a[0]在前
        if (val != -1)
        {
            l2 = len2;
        }
        else
        {
//            printf("i:%d, j:%d\n", i, j);
            if (i == len1 && j - 1 >= 0 && a[0][len1 - 1] == a[1][j - 1])
            {
                l2 = j;
            }
        }
//        printf("l1:%d,l2:%d\n",l1,l2);
        printf("%d\n", len1 + len2 - max(l1, l2));
    }
    return 0;
}
