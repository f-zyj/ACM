//
//  main.cpp
//  f-POJ-3461-Oulipo
//
//  Created by ZYJ on 2017/10/9.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

const int MAXN = 1e4 + 10;
const int MAXM = 1e6 + 10;

void KMP_Pre(char x[], int m, int next[])
{
    int i = 0, j = next[0] = -1;
    while (i < m)
    {
        while (-1 != j && x[i] != x[j])
        {
            j = next[j];
        }
        next[++i] = ++j;
    }
}

int n;
int nxt[MAXN];
char W[MAXN];
char T[MAXM];

int KMP_Count(char x[], int m, char y[], int n)
{
    int i, j, ret = 0;
    
    KMP_Pre(x, m, nxt);
    
    i = j = 0;
    while (i < n)
    {
        while (-1 != j && y[i] != x[j])
        {
            j = nxt[j];
        }
        i++;
        j++;
        if (j >= m)
        {
            ret++;
            j = nxt[j];
        }
    }
    
    return ret;
}

int main(int argc, const char * argv[])
{
    scanf("%d", &n);

    while (n--)
    {
        scanf("%s%s", W, T);
        
        int m = (int)strlen(W);
        int n = (int)strlen(T);
        
        printf("%d\n", KMP_Count(W, m, T, n));
    }
    
    return 0;
}
