//
//  main.c
//  f-ZZUACM-词法分析器
//
//  Created by ZYJ on 16/4/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    char code[1000];
    int sum = 0, j = 0, extent;
    while (~scanf("%s", code))
    {
        extent = (int)strlen(code);
        for (j = 0; j < extent; j++)
        {
            if (j + 1 < extent && code[j] == 'i' && code[j + 1] == 'f')
            {
                sum++;
            }
            if (j + 2 < extent && code[j] == 'w' && code[j + 1] == 'h' && code[j + 2] == 'i' && code[j + 3] == 'l' && code[j + 4] == 'e')
            {
                sum++;
            }
            if (j + 4 < extent && code[j] == 'f' && code[j + 1] == 'o' && code[j + 2] == 'r')
            {
                sum++;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}
