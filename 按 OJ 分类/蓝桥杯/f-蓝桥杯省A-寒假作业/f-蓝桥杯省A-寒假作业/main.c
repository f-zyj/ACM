//
//  main.c
//  f-蓝桥杯省A-寒假作业
//
//  Created by ZYJ on 16/4/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define _MAX 13
int ans = 0;
int num[_MAX] = {0};
int visited[_MAX] = {0};

int test(int n)
{
    if (n == 2)
    {
        if (num[0] + num[1] == num[2])
        {
            return 1;
        }
    }
    else if (n == 5)
    {
        if (num[3] - num[4] == num[5])
        {
            return 1;
        }
    }
    else if (n == 8)
    {
        if (num[6] * num[7] == num[8])
        {
            return 1;
        }
    }
    else if (n == 11)
    {
        if (num[10] * num[11] == num[9])
        {
            ans++;
            return 1;
        }
    }
    else
    {
        return 1;
    }
    return 0;
}

void dfs(int n)
{
    int i = 0;
    if (n >= _MAX)
    {
        return ;
    }
    for (; i < _MAX; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            num[n] = i + 1;
            if (!test(n))   //如果不符合规则，则撤销这个分支
            {
                visited[i] = 0;
                continue;
            }
            dfs(n + 1);
            visited[i] = 0;
        }
    }
    return ;
}

int main(int argc, const char * argv[])
{
    dfs(0);
    printf("%d\n", ans);
    return 0;
}
