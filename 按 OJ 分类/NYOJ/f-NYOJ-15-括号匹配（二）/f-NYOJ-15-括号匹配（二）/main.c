//
//  main.c
//  f-NYOJ-15-括号匹配（二）
//
//  Created by ZYJ on 16/4/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//问题代码
//#include <stdio.h>
//#include <string.h>
//#define MIN(a, b) a > b ? b : a
//
//int main(int argc, const char * argv[])
//{
//    int N, i, j;
//    int len, tag, count, min;
//    char S[101];
//    scanf("%d", &N);
//    while (N--)
//    {
//        int A[101];
//        scanf("%s", S);
//        len = (int)strlen(S);
//        tag = 1;
//        count = 0;
//        min = 101;
//        //删除匹配的括号（中间没有其它括号）
//        while (tag)
//        {
//            tag = 0;
//            for (i = 0; i < len; i++)
//            {
//                if (S[i] == '(')
//                {
//                    for (j = i + 1; j < len; )
//                    {
//                        if (S[j] == ')')
//                        {
//                            S[i] = ' ';
//                            S[j] = ' ';
//                            i = j;
//                            tag++;
//                            break;
//                        }
//                        else if (S[j] == ' ')
//                        {
//                            j++;
//                        }
//                        else
//                        {
//                            break;
//                        }
//                    }
//                }
//                else if (S[i] == '[')
//                {
//                    for (j = i + 1; j < len; j++)
//                    {
//                        if (S[j] == ']')
//                        {
//                            S[i] = ' ';
//                            S[j] = ' ';
//                            i = j;
//                            tag++;
//                            break;
//                        }
//                        else if (S[j] == ' ')
//                        {
//                            j++;
//                        }
//                        else
//                        {
//                            break;
//                        }
//                    }
//                }
//            }
//        }
//        //将剩下括号整合到两个数组中
//        for (i = 0; i < len; i++)
//        {
//            if (S[i] != ' ')
//            {
//                A[count] = S[i];
//                S[count++] = S[i];
//            }
//        }
//        //再次删除括号，删除匹配的()（中间允许有其它括号）
//        tag = 0;    //删除的个数
//        for (i = 0; i < count; i++)
//        {
//            if (A[i] == '(')
//            {
//                for (j = i + 1; j < count; j++)
//                {
//                    if (A[j] == ')')
//                    {
//                        A[i] = ' ';
//                        A[j] = ' ';
//                        tag += 2;
//                        break;
//                    }
//                }
//            }
//        }
//        min = MIN(min, count - tag);    //取最少
//        //再次删除括号，删除匹配的[]（中间允许有其它括号）
//        tag = 0;    //删除的个数
//        for (i = 0; i < count; i++)
//        {
//            if (S[i] == '[')
//            {
//                for (j = i + 1; j < count; j++)
//                {
//                    if (S[j] == ']')
//                    {
//                        S[i] = ' ';
//                        S[j] = ' ';
//                        tag += 2;
//                        break;
//                    }
//                }
//            }
//        }
//        min = MIN(min, count - tag);    //取最少
//        printf("%d %d\n", count, min);
//    }
//    return 0;
//}


#include <stdio.h>
#include <string.h>

#define MAX_LEN 101
#define min(a,b) (a) > (b) ? (b) : (a)

int isMatch(char a, char b);

int main()
{
    int N;
    scanf("%d", &N);
    int i, j, k, tmp;
    int length = 0;
    char str[MAX_LEN];
    int data[MAX_LEN][MAX_LEN];
    
    while (N--)
    {
        memset(data,0,sizeof(data));
        
        scanf("%s",str+1);
        
        length = (int)strlen(str + 1);
        
        for (i = 1; i <= length; i++)
            data[i][i] = 1;
        //dp[i][j]从第i + 1个数到第j个数匹配str[i]的右（小或中）括号
        //结果为两种，一种是在不同位置的匹配后结果取最小，一种是不匹配结果取最小
        for (j = 1; j <= length; j++)
        {
            for (i = j - 1; i >= 1; i--)
            {
                tmp = 0x1ffff;
                
                for (k = i + 1; k <= j; k++)
                {
                    if (isMatch(str[i], str[k]))
                    {
                        tmp = min(tmp ,(data[i + 1][k - 1] + data[k + 1][j]));
                    }
                }
                
                data[i][j] = min(tmp, data[i + 1][j] + 1);
            }
        }
        //从第一个到第length个数插入括号数量最少
        printf("%d\n", data[1][length]);	
    }
    return 0;
}

//判断是否匹配
int isMatch(char a, char b)
{
    if ((a == '(' && b == ')') || (a == '[' && b == ']'))
    {
        return 1;
    }
    return 0;
}