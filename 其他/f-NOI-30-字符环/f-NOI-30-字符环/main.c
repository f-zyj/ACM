//
//  main.c
//  f-NOI-30-字符环
//
//  Created by ZYJ on 16/4/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAX(a, b) a > b ? a : b

int main(int argc, const char * argv[])
{
    int i, j, k;
    int lenA, lenB, len, maxLen;
    char A[256], B[256];
    while (~scanf("%s %s", A, B))
    {
        maxLen = 0;
        lenA = (int)strlen(A);
        lenB = (int)strlen(B);
        
        for (i = 0; i < lenA; i++)
        {
            for (j = 0; j < lenB; j++)
            {
                len = 0;
                for (k = 0; k < lenA + lenB; k++)
                {
                    if (A[(i + k) % lenA] == B[(j + k) % lenB])
                    {
                        len++;
                    }
                    else
                    {
                        maxLen = MAX(len, maxLen);
                        len = 0;
                    }
                }
                
            }
        }
        
        printf("%d\n", maxLen);
    }
    
    return 0;
}
