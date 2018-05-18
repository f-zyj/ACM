//
//  main.c
//  f-BASIC-12-	十六进制转八进制
//
//  Created by ZYJ on 16/3/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char str[100005], num;
void Fun(int i, int state)
{
    int temp;
    if(i < 0)
    {
        if(num != 0)  //此时的num转二进制后的有效位数小于三位，即num小于8
        {
            printf("%d", num);
        }
        return;
    }
    if(state != 3)
    {
        temp = str[i] >= '0' && str[i] <= '9' ? str[i] - '0' : str[i] - 'A' + 10;
        temp <<= state;  //state指每次将16进制转2进制后，截取最后三位后剩余几位
        num |= temp;     //把二进制的num和二进制的temp相加（等同于十进制之间的加，因为对应num位数的temp的后几位在上一步左移时填补了0）
        temp = num;
        num >>= 3;
        Fun(i - 1, state + 1);
        printf("%d", (temp & 1) + (temp & 2) + (temp & 4));  //相当于将temp转二进制后的最后三位取出并转8进制
    }
    else
    {
        temp = num;
        num >>= 3;
        Fun(i, 0);
        printf("%d", (temp & 1) + (temp & 2) + (temp & 4));
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        num = 0;
        scanf("%s", str);
        Fun((int)strlen(str) - 1, 0);
        printf("\n");
    }
    return 0;
}