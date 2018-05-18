//
//  main.cpp
//  f-51Nod-1124-N!的非0最低位
//
//  Created by ZYJ on 2018/1/16.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>

const int MAXN = 10001;
const int MAGIC[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8, 4, 4, 8, 4, 6, 8, 8, 6, 8, 2};

char n[MAXN];
int a[MAXN];

int last_digit()
{
    int len = (int)strlen(n);
    
    if (len == 1)
    {
        return MAGIC[n[0] - '0'];
    }
    
    for (int i = 0; i < len; i++)
    {
        a[i] = n[len - 1 - i] - '0';
    }
    
    int ret = 1;
    while (len)
    {
        ret = ret * MAGIC[a[1] % 2 * 10 + a[0]] % 5;
        for (int c = 0, i = len - 1; i >= 0; i--)
        {
            c = c * 10 + a[i];
            a[i] = c / 5;
            c %= 5;
        }
        len -= !a[len - 1];
    }
    
    return ret + ret % 2 * 5;
}

int main()
{
    while (scanf("%s", n) != EOF)
    {
        printf("%d\n", last_digit());
    }
    
    return 0;
}
