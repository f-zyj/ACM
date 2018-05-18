//
//  main.cpp
//  f-51Nod-1804-小C的多边形
//
//  Created by ZYJ on 2017/5/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 1e6 + 10;
const int MAXM = 10;
const int MAX_BUFF = 1 << 24;

int A[MAXN];
char s[MAX_BUFF];
char tmp[MAXM];

void intToChar(int &pos, int a)
{
    int cnt = 0;
    while (a)
    {
        tmp[cnt++] = a % 10;
        a /= 10;
    }
    while (cnt != 0)
    {
        s[pos++] = tmp[--cnt] + '0';
    }
}

int main()
{
    int n;
    cin >> n;
    
    n--;
    if (n % 2 == 0)
    {
        cout << 0 << '\n';
        return 0;
    }
    int k = 1, num = n;
    
    while (1)
    {
        A[k] = num--;
        if (k == n - 1)
        {
            break;
        }
        k = (k + 2);
        if (k >= n)
        {
            k -= n;
        }
    }
    
    int pos = 0;
    for (int i = 1; i < n; i++)
    {
        intToChar(pos, i);
        s[pos++] = ' ';
    }
    intToChar(pos, n);
    s[pos++] = '\0';
    puts(s);
    
    pos = 0;
    for (int i = 0; i < n - 1; i++)
    {
        intToChar(pos, A[i]);
        s[pos++] = ' ';
    }
    intToChar(pos, A[n - 1]);
    s[pos++] = '\0';
    puts(s);
    
    return 0;
}
