//
//  main.c
//  f-51Nod-1347-旋转字符串
//
//  Created by ZYJ on 16/5/14.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include<stdio.h>
#include<string.h>

int main()
{
    char a[1000001];
    int i, l = 0, flag;
    while (~scanf("%s", a))
    {
        flag = 1;
        l = (int)strlen(a);
        if(l % 2 != 0)
        {
            printf("No\n");
            return 0;
        }
        
        for(i = 0; i < l / 2; i++)
        {
            if (a[i] != a[i + l / 2])
            {
                flag = 0;
                break;
            }
        }
        
        if(flag)
            printf("Yes\n");
        else 
            printf("No\n");
    }
    
    return 0;
}