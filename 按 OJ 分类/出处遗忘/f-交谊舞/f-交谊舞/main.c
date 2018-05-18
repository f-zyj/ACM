//
//  main.c
//  f-交谊舞
//
//  Created by ZYJ on 16/4/14.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 200
#define OK 1
#define ERROR 0
#define Max(a, b) ((a > b) ? (a) : (b))
typedef int Status;
typedef char SElemType;
//栈结构
typedef struct
{
    int top;    //用于栈顶指针
    SElemType data[MAXSIZE];
    int tag[MAXSIZE];   //是否被女舞伴占用
} SqStack;
//Push
Status Push (SqStack *S, SElemType e)
{
    if (S->top == MAXSIZE - 1)  //栈满
    {
        return ERROR;
    }
    S->top++;   //栈顶指针加一
    S->data[S->top] = e;    //将新插入元素
    S->tag[S->top] = 1;
    return OK;
}
////Pop
//Status Pop (SqStack *S)
//{
//    if (S->top == -1)   //栈空
//    {
//        return ERROR;
//    }
//    S->top--;
//    return OK;
//}

int main(int argc, const char * argv[])
{
    int sum = 0, i, j, k = 0;
    int num, women[100], man[100];
    SqStack *S = (SqStack*)malloc(sizeof(SqStack));
    scanf("%d", &num);
    //合并入栈
    for (i = 0; i < num; i++)
    {
        scanf("%d", &women[i]);
        for (; sum < women[i]; sum++)
        {
            Push(S, '(');
        }
        Push(S, ')');
    }
//    for (i = 1; i < S->top; i++)
//    {
//        printf("%c ", S->data[i]);
//    }
//    printf("%c\n", S->data[S->top]);
    //查找男舞伴
    for (i = 2; i <= S->top; i++)
    {
        if (S->data[i] == ')')
        {
            for (j = i - 1; j > 0; j--)
            {
                if (S->data[j] == '(' && S->tag[j])
                {
                    S->tag[j] = 0;
                    man[k++] = (i - j + 1) / 2;
                    break;
                }
            }
        }
    }
    //输出距离
    for (i = 0; i < num - 1; i++)
    {
        printf("%d ", man[i]);
    }
    printf("%d\n", man[num - 1]);
    return 0;
}