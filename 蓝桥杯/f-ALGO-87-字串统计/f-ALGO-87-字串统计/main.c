//
//  main.c
//  f-ALGO-87-字串统计
//
//  Created by ZYJ on 16/4/17.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>

//判断此串是否符合规则
int isSubStr(char *S, int indexOne, int indexTwo, int len)
{
    int i = 0;
    for (; i != len; i++)
    {
        if (S[indexOne + i] != S[indexTwo + i])
        {
            return 0;
        }
    }
    return 1;
}

//在串中找以index为开始，长度为len的串的数量
int repeat(char *S, int index, int len)
{
    int rep = 1, i;
    
    for (i = index + 1; i <= (int)strlen(S) - len; i++)
    {
        if (isSubStr(S, index, i, len))
        {
            rep++;
        }
    }
    return rep;
}

int main(int argc, const char * argv[])
{
    int L, len, i, rep;
    char S[61];
    int  maxRep = 0, maxIndex = 0, maxLen = 0;
    scanf("%d %s", &L, S);
    
    // 子串长度
    for (len = (int)strlen(S) - 1; len != L - 1; len--)
    {
        for (i = 0; i != (int)strlen(S) - len; i++)
        {
            //从当前下标开始，len长度的子串
            rep = repeat(S, i, len);
            
            if (maxRep < rep)
            {
                maxRep = rep;
                maxIndex = i;
                maxLen = len;
            }
        }
    }
    
    for (i = maxIndex; i < maxIndex + maxLen; i++)
    {
        printf("%c", S[i]);
    }
    printf("\n");
    return 0;
}
