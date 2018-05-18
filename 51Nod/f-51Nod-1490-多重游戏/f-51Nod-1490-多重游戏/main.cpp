//
//  main.cpp
//  f-51Nod-1490-多重游戏
//
//  Created by ZYJ on 2016/9/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

#define mem(a, b) memset(a, b, sizeof(a))

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXL = 26;

char s[MAXN];
int ch[MAXN][MAXL + 5];
int val[MAXN];
int sz;
int sg[MAXN];

void init()
{
    sz = 1;
    mem(ch[0], 0);
    return ;
}

void inser(char *s)
{
    int u = 0;
    int len = (int)strlen(s);
    for (int i = 0; i < len; i++)
    {
        int c = s[i] - 'a';
        if (!ch[u][c])
        {
            mem(ch[sz], 0);
            val[sz] = 0;
            ch[u][c] = sz++;
        }
        u = ch[u][c];
    }
    val[u] = 1;
    return ;
}

//  输
int losses(int u)
{
    int x = 0, y = 0;
    for (int j = 0; j < MAXL; j++)
    {
        int p = ch[u][j];
        if (p)
        {
            if (losses(p))
            {
                x++;
            }
            else
            {
                y++;
            }
        }
    }
    if (x == 0 && y == 0)
    {
        return 1;
    }
    if (y)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//  赢
int gains(int u)
{
    int x = 0, y = 0;
    for (int j = 0; j < MAXL; j++)
    {
        int p = ch[u][j];
        if (p)
        {
            if (gains(p))
            {
               x++;
            }
            else
            {
                y++;
            }
        }
    }
    if (y)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    init();
    
    int n, k;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        inser(s);
    }
    
    int A = losses(0);  //  A:1->先手可以达成必输，0->先手不可以达成必输
    int B = gains(0);   //  B:1->先手可以达成必应，0->先手不可以达成必赢
    if (A && B)
    {
        cout << "First" << endl;
    }
    else
    {
        if (A)
        {
            cout << "Second" << endl;
        }
        else
        {
            if (B)
            {
                if (k % 2)
                {
                    cout << "First" << endl;
                }
                else
                {
                    cout << "Second" << endl;
                }
            }
            else
            {
                cout << "Second" << endl;
            }
        }
    }
    
    return 0;
}
