//
//  main.cpp
//  f-51Nod-1205-流水线调度
//
//  Created by ZYJ on 16/8/27.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 5e4 + 5;

struct task
{
    int a;
    int b;
} TaskA[MAXN], TaskB[MAXN];

bool cmpA(task a, task b)
{
    return a.a <= b.a;
}

bool cmpB(task a, task b)
{
    return a.b >= b.b;
}

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
   
    int a, b;
    int posA = 0, posB = 0;
    int sumA = 0, sumB = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &a, &b);
        if (a < b)
        {
            TaskA[posA].a = a;
            TaskA[posA++].b = b;
            sumA += b;
        }
        else
        {
            TaskB[posB].a = a;
            TaskB[posB++].b = b;
            sumB += a;
        }
    }
    sort(TaskA, TaskA + posA, cmpA);
    sort(TaskB, TaskB + posB, cmpB);
    
    for (int i = 0; i < posB; i++)
    {
        TaskA[posA++] = TaskB[i];
    }
    
    int ans = TaskA[0].a + TaskA[0].b;
    int sum = TaskA[0].a;
    for (int i = 1; i < posA; i++)
    {
        sum += TaskA[i].a;
        ans = sum < ans ? ans + TaskA[i].b : sum + TaskA[i].b;
    }
    
    cout << ans << '\n';
    
    return 0;
}

