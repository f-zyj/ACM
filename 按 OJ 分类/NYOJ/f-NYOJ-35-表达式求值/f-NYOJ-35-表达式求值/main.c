//
//  main.c
//  f-NYOJ-35-表达式求值
//
//  Created by ZYJ on 16/5/25.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include<stdio.h>
//#include<stdlib.h>
//
////数据栈
//typedef struct DA
//{
//    float data[1000];
//    int pop;
//} SDA;
//
////运算符栈
//typedef struct OP
//{
//    char op[1000];
//    int pop;
//} SOP;
//
////初始化数据栈
//int InitSDA(SDA * p)
//{
//    p->pop = 0;
//    return 0;
//}
//
////初始化运算符栈
//int InitSOP(SOP * p)
//{
//    p->pop = 0;
//    (p->op[p->pop]) = '=';
//    (p->pop)++;
//    return 0;
//}
//
////数据入栈
//int PushSDA(SDA * p, float d)
//{
//    if(p->pop < 1000)
//    {
//        p->data[p->pop] = d;
//        (p->pop)++;
//        return 0;
//    }
//    else
//        return 1;	//栈满
//}
//
////运算符入栈
//int PushSOP(SOP * p, char c)
//{
//    if(p->pop < 1000)
//    {
//        p->op[p->pop] = c;
//        (p->pop)++;
//        return 0;
//    }
//    else
//        return 1;	//栈满
//}
//
////数据出栈
//int PopSDA(SDA * p, float * d)
//{
//    (p->pop)--;
//    if(p->pop >= 0)
//    {
//        *d = p->data[p->pop];
//        return 0;
//    }
//    else
//        return 1;
//}
//
////运算符出栈
//int PopSOP(SOP * p, char * c)
//{
//    (p->pop)--;
//    if(p->pop >= 0)
//    {
//        *c = p->op[p->pop];
//        return 0;
//    }
//    else
//        return 1;
//}
//
////从s[*pc]开始获取一个浮点数
//int StrToInt(char s[], int * pc, float *pout)
//{
//    char buf[100];
//    int i = 0;
//    
//    if(s[*pc]<'0' || s[*pc]>'9')
//        return 1;
//    else
//    {
//        while((s[*pc] >= '0' && s[*pc] <= '9') || s[*pc] == '.')
//        {
//            buf[i] = s[*pc];
//            (*pc)++;
//            i++;
//        }
//        buf[i] = '\0';
//        *pout = (float)atof(buf);
//        return 0;
//    }
//}
//
////从s[*pc]获取一个char
//int StrToChar(char s[], int *pc, char *pout)
//{
//    if('+'==s[*pc] || '-'==s[*pc] || '*'==s[*pc] || '/'==s[*pc] || '('==s[*pc] || ')'==s[*pc])
//    {
//        *pout = s[*pc];
//        (*pc)++;
//        return 0;
//    }
//    else
//        return 1;
//}
//
////获取优先级
//char GetPri(char c1, char c2)
//{
//    
//    char f[7][7] = {'>', '>', '<', '<', '<', '>', '>',
//        '>', '>', '<', '<', '<', '>', '>',
//        '>', '>', '>', '>', '<', '>', '>',
//        '>', '>', '>', '>', '<', '>', '>',
//        '<', '<', '<', '<', '<', '=', '\0',
//        '>', '>', '>', '>', '\0', '>', '>',
//        '<', '<', '<', '<', '<', '\0', '=',};
//    
//    int i=0, j=0;
//    switch(c1)
//    {
//        case '+': i = 0; break;
//        case '-': i = 1; break;
//        case '*': i = 2; break;
//        case '/': i = 3; break;
//        case '(': i = 4; break;
//        case ')': i = 5; break;
//        case '=': i = 6; break;
//    }
//    switch(c2)
//    {
//        case '+': j = 0; break;
//        case '-': j = 1; break;
//        case '*': j = 2; break;
//        case '/': j = 3; break;
//        case '(': j = 4; break;
//        case ')': j = 5; break;
//        case '=': j = 6; break;
//    }
//    return f[i][j];
//}
//
////计算表达式
//float Operate(float a, char op, float b)
//{
//    switch(op)
//    {
//        case '+': return a + b;
//        case '-': return a - b;
//        case '*': return a * b;
//        case '/': return a / b;
//        default: return 0;
//    }
//}
//
//int main(void)
//{
//    char s[10][1000];
//    int c = 0;
//    float bufda;
//    char bufop;
//    float a, b;
//    SDA sda;
//    SOP sop;
//    int n;
//    int i;
//    
//    
//    scanf("%d", &n);
//    for(i = 0; i < n; i++)
//        scanf("%s", s[i]);
//    for(i = 0; i < n; i++)
//    {
//        c = 0;
//        InitSDA(&sda);	//初始化数据栈
//        InitSOP(&sop);	//初始化符号栈
//        while(s[i][c] != '=' || sop.op[sop.pop - 1] != '=')	//	计算未完成
//        {
//            if(0 == StrToInt(s[i], &c, &bufda))
//                PushSDA(&sda, bufda);	//数据入栈
//            else
//            {
//                switch(GetPri(sop.op[sop.pop - 1], s[i][c]))
//                {
//                    case '<':
//                        if(0 == StrToChar(s[i], &c, &bufop))
//                            PushSOP(&sop, bufop);
//                        break;
//                    case '=':
//                        PopSOP(&sop, &bufop);
//                        c++;
//                        break;
//                    case '>':
//                        PopSOP(&sop, &bufop);
//                        PopSDA(&sda, &b);
//                        PopSDA(&sda, &a);
//                        PushSDA(&sda, Operate(a, bufop, b));
//                        break;
//                }
//            }
//        }
//        PopSDA(&sda, &a);
//        printf("%.2f\n", a);
//    }
//    return 0;
//}

