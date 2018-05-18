//
//  main.c
//  f-CDOJ-2016-F-柱爷与三叉戟不得不说的故事
//
//  Created by ZYJ on 16/5/9.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define MAXSIZE 10001
int D[16];
int N;
int A[MAXSIZE][6];
int AD[MAXSIZE] = {0};    //存储洞穴对应D的物品价值和
int C[MAXSIZE];
int flag[MAXSIZE] = {0};

int dfs(int i, int ans)
{
    if (i > 15)
    {
        return ans;
    }
    
    if (AD[i] > C[i])
    {
        for (int j = 1; j <= A[i][0]; j++)
        {
            if (flag[A[i][j]] != 0)
            {
                dfs(i + 1, ans);
                return ans;
            }
        }
        dfs(i + 1, ans);
        for (int j = 1; j <= A[i][0]; j++)
        {
            flag[A[i][j]] = 1;
        }
        ans = ans - AD[i] + C[i];
        dfs(i + 1, ans);
        for (int j = 1; j <= A[i][0]; j++)
        {
            flag[A[i][j]] = 0;
        }
    }
    else
    {
        dfs(i + 1, ans);
    }
    return ans;
}

int main(int argc, const char * argv[])
{
    int i, j;
    int ans = 0;
    for (i = 1; i <= 15; i++)
    {
        scanf("%d", D + i);
        ans += D[i];
    }
    scanf("%d", &N); 
    for (i = 1; i <= N; i++)
    {
        scanf("%d", A[i]);
        for (j = 1; j <= A[i][0]; j++)
        {
            scanf("%d", A[i] + j);
            AD[i] += D[A[i][j]];
        }
        scanf("%d", C + i);
    }
    
    printf("%d\n", dfs(1, ans));
    return 0;
}
