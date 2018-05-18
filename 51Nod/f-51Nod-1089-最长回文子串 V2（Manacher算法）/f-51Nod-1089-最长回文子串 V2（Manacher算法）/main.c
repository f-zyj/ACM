//
//  main.c
//  f-51Nod-1089-最长回文子串 V2（Manacher算法）
//
//  Created by ZYJ on 16/4/25.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX(a,b) ((a>b)?(a):(b))
int f[200005];
char str[200005];

int main()
{
    int i, j, k, max = 0, o, r, l;
    scanf("%s", str);
    l = (int)strlen(str);
    //扩充为原来两倍长，中间补*号
    for(i = l - 1; i >= 0; i--)
    {
        str[2 * i] = str[i];
        str[2 * i - 1] = '*';
    }
    
    for(o = 0, r = 0, i = 1; i <=2 * (l - 1); i++)
    {
        if(i > (o + r))
        {
            j = i - 1;
            k = i + 1;
        }
        else if (f[2 * o - i] >= o + r - i)
        {
            k = o + r + 1;
            j = 2 * i - k;
        }
        else
        {
            f[i] = f[2 * o - i];
            continue;
        }
        while (j >= 0 && k <= 2 * (l - 1) && str[j] == str[k])
        {
            j--;
            k++;
        }
        f[i] = --k - i;
        if(k >= o + r)
        {
            r = k - i;
            o = i;
            max = MAX((r + o % 2) / 2 * 2 - (o % 2) + 1, max);
        }
    }
    
    printf("%d", max);
    return 0;
}