//// AC(动态规划）
//#include<stdio.h>
//#include<string.h>
//
//int len;
//int fst[1005];
//char str[1005];
//double Jud(int begin, int end); /*计算并返回表达式在区间[begin end]中的值*/
//
//int main()
//{
//    int T, i;
//    double ans;
//    scanf("%d", &T);
//    while(T--)
//    {
//        memset(fst, 0, sizeof(fst)); /*一定要清0*/
//        scanf("%s", str);
//        len = (int)strlen(str)-1;
//        fst[0] = 1;
//        for(i = 1; i <= len - 1; i++) /*fst[i]表示优先级,fst[i]越大,说明优先级越高↓↓*/
//        {                           /*例如str[] -- ((1+2)*5+1)/4=*/
//            if(str[i - 1]== '(')	/*对应fst[] -- 12333222221110*/
//                fst[i] = fst[i - 1] + 1;
//            else if(str[i] == ')')
//                fst[i] = fst[i - 1] - 1;
//            else
//                fst[i] = fst[i - 1];
//        }
//        ans = Jud(0, len - 1); /*传入整个表达式，不包括=*/
//        printf("%.2f\n", ans);
//    }
//    return 0;
//}
//
//double Jud(int begin, int end)
//{ /*规定区间[begin, end]的优先级标准为fst[begin]*/
//    int i;
//    double k;
//    for(i = begin; i <= end; i++) /*先从做左到右找到第一个处于指定优先级的'+'运算符*/
//    {
//        if(str[i]== '+' && fst[i] == fst[begin])
//        {
//            k = Jud(begin, i - 1) + Jud(i + 1, end); /*将其拆成两个个表达式的和*/
//            return k;
//        }
//    }
//    for(i = end; i >= begin; i--) /*如果找不到'+',再从右往左找到第一个处于指定优先级的'-'运算符*/
//    {
//        if(str[i]=='-' && fst[i] == fst[begin])
//        {
//            k = Jud(begin, i - 1) - Jud(i + 1, end);	/*将其拆成两个个表达式的差*/
//            return k;
//        }
//    }
//    for(i = begin; i <= end; i++)	/*如果还找不到,再从左往右找到第一个处于指定优先级的'*'运算符*/
//    {
//        if(str[i] == '*' && fst[i] == fst[begin])
//        {
//            k = Jud(begin, i - 1) * Jud(i + 1, end);	/*将其拆成两个个表达式的积*/
//            return k;
//        }
//    }
//    for(i = end; i >= begin; i--)	/*同上,从右往左找到第一个处于指定优先级的'/'运算符*/
//    {
//        if(str[i] == '/' && fst[i] == fst[begin])
//        {
//            k = Jud(begin, i - 1) / Jud(i + 1, end); /*将其拆成两个个表达式的商*/
//            return k;
//        }
//    }
//    if(str[begin]=='(') /*如果在这个[begin,end]区间里的指定优先级中没有任何运算符,说明此区间可能完全包含上一级*/
//    {
//        for(i = begin + 1; fst[i] >= fst[begin + 1]; i++);
//        k = Jud(begin + 1, i - 1);
//    }
//    else /*既然没有包含上一级,说明这个区间就只剩下一个数啦*/
//    {
//        char *p = str;
//        sscanf(p+begin, "%lf", &k); /*将这个数赋值给k,并返回*/
//    }
//    return k;
//}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 10000000
#define ADD INF + 1 //+
#define SUB INF + 2 //-
#define MUL INF + 3 //x
#define DIV INF + 4 //÷

char str[1005];     //原公式
int len;            //公式长度
char symbol[1000];   //运算符号栈
float suffix[1005]; //后缀式
float answer[1000];  //运算栈

