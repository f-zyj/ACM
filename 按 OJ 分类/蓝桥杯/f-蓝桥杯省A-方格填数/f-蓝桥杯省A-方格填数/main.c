//
//  main.c
//  f-蓝桥杯省A-方格填数
//
//  Created by ZYJ on 16/4/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define row 3
#define col 4

//const int row = 3, col = 4; //row行数，col列数
int visit[10];              //数字的使用情况
int flag[row][col];         //格子填写标记
int mpt[row][col];          //格子
int ans = 0;

void init()
{
    int i, j;
    ans = 0;
    for (i = 0; i < 10; i++)
    {
        visit[i] = 0;
    }
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            mpt[i][j] = 0;
            flag[i][j] = 1;
        }
    }
    //左上角和右下角不能填写任何数字
    flag[0][0] = 0;
    flag[row - 1][col - 1] = 0;
    return ;
}

void judge()
{
    //八个方向  右  左  上  下  右下  左下  右上  左上
    int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int i, j, k, x, y;
    int valid = 1;  //初始化为合法
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            //左上角和右下角不处理
            if (flag[i][j] == 0)
            {
                continue;
            }
            for (k = 0; k < 8; k++) //检测
            {
                x = i + dir[k][0];
                y = j + dir[k][1];
                //当前访问点是否还在矩形中
                if (x < 0 || x > 2 || y < 0 || y > 3 || flag[x][y] == 0)
                {
                    continue;
                }
                //相邻即相减后的绝对值为1 判断当前是否合法
                if (mpt[i][j] - mpt[x][y] == 1)
                {
                    valid = 0;
                }
            }
        }
    }
    if (valid)
    {
        ans++;
        //用来测试输入结果
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                printf("%d ", mpt[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return ;
}

void dfs(int n)
{
    int i, x, y;
    x = n / 4;  //获得行数
    y = n % 4;  //获得所在列
    
    if (x == 2 && y == 3)     //填满后判断是否满足情况
    {
        judge();
        return ;
    }
    if (flag[x][y]) //如果当前位置可填入数字
    {
        for (i = 0; i < 10; i++)
        {
            if (visit[i] == 0)  //是否使用过
            {
                visit[i] = 1;
                mpt[x][y] = i;
                dfs(n + 1);
                visit[i] = 0;   //取消当前数字的使用
            }
        }
    }
    else    //不可填的时候换下一个位置
    {
        dfs(n + 1);
    }
    return ;
}

int main(int argc, const char * argv[])
{
    init();
    dfs(0);
    
    printf("%d\n", ans);
    return 0;
}
