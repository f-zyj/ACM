//
//  main.c
//  f-ALGO-137-Lift and Throw
//
//  Created by ZYJ on 16/3/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
//int initialPlace[4], movement[4], throwing[4], tag[4], tagOne[4], tagTwo[4], tagThree[4], tagFour[4];
////  初始位置           可移动距离     可抛出距离    操作？   操作一？     操作二？    操作三？       举？
////  1-10              1-10         1-10        ［      1为可操作，0为不可操作         ］     0未举，1-3
////操作一：移动，direction为－1向左，为1向右
//void Run(int manRun, int distance, int dirction)
//{
//    if (dirction == -1)
//    {
//        initialPlace[manRun] = initialPlace[manRun] - distance;
//        tagOne[manRun] = 0;
//        if (tagFour[manRun] != 0)
//        {
//            initialPlace[tagFour[manRun]] = initialPlace[manRun];
//            if (tagFour[tagFour[manRun]] != 0)
//            {
//                initialPlace[tagFour[tagFour[manRun]]] = initialPlace[manRun];
//            }
//        }
//        return ;
//    }
//    else
//    {
//        initialPlace[manRun] = initialPlace[manRun] + distance;
//        tagOne[manRun] = 0;
//        if (tagFour[manRun] != 0)
//        {
//            initialPlace[tagFour[manRun]] = initialPlace[manRun];
//            if (tagFour[tagFour[manRun]] != 0)
//            {
//                initialPlace[tagFour[tagFour[manRun]]] = initialPlace[manRun];
//            }
//        }
//        return ;
//    }
//}
////操作二：举起
//void Raise(int man, int manRaise)
//{
//    initialPlace[manRaise] = initialPlace[man];
//    tag[manRaise] = 0;
//    tagTwo[man] = 0;
//    if (tagFour[manRaise] != 0)
//    {
//        initialPlace[tagFour[manRaise]] = initialPlace[man];
//    }
//    return ;
//}
////操作三：抛出
//void throw(int manThrow, int man, int distance, int dirction)
//{
//    if (dirction == -1)
//    {
//        initialPlace[man] = initialPlace[man] - distance;
//        tagThree[manThrow] = 0;
//        tag[man] = 1;
//        if (tagFour[man] != 0)
//        {
//            initialPlace[tagFour[man]] = initialPlace[man];
//        }
//        return ;
//    }
//    else
//    {
//        initialPlace[man] = initialPlace[man] + distance;
//        tagThree[manThrow] = 0;
//        tag[man] = 1;
//        if (tagFour[man] != 0)
//        {
//            initialPlace[tagFour[man]] = initialPlace[man];
//        }
//        return ;
//    }
//
//}
//int main(int argc, const char * argv[])
//{
//    int i = 1;
//    for (; i < 4; i++)
//    {
//        scanf("%d %d %d", &initialPlace[i], &movement[i], &throwing[i]);
//        tag[i] = 1, tagOne[i] = 1, tagTwo[i] = 1, tagThree[i] = 1, tagFour[i] = 0;
//    }
//    
//    printf("Hello, World!\n");
//    return 0;
//}

