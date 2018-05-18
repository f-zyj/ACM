//
//  main.c
//  f-NYOJ-110-剑客决斗
//
//  Created by ZYJ on 16/4/27.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int vic[501][501];  //vic[i][j]第i个与第j个是否有机会PK
int rel[501][501];  //剑客间的胜负关系

//初始化
void init(int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", rel[i] + j);
        }
    }
    memset(vic, 0, sizeof(int) * 501 * 501);
    for (i = 0; i < n; i++) //初始化时只能确定相邻的两个人是可以PK的
    {
        vic[i][(i + 1) % n] = 1;
    }
    return ;
}

int solve(int n)
{
    int i, j, start, end;
    for (i = 1; i < n; i++) //中间隔着i个人
    {
        for (start = 0; start < n; start++)
        {
            end = (start + i + 1) % n;
            if (vic[start][end])    //当确认两个能PK时
            {
                continue;
            }
            for (j = (start + 1) % n; j != end; j++, j %= n)
            {
                if (vic[start][j] && vic[j][end] && (rel[start][j] || rel[end][j])) //当start可以和jPK，j可以和endPK，并且至少有一方可以大过j方能实现start和endPK
                {
                    vic[start][end] = 1;
                    break;
                }
            }
        }
    }
    int cnt = 0;
    for (i = 0; i < n; i++)
    {
        if (vic[i][i])  //为1说明i可以胜出
        {
            cnt++;
        }
    }
    return cnt;
}

int main(int argc, const char * argv[])
{
    int N, n;
    scanf("%d", &N);
    
    while (N--)
    {
        scanf("%d", &n);
        init(n);
        printf("%d\n", solve(n));
    }
    
    return 0;
}
