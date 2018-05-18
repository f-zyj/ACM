//
//  main.c
//  f-ZZUACM-最长匹配子串
//
//  Created by ZYJ on 16/4/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100000
#define OK 1
#define ERROR 0
#define Max(a, b) ((a > b) ? (a) : (b))
typedef int Status;
typedef int SElemType;
//栈结构
typedef struct
{
    int top;    //用于栈顶指针
    SElemType data[MAXSIZE];
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
    return OK;
}
//Pop
Status Pop (SqStack *S)
{
    if (S->top == -1)   //栈空
    {
        return ERROR;
    }
    S->top--;
    return OK;
}

int main(int argc, const char * argv[])
{
    int T, ans, len, last, i;
    char s[MAXSIZE + 5];
    SqStack *S = (SqStack*)malloc(sizeof(SqStack));
    scanf("%d", &T);
    //T组子串
    while (T--)
    {
        S->top = -1;
        scanf("%s", s);
        ans = 0;
        len = (int)strlen(s);
        last = -1;
        //逐字符进行处理
        for (i = 0; i < len; i++)
        {
            if (s[i] == '(')
            {
                Push(S, i);
            }
            else
            {
                if (S->top == -1)
                {
                    last = i;
                    continue;
                }
                Pop(S);
                if (S->top == -1)
                {
                    ans = Max(ans, i - last);
                }
                else
                {
                    ans = Max(i - S->top, ans);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}


//#include <stdio.h>
//#include <string.h>
//char a[100010];
//int main()
//{
//    int t, x, max, i, j, c;
//    
//    scanf( "%d", &t);
//    getchar();
//    while ( t--){
//        gets( a);
//        x = (int)strlen( a);
//        max = i = 0;
//        while ( i < x){
//            if ( a[i] == '('){
//                c = 1;
//                for ( j = i + 1; j < x; ++j){
//                    if ( a[j] == '(')
//                        c++;
//                    else
//                        c--;
//                    if ( c == 0 && j - i + 1 > max)
//                        max = j - i + 1;
//                    if ( c < 0){
//                        i = j;
//                        break;
//                    }
//                }
//            }
//            i++;
//        }
//        printf( "%d\n", max);
//    }
//    return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#define MAXSIZE 100000
//#define Max(a, b) ((a > b) ? (a) : (b))
//
//int main(int argc, const char * argv[])
//{
//    int T, ans, tmp, len, last, i, top;
//    char s[MAXSIZE + 5];
//    scanf("%d", &T);
//    //T组子串
//    while (T--)
//    {
//        top = -1;
//        scanf("%s", s);
//        ans = 0;
//        tmp = 0;
//        len = (int)strlen(s);
//        last = -1;
//        //逐字符进行处理
//        for (i = 0; i < len; i++)
//        {
//            if (s[i] == '(')
//            {
//                top++;
//            }
//            else
//            {
//                if (top == -1)
//                {
//                    last = i;
//                    continue;
//                }
//                top--;
//                if (top == -1)
//                {
//                    ans = Max(ans, i - last);
//                }
//                else
//                {
//                    ans = Max(i - top, ans);
//                }
//            }
//        }
//        printf("%d\n", ans);
//    }
//    return 0;
//}