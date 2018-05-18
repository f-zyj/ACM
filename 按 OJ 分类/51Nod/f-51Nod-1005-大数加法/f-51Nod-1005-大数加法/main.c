//
//  main.c
//  f-51Nod-1005-大数加法
//
//  Created by ZYJ on 16/4/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define _MAX 10005
int product[_MAX] = {0};
char numOne[_MAX] = {0}, numTwo[_MAX] = {0};
char numOneUp[_MAX] = {0}, numTwoUp[_MAX] = {0};    //倒序存储位置
int absMax = 1;
//递归进位函数
void Carrying(int tag, int i, int *p)
{
    p[i] += tag;
    if (p[i] > 9)
    {
        tag = 1;
        p[i] -= 10;
        Carrying(tag, i + 1, p);    //写成Carrying(tag, i, j+1, p);也成立，为了让i+j递增而已
    }
    return ;
}

//递归退位函数
void Abdicate(int tag, int i, int *p)
{
    p[i] += tag;
    if (p[i] < 0)
    {
        tag = -1;
        p[i] += 10;
        Abdicate(tag, i + 1, p);
    }
    return ;
}

//判断大小
void size(int numOneLen, int numTwoLen)
{
    int i, j;
    if (numOneLen < numTwoLen)
    {
        absMax = 2;
        for (i = 0; i < numTwoLen; i++)
        {
            numOneUp[i] ^= numTwoUp[i];
            numTwoUp[i] ^= numOneUp[i];
            numOneUp[i] ^= numTwoUp[i];
        }
        return ;
    }
    if (numOneLen == numTwoLen)
    {
        for (i = numOneLen - 1; i >= 0; i--)
        {
            if (numOneUp[i] < numTwoUp[i])
            {
                absMax = 2;
                for (j = 0; j < numTwoLen; j++)
                {
                    numOneUp[j] ^= numTwoUp[j];
                    numTwoUp[j] ^= numOneUp[j];
                    numOneUp[j] ^= numTwoUp[j];
                }
                return ;
            }
            else if (numOneUp[i] > numTwoUp[i])
            {
                return ;
            }
        }
    }
    return ;
}

//加减处理
void addOrSub(int numOneLen, int numTwoLen, int flag)   //flag加法为1减法为0
{
    int i, key = 0, tag, numLenMax, numLenMin;
    numOneLen = numOneLen - 1;
    numTwoLen = numTwoLen - 1;
    //数据逆序
    for (i = numOneLen; i > 0; i--)
    {
        numOneUp[key++] = numOne[i];
    }
    if (numOne[0] != '-')
    {
        numOneUp[key] = numOne[0];
        numOneLen++;
    }
    key = 0;
    for (i = numTwoLen; i > 0; i--)
    {
        numTwoUp[key++] = numTwo[i];
    }
    if (numTwo[0] != '-')
    {
        numTwoUp[key] = numTwo[0];
        numTwoLen++;
    }
    numLenMax = numOneLen > numTwoLen ? numOneLen : numTwoLen;
    numLenMin = numOneLen < numTwoLen ? numOneLen : numTwoLen;
    //逐位相加
    if (flag)
    {
        size(numOneLen, numTwoLen);
        for (i = 0; i < numLenMax; i++)
        {
            product[i] = (int)numOneUp[i] - 48;
        }
        for (i = 0; i < numLenMin; i++)
        {
            tag = (int)numTwoUp[i]-48;
            Carrying(tag, i, product);                          //递归
        }
    }
    //逐位相减
    else
    {
        size(numOneLen, numTwoLen);
        for (i = 0; i < numLenMax; i++)
        {
            product[i] = (int)numOneUp[i] - 48;
        }
        for (i = 0; i < numLenMin; i++)
        {
            tag = -((int)numTwoUp[i]-48);
            Abdicate(tag, i, product);                          //递归
        }
    }
}

//输出结果
void print()
{
    int i, j;
    //倒序输出结果
    for (i = _MAX - 1; i > 0; i--)
    {
        if (product[i] != 0)
        {
            break;                               //查找到第一个不等于0的跳出
        }
    }
    for (j = i; j >= 0; j--)
    {
        printf("%d",product[j]);
    }
    printf("\n");
}

int main(int argc, const char * argv[])
{
    int numOneLen, numTwoLen;
    
    scanf("%s %s",numOne,numTwo);                    //存数据

    numOneLen=(int)strlen(numOne);
    numTwoLen=(int)strlen(numTwo);
    
    if (numOne[0] == '-' && numTwo[0] == '-')
    {
        addOrSub(numOneLen, numTwoLen, 1);
        printf("-");
        print();
    }
    else if (numOne[0] == '-' || numTwo[0] == '-')
    {
        addOrSub(numOneLen, numTwoLen, 0);
        if ((numOne[0] == '-' && absMax == 1) || (numTwo[0] == '-' && absMax == 2))
        {
            printf("-");
        }
        print();
    }
    else
    {
        addOrSub(numOneLen, numTwoLen, 1);
        print();
    }
    return 0;
}

