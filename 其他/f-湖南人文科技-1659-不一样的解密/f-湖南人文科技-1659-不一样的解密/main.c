//
//  main.c
//  f-湖南人文科技-1659-不一样的解密
//
//  Created by ZYJ on 16/5/18.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>
char A[101], B[101];
int letterA[27], letterB[27];

int main(int argc, const char * argv[])
{
    scanf("%s %s", A, B);

    int len = (int)strlen(A);
    
    for (int i = 0; i < len; i++)
    {
        letterA[(int)A[i] - 64]++;
        letterB[(int)B[i] - 64]++;
    }
    
    for (int i = 1; i < 26; i++)
    {
        for (int j = i + 1; j <= 26; j++)
        {
            if (letterA[i] > letterA[j])
            {
//                letterA[i] ^= letterA[j] ^= letterA[i] ^= letterA[j];
                letterA[i] ^= letterA[j];
                letterA[j] ^= letterA[i];
                letterA[i] ^= letterA[j];
            }
            if (letterB[i] > letterB[j])
            {
//                letterB[i] ^= letterB[j] ^= letterB[i] ^= letterB[j];
                letterB[i] ^= letterB[j];
                letterB[j] ^= letterB[i];
                letterB[i] ^= letterB[j];
            }
        }
    }
    
    for (int i = 1; i <= 26; i++)
    {
        if (letterA[i] != letterB[i])
        {
            printf("NO\n");
            return 0;
        }
    }
    
    printf("YES\n");
    
    return 0;
}
