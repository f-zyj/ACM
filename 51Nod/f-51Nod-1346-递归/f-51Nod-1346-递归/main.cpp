//
//  main.cpp
//  f-51Nod-1346-递归
//
//  Created by ZYJ on 2017/5/18.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cstring>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXN = 131072;
//const int MAXM = 100;
//const int MAXA = MAXM + 10;
//const int MAXB = MAXN + MAXM;
//const int MAXC = MAXN + MAXM + 10;
//
//int b[MAXA][MAXC];
//int b_[MAXC][MAXA];
//
//void init()
//{
//    for (int i = 2; i <= MAXM; i++)
//    {
//        for (int j = 2; j <= MAXB; j++)
//        {
//            b[i][j] = b[i - 1][j] ^ b[i][j - 1];
//        }
//    }
//    for (int i = 2; i <= MAXB; i++)
//    {
//        for (int j = 2; j <= MAXM; j++)
//        {
//            b_[i][j] = b_[i - 1][j] ^ b_[i][j - 1];
//        }
//    }
//}
//
//int main()
//{
//    memset(b, 0, sizeof(b));
//    memset(b_, 0, sizeof(b_));
//    
//    int a;
//    for (int i = 2; i <= MAXB; i++)
//    {
//        scanf("%d", &a);
//        b[1][i] = a;
//        if (i >= 2 && i <= MAXM)
//        {
//            b_[1][i] = a;
//        }
//    }
//    
//    for (int i = 2; i <= MAXB; i++)
//    {
//        scanf("%d", &a);
//        b_[i][1] = a;
//        if (i >= 2 && i <= MAXM)
//        {
//            b[i][1] = a;
//        }
//    }
//    
//    init();
//    
//    int Q;
//    scanf("%d", &Q);
//    
//    int n, m;
//    for (int i = 0; i < Q; i++)
//    {
//        scanf("%d%d", &n, &m);
//        cout << (b[n][MAXN + m] ^ b_[MAXN + n][m])<< endl;
//    }
//    
//    return 0;
//}

#include <stdio.h>

const int MAXN = 131072;
const int MAXM = MAXN + 100;
const int MAXA = MAXM + 10;
const int MAXB = 100;
const int MAXC = MAXB + 10;


int a[MAXA], b[MAXA];
int c[MAXC][MAXC];

inline int get_c(int x, int y)
{
    int ret = 0;
    for (int i = 2; i <= y; ++i)
    {
        if (((x - 2 + y - i) & (x - 2)) == x - 2)   //  ???
        {
            ret ^= a[i];
        }
    }
    for (int i = 2; i <= x; ++i)
    {
        if (((x - i + y - 2) & (y - 2)) == y - 2)   //  ???
        {
            ret ^= b[i];
        }
    }
    
    return ret;
}

int main()
{
    for (int i = 2; i <= MAXM; ++i)
    {
        scanf("%d", a + i);
    }
    for (int j = 2; j <= MAXM; ++j)
    {
        scanf("%d", b + j);
    }
    
    for (int i = 1; i <= MAXB; ++i)
    {
        c[0][i] = get_c(MAXN, i + MAXN);
    }
    for (int i = 1; i <= MAXB; ++i)
    {
        c[i][0] = get_c(i + MAXN, MAXN);
    }
    
    for (int i = 1; i <= MAXB; ++i)
    {
        for (int j = 1; j <= MAXB; ++j)
        {
            c[i][j] = c[i - 1][j] ^ c[i][j - 1];
        }
    }
    
    int Q;
    scanf("%d", &Q);
    
    int n, m;
    while (Q--)
    {
        scanf("%d%d", &n, &m);
        printf("%d\n", c[n][m]);
    }
    
    return 0;
}
