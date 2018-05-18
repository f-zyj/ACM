//
//  main.c
//  f-NYOJ-5-Binary String Matching
//
//  Created by ZYJ on 16/5/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    int N;
    char A[11], B[1001];
    int lenA, lenB, flag, ans;
    scanf("%d", &N);
    
    while (N--)
    {
        ans = 0;
        scanf("%s %s", A, B);
        lenA = (int)strlen(A);
        lenB = (int)strlen(B);
        
        for (int i = 0; i < lenB - lenA + 1; i++)
        {
            flag = 1;
            for (int j = 0; j < lenA; j++)
            {
                if (A[j] != B[i + j])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                ans++;
            }
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