#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define max(a, b) a > b ? a : b
//定义数组大小为4，从一开始，空出下标为0，方便计算
int x[4];                  //三个人的位置
int l[4];                  //三个人的机动性（可移动距离）
int t[4];                  //三个人的抛的距离
int ans = 0;               //经过操作后的最远距离，初始化为0
int w[4];                  //初始化为0，0表示可以进行操作，非零表示不可以
int p[4];                  //初始化为0，表示a[i]所举起的人
int a[4] = {3, 3, 3, 3};   //初始化为3，表人的状态，这里a对应的二进制为0011，后三位分别是三个动作：抛出，举起，移动。0（无意义）0（不可抛出）1（未进行举起）1（未进行移动）。这道题中，a只有六个可能值：0(0000)、1(0001)、2(0010)、3(0011)、4(0100)、5(0101)，表示人的六种状态
//bool类型
int near(int s)
{
    int i = 1;
    for (; i <= 3; i++)
    {
        if (s == x[i] + 1 || s == x[i] - 1)
        {
            return TRUE;
        }
    }
    return FALSE;
}
//dfs深度遍历
void dfs(int d)
{
    int i = 1, j = 1, e = 0;
    //每次都取最远（大）的位置
    for (; i <= 3; i++)
    {
        ans = max(ans, x[i]);
    }
    for (i = 1; i <= 3; i++)
    {
        //是否可以进行操作
        if (w[i])
        {
            continue;
        }
        //a[i] == 1 || a[i] == 3（未进行移动且不可抛出）
        if ((a[i] & 1) && !(a[i] & 4))
        {
            for (j = 1; j <= l[i]; j++)                         //移动
            {
                x[i] += j;                                      //a[i]向前移动j
                a[i] ^= 1;                                      //已移动
                if (near(x[i]) || j == l[i])                    //如果a[i]移动后的位置旁边有人或者移动距离达到上限
                {
                    dfs(d + 1);
                }
                x[i] -= j;                                      //归位
                x[i] -= j;                                      //a[i]向后移动j
                if (near(x[i]) || j == l[i])                    //如果a[i]移动后的位置旁边有人或者移动距离达到上限
                {
                    dfs(d + 1);
                }
                x[i] += j;                                      //归位
                a[i] ^= 1;                                      //还原为未移动
            }
        }
        //a[i] == 2 || a[i] == 3 || a[i] == 5（未进行举起）
        if (a[i] & 2)
        {
            for (j = 1; j <= 3; j++)                            //举起
            {
                if (i != j && !w[j] && t[i] > 0)                //是否可以进行操作
                {
                    if (x[i] == x[j] + 1 || x[j] == x[i] + 1)   //a[i]附近是否有人
                    {
                        w[j] = 1;                               //即将举起（抛出）j，抛出前将j是否可操作标记变更为否
                        a[i] ^= 2;                              //已举起
                        a[i] ^= 4;                              //可抛出
                        p[i] = j;                               //记录a[i]举起（抛出）了j
                        e = x[j];                               //记录a[j]的举起前位置
                        x[j] = -j;                              //a[j]（被举起）的位置定为负数，只作用于下一层递归时的取最远位置的循环
                        dfs(d + 1);
                        x[j] = e;                               //归位
                        w[j] = 0;                               //还原为可以进行操作
                        a[i] ^= 2;                              //还原为未举起
                        a[i] ^= 4;                              //还原为不可抛出
                    }
                }
            }
        }
        //a[i] == 4 || a[i] == 5（可抛出）
        if (a[i] & 4)
        {
            for (j = 1; j <= t[i]; j++)                         //抛出
            {
                w[p[i]] = 0;                                    //变更a[j]为可操作（以下a[j]指a[i]所举起的人）
                a[i] ^= 4;                                      //不可抛出
                e = x[p[i]];                                    //记录a[j]被举起前位置
                x[p[i]] = x[i] + j;                             //抛出a[j]，并更新a[j]位置
                if (near(x[p[i]]) || j == t[i])                 //如果a[j]被抛出后的位置旁边有人或者抛出距离达到上限
                {
                    dfs(d + 1);
                }
                x[p[i]] -= j;                                   //归位
                x[p[i]] -= j;                                   //a[j]向后抛出j
                if (near(x[p[i]]) || j == t[i])                 //如果a[j]被抛出后的位置旁边有人或者抛出距离达到上限
                {
                    dfs(d + 1);
                }
                x[p[i]] = e;                                    //还原a[j]为未举起前的位置
                a[i] ^= 4;                                      //还原a[j]为可抛出
                w[p[i]] = 1;                                    //还原a[j]为不可操作
            }
        }
    }
    return ;
}

int main()
{
    int i = 1;
    //键入每个人的信息
    for (; i <= 3; i++)
    {
        scanf("%d %d %d", &x[i], &l[i], &t[i]);
    }
    //深度优先遍历
    dfs(1);
    //输出最远距离
    printf("%d\n", ans);
    return 0;
}
