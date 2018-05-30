//
//  main.cpp
//  f-CF-Codeforces Round #485 (Div. 2)
//
//  Created by ZYJ on 2018/5/30.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

//  AC
//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//
//int n;
//
//int main()
//{
//    scanf("%d", &n);
//
//    int cnt = 0, x;
//    for (int i = 1; i <= n; i++)
//    {
//        scanf("%d", &x);
//        cnt += (x == i);
//    }
//
//    if (cnt >= n / 1000)
//    {
//        puts("Petr");
//    }
//    else
//    {
//        puts("Um_nik");
//    }
//
//    return 0;
//}

#include <cstdio>

const int MAXN = 1e6 + 10;

int n;
int a[MAXN], p[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        p[a[i]] = i;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == i)
        {
            continue;
        }
        
        cnt++;
        a[p[i]] = a[i];
        p[a[i]] = p[i];
    }
    
    if ((3 * n - cnt) % 2 == 0)
    {
        printf("Petr");
    }
    else
    {
        printf("Um_nik");
    }
    
    return 0;
}
