//
//  main.cpp
//  f-稳定婚姻问题
//
//  Created by ZYJ on 16/7/18.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

/*
 *  稳定婚姻问题O(n^2)
 */
const int N = 1001;
struct People
{
    bool state;
    int opp, tag;
    int list[N];        //  man使用
    int priority[N];    //  woman使用，有必要的话可以和list合并，以节省空间
    void Init()
    {
        state = tag = 0;
    }
} man[N], woman[N];

struct R
{
    int opp;
    int own;
} requst[N];
int n;
void Input();
void Output();
void stableMatching();

int main()
{
    Input();
    stableMatching();
    Output();
    
    return 0;
}

void Input()
{
    scanf("%d\n", &n);
    int i, j, ch;
    for (i = 0; i < n; ++i)
    {
        man[i].Init();
        for(j = 0; j < n; ++j)
        {   //  按照man的意愿递减排序
            scanf("%d", &ch);
            man[i].list[j] = ch - 1;
        }
    }
    for (i = 0; i < n; ++i)
    {
        woman[i].Init();
        for (j = 0; j < n; ++j)
        {   //  按照woman的意愿递减排序,但是，存储方法与man不同
            scanf("%d", &ch);
            woman[i].priority[ch - 1] = j;
        }
    }
    return ;
}

void stableMatching()
{
    int k;
    for (k = 0; k < n; ++k)
    {
        int i, id = 0;
        for (i = 0; i < n; ++i)
        {
            if (man[i].state == 0)
            {
                requst[id].opp = man[i].list[man[i].tag];
                requst[id].own = i;
                man[i].tag += 1;
                ++id;
            }
        }
        if (id == 0)
        {
            break;
        }
        for (i = 0; i < id; i++)
        {
            if (woman[requst[i].opp].state == 0)
            {
                woman[requst[i].opp].opp = requst[i].opp;
                woman[requst[i].opp].state = 1;
                man[requst[i].own].state = 1;
                man[requst[i].own].opp = requst[i].opp;
            }
            else
            {
                if (woman[requst[i].opp].priority[woman[requst[i].opp].opp] >woman[requst[i].opp].priority[requst[i].own])
                {
                    man[woman[requst[i].opp].opp].state = 0;
                    woman[requst[i].opp].opp = requst[i].own;
                    man[requst[i].own].state = 1;
                    man[requst[i].own].opp = requst[i].opp;
                }
            }
        }
    }
    return ;
}

void Output()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", man[i].opp + 1);
    }
    return ;
}