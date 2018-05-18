//
//  main.c
//  f-ADV-158-	新建Microsoft Word文档
//
//  Created by ZYJ on 16/3/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define _MaxOperate 1481
#define _MaxNumber 2012
int OperateAnswer[_MaxOperate], File[_MaxOperate], i = 0, j = 0, l = 0, key = 0, sum = 0;

//新建文档
void New()
{
    for (l = 0; l < _MaxOperate; l++)
    {
        if (File[l] == 0)
        {
            File[l] = 1;
            OperateAnswer[key++] = l + 1;
            return ;
        }
    }
}
//删除文档
void Delete(char *p)
{
    sum = 0;
    for (l = 7; l < 11; l++)
    {
        if (p[l] >= '0' && p[l] <= '9')
        {
            sum = sum * 10 + p[l] - '0';
        }
    }
    switch (File[sum - 1])
    {
        case 1:
            File[sum - 1] = 0;
            OperateAnswer[key++] = _MaxNumber + 1;
            break;
        default:
            OperateAnswer[key++] = 0;
            break;
    }
    return ;
}
int main()
{
    int n;
    char Operate[13];
    scanf("%d", &n);
    fgets(Operate, 2, stdin);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 11; j++)
        {
            Operate[j] = '\0';
        }
        fgets(Operate, 13, stdin);
        switch (Operate[0])
        {
            case 'N':
                New();
                break;
                
            default:
                Delete(Operate);
                break;
        }
    }
    for (i = 0; i < n; i++)
    {
        switch (OperateAnswer[i])
        {
            case 0:
                printf("Failed\n");
                break;
            case _MaxNumber + 1:
                printf("Successful\n");
                break;
            default:
                printf("%d\n", OperateAnswer[i]);
                break;
        }
    }
    return 0;
}
