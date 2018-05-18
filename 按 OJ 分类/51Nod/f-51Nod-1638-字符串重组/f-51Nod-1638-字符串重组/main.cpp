//
//  main.cpp
//  f-51Nod-1638-字符串重组
//
//  Created by ZYJ on 2017/11/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e6 + 10;

int len_a, len_b;
char a[MAXN], b[MAXN], c[MAXN];
int p[MAXN], _nt[MAXN], z[MAXN], extend[MAXN];

void kmp()
{
    memcpy(c, a, sizeof(a));
    reverse(c, c + len_a);
    
    p[0] = 0;
    for (int i = 1, j = 0; i < len_a; ++i)
    {
        while (j && c[j] != c[i])
        {
            j = p[j - 1];
        }
        if (c[j] == c[i])
        {
            ++j;
        }
        p[i] = j;
    }
    
    for (int i = 0, j = 0; i < len_a; ++i)
    {
        while (j && b[i] != c[j])
        {
            j = p[j - 1];
        }
        if (b[i] == c[j])
        {
            ++j;
        }
        _nt[i] = j;
    }
}

void exkmp()
{
    int k = 1, p, i, j;
    for (j = 0; j + 1 < len_a && b[j] == b[j + 1]; ++j) ;
    z[1] = p = j;
    
    for (i = 2; i < len_a; ++i)
    {
        if (z[i - k] < p - i + 1)
        {
            z[i] = z[i - k];
        }
        else
        {
            for (j = max(0, p - i + 1); i + j < len_a && b[i + j] == b[j]; ++j) ;
            z[i] = j;
            k = i;
            p = i + j - 1;
        }
    }
    
    for (j = 0; j < len_a && a[j] == b[j]; ++j) ;
    extend[0] = j;
    k = 0;
    p = j - 1;
    for (i = 1; i < len_a; ++i)
    {
        if (z[i - k] < p - i + 1)
        {
            extend[i] = z[i - k];
        }
        else
        {
            for (j = max(0, p - i + 1); i + j < len_a && a[i + j] == b[j]; ++j) ;
            extend[i] = j;
            k = i;
            p = i + j - 1;
        }
    }
}

int main()
{
    fgets(a, MAXN, stdin);
    fgets(b, MAXN, stdin);
    len_a = (int)strlen(a) - 1;
    len_b = (int)strlen(b) - 1;
    a[len_a] = '\0';
    b[len_b] = '\0';
    
    if (len_a != strlen(b))
    {
        puts("-1 -1");
        return 0;
        
    }

    kmp();
    exkmp();
    
    int _i = -1, _j = -1;
    for (int i = 0; i + 1 < len_a && a[i] == b[len_a - 1 - i]; ++i)
    {
        if (extend[i + 1] >= len_a - _nt[len_a - 2 - i] - i - 1)
        {
            _i = i;
            _j = len_a - _nt[len_a - 2 - i];
        }
    }
    
    printf("%d %d\n", _i, _j);
    
    return 0;
}
