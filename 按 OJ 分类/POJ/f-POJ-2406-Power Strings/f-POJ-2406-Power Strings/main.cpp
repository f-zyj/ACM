//
//  main.cpp
//  f-POJ-2406-Power Strings
//
//  Created by ZYJ on 2017/10/9.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1e6;

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
    while (~scanf("%s", s))
    {
        if (s[0] == '.')
        {
            break;
        }
        
        int len = (int)strlen(s);
        
        getnxt();
        
        if (len % (len - nxt[len]) == 0)
        {
            printf("%d\n", len / (len - nxt[len]));
        }
        else
        {
            printf("1\n");
        }
    }
    
    return 0;
}
