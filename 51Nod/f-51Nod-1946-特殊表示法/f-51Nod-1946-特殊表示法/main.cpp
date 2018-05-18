//
//  main.cpp
//  f-51Nod-1946-特殊表示法
//
//  Created by ZYJ on 2018/1/1.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e6 + 5;

int n, m;
int a[MAXN];
int b[MAXN];
char c[MAXN << 1];

int main()
{
    scanf("%d", &n);
    getchar();
    
    for (int i = 0; i < n; i++)
    {
        a[i] = getchar() - '0';
        getchar();
    }
    
    scanf("%d", &m);
    getchar();
    
    for (int i = 0; i < m; i++)
    {
        a[i] += getchar() - '0';
        getchar();
    }
    
    //  逆着扩展一遍
    n = max(m, n);
    for (int i = n - 1; i > 1; i--)
    {
        if (a[i] >= 2)
        {
            //  ex: 2 * 5 = 8 + 2
            a[i] -= 2;
            a[i - 2] += 1;
            a[i + 1] += 1;
            n = max(i + 2, n);
        }
        if (a[i] >= 1 && a[i - 1] >= 1)
        {
            //  ex: 2 + 3 = 5
            a[i] -= 1;
            a[i - 1] -= 1;
            a[i + 1] += 1;
            n = max(i + 2, n);
        }
    }

    //  处理边界特殊情况
    if (a[0] >= 2 && a[1] == 0)
    {
        //  ex: 1 + 1 = 2
        a[0] -= 2;
        a[1] += 1;
    }
    else if (a[1] == 3)
    {
        //  ex: 2 + 2 + 2 = 1 + 2 + 3
        a[1] -= 1;
        a[0] += 1;
        a[2] += 1;
    }
    
    //  正着扩展若干遍，一直到无法扩展
    int flag = 1;
    while (flag)
    {
        flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= 1 && a[i + 1] >= 1 && a[i + 2] != 1)
            {
                flag = 1;
                //  ex: 2 + 3 = 5
                a[i] -= 1;
                a[i + 1] -= 1;
                a[i + 2] += 1;
                n = max(i + 3, n);
            }
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        c[cnt++] = a[i] + '0';
        if (i != n - 1)
        {
            c[cnt++] = ' ';
        }
    }
    c[cnt] = '\n';
    
    printf("%d\n%s", n, c);
    
    return 0;
}
