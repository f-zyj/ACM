//
//  main.cpp
//  f-HDU-2017 多校训练赛2-1011-Regular polygon
//
//  Created by ZYJ on 2017/7/27.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1000;

struct Node
{
    int x, y;
};

struct hashTable
{
    int x, y;
    hashTable *next;
    
    hashTable()
    {
        next = 0;
    }
};

Node pos[MAXN];
hashTable *_hash[MAXN << 1];

void insert(int k)
{
    int key = ((pos[k].x * pos[k].x) + (pos[k].y * pos[k].y)) % MAXN + 1;
    
    if (!_hash[key])
    {
        hashTable *temp = new hashTable;
        temp->x = pos[k].x;
        temp->y = pos[k].y;
        _hash[key] = temp;
    }
    else
    {
        hashTable *temp = _hash[key];
        
        while (temp->next)
        {
            temp = temp->next;
        }
        
        temp->next = new hashTable;
        temp->next->x = pos[k].x;
        temp->next->y = pos[k].y;
    }
}

bool find(int x, int y)
{
    int key = (x * x + y * y) % MAXN + 1;
    
    if (!_hash[key])
    {
        return false;
    }
    else
    {
        hashTable *temp = _hash[key];
        
        while (temp)
        {
            if (temp->x == x && temp->y == y)
            {
                return true;
            }
            
            temp = temp->next;
        }
    }
    
    return false;
}

int main()
{
    int n;
    while (cin >> n)
    {
        memset(_hash, 0, sizeof(_hash));
        
        for (int k = 1; k <= n; k++)
        {
            cin >> pos[k].x >> pos[k].y;
            insert(k);
        }
        
        int res = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                int a = pos[j].x - pos[i].x;
                int b = pos[j].y - pos[i].y;
                
                int x3 = pos[i].x + b;
                int y3 = pos[i].y - a;
                int x4 = pos[j].x + b;
                int y4 = pos[j].y - a;
                
                if (find(x3, y3) && find(x4, y4))
                {
                    res++;
                }
                
                x3 = pos[i].x - b;
                y3 = pos[i].y + a;
                x4 = pos[j].x - b;
                y4 = pos[j].y + a;
                
                if (find(x3, y3) && find(x4, y4))
                {
                    res++;
                }
            }
        }
        
        cout << res / 4 << endl;
    }
    
    return 0;
}
