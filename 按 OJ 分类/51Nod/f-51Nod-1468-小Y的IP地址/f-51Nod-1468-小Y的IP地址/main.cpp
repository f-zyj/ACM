//
//  main.cpp
//  f-51Nod-1468-小Y的IP地址
//
//  Created by ZYJ on 2017/7/2.
//  Copyright ? 2017年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

const int MAXN = (1 << 16) + 10;
const int SZ = 1 << 16;

int n, a, b;
int H[MAXN];
int V[MAXN];

int main ()
{
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        H[a] = b;
    }
    
    V[0] = H[0];
    V[1] = H[1];
    for (int i = 2, a = 2, b = 4; i < SZ; i++)
    {
        if (i == b)
        {
            b <<= 1;
            a <<= 1;
        }
        V[i] = H[i] - H[i - a];
    }
    for (int i = 0; i < SZ; i++)
    {
        printf("%d ", V[i]);
    }
    putchar(10);
    
    return 0;
}
