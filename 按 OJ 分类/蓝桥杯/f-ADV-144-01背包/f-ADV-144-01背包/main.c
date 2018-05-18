//
//  main.c
//  f-ADV-144-01背包
//
//  Created by ZYJ on 16/3/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
int V[200][5000];     //前i个物品装入容量为j的背包中获得的最大值

int max(int a,int b)
{
    if(a >= b)
        return a;
    else
        return b;
}

int Sack(int n, int *w, int *v, int C)
{
    int i, j;
    //初始化
    for (i = 0; i <= n; i++)
        V[i][0] = 0;
    for (j = 0; j <= C; j++)
        V[0][j] = 0;
    //动归
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= C; j++)
        {
            if (j < w[i])
                V[i][j] = V[i - 1][j];
            else
                V[i][j] = max(V[i - 1][j], V[i-1][j - w[i]] + v[i]);
        }
    }
    //j = C;   //通过上述的动归，j已经等于了C，无需再度赋值
    return V[n][C];
}

int main()
{
    int s;       //获得的最大价值
    int w[200];   //物品的重量
    int v[200];   //物品的价值
    int n = 0, i = 0;
    int C;       //背包最大容量

    scanf("%d %d", &n, &C);

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
        scanf("%d", &v[i]);
    }
    
    s = Sack(n, w, v, C);
    
    printf("%d\n", s);
        
    return 0;
}