//从s[*pc]开始获取一个浮点数
int StrToInt(char s[], int * pc, float *pout)
{
    char buf[100];
    int i = 0;

    if(s[*pc]<'0' || s[*pc]>'9')
        return 1;
    else
    {
        while((s[*pc] >= '0' && s[*pc] <= '9') || s[*pc] == '.')
        {
            buf[i] = s[*pc];
            (*pc)++;
            i++;
        }
        buf[i] = '\0';
        *pout = (float)atof(buf);
        return 0;
    }
}

void swi(int *key, char sym)
{
    switch (sym)
    {
        case '+':
            suffix[(*key)++] = ADD;
            break;
        case '-':
            suffix[(*key)++] = SUB;
            break;
        case '*':
            suffix[(*key)++] = MUL;
            break;
        case '/':
            suffix[(*key)++] = DIV;
            break;
    }
}

void perform(int suf, int *_key)
{
    float a = answer[(*_key)--];
    float b = answer[(*_key)];
    float c;
    switch (suf)
    {
        case (INF + 1):
            c = a + b;
            break;
        case (INF + 2):
            c = b - a;
            break;
        case (INF + 3):
            c = a * b;
            break;
        default:
            c = b / a;
            break;
    }
    answer[*_key] = c;
//    printf("%.2f\n", answer[*_key]);
    return ;
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while(T--)
    {
        scanf("%s", str);
        len = (int)strlen(str) - 1;
        int key = 0;
        int top = -1;
        float pout;
        //中缀式转后缀式
        for (int i = 0; i < len; )
        {
            if (!StrToInt(str, &i, &pout))
            {
                suffix[key++] = pout;
            }
            else if (top != -1 && str[i] == ')')
            {
                while (symbol[top] != '(')
                {
                    swi(&key, symbol[top--]);
                }
                i++;
                top--;
            }
            else if (top != -1 && (str[i] == '+' || str[i] == '-') && (symbol[top] == '*' || symbol[top] == '/'))
            {
                while (symbol[top] != '(' && top >= 0)
                {
                    swi(&key, symbol[top--]);
                }
                symbol[++top] = str[i++];
            }
            else if (top != -1 && (str[i] == '*' || str[i] == '/') && (symbol[top] == '*' || symbol[top] == '/'))
            {
                swi(&key, symbol[top]);
                symbol[top] = str[i++];
            }
            else
            {
                symbol[++top] = str[i++];
            }
        }
        while (top >= 0)
        {
            swi(&key, symbol[top--]);
        }
        
//        for (int i = 0; i < key; i++)
//        {
//            printf("%f  ", suffix[i]);
//        }
//        printf("\n");
        //后缀式运算
        int _key = -1;
        for (int i = 0; i < key; i++)
        {
            if (suffix[i] < INF)
            {
                answer[++_key] = suffix[i];
//                printf("%.2f\n", answer[_key]);
            }
            else
            {
                perform((int)suffix[i], &_key);
            }
        }
        printf("%.2f\n", answer[0]);
    }
    return 0;
}


//#include <stack>
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdlib.h>
//
//using namespace std;
//
//int priority(char c)
//{
//    if(c == '=')    return 0;
//    if(c == '+')    return 1;
//    if(c == '-')    return 1;
//    if(c == '*')    return 2;
//    if(c == '/')    return 2;
//    return 0;
//}
//
//void compute(stack<double>& Num,stack<char>& Op)
//{
//    double b = Num.top();
//    Num.pop();
//    double a = Num.top();
//    Num.pop();
//    switch(Op.top())
//    {
//        case '+':Num.push(a+b);break;
//        case '-':Num.push(a-b);break;
//        case '*':Num.push(a*b);break;
//        case '/':Num.push(a/b);break;
//    }
//    Op.pop();
//}
//
//int main()
//{
//    int z;
//    char str[1005];
//    stack<double> Num;
//    stack<char> Op;
//    scanf("%d",&z);
//    while(z--)
//    {
//        scanf("%s",str);
//        int len = strlen(str);
//        for(int i=0;i<len;i++)
//        {
//            if(isdigit(str[i]))
//            {
//                double n = atof(&str[i]);
//                while(i<len && (isdigit(str[i]) || str[i]=='.'))
//                    i++;
//                i--;
//                Num.push(n);
//            }
//            else
//            {
//                if(str[i] == '(')
//                    Op.push(str[i]);
//                else if(str[i] == ')')
//                {
//                    while(Op.top()!='(')
//                        compute(Num,Op);
//                    Op.pop();
//                }
//                else if(Op.empty() || priority(str[i])>priority(Op.top()))
//                    Op.push(str[i]);
//                else
//                {
//                    while(!Op.empty() && priority(str[i])<=priority(Op.top()))
//                        compute(Num,Op);
//                    Op.push(str[i]);
//                }
//            }
//        }
//        Op.pop();
//        printf("%.2f\n",Num.top());
//        Num.pop();
//    }
//    return 0;
//}
