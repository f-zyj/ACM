//
//  main.cpp
//  f-HDU-1272-小希的迷宫
//
//  Created by ZYJ on 2016/10/24.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

#define mem(a, b) memset(a, b, sizeof(a))

using namespace std;

const int MAXN = 100010;

int flag;
int maxRoom;
int pre[MAXN];
int room[MAXN];
int root;

int find(int x)
{
    int r = x;
    while (pre[r] != r)
    {
        r = pre[r];
    }
    
    int i = x, j;
    while (i != r)
    {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}

void join(int x, int y)
{
    room[x] = room[y] = 1;
    if (x > maxRoom)
    {
        maxRoom = x;
    }
    if (y > maxRoom)
    {
        maxRoom = y;
    }
    
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        pre[fx] = fy;
    }
    else
    {
        flag = 0;
    }
    
    return ;
}

int main(int argc, const char * argv[])
{
    int A, B;
    while (cin >> A >> B, A != -1 || B != -1)
    {
        if (A == 0 && B == 0)
        {
            cout << "Yes\n";
            continue;
        }
        mem(room, 0);
        
        for (int i = 0; i <= MAXN; i++)
        {
            pre[i] = i;
        }
        
        join(A, B);
        
        flag = 1;
        maxRoom = 0;
        while (cin >> A >> B, A != 0 || B != 0)
        {
            join(A, B);
        }
        
        if (!flag)
        {
            cout << "No\n";
            continue;
        }
        
        root = 0;
        for (int i = 0; i <= maxRoom; i++)
        {
            if (room[i] && pre[i] == i)
            {
                root++;
            }
            if (root > 1)
            {
                flag = 0;
                break;
            }
        }
        
        if (flag)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    
    return 0;
}
