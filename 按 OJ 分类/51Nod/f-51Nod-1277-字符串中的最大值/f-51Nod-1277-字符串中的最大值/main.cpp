//
//  main.cpp
//  f-51Nod-1277-字符串中的最大值
//
//  Created by ZYJ on 2017/4/20.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 10;

char str[MAXN];
int len;
int nt[MAXN];
int res[MAXN];

void getNext()
{
    nt[0] = -1;
    int i = 0, j = -1;
    while (i <= len)
    {
        if (j == -1 || str[i] == str[j])
        {
            nt[++i] = ++j;
        }
        else
        {
            j = nt[j];
        }
    }
}

int main()
{
    scanf("%s", str);
    len = (int)strlen(str);
    getNext();
    
    for (int i = len; i >= 1; i--)
    {
        res[i]++;
        res[nt[i]] += res[i];
    }
    
    long long ans = 0;
    for (long long i = 1; i <= len; i++)
    {
        ans = max(i * res[i], ans);
    }
    printf("%lld\n", ans);
    
    return 0;
}
