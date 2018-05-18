//
//  main.cpp
//  f-51Nod-1070-Bash游戏 V4
//
//  Created by ZYJ on 16/8/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 46;
int FB[MAXN];   //  斐波那契数列

void init()
{
    FB[0] = 0;
    FB[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        FB[i] = FB[i - 1] + FB[i - 2];
    }
    return ;
}

//  二分查找N
int bs(int a[], int l, int h, int N)
{
    int m;
    while (l < h)
    {
        m = (l + h) >> 1;
        if (a[m] == N)
        {
            return m;
        }
        if (a[m] < N)
        {
            l = m + 1;
        }
        else
        {
            h = m;
        }
    }
    return 0;
}

int main(int argc, const char * argv[])
{
    init();
    
    int T;
    cin >> T;
    
    int N;
    while (T--)
    {
        cin >> N;
        if (bs(FB, 1, MAXN, N))
        {
            cout << "B\n";
        }
        else
        {
            cout << "A\n";
        }
    }
    
    return 0;
}
