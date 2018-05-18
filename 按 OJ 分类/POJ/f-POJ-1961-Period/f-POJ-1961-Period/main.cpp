//
//  main.cpp
//  f-POJ-1961-Period
//
//  Created by ZYJ on 2017/10/9.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1e6;

int n;
char s[MAXN];
int nxt[MAXN];

void getnxt()
{
    nxt[0] = -1;
    int i = 0, j = -1;
    int len = (int)strlen(s);
    while (i < len)
    {
        if (s[i] == s[j] || j == -1)
        {
            i++;
            j++;
            nxt[i] = j;
        }
        else
        {
            j = nxt[j];
        }
    }
}

int main()
{
    int ce = 1;
    while (~scanf("%d", &n) && n != 0)
    {
        scanf("%s", s);
        
        printf("Test case #%d\n", ce++);
        
        int len = (int)strlen(s);
        
        getnxt();
        
        for (int i = 2; i <= len; i++)
        {
            if (i % (i - nxt[i]) == 0 && nxt[i] != 0)
            {
                printf("%d %d\n", i, i / (i - nxt[i]));
            }
        }
        
        puts("");
    }
    
    return 0;
}
