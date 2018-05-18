//
//  main.c
//  f-NYOJ-2-括号配对问题
//
//  Created by ZYJ on 16/5/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    int N;
    char brackets[10001];
    char b[10001];
    int len, key, flag;
    scanf("%d", &N);
    while (N--)
    {
        key = 0;
        flag = 1;
        scanf("%s", brackets);
        len = (int)strlen(brackets);
        for (int i = 0; i < len; i++)
        {
            if (brackets[i] == '(' || brackets[i] == '[')
            {
                b[key++] = brackets[i];
            }
            else if (brackets[i] == ')' && b[key - 1] == '(')
            {
                key--;
            }
            else if (brackets[i] == ']' && b[key - 1] == '[')
            {
                key--;
            }
            else
            {
                printf("No\n");
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            printf("Yes\n");
        }
    }
    
    return 0;
}
