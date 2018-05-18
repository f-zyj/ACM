//
//  main.cpp
//  f-2016码农谷全国大学生程序设计邀请赛（第一轮资格赛）-试题一 对码农的编程水平进行排名
//
//  Created by ZYJ on 16/7/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;

typedef list<int> LISTINT;

int p[100];
int q[100];
int a[100];

int main(int argc, const char * argv[])
{
    LISTINT listPeople;
    LISTINT::iterator it;
    int N, M;
    int P, Q;
    cin >> N >> M;
    int key = 0;
    while (M--)
    {
        cin >> P >> Q;
        p[key] = P;
        q[key++] = Q;
    }
    for (int i = 0; i < key - 1; i++)
    {
        for (int j = i + 1; j < key; j++)
        {
            if (p[i] > p[j])
            {
                swap(p[i], p[j]);
                swap(q[i], q[j]);
            }
            else if (p[i] == p[j] && q[i] < q[j])
            {
                swap(p[i], p[j]);
                swap(q[i], q[j]);
            }
        }
    }
    listPeople.push_back(p[0]);
    listPeople.push_back(q[0]);
    int flag = key - 1;
    while (flag)
    {
    l:
        for (int i = 1; i < key; i++)
        {
            if (p[i] != 0)
            {
                for (it = listPeople.begin(); it != listPeople.end(); it++)
                {
                    if (*it == q[i])
                    {
                        listPeople.insert(it, p[i]);
                        p[i] = 0;
                        flag--;
                        goto l;
                    }
                    else if (*it == p[i])
                    {
                        listPeople.insert(++it, q[i]);
                        it--;
                        p[i] = 0;
                        flag--;
                        goto l;
                    }
                }
            }
        }
    }
   
    int k = 0;
    for (it = listPeople.begin(); it != listPeople.end(); it++)
    {
        a[k++] = *it;
    }
    for (int i = 0; i < k - 1; i++)
    {
        cout << a[i] << ' ';
    }
    cout << a[k - 1] << '\n';
    free(&it);
    free(&listPeople);
    return 0;
}
