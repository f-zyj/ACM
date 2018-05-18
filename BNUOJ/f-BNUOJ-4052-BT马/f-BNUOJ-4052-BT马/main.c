//
//  main.c
//  f-BNUOJ-4052-BT马
//
//  Created by ZYJ on 16/4/23.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include<stdio.h>

int book[10][10] = {0};

struct step
{
    int x;//横
    int y;//纵
    int stepNum;    //步数
};

struct step que[100];

int main()
{
    int x, y, n;
    
    int next[2][2]= {{0, 1}, {1, 0}};
    int first = 1, last = 1;
    int i, tx, ty, tStepNum;
    scanf("%d %d", &x, &y);
    scanf("%d", &n);
    if (n > x || n > y)
    {
        printf("No\n");
        return 0;
    }

    que[last].x = 0;
    que[last].y = 0;
    que[last].stepNum = 0;
    last++;
    
    book[0][0] = 1;
    
    while(first < last)
    {
        for(i = 0; i < 2; i++)
        {
            tx = que[first].x + next[i][0];
            ty = que[first].y + next[i][1];
            tStepNum = que[first].stepNum + 1;
            
            if(book[tx][ty] == 0 && tx + tStepNum * n < x && ty + tStepNum * n < y)
            {
                //把这个点标记为已经走过
                // 注意广搜每个点只入队一次，所以和深搜不一样，不需要把book数组还原
                book[tx][ty] = 1;
                //插入新的点到队列中
                que[last].x = tx;
                que[last].y = ty;
                que[last].stepNum = tStepNum;
                last++;
            }
            if(tx + tStepNum * n == x && ty + tStepNum * n == y)
            {
                printf("Yes\n");
                return 0;
            }
        }
        
        first++;
    }
    
    printf("No\n");
    return 0;
}