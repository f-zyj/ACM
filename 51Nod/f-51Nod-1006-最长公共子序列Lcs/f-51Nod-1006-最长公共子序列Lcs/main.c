//
//  main.c
//  f-51Nod-1006-最长公共子序列Lcs
//
//  Created by ZYJ on 16/4/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define  MAXN  1002
char A[MAXN] = {0};
char B[MAXN] = {0};
char R[MAXN] = {0};
short mat[MAXN][MAXN] = {0};

//返回三个数的最大值
short max(short a, short b, short c)
{
    if(a > b)
    {
        b = a;
    }
    return  b > c ? b : c;
}

int main()
{
    int  i, j = 0, k;
    scanf("%s %s", A + 1, B + 1);
    for(i = 1; A[i]; i++)
    {
        for(j = 1; B[j]; j++)
        {
            mat[i][j] = max(mat[i-1][j], mat[i][j-1], mat[i-1][j-1] + (A[i]==B[j] ? 1 : 0));
        }
    }
    i--;
    j--;
    k = MAXN - 1;
    while(i > 0 && j > 0)
    {
        if(A[i] == B[j])
        {
            R[k--] = A[i];
            i--;
            j--;
        }
        else if(mat[i-1][j] > mat[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    printf( "%s\n", R + k + 1);
    return 0;
}