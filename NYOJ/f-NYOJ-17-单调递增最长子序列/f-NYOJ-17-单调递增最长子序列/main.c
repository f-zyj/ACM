//
//  main.c
//  f-NYOJ-17-单调递增最长子序列
//
//  Created by ZYJ on 16/5/17.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>
char strA[10001], strB[50];

int upper_bound(int A, int key)
{
    for (int i = 0; i < key; i++)
    {
        if (strB[i] >= A)
        {
            return i;
        }
    }
    return key;
}

int main(int argc, const char * argv[])
{
    int n;
    scanf("%d", &n);
    
    while (n--)
    {
        scanf("%s", strA);
        
        int len = (int)strlen(strA);
        int key = 0;
        strB[key] = strA[key];
        
        for (int i = 1; i < len; i++)
        {
            if (strA[i] > strB[key])
            {
                strB[++key] = strA[i];
            }
            else
            {
                strB[upper_bound(strA[i], key)] = strA[i];
            }
        }
        
        printf("%d\n", key + 1);
    }
    
    return 0;
}